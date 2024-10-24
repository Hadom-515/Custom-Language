/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */


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


#line 114 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SUBTRACTION = 258,
    ADD = 259,
    MULTIPLY = 260,
    DIVIDE = 261,
    MOD = 262,
    L_PAR = 263,
    R_PAR = 264,
    IDENTIFIER = 265,
    NUMBER = 266,
    RETURN = 267,
    RRETURN = 268,
    INT = 269,
    PRT = 270,
    FUNC = 271,
    WHILE = 272,
    IF = 273,
    ELSE = 274,
    BREAK = 275,
    CONTINUE = 276,
    READ = 277,
    SEMICOLON = 278,
    COMMA = 279,
    L_CURLY = 280,
    R_CURLY = 281,
    L_BRAKET = 282,
    R_BRAKET = 283,
    ASSIGNMENT = 284,
    LESS = 285,
    LESS_EQ = 286,
    GREATER = 287,
    GREATER_EQ = 288,
    EQUALITY = 289,
    NOT_EQ = 290,
    UNKNOWN_TOKEN = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "parser.y" /* yacc.c:355  */

 struct CodeNode *codenode;
 char *op_value;

#line 196 "parser.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 227 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    94,   103,   108,   117,   122,   124,   126,
     128,   130,   132,   134,   136,   138,   143,   148,   150,   155,
     157,   159,   161,   163,   165,   170,   182,   194,   208,   213,
     225,   239,   241,   243,   248,   248,   274,   289,   301,   304,
     317,   333,   339,   342,   355,   368,   384,   386,   393,   408,
     413,   424,   432,   437,   450,   461,   471,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUBTRACTION", "ADD", "MULTIPLY",
  "DIVIDE", "MOD", "L_PAR", "R_PAR", "IDENTIFIER", "NUMBER", "RETURN",
  "RRETURN", "INT", "PRT", "FUNC", "WHILE", "IF", "ELSE", "BREAK",
  "CONTINUE", "READ", "SEMICOLON", "COMMA", "L_CURLY", "R_CURLY",
  "L_BRAKET", "R_BRAKET", "ASSIGNMENT", "LESS", "LESS_EQ", "GREATER",
  "GREATER_EQ", "EQUALITY", "NOT_EQ", "UNKNOWN_TOKEN", "$accept", "if_stm",
  "else_stm", "comparitors", "bool_expr", "read_stm", "while_stm",
  "program", "functions", "statements", "statement", "return_stm",
  "var_dec", "param_dec", "function", "$@1", "var_assigment", "expression",
  "multiplicative_expr", "term", "pars", "varibles", "print_stm", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -104,     7,     1,  -104,    17,  -104,     3,  -104,    23,    -9,
      22,    24,    25,    31,    23,    51,  -104,  -104,    42,    18,
      23,   -13,     2,    -5,    61,    70,    77,    65,    71,    84,
    -104,  -104,    79,  -104,  -104,    80,    81,    82,    83,  -104,
      96,     2,     2,    -6,  -104,  -104,    38,    19,  -104,    64,
      97,     2,     2,     2,  -104,  -104,     2,  -104,  -104,  -104,
    -104,  -104,    85,  -104,   100,     2,    99,     2,     2,     2,
       2,     2,     2,    86,   102,   103,    66,   106,   107,    88,
    -104,  -104,    -1,    90,  -104,  -104,  -104,  -104,  -104,  -104,
     109,  -104,    95,  -104,  -104,  -104,  -104,  -104,  -104,     2,
      98,  -104,     2,  -104,     2,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,    37,    50,  -104,   105,   101,  -104,  -104,    69,
    -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     0,    34,    33,     0,
       0,    29,     0,     0,    33,     0,     6,    30,    31,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    11,     0,    13,     5,     0,     0,     0,     0,    32,
       0,     0,     0,    53,    47,    25,    38,    42,    49,    26,
       0,     0,     0,     0,    14,    15,     0,    12,    10,     7,
       8,     9,     0,    36,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    51,     0,     0,    40,    39,    44,    45,    43,    28,
       0,    55,     0,    19,    20,    21,    22,    23,    24,     0,
       0,    56,     0,    48,     0,    54,    27,     6,    41,     6,
      37,    50,     0,     0,    57,    18,     0,    16,     6,     0,
      17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,  -104,    68,  -104,  -104,  -104,  -104,  -103,
    -104,  -104,  -104,   -11,  -104,  -104,  -104,   -22,     4,  -104,
    -104,  -104,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    31,   117,    99,    75,    32,    33,     1,     2,    19,
      34,    35,    36,    10,     5,     8,    37,    76,    46,    47,
      82,    48,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    11,    65,    17,   112,    49,   113,     3,   103,    39,
      42,     7,    43,    44,    40,   119,    41,     4,    12,    63,
      64,    66,    50,   104,    69,    70,    71,     6,    21,    74,
      22,    13,    23,    24,    78,    25,    26,     9,    27,    28,
      29,    67,    68,    81,    30,    84,    85,    21,    14,    22,
      89,    23,    24,    15,    25,    26,    16,    27,    28,    29,
      21,    18,    22,   114,    23,    24,    20,    25,    26,    51,
      27,    28,    29,    86,    87,    88,   115,   108,    52,    21,
     110,    22,   111,    23,    24,    53,    25,    26,    54,    27,
      28,    29,    56,    72,    55,   120,    93,    94,    95,    96,
      97,    98,    57,    58,    59,    60,    61,    62,    73,    80,
      83,    91,    92,    79,    90,   100,   101,   102,   105,   106,
     107,    77,     0,   109,   116,     0,   118
};

static const yytype_int8 yycheck[] =
{
      22,    10,     8,    14,   107,    10,   109,     0,     9,    20,
       8,     8,    10,    11,    27,   118,    29,    16,    27,    41,
      42,    27,    27,    24,     5,     6,     7,    10,    10,    51,
      12,     9,    14,    15,    56,    17,    18,    14,    20,    21,
      22,     3,     4,    65,    26,    67,    68,    10,    24,    12,
      72,    14,    15,    28,    17,    18,    25,    20,    21,    22,
      10,    10,    12,    26,    14,    15,    24,    17,    18,     8,
      20,    21,    22,    69,    70,    71,    26,    99,     8,    10,
     102,    12,   104,    14,    15,     8,    17,    18,    23,    20,
      21,    22,     8,    29,    23,    26,    30,    31,    32,    33,
      34,    35,    23,    23,    23,    23,    23,    11,    11,     9,
      11,     9,     9,    28,    28,     9,     9,    29,    28,    10,
      25,    53,    -1,    25,    19,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,    16,    51,    10,     8,    52,    14,
      50,    10,    27,     9,    24,    28,    25,    50,    10,    46,
      24,    10,    12,    14,    15,    17,    18,    20,    21,    22,
      26,    38,    42,    43,    47,    48,    49,    53,    59,    50,
      27,    29,     8,    10,    11,    54,    55,    56,    58,    10,
      27,     8,     8,     8,    23,    23,     8,    23,    23,    23,
      23,    23,    11,    54,    54,     8,    27,     3,     4,     5,
       6,     7,    29,    11,    54,    41,    54,    41,    54,    28,
       9,    54,    57,    11,    54,    54,    55,    55,    55,    54,
      28,     9,     9,    30,    31,    32,    33,    34,    35,    40,
       9,     9,    29,     9,    24,    28,    10,    25,    54,    25,
      54,    54,    46,    46,    26,    26,    19,    39,    25,    46,
      26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    38,    39,    39,    40,
      40,    40,    40,    40,    40,    48,    49,    49,    49,    50,
      50,    50,    50,    50,    52,    51,    53,    53,    54,    54,
      54,    41,    55,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    59,    42,    43
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     2,     2,     2,
       2,     1,     2,     1,     2,     2,     8,     4,     0,     1,
       1,     1,     1,     1,     1,     2,     2,     5,     4,     2,
       4,     4,     6,     0,     0,     9,     3,     6,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     4,     1,
       3,     1,     0,     1,     4,     4,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 82 "parser.y" /* yacc.c:1646  */
    {
        struct CodeNode * node = (yyvsp[0].codenode);
        if (!hasSemanticError) {
            milFile << node -> code;
            std::cout << "successful\n";
        }
        milFile.close();
        }
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * functions = (yyvsp[-1].codenode);
            struct CodeNode * function = (yyvsp[0].codenode);
            struct CodeNode * node = new CodeNode;
            node -> code = functions -> code + function -> code;
            (yyval.codenode) = node;
        }
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * statements = (yyvsp[-1].codenode);
            struct CodeNode * statement = (yyvsp[0].codenode);
            struct CodeNode * node = new CodeNode;
            node -> code = statements -> code + statement -> code;
            (yyval.codenode) = node;
        }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[-1].codenode);}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[-1].codenode);}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[-1].codenode);}
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[-1].codenode);}
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    {}
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    {}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "parser.y" /* yacc.c:1646  */
    {}
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "parser.y" /* yacc.c:1646  */
    {}
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 157 "parser.y" /* yacc.c:1646  */
    {}
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "parser.y" /* yacc.c:1646  */
    {}
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 161 "parser.y" /* yacc.c:1646  */
    {}
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "parser.y" /* yacc.c:1646  */
    {}
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 165 "parser.y" /* yacc.c:1646  */
    {}
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 171 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = (yyvsp[0].codenode);
            node -> code = expression -> code;
            node -> code += std::string("ret ") + expression -> name + std::string("\n");
            (yyval.codenode) = node;
        }
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "parser.y" /* yacc.c:1646  */
    {
            if (isDeclared((yyvsp[0].op_value))) {
            yyerror("Variable redeclared");
            } else {
            symbolTable.push_back((yyvsp[0].op_value));
            struct CodeNode * node = new CodeNode;
            node -> code = std::string(". ") + std::string((yyvsp[0].op_value)) + std::string("\n");
            (yyval.codenode) = node;
            }
        }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 195 "parser.y" /* yacc.c:1646  */
    {
            if (isDeclared((yyvsp[0].op_value))) {
                yyerror("Array variable redeclared");
            } else if (atoi((yyvsp[-2].op_value)) <= 0) {
                fprintf(stderr, "Semantic error at line %d: array declared of size less than or equal to 0\n", yylineno);
            } else {
                symbolTable.push_back((yyvsp[0].op_value));
                struct CodeNode * node = new CodeNode;
                node -> code = std::string(".[] ") + std::string((yyvsp[0].op_value)) + std::string(", ") + std::string((yyvsp[-2].op_value)) + std::string("\n");
                (yyval.codenode) = node;
            }
        }
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 208 "parser.y" /* yacc.c:1646  */
    {}
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "parser.y" /* yacc.c:1646  */
    {
            if (isDeclared((yyvsp[0].op_value))) {
            yyerror("Parameter redeclared");
            } else {
            symbolTable.push_back((yyvsp[0].op_value));
            struct CodeNode * paramNode = new CodeNode;
            paramNode -> code = std::string(". ") + std::string((yyvsp[0].op_value)) + std::string("\n");
            (yyval.codenode) = paramNode;
            }
        }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 226 "parser.y" /* yacc.c:1646  */
    {
            if (isDeclared((yyvsp[-2].op_value))) {
            yyerror("Parameter redeclared");
            } else {
            symbolTable.push_back((yyvsp[-2].op_value));
            struct CodeNode * node = new CodeNode;
            struct CodeNode * param_dec = (yyvsp[0].codenode);
            node -> code = std::string(". ") + std::string((yyvsp[-2].op_value)) + std::string("\n");
            node -> code += param_dec -> code;
            (yyval.codenode) = node;
            }
        }
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "parser.y" /* yacc.c:1646  */
    {}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 241 "parser.y" /* yacc.c:1646  */
    {}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode; (yyval.codenode) = node;}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "parser.y" /* yacc.c:1646  */
    {symbolTable.clear();}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 249 "parser.y" /* yacc.c:1646  */
    {
        std::string subS = "";
        int cnt = 0;
        int dotPlace = 0;
        struct CodeNode * node = new CodeNode;
        struct CodeNode * statements = (yyvsp[-1].codenode);
        struct CodeNode * param_dec = (yyvsp[-4].codenode);
        node -> code = std::string("func ") + std::string((yyvsp[-7].op_value)) + std::string("\n");
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
        (yyval.codenode) = node;
    }
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 275 "parser.y" /* yacc.c:1646  */
    {
            if (!isDeclared((yyvsp[-2].op_value))) {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "Undeclared variable'%s'", (yyvsp[-2].op_value));
            yyerror(buffer);
            } else {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = (yyvsp[0].codenode);
            node -> code = expression -> code;
            node -> code += std::string("= ") + std::string((yyvsp[-2].op_value)) + std::string(", ") + expression -> name + std::string("\n");
            (yyval.codenode) = node;
            }
        }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 290 "parser.y" /* yacc.c:1646  */
    {

            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = (yyvsp[0].codenode);
            node -> code = expression -> code;
            node -> code += std::string("[]= ") + std::string((yyvsp[-5].op_value)) + std::string(", ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + expression -> name + std::string("\n");
            (yyval.codenode) = node;
        }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[0].codenode);}
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 305 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * left = (yyvsp[-2].codenode);
            struct CodeNode * right = (yyvsp[0].codenode);
            std::string tempVarible = createTempVarible();
            node -> code = left -> code + right -> code;
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("+ ") + tempVarible + std::string(", ") + left -> name + std::string(", ") + right -> name + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 318 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * multiplicative_expr = (yyvsp[-2].codenode);
            struct CodeNode * expression = (yyvsp[0].codenode);
            node -> code = multiplicative_expr -> code + expression -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("- ") + tempVarible + std::string(", ") + multiplicative_expr -> name + std::string(", ") + expression -> name + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 334 "parser.y" /* yacc.c:1646  */
    {}
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[0].codenode); }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 343 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = (yyvsp[-2].codenode);
            struct CodeNode * multiplicative_expr = (yyvsp[0].codenode);
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("% ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = (yyvsp[-2].codenode);
            struct CodeNode * multiplicative_expr = (yyvsp[0].codenode);
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("* ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 369 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * term = (yyvsp[-2].codenode);
            struct CodeNode * multiplicative_expr = (yyvsp[0].codenode);
            node -> code = term -> code + multiplicative_expr -> code;
            std::string tempVarible = createTempVarible();
            node -> code += std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("/ ") + tempVarible + std::string(", ") + term -> name + std::string(", ") + multiplicative_expr -> name + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[-1].codenode);}
#line 2132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 387 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            node -> name = std::string((yyvsp[0].op_value));
            (yyval.codenode) = node;
        }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 395 "parser.y" /* yacc.c:1646  */
    {

             struct CodeNode * node = new CodeNode;
             struct CodeNode * pars = (yyvsp[-1].codenode);
             std::string tempVarible = createTempVarible();
             node -> code = pars -> code;
             node -> code += std::string(". ") + tempVarible + std::string("\n");
             node -> code += std::string("call ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + tempVarible + std::string("\n");
             node -> name = tempVarible;
             (yyval.codenode) = node;
           }
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 408 "parser.y" /* yacc.c:1646  */
    {(yyval.codenode) = (yyvsp[0].codenode);}
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 414 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = (yyvsp[0].codenode);
            struct CodeNode * pars = (yyvsp[-2].codenode);
            node -> code = pars -> code;
            node -> code += expression -> code;
            node -> code += std::string("param ") + expression -> name + std::string("\n");
            (yyval.codenode) = node;
        }
#line 2178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 425 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            struct CodeNode * expression = (yyvsp[0].codenode);
            node -> code += expression -> code;
            node -> code += std::string("param ") + expression -> name + std::string("\n");
            (yyval.codenode) = node;
        }
#line 2190 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 432 "parser.y" /* yacc.c:1646  */
    {struct CodeNode * node = new CodeNode;(yyval.codenode) = node;}
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "parser.y" /* yacc.c:1646  */
    {
            if (!isDeclared((yyvsp[0].op_value))) {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "Undeclared variable '%s'", (yyvsp[0].op_value));
            yyerror(buffer);
            } else {
            struct CodeNode * node = new CodeNode;
            node -> name = std::string((yyvsp[0].op_value));
            (yyval.codenode) = node;
            }
        }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 451 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode * node = new CodeNode;
            std::string tempVarible = createTempVarible();
            node -> code = std::string(". ") + tempVarible + std::string("\n");
            node -> code += std::string("=[] ") + tempVarible + std::string(", ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + std::string((yyvsp[-1].op_value)) + std::string("\n");
            node -> name = tempVarible;
            (yyval.codenode) = node;
        }
#line 2225 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 462 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode *node = new CodeNode;
            struct CodeNode *expression = (yyvsp[-1].codenode);
            node->code = expression->code;
            node-> code += std::string(".> ") + expression->name + std::string("\n");
            (yyval.codenode) = node;
        }
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 471 "parser.y" /* yacc.c:1646  */
    {}
#line 2243 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 477 "parser.y" /* yacc.c:1646  */
    {
            struct CodeNode* condition = (yyvsp[-4].codenode); 
            struct CodeNode* body = (yyvsp[-1].codenode); 

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
            (yyval.codenode) = node;
        }
#line 2281 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2285 "parser.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 511 "parser.y" /* yacc.c:1906  */


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
