%{
#include <stdio.h>

int column = 1;
int intNum=0;
int intOp=0;
int intEq=0;
int intPar=0;
%}

%option yylineno

DIGIT       [0-9]
ALPHA       [a-zA-Z]
COMMENT     [#].*\n
WHITESPACE  [ \t\n]+
KEYWORDS "func"|"return"|"int"|"prt"|"read"|"while"|"if"|"else"|"break"|"continue"
IDENTIFIER  {ALPHA}+(({ALPHA}|{DIGIT})+)?
NUMBER      {DIGIT}+(\.{DIGIT}+)?
SCINTIFICNUM {NUMBER}[eE][+-]?{NUMBER}
SYMBOLS  ";"|","|"("|")"|"{"|"}"|"["|"]"
MATHOPERATIONS "+"|"-"|"*"|"/"|"%"
COMPARISON "<"|"<="|">"|">="|"==="|"!="
IDENTIFIER_INVALID {DIGIT}+({ALPHA}|{DIGIT})+
ASSIGNMENT_ERROR [=][^ \t\n]	 
ERRORCOM {COMPARISON}[^ \t\n]|"=="

%%
 
{KEYWORDS}            {printf("KEYWORDS: %s\n", yytext);}
{SYMBOLS}            {if(*(yytext) == '(' || *(yytext) == ')') intPar+=1;printf("SYMBOLS: %s\n", yytext);}
{MATHOPERATIONS}            {intOp+=1;printf("MATH OPPERATOR: %s\n", yytext);}
{COMPARISON}            {printf("COMPARISON SYMBOL: %s\n", yytext);}
{IDENTIFIER}            {printf("IDENTIFIER: %s\n", yytext);}
"="         		{intEq+=1;printf("ASSIGNMENT OPPERATOR: =\n");}
{ASSIGNMENT_ERROR}              { printf("ERROR: Unrecognized symbol '%s' at line %d, column %d\n", yytext, yylineno, column); column += yyleng; return -1;}
{NUMBER}                {intNum+=1; printf("NUMBER: %s\n", yytext);}
{SCINTIFICNUM}		{{intNum+=1; printf("SCINTIFIC NUMBER: %s\n", yytext);}}	
{COMMENT}               {}
{WHITESPACE}            { printf; column += yyleng; }
{IDENTIFIER_INVALID}    { printf("ERROR: Invalid identifier '%s' at line %d, column %d\n", yytext, yylineno, column); column += yyleng; return -1; }
{ERRORCOM}              { printf("ERROR: Unrecognized symbol '%s' at line %d, column %d\n", yytext, yylineno, column); column += yyleng; return -1;}
.                       { printf("ERROR: Unrecognized symbol '%s' at line %d, column %d\n", yytext, yylineno, column); column += yyleng; return -1;}
                     
%%

int main(int argc, char **argv)
{
    yylex();
printf( "# of ints = %d\n",intNum);
printf( "# of Opperations = %d\n",intOp);
printf( "# of  parentheses = %d\n",intPar);
printf( "# of equals = %d\n",intEq);

    return 0;
}

int yywrap(void)
{
    return 1;
}
