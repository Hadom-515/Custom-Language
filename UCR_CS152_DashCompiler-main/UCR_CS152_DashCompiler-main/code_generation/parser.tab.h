/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SUBTRACTION = 258,             /* SUBTRACTION  */
    ADD = 259,                     /* ADD  */
    MULTIPLY = 260,                /* MULTIPLY  */
    DIVIDE = 261,                  /* DIVIDE  */
    MOD = 262,                     /* MOD  */
    L_PAR = 263,                   /* L_PAR  */
    R_PAR = 264,                   /* R_PAR  */
    NUMBER = 265,                  /* NUMBER  */
    IDENTIFIER = 266,              /* IDENTIFIER  */
    RETURN = 267,                  /* RETURN  */
    RRETURN = 268,                 /* RRETURN  */
    INT = 269,                     /* INT  */
    PRT = 270,                     /* PRT  */
    FUNC = 271,                    /* FUNC  */
    WHILE = 272,                   /* WHILE  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    READ = 277,                    /* READ  */
    SEMICOLON = 278,               /* SEMICOLON  */
    COMMA = 279,                   /* COMMA  */
    L_CURLY = 280,                 /* L_CURLY  */
    R_CURLY = 281,                 /* R_CURLY  */
    L_BRAKET = 282,                /* L_BRAKET  */
    R_BRAKET = 283,                /* R_BRAKET  */
    ASSIGNMENT = 284,              /* ASSIGNMENT  */
    LESS = 285,                    /* LESS  */
    LESS_EQ = 286,                 /* LESS_EQ  */
    GREATER = 287,                 /* GREATER  */
    GREATER_EQ = 288,              /* GREATER_EQ  */
    EQUALITY = 289,                /* EQUALITY  */
    NOT_EQ = 290,                  /* NOT_EQ  */
    UNKNOWN_TOKEN = 291            /* UNKNOWN_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"

 struct CodeNode *codenode;
 char *op_value;

#line 105 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
