%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
int breakCnt=0;
int continueCnt=0;
int loopCnt=0;
struct CodeNode{
std :: string code;
std :: string name;
};
struct loopLabel{
std::string label;
bool breakS = false;
bool continueS = false;

};
std:: stack <loopLabel> labeles;
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
std::string createJmpLabel(){
 static int cnt = 0;
 return std::string("_L") + std::to_string(cnt++);
}
enum Type { Integer, Array };

struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};
std::vector <Function> symbol_table;
Function *get_function() {
  int last = symbol_table.size()-1;
  if (last < 0) {
    printf("***Error. Attempt to call get_function with an empty symbol table\n");
    printf("Create a 'Function' object using 'add_function_to_symbol_table' before\n");
    printf("calling 'find' or 'add_variable_to_symbol_table'");
    exit(1);
  }
  return &symbol_table[last];
}

int find(std::string &value) {

  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {

      return s->type;
    }
  }
  return -1;
}
bool find_function(std:: string &value){
 for(int i=0;i<symbol_table.size();i++){
  if(symbol_table.at(i).name.compare(value) == 0){ return true;}
 }
 return false;

}
void add_function_to_symbol_table(std::string &value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}
void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}
bool checkMainFunc(){
 for(int i=0; i<symbol_table.size();i++){
  if(symbol_table.at(i).name.compare("main") == 0) return true;
 }
 return false;
}
Type getVarType(std:: string &code){

 if(code.at(1) == '['){ return Array;}
 return Integer;
}

std:: string getVarNameDecleration(Type t, std:: string &code){

 if(t == Integer){
  return code.substr(2,code.find('\n')-2);
 }
 else{
  for(int i = 4;i<code.length();i++){
   if(code.at(i) == ','){
     return code.substr(4,i-4);
   }
  }
 }
}

std:: string getVarNamePrint(Type t, std:: string &code){
 if(t == Integer){
  return code.substr(3,code.find('\n')-3);
 }
 else{
  for(int i = 4;i<code.length();i++){
   if(code.at(i) == ','){
     return code.substr(5,i-4);
   }
  }
 }
}


void checkIntergerAssignemnt(std:: string &code){
  for(int i=2;i<code.length();i++){
    if(code.at(i)==','){
     std:: string s = code.substr(2,i-2);
     int isValid = find(s);
        if(isValid == 1){
          fprintf(stderr, "Sematic error at line %d: treating an array as an interger\n", yylineno);
           exit(1);
         }
         if(isValid == -1){
          fprintf(stderr, "Sematic error at line %d: assigning an undeclared varible\n", yylineno);
           exit(1);
         }
     if(code.at(i+2) != '_' && code.at(i+2)>64){
        s = code.substr(i+2,code.length()-(i+2));
        isValid = find(s);
        if(isValid == 1){
          fprintf(stderr, "Sematic error at line %d: assiging an integer to a array\n", yylineno);
           exit(1);
         }
         if(isValid == -1){
          fprintf(stderr, "Sematic error at line %d: assigning an undeclared varible\n", yylineno);
           exit(1);
         }
      }
      break;
    }
  }
}
void checkArrayAssignmentLeft(std:: string &code){
  int startVal=0;
  for(int i=0;i<code.length();i++){
   if(code.at(i) == ','){
     startVal=i+2;
     break;
   }
  }
  std:: string temp = "";
  for(int i=startVal;i<code.length();i++){
   if(code.at(i) == ','){
    break;
   }
   temp += code.at(i);
 }
 int check = find(temp);
 if(check == -1){
   fprintf(stderr, "Sematic error at line %d: Accessing an unknow array\n", yylineno);
           exit(1);
 }
 if(check == 0){
   fprintf(stderr, "Sematic error at line %d: treating an interger as an array\n", yylineno);
           exit(1);
 }
}
void checkArrayAssignmentRight(std::string &code){
int numberStart = 0;
int srcStart = 0;
std:: string temp = "";
for(int i=4;i<code.length();i++){
   if(code.at(i) == ','){
     numberStart=i+2;
     break;
    }
    temp += code.at(i); 
  }
 int check = find(temp);
 if(check == -1){
   fprintf(stderr, "Sematic error at line %d: Assigning an unknow array\n", yylineno);
           exit(1);
 }
 if(check == 0){
   fprintf(stderr, "Sematic error at line %d: treating an interger as an array\n", yylineno);
           exit(1);
 }
 for(int i=numberStart;i<code.length();i++){
   if(code.at(i) == ','){
     srcStart=i+2;
     break;
    }
  }
  temp = code.substr(srcStart, code.length()-srcStart);
  if(temp.at(0) != '_'  && temp.at(0)>64){
    check = find(temp);
     if(check == -1){
       fprintf(stderr, "Sematic error at line %d: accessing an unknow varible\n", yylineno);
           exit(1);
      }
         if(check == 1){
          fprintf(stderr, "Sematic error at line %d: treating an array as an interger\n", yylineno);
           exit(1);
     }
   } 
}
void checkMath(std::string &code){
 std:: string temp1 = "";
 std:: string temp2 =  "";
 int commaCont =0;
 int check;
 for(int i=0; i<code.length();i++){
  if(code.at(i) == '\n'){
   break;
  }
  if(code.at(i) == ','){
    commaCont++;
    i+=2;
   }
   if(commaCont==1){
    temp1+=code.at(i);
   }
   if(commaCont == 2){
    temp2+=code.at(i);
   }
  }
  if(temp1.at(0) != '_' && temp1.at(0)>64){
   check = find(temp1);
   if(check == -1){
       fprintf(stderr, "Sematic error at line %d: accessing an unknow varible\n", yylineno);
           exit(1);
      }
         if(check == 1){
          fprintf(stderr, "Sematic error at line %d: treating an array as an interger\n", yylineno);
           exit(1);
     }
  }
 if(temp2.at(0) != '_' && temp2.at(0)>64){
   check = find(temp2);
   if(check == -1){
       fprintf(stderr, "Sematic error at line %d: accessing an unknow varible\n", yylineno);
           exit(1);
      }
         if(check == 1){
          fprintf(stderr, "Sematic error at line %d: treating an array as an interger\n", yylineno);
           exit(1);
     }
  }
}

void generate_table_and_verify_code(std::string &code){
 int startLine=0;
 for(int i=0;i<code.length();i++){
   if(code.at(i) == '\n'){

    std::string s = code.substr(startLine,i-startLine);
     if(code.at(startLine) == '.' && code.at(startLine+1) != '[' && code.at(startLine+1) != '>' && code.at(startLine+2) != '_'){
        s=getVarNameDecleration(Integer,s);
        if(find(s)!= -1){
          fprintf(stderr, "Sematic error at line %d: redeclaring a know varible\n", yylineno);
  	   exit(1);
	 }
        add_variable_to_symbol_table(s,Integer);
      }
     if(code.at(startLine) == '.' && code.at(startLine+1) == '[' && code.at(startLine+3) != '>'){
        s=getVarNameDecleration(Array,s);
        if(find(s)!= -1){
          fprintf(stderr, "Sematic error at line %d: redeclaring a know varible\n", yylineno);
           exit(1);
         }
        add_variable_to_symbol_table(s,Array);
     }
      if(code.at(startLine) == '.' && code.at(startLine+1) == '>' && code.at(startLine+3) != '_'){
        s=getVarNamePrint(Integer,s);
        int isValid = find(s);
        if(isValid == 1){
          fprintf(stderr, "Sematic error at line %d: treating an array as an interger\n", yylineno);
           exit(1);
         }
         if(isValid == -1){
          fprintf(stderr, "Sematic error at line %d: print an undeclared varible\n", yylineno);
           exit(1);
         }
     }
     if(code.at(startLine) == '=' && code.at(startLine+1)== ' '){
     checkIntergerAssignemnt(s);
   }
    if(code.at(startLine) == '=' && code.at(startLine+1)== '['){
     checkArrayAssignmentLeft(s);  
   }
   if(code.at(startLine) == '['){
      checkArrayAssignmentRight(s);
  
    }
   if((code.at(startLine) == '=' && code.at(startLine+1) == '=') || code.at(startLine) == '!' || code.at(startLine) == '<' || code.at(startLine) == '>'|| code.at(startLine) == '+' || code.at(startLine) == '-' || code.at(startLine) == '*' || code.at(startLine) == '/' || code.at(startLine) == '%'){
    checkMath(s);
   

  }
   startLine = i+1;
      }
    }
  }

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());

       printf("  type: %d\n", symbol_table[i].declarations[j].type);

    }
  }
  printf("--------------------\n");
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

%nterm <double> read_statement 

%start program
%type <codenode> function_declerations function_decleration statements statement var_decleration if_statement
%type <codenode> var_assigment expression multiplicative_expr term varibles print_statement pars while_statement
%type <codenode> paramerter_decleration return_statement comparitors else_statement bool_expression
%%
program                : function_declerations { struct CodeNode *node = $1;
 if(!checkMainFunc()){
  fprintf(stderr, "Sematic error at line %d: no main fuction declared\n", yylineno);
  exit(1);

 }
 if(!labeles.empty() || (loopCnt < breakCnt) || (loopCnt < continueCnt) ){
  fprintf(stderr, "Sematic error at line %d: mutiple break/continue statement used outside loop or mutiple  break/continue from in a loop \n", yylineno);
  exit(1);
 }
                         printf("%s\n", node->code.c_str());}
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
		       | if_statement { $$ = $1;}
		       | return_statement SEMICOLON {$$ = $1;}
                       | read_statement SEMICOLON {
struct CodeNode *node = new CodeNode;
 $$ = node;}
		       | while_statement { 
loopCnt++;
$$ = $1;}
                       | BREAK SEMICOLON {
breakCnt++;
struct CodeNode *node = new CodeNode;
std::string temp;
if(labeles.empty() || labeles.top().breakS){
 temp=createJmpLabel();
 loopLabel Label;
 Label.label = temp;
 Label.breakS = true;
 labeles.push(Label);
 node->code = std::string(":= ") + temp + std::string("end\n");
}
else{
 labeles.top().breakS = true;
 node->code = std::string(":= ") + temp + std::string("end\n");
}
 $$ = node;}
                       | CONTINUE SEMICOLON {
continueCnt++;
struct CodeNode *node = new CodeNode;
std::string temp;
if(labeles.empty() || labeles.top().continueS){
 temp=createJmpLabel();
 loopLabel Label;
 Label.label = temp;
 Label.continueS = true;
 labeles.push(Label);
 node->code = std::string(":= ") + temp + std::string("begin\n");
}
else{
 labeles.top().continueS = true;
 node->code = std::string(":= ") + temp + std::string("begin\n");
}
 $$ = node;
}
		       ;  
if_statement           : IF L_PAR bool_expression R_PAR L_CURLY statements R_CURLY else_statement {
struct CodeNode *node= new CodeNode;
struct CodeNode *bool_expression= $3;
struct CodeNode *statements= $6;
struct CodeNode *else_statement= $8;
node->code = bool_expression->code;
node->code+= std::string("?:= ") + else_statement->name + std::string(", ") + bool_expression->name + std::string("\n");node->code+= statements->code + else_statement->code;
$$ = node;

};
else_statement         : ELSE L_CURLY statements R_CURLY {
struct CodeNode *node= new CodeNode;
struct CodeNode *statements= $3;
std::string label1 = createJmpLabel();
std::string label2 = createJmpLabel();
node->code = std::string(":= ") + label2+ std::string("\n");
node->code += std::string(": ") + label1 + std::string("\n");
node->code += statements->code;
node->code += std::string(": ") + label2 + std::string("\n");
node->name = label1;
$$ = node;

}
		       | %empty {struct CodeNode *node = new CodeNode; node->name = createJmpLabel(); 
 node->code = std::string(": ") + node->name + std::string("\n");
 $$ = node;
 }
                       ;
comparitors            : LESS {struct CodeNode *node= new CodeNode; node->name=">="; $$=node;}
		       | LESS_EQ {struct CodeNode *node= new CodeNode; node->name=">"; $$=node;}
		       | GREATER {struct CodeNode *node= new CodeNode; node->name="<="; $$=node;}
                       | GREATER_EQ {struct CodeNode *node= new CodeNode; node->name="<"; $$=node;}
                       | EQUALITY {struct CodeNode *node= new CodeNode; node->name="!="; $$=node;} 
                       | NOT_EQ {struct CodeNode *node= new CodeNode; node->name="=="; $$=node;}
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
  exit(1);
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

std::string subS= std::string($2);
add_function_to_symbol_table(subS);
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
           subS= subS.substr(1);
           add_variable_to_symbol_table(subS, Integer);
           dotPlace =i+1;
	}
}
node->code += statements->code;
generate_table_and_verify_code(statements->code);
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
 struct CodeNode *multiplicative_expr = $1; 
 struct CodeNode *expression = $3;
 node -> code = multiplicative_expr -> code + expression->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 node -> code += std::string("+ ") + tempVarible + std::string(", ") + multiplicative_expr->name  + std::string(", ") + expression->name + std::string("\n");
 node -> name = tempVarible; 
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
bool_expression        : expression comparitors expression {
 struct CodeNode *node = new CodeNode;
 struct CodeNode *exprL = $1;
 struct CodeNode *exprR = $3;
 struct CodeNode *comparitors = $2;
 node->code= exprL->code + exprR->code;
 std:: string tempVarible = createTempVarible();
 node -> code +=  std:: string(". ") + tempVarible + std::string("\n");
 
 node->code += comparitors->name += std::string(" ")+ tempVarible + std::string(", ") + exprL->name + std::string(", ")+exprR->name + std::string("\n");
node->name = tempVarible;
$$ = node;
 

};
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

 std:: string s = $1;
if(!find_function(s)){
  fprintf(stderr, "Sematic error at line %d: called an underclared function\n", yylineno);
  exit(1);
 }

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

if(atoi($3) < 0){
  fprintf(stderr, "Sematic error at line %d: array index less than 0\n", yylineno);
  exit(1);
 }

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
while_statement        : WHILE L_PAR bool_expression R_PAR L_CURLY statements R_CURLY {
std:: string temp;
struct CodeNode *node = new CodeNode;
struct CodeNode *bool_expression = $3;
struct CodeNode *statements = $6;
if(!labeles.empty()){ temp=labeles.top().label;
 temp = labeles.top().label;
 labeles.pop();
}
else{
 temp = createJmpLabel();
 }

node->code= std::string(": ") + temp + std::string("begin\n");
node->code += bool_expression->code;
node->code+= std::string("?:= ") + temp + std::string("end, ") + bool_expression->name + std::string("\n");
node->code+=statements->code;
node->code += std::string(":= ") + temp + std::string("begin\n");
node->code += std::string(": ") + temp + std::string("end\n");
$$ = node;

};
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
   //print_symbol_table();
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












