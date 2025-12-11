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

#ifndef YY_YY_STYLAXX_TAB_H_INCLUDED
# define YY_YY_STYLAXX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 14 "stylaxx.y"

    typedef struct {
        int type;       // 0=INT, 1=FLOAT, 2=STRING
        int i_val;
        double f_val;
        char *s_val;
        int is_array;
        int *arr_vals;
        int arr_size;
    } Data;

    typedef enum { 
        NODE_CONST, NODE_VAR, NODE_OP, NODE_ASSIGN, 
        NODE_IF, NODE_WHILE, NODE_FOR, NODE_SEQ, NODE_PRINT, NODE_INPUT,
        NODE_ARRAY_DECL, NODE_ARRAY_ASSIGN, NODE_ARRAY_ACCESS,
        NODE_MATH_FUNC
    } NodeType;

    typedef struct Node {
        NodeType type;
        Data value;             
        char *varName;          
        char op;                
        int mathFuncType;       
        struct Node *left;      
        struct Node *right;     
        struct Node *cond;      
        struct Node *body;      
        struct Node *elseBody;  
    } Node;

#line 81 "stylaxx.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_NUM = 258,                 /* INT_NUM  */
    FLOAT_NUM = 259,               /* FLOAT_NUM  */
    STRING_LIT = 260,              /* STRING_LIT  */
    VARIABLE = 261,                /* VARIABLE  */
    DEKHAO = 262,                  /* DEKHAO  */
    DHORI = 263,                   /* DHORI  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    INPUT = 268,                   /* INPUT  */
    POW = 269,                     /* POW  */
    ROOT = 270,                    /* ROOT  */
    SIN = 271,                     /* SIN  */
    COS = 272,                     /* COS  */
    TAN = 273,                     /* TAN  */
    ABS = 274,                     /* ABS  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    GE = 279,                      /* GE  */
    LE = 280,                      /* LE  */
    GT = 281,                      /* GT  */
    LT = 282,                      /* LT  */
    ASSIGN = 283,                  /* ASSIGN  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    MUL = 286,                     /* MUL  */
    DIV = 287,                     /* DIV  */
    MOD = 288,                     /* MOD  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    LBRACE = 291,                  /* LBRACE  */
    RBRACE = 292,                  /* RBRACE  */
    SEMICOLON = 293,               /* SEMICOLON  */
    LBRACKET = 294,                /* LBRACKET  */
    RBRACKET = 295,                /* RBRACKET  */
    COMMA = 296                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "stylaxx.y"

    int intVal;
    double floatVal;
    char *strVal;
    Node *nodePtr;

#line 146 "stylaxx.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_STYLAXX_TAB_H_INCLUDED  */
