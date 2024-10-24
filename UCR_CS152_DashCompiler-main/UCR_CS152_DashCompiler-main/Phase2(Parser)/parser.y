%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <string.h>
#include <fstream>

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
int error_count = 0;
void yyerror(const char* s);
std::string createTempVarible(){
 static int cnt = 0;
 return std::string("_temp") + std::to_string(cnt++);
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

%nterm <double> if_statement else_statement 
%nterm <double> comparitors bool_expression
%nterm <double> read_statement while_statement 

%start program
%type <codenode> function_declerations function_decleration statements statement var_decleration
%type <codenode> var_assigment expression multiplicative_expr term varibles print_statement pars
%type <codenode> paramerter_decleration return_statement
%%
program                : function_declerations { 
                        struct CodeNode *node = $1;
                         printf("%s\n", node->code.c_str());
                         milFile << node->code; 
                        milFile.close();}
function_declerations  : function_declerations function_decleration {
 struct CodeNode *function_declerations = $1;
 struct CodeNode *function_decleration = $2;
 struct CodeNode *node = new CodeNode;
 node -> code = function_declerations-> code + function_decleration -> code;
 $$ = node; }
                       | %empty{
 struct CodeNode *node = new CodeNode;
 $$ = node;}
                       ;
statements	       : statements statement { 
 struct CodeNode *statements = $1;
 struct CodeNode *statement = $2;
 struct CodeNode *node = new CodeNode;
 node -> code = statements-> code + statement -> code;
 $$ = node;}
		       | %empty		      {
  struct CodeNode *node = new CodeNode;
 $$ = node;
 }
		       ;
statement	       : var_decleration SEMICOLON {$$ = $1;}
	               | var_assigment SEMICOLON { $$ = $1; }
		       | print_statement SEMICOLON {$$ = $1;}
		       | if_statement {
struct CodeNode *node = new CodeNode;
 $$ = node;}
		       | return_statement SEMICOLON {$$ = $1;}
                       | read_statement SEMICOLON {
struct CodeNode *node = new CodeNode;
 $$ = node;}
		       | while_statement {
struct CodeNode *node = new CodeNode;
 $$ = node;}
                       | BREAK SEMICOLON {
struct CodeNode *node = new CodeNode;
 $$ = node;}
                       | CONTINUE SEMICOLON {
struct CodeNode *node = new CodeNode;
 $$ = node;}
		       ;  
if_statement           : IF L_PAR bool_expression R_PAR L_CURLY statements R_CURLY else_statement {};
else_statement         : ELSE L_CURLY statements R_CURLY {}
		       | %empty {}
                       ;
comparitors            : LESS {}
		       | LESS_EQ {}
		       | GREATER {}
                       | GREATER_EQ {}
                       | EQUALITY {} 
                       | NOT_EQ {}
                       ;
return_statement       : RETURN expression {
 struct CodeNode *node= new CodeNode;
 struct CodeNode *expression= $2;
 node->code=expression->code;
 node->code+= std::string("ret ")+expression->name +std::string("\n");
 $$=node;

};
var_decleration        : INT IDENTIFIER {
 struct CodeNode *node= new CodeNode;
 node->code = std:: string(". ") + std::string($2) + std::string("\n");
 $$ = node;
 
 } 
		       | INT L_BRAKET NUMBER R_BRAKET IDENTIFIER {
  if(atoi($3) <= 0){
  fprintf(stderr, "Sematic error at line %d: array decleared of size less than or equal to 0\n", yylineno);
  return -1;
 }
  struct CodeNode *node= new CodeNode;
  node -> code =  std:: string(".[] ") + std::string($5) + std::string(", ")+std::string($3)+ std::string("\n");
  $$ = node;
  
 } 
	               | INT IDENTIFIER ASSIGNMENT expression  {}
		       ;
paramerter_decleration : INT IDENTIFIER {
 struct CodeNode *node = new CodeNode;
 node->code = std:: string(". ") + std::string($2) + std::string("\n");
 $$ = node;
}
            	       | INT IDENTIFIER COMMA paramerter_decleration{ 
struct CodeNode *node = new CodeNode;
struct CodeNode *paramerter_decleration = $4;
 node->code = std:: string(". ") + std::string($2) + std::string("\n");
 node->code += paramerter_decleration->code;
 $$ = node;
}
		       | INT L_BRAKET R_BRAKET IDENTIFIER {}
            	       | INT L_BRAKET R_BRAKET IDENTIFIER COMMA paramerter_decleration {}
		       | %empty {struct CodeNode *node = new CodeNode; $$ = node;}
		       ; 
function_decleration   : FUNC IDENTIFIER L_PAR paramerter_decleration R_PAR L_CURLY statements R_CURLY {
std::string subS="";
int cnt=0;
int dotPlace=0;
struct CodeNode *node = new CodeNode;
struct CodeNode *statements = $7; 
struct CodeNode *paramerter_decleration = $4;
node->code = std::string("func ") + std::string($2) + std::string("\n");
node->code += paramerter_decleration->code;
for(int i=0; i< paramerter_decleration->code.length();i++){
	if(paramerter_decleration->code.at(i) == '\n'){
	   subS = paramerter_decleration->code.substr(dotPlace + 1 , i-dotPlace-1);
           node->code += std::string("= ")+subS+std::string(", $")+std::to_string(cnt) + std::string("\n");
	   cnt++;
           dotPlace =i+1;
	}
}
node->code += statements->code;
node->code += std::string("endfunc\n\n");
$$ = node;};
var_assigment          : IDENTIFIER ASSIGNMENT expression {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *expression = $3;
 node -> code = expression -> code;
 node-> code += std:: string("= ")+ std::string($1) + std::string(", ")+ expression->name+ std::string("\n");
 $$ = node;
 }
                       | IDENTIFIER L_BRAKET NUMBER R_BRAKET ASSIGNMENT expression{

 struct CodeNode *node = new CodeNode;
 struct CodeNode *expression = $6;
 node -> code = expression -> code; 
 node-> code += std:: string("[]= ") + std::string($1) + std::string(", ") + std::string($3) + std::string(", ") + expression->name + std::string("\n");
 $$= node;
}
                       ;
expression             : multiplicative_expr {$$ = $1;}
		       | multiplicative_expr ADD expression {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *left = $1; 
    struct CodeNode *right = $3;
    std::string tempVarible = createTempVarible();
    node->code = left->code + right->code;
    node->code += std::string(". ") + tempVarible + std::string("\n");
    node->code += std::string("+ ") + tempVarible + std::string(", ") + left->name  + std::string(", ") + right->name + std::string("\n");
    node->name = tempVarible;
 $$ = node;}
		       | multiplicative_expr SUBTRACTION expression { 
 struct CodeNode *node = new CodeNode;
 struct CodeNode *multiplicative_expr = $1;
 struct CodeNode *expression = $3;
 node -> code = multiplicative_expr -> code + expression->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std::string("- ") + tempVarible + std::string(", ") + multiplicative_expr->name  + std::string(", ") + expression->name + std::string("\n");
 node -> name = tempVarible;
 $$ = node;}
                       ;
bool_expression        : expression comparitors expression {};
multiplicative_expr    : term {$$ = $1;}
                       | term MOD multiplicative_expr {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *term = $1;
 struct CodeNode *multiplicative_expr = $3;
 node -> code = term -> code + multiplicative_expr->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std::string("% ") + tempVarible + std::string(", ") + term->name  + std::string(", ") + multiplicative_expr->name + std::string("\n");
 node -> name = tempVarible;
 $$ = node;}
		       | term MULTIPLY multiplicative_expr {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *term = $1;
 struct CodeNode *multiplicative_expr = $3;
 node -> code = term -> code + multiplicative_expr->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std::string("* ") + tempVarible + std::string(", ") + term->name  + std::string(", ") + multiplicative_expr->name + std::string("\n");
 node -> name = tempVarible;
 $$ = node;}
		       | term DIVIDE multiplicative_expr {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *term = $1;
 struct CodeNode *multiplicative_expr = $3;
 node -> code = term -> code + multiplicative_expr->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std::string("/ ") + tempVarible + std::string(", ") + term->name  + std::string(", ") + multiplicative_expr->name + std::string("\n");
 node -> name = tempVarible;
 $$ = node;}
		       ;
term                   : L_PAR expression R_PAR {$$ = $2; }
		       | NUMBER {
 struct CodeNode *node = new CodeNode;
 node -> name = std::string($1); 
 $$ = node;}
                       | IDENTIFIER L_PAR pars R_PAR {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *pars = $3;
 std:: string tempVarible = createTempVarible();
 node->code=pars->code;
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node->code+=std::string("call ")+ std::string($1) + std::string(", ") + tempVarible +  std::string("\n");
 node->name = tempVarible; 
 $$ = node;}
		       | varibles {$$ = $1;}
		       ;
pars                   : pars COMMA expression {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *expression = $3;
  struct CodeNode *pars = $1;
  node->code = pars->code;
 node->code += expression->code;
  node->code += std::string("param ") + expression->name +std::string("\n");
 $$ = node;
}
		       | expression { 
 struct CodeNode *node = new CodeNode;
 struct CodeNode *expression = $1;
 node->code += expression->code;
 node->code += std::string("param ") + expression->name +std::string("\n");
 $$ = node;}
                       | %empty {struct CodeNode *node = new CodeNode; $$ = node;}
                       ;
varibles               : IDENTIFIER {
 struct CodeNode *node = new CodeNode;
 node -> name = std::string($1);
 $$ = node;}
		       | IDENTIFIER L_BRAKET NUMBER R_BRAKET {
 struct CodeNode *node = new CodeNode;
 std:: string tempVarible = createTempVarible();
 node -> code =  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std:: string("=[] ")+tempVarible + std:: string(", ") +std::string($1) + std:: string(", ") + std::string($3) +  std::string("\n");
 node->name = tempVarible;
 $$ = node;}
                       ;
 print_statement		       : PRT L_PAR expression R_PAR {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *expression = $3;
 node->code = expression->code;
 node-> code += std::string(".> ") + expression->name + std::string("\n");
 $$ = node;
};
read_statement 	       : READ L_PAR expression R_PAR {};
while_statement        : WHILE L_PAR bool_expression R_PAR L_CURLY statements R_CURLY {};
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

    if (error_count > 0) {
        fprintf(stderr, "Parsing finished with %d error(s).\n", error_count);
        return 1; 
    }

    return 0;
}

void yyerror(const char *s) {
  if (strcmp(s, "syntax error") == 0) {
        fprintf(stderr, "Syntax error at line %d: Unexpected token\n", yylineno);
    } else if (strcmp(s, "type error") == 0) {
        fprintf(stderr, "Type error at line %d: Incompatible types\n", yylineno);
    } else if (strcmp(s, "undeclared variable") == 0) {
        fprintf(stderr, "Error at line %d: Undeclared variable\n", yylineno);
    } else {
        fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    }
    error_count++;
}