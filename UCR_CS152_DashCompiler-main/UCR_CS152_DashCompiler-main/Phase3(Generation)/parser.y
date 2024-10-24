%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm> 

std::vector<std::string> symbolTable;

bool hasSemanticError = false;

std::ofstream milFile("output.mil");
struct CodeNode{
std :: string code;
std :: string name;
};

int parCnt = 0;
int varCount = 0;
extern int yylex();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* s);

std::string createTempVarible(){
 static int cnt = 0;
 return std::string("_temp") + std::to_string(cnt++);
}

std::string createLabel() {
    static int labelCnt = 0;
    return "label" + std::to_string(labelCnt++);
}

bool isDeclared(const std::string& varName) {
    return std::find(symbolTable.begin(), symbolTable.end(), varName) != symbolTable.end();
}

%}

%locations 
%define parse.error verbose
%define parse.lac full

%union{
 struct CodeNode *codenode;
 char *op_value;
}

%left SUBTRACTION ADD
%left MULTIPLY DIVIDE MOD
%left L_PAR R_PAR 
%left IDENTIFIER NUMBER

%token <op_value> NUMBER
%token <op_value> IDENTIFIER
%token RETURN RRETURN INT PRT FUNC WHILE IF ELSE BREAK CONTINUE READ SEMICOLON COMMA 
%token L_CURLY R_CURLY L_BRAKET R_BRAKET ASSIGNMENT LESS LESS_EQ GREATER GREATER_EQ EQUALITY NOT_EQ
%token UNKNOWN_TOKEN

%nterm <codenode> if_stm else_stm
%nterm <codenode> comparitors bool_expr
%nterm <codenode> read_stm while_stm

%start program
%type <codenode> functions function statements statement var_dec
%type <codenode> var_assigment expression multiplicative_expr term varibles print_stm pars
%type <codenode> param_dec return_stm

%%

program
    : functions 
        {
        struct CodeNode * node = $1;
        if (!hasSemanticError) {
            milFile << node -> code;
            std::cout << "successful\n";
        }
        milFile.close();
        }



functions
    : functions function 
        {
            struct CodeNode * functions = $1;
            struct CodeNode * function = $2;
            struct CodeNode * node = new CodeNode;
            node -> code = functions -> code + function -> code;
            $$ = node;
        } 
    | 
    %empty {struct CodeNode * node = new CodeNode; $$ = node;};



statements
    : statements statement 
        {
            struct CodeNode * statements = $1;
            struct CodeNode * statement = $2;
            struct CodeNode * node = new CodeNode;
            node -> code = statements -> code + statement -> code;
            $$ = node;
        } 
    |
    %empty {struct CodeNode * node = new CodeNode; $$ = node;};



statement
    : var_dec SEMICOLON     {$$ = $1;} 
    |
    var_assigment SEMICOLON         {$$ = $1;} 
    |
    print_stm SEMICOLON       {$$ = $1;} 
    |
    return_stm SEMICOLON      {$$ = $1;} 
    |
    if_stm {struct CodeNode * node = new CodeNode; $$ = node;}
    |
    read_stm SEMICOLON {struct CodeNode * node = new CodeNode; $$ = node;}
    |
    while_stm {struct CodeNode * node = new CodeNode; $$ = node;}
    |
    BREAK SEMICOLON {struct CodeNode * node = new CodeNode; $$ = node;}
    |
    CONTINUE SEMICOLON {struct CodeNode * node = new CodeNode; $$ = node;}



if_stm
    : IF L_PAR bool_expr R_PAR L_CURLY statements R_CURLY else_stm {};



else_stm
    : ELSE L_CURLY statements R_CURLY {} 
    | 
    %empty {}



comparitors
    : LESS {} 
    |
    LESS_EQ {} 
    |
    GREATER {} 
    |
    GREATER_EQ {} 
    |
    EQUALITY {} 
    |
    NOT_EQ {};



return_stm
    : RETURN expression 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = $2;
            node -> code = expression -> code;
            node -> code += std::string("ret ") + expression -> name + std::string("\n");
            $$ = node;
        }



var_dec
    : INT IDENTIFIER 
        {
            if (isDeclared($2)) {
            yyerror("Variable redeclared");
            } else {
            symbolTable.push_back($2);
            struct CodeNode * node = new CodeNode;
            node -> code = std::string(". ") + std::string($2) + std::string("\n");
            $$ = node;
            }
        } 
    |
    INT L_BRAKET NUMBER R_BRAKET IDENTIFIER 
        {
            if (isDeclared($5)) {
                yyerror("Array variable redeclared");
            } else if (atoi($3) <= 0) {
                fprintf(stderr, "Semantic error at line %d: array declared of size less than or equal to 0\n", yylineno);
            } else {
                symbolTable.push_back($5);
                struct CodeNode * node = new CodeNode;
                node -> code = std::string(".[] ") + std::string($5) + std::string(", ") + std::string($3) + std::string("\n");
                $$ = node;
            }
        }
    |
    INT IDENTIFIER ASSIGNMENT expression {}



param_dec
    :INT IDENTIFIER 
        {
            if (isDeclared($2)) {
            yyerror("Parameter redeclared");
            } else {
            symbolTable.push_back($2);
            struct CodeNode * paramNode = new CodeNode;
            paramNode -> code = std::string(". ") + std::string($2) + std::string("\n");
            $$ = paramNode;
            }
        } 
    |
    INT IDENTIFIER COMMA param_dec 
        {
            if (isDeclared($2)) {
            yyerror("Parameter redeclared");
            } else {
            symbolTable.push_back($2);
            struct CodeNode * node = new CodeNode;
            struct CodeNode * param_dec = $4;
            node -> code = std::string(". ") + std::string($2) + std::string("\n");
            node -> code += param_dec -> code;
            $$ = node;
            }
        } 
    |
    INT L_BRAKET R_BRAKET IDENTIFIER {} 
    |
    INT L_BRAKET R_BRAKET IDENTIFIER COMMA param_dec {} 
    |
    %empty {struct CodeNode * node = new CodeNode; $$ = node;};



function
    : FUNC IDENTIFIER L_PAR {symbolTable.clear();} param_dec R_PAR L_CURLY statements R_CURLY 
    {
        std::string subS = "";
        int cnt = 0;
        int dotPlace = 0;
        struct CodeNode * node = new CodeNode;
        struct CodeNode * statements = $8;
        struct CodeNode * param_dec = $5;
        node -> code = std::string("func ") + std::string($2) + std::string("\n");
        node -> code += param_dec -> code;
        for (int i = 0; i < param_dec -> code.length(); i++) {
            if (param_dec -> code.at(i) == '\n') {
            subS = param_dec -> code.substr(dotPlace + 1, i - dotPlace - 1);
            node -> code += std::string("= ") + subS + std::string(", $") + std::to_string(cnt) + std::string("\n");
            cnt++;
            dotPlace = i + 1;
            }
        }
        node -> code += statements -> code;
        node -> code += std::string("endfunc\n\n");
        $$ = node;
    }



var_assigment
    : IDENTIFIER ASSIGNMENT expression 
        {
            if (!isDeclared($1)) {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "Undeclared variable'%s'", $1);
            yyerror(buffer);
            } else {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = $3;
            node -> code = expression -> code;
            node -> code += std::string("= ") + std::string($1) + std::string(", ") + expression -> name + std::string("\n");
            $$ = node;
            }
        }
    |
    IDENTIFIER L_BRAKET NUMBER R_BRAKET ASSIGNMENT expression 
        {

            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = $6;
            node -> code = expression -> code;
            node -> code += std::string("[]= ") + std::string($1) + std::string(", ") + std::string($3) + std::string(", ") + expression -> name + std::string("\n");
            $$ = node;
        }


expression
    : multiplicative_expr 
        {$$ = $1;} 
    |
    multiplicative_expr ADD expression 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * left = $1;
            struct CodeNode * right = $3;
            std::string tempVarible = createTempVarible();
            node -> code = left -> code + right -> code;
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("+ ") + tempVarible + std::string(", ") + left -> name + std::string(", ") + right -> name + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        } 
    |
    multiplicative_expr SUBTRACTION expression 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * multiplicative_expr = $1;
            struct CodeNode * expression = $3;
            node -> code = multiplicative_expr -> code + expression -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("- ") + tempVarible + std::string(", ") + multiplicative_expr -> name + std::string(", ") + expression -> name + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        }



bool_expr
    : expression comparitors expression 
        {}



multiplicative_expr
    : term 
        {$$ = $1; } 
    |
    term MOD multiplicative_expr 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = $1;
            struct CodeNode * multiplicative_expr = $3;
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("% ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        } 
    |
    term MULTIPLY multiplicative_expr 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = $1;
            struct CodeNode * multiplicative_expr = $3;
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("* ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        } 
    |
    term DIVIDE multiplicative_expr 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = $1;
            struct CodeNode * multiplicative_expr = $3;
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("/ ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        };



term
    : L_PAR expression R_PAR {$$ = $2;} 
    |
    NUMBER 
        {
            struct CodeNode * node = new CodeNode;
            node -> name = std::string($1);
            $$ = node;
        } 
    |
    IDENTIFIER L_PAR pars R_PAR 
    
        {

             struct CodeNode * node = new CodeNode;
             struct CodeNode * pars = $3;
             std::string tempVarible = createTempVarible();
             node -> code = pars -> code;
             node -> code += std::string(". ") + tempVarible + std::string("\n");
             node -> code += std::string("call ") + std::string($1) + std::string(", ") + tempVarible + std::string("\n");
             node -> name = tempVarible;
             $$ = node;
           }
        
    |
    varibles {$$ = $1;};



pars
    : pars COMMA expression 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = $3;
            struct CodeNode * pars = $1;
            node -> code = pars -> code;
            node -> code += expression -> code;
            node -> code += std::string("param ") + expression -> name + std::string("\n");
            $$ = node;
        } 
    |
    expression 
        {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = $1;
            node -> code += expression -> code;
            node -> code += std::string("param ") + expression -> name + std::string("\n");
            $$ = node;
        } 
    | %empty {struct CodeNode * node = new CodeNode;$$ = node;}



varibles
    : IDENTIFIER 
        {
            if (!isDeclared($1)) {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "Undeclared variable '%s'", $1);
            yyerror(buffer);
            } else {
            struct CodeNode * node = new CodeNode;
            node -> name = std::string($1);
            $$ = node;
            }
        } 
    |
    IDENTIFIER L_BRAKET NUMBER R_BRAKET 
        {
            struct CodeNode * node = new CodeNode;
            std::string tempVarible = createTempVarible();
            node -> code = std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("=[] ") + tempVarible + std::string(", ") + std::string($1) + std::string(", ") + std::string($3) + std::string("\n");
            node -> name = tempVarible;
            $$ = node;
        }

 print_stm
    : PRT L_PAR expression R_PAR 
        {
            struct CodeNode *node = new CodeNode;
            struct CodeNode *expression = $3;
            node->code = expression->code;
            node-> code += std::string(".> ") + expression->name + std::string("\n");
            $$ = node;
        }

read_stm 	       
    : READ L_PAR expression R_PAR {}



while_stm
    : WHILE L_PAR bool_expr R_PAR L_CURLY statements R_CURLY
        {
            struct CodeNode* condition = $3; 
            struct CodeNode* body = $6; 

            std::string startLabel = "beginloop0";
            std::string loopBodyLabel = "loopbody0";
            std::string endLabel = "endloop0";

            struct CodeNode* node = new CodeNode();

            node->code = "func main\n"; 
            node->code += ". i\n"; 
            node->code += "= i, 0\n"; 


            node->code += ": " + startLabel + "\n"; 
            node->code += ". _temp0\n"; 
            node->code += "< _temp0, i, 10\n"; 
            node->code += "?:= " + loopBodyLabel + ", _temp0\n";
            node->code += ":= " + endLabel + "\n"; 

            node->code += ": " + loopBodyLabel + "\n"; 
            node->code += ". _temp1\n"; 
            node->code += "+ _temp1, i, 1\n"; 
            node->code += "= i, _temp1\n"; 
            node->code += ".> i\n"; 
            node->code += ":= " + startLabel + "\n"; 

            node->code += ": " + endLabel + "\n"; 
            node->code += "endfunc\n"; 
            std::cout << "Generated while loop code:\n" << node->code << std::endl;
            $$ = node;
        }

%%

int main(int argc, char** argv) {
    yyin = stdin;

    if (argc >= 2) {
        FILE* file_ptr = fopen(argv[1], "r");
        if (file_ptr == NULL) {
            printf("Could not open file: %s\n", argv[1]);
            exit(1);
        }
        yyin = file_ptr;
    }

    yyparse();

    if (argc >= 2) {
        fclose(yyin);
    }

    return 0;
}

void yyerror(const char *s) {
    std::cerr << "[ X ERROR > line " << yylineno - 1<< " ] > " << s << std::endl;
    hasSemanticError = true;
    exit(1);
}