DIGIT       [0-9]
ALPHA       [a-zA-Z]
COMMENT     [#].*\n
WHITESPACE  [ \t\n]+
FUNC func
RETURN return
INT int
PRT prt
READ read
WHILE while
IF if
ELSE else
BREAK break
CONTINUE continue
IDENTIFIER  {ALPHA}+(({ALPHA}|{DIGIT})+)?
NUMBER      [+-]?{DIGIT}+(\.{DIGIT}+)?
SCINTIFICNUM {NUMBER}[eE][+-]?{NUMBER}
SEMICOLON  ;
COMMA ,
L_PAR \(
R_PAR \)
L_CURLY \{
R_CURLY \}
L_BRAKET \[
R_BRAKET \]
ADD \+
SUBTRACTION \-
MULTIPLY \*
DIVIDE \/
MOD \%
ASSIGNMENT \=
LESS <
LESS_EQ <=
GREATER >
GREATER_EQ >=
EQUALITY ===
NOT_EQ !=
COMPARISON {LESS}|{LESS_EQ}|{GREATER}|{GREATER_EQ}|{EQUALITY}|{NOT_EQ}
IDENTIFIER_INVALID {DIGIT}+({ALPHA}|{DIGIT})+
ASSIGNMENT_ERROR [=][^ \t\n]	 
ERRORCOM {COMPARISON}[^ \t\n]|"=="

%{
#include <stdio.h>

#define YY_DECL int yylex()
#include "parser.tab.h"
%}

%option yylineno

%%

{FUNC}            {return FUNC;}
{RETURN}            {return RETURN;}
{INT}            {return INT;}
{PRT}            {return PRT;}
{WHILE}            {return WHILE;}
{IF}            {return IF;}
{ELSE}            {return ELSE;}
{BREAK}            {return BREAK;}
{CONTINUE}            {return CONTINUE;}
{READ}            {return READ;}
{SEMICOLON}            {return SEMICOLON;}
{COMMA}            {return COMMA;}
{L_PAR}            {return L_PAR;}
{R_PAR}            {return R_PAR;}
{L_CURLY}            {return L_CURLY;}
{R_CURLY}            {return R_CURLY;}
{L_BRAKET}            {return L_BRAKET;}
{R_BRAKET}            {return R_BRAKET;}
{ADD}            {return ADD;}
{SUBTRACTION}            {return SUBTRACTION;}
{MULTIPLY}            {return MULTIPLY;}
{DIVIDE}            {return DIVIDE;}
{MOD}            {return MOD;}
{ASSIGNMENT}            {return ASSIGNMENT;}
{LESS}            {return LESS;}
{LESS_EQ}            {return LESS_EQ;}
{GREATER}            {return GREATER;}
{GREATER_EQ}            {return GREATER_EQ;}
{EQUALITY}            {return EQUALITY;}
{NOT_EQ}            {return NOT_EQ;}







{IDENTIFIER}            { yylval.sval = strdup(yytext); return IDENTIFIER; }
{ASSIGNMENT_ERROR}      {printf("Error: unrecognized symbol \"%s\"\n", yytext); return -1; }
{NUMBER}                { yylval.dval = atof(yytext); return NUMBER; }

{SCINTIFICNUM}		{ printf("SCINTIFIC NUMBER: %s\n", yytext);}
{COMMENT}               {/* ignore */}
{WHITESPACE}            { /*ignore*/ }
{IDENTIFIER_INVALID}    {printf("Error: unrecognized symbol \"%s\"\n", yytext); return -1; }
{ERRORCOM}              {printf("Error: unrecognized symbol \"%s\"\n", yytext); return -1; }
.                       {printf("Error: unrecognized symbol \"%s\"\n", yytext); return -1; }
 
%%
int yywrap(void)
{
    return 1;
}
