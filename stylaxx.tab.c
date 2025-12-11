/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "stylaxx.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex();
    void yyerror(const char *s);
    extern FILE *yyin;
    extern char *yytext;

#line 82 "stylaxx.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "stylaxx.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_NUM = 3,                    /* INT_NUM  */
  YYSYMBOL_FLOAT_NUM = 4,                  /* FLOAT_NUM  */
  YYSYMBOL_STRING_LIT = 5,                 /* STRING_LIT  */
  YYSYMBOL_VARIABLE = 6,                   /* VARIABLE  */
  YYSYMBOL_DEKHAO = 7,                     /* DEKHAO  */
  YYSYMBOL_DHORI = 8,                      /* DHORI  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_MUL = 22,                       /* MUL  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_LBRACKET = 29,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 30,                  /* RBRACKET  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_statement = 33,                 /* statement  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_expression = 35                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 63 "stylaxx.y"

    struct Symbol {
        char *name;
        Data data;
    };
    struct Symbol table[100];
    int count = 0;

    void set_var(char *name, Data d) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) {
                if(table[i].data.is_array && !d.is_array) { /* protect array type */ }
                else table[i].data = d;
                return;
            }
        }
        table[count].name = strdup(name);
        table[count].data = d;
        count++;
    }

    Data get_var(char *name) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) return table[i].data;
        }
        printf("Runtime Error: Variable '%s' not found.\n", name);
        return (Data){0};
    }

    /* --- NODE CREATION --- */
    Node* makeNum(int v) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=0; p->value.i_val=v; return p; }
    Node* makeFloat(double v) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=1; p->value.f_val=v; return p; }
    Node* makeStr(char *s) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=2; p->value.s_val=s; return p; }
    Node* makeVar(char *n) { Node *p = malloc(sizeof(Node)); p->type=NODE_VAR; p->varName=n; return p; }
    
    Node* makeOp(Node *l, Node *r, char op) { 
        Node *p = malloc(sizeof(Node)); p->type=NODE_OP; p->left=l; p->right=r; p->op=op; return p; 
    }
    Node* makeAssign(char *n, Node *expr) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ASSIGN; p->varName=n; p->left=expr; return p;
    }
    Node* makePrint(Node *expr) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_PRINT; p->left=expr; return p;
    }
    Node* makeSeq(Node *l, Node *r) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_SEQ; p->left=l; p->right=r; return p;
    }
    Node* makeIf(Node *cond, Node *ifB, Node *elseB) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_IF; p->cond=cond; p->body=ifB; p->elseBody=elseB; return p;
    }
    Node* makeWhile(Node *cond, Node *body) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_WHILE; p->cond=cond; p->body=body; return p;
    }
    
    /* NEW: FOR LOOP NODE CREATION */
    Node* makeFor(Node *init, Node *cond, Node *incr, Node *body) {
        Node *p = malloc(sizeof(Node)); 
        p->type=NODE_FOR; 
        p->left=init;    // Initialization (dhori i=0;)
        p->cond=cond;    // Condition (i<5)
        p->right=incr;   // Increment (i=i+1;)
        p->body=body;    // Loop Body
        return p;
    }

    Node* makeArrayDecl(char *n, int size) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_DECL; p->varName=n; p->value.i_val=size; return p;
    }
    Node* makeArrayAcc(char *n, Node *idx) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_ACCESS; p->varName=n; p->left=idx; return p;
    }
    Node* makeArrayAss(char *n, Node *idx, Node *val) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_ASSIGN; p->varName=n; p->left=idx; p->right=val; return p;
    }

    /* --- EXECUTION ENGINE --- */
    Data run(Node *p) {
        if(!p) return (Data){0};
        
        switch(p->type) {
            case NODE_CONST: return p->value;
            case NODE_VAR:   return get_var(p->varName);
            
            case NODE_OP: {
                Data v1 = run(p->left);
                Data v2 = run(p->right);
                Data res = {0};
                
                double n1 = (v1.type==1)?v1.f_val:v1.i_val;
                double n2 = (v2.type==1)?v2.f_val:v2.i_val;
                int isF = (v1.type==1 || v2.type==1);
                
                if(p->op=='+') { if(isF) {res.type=1; res.f_val=n1+n2;} else {res.type=0; res.i_val=(int)n1+(int)n2;} }
                if(p->op=='-') { if(isF) {res.type=1; res.f_val=n1-n2;} else {res.type=0; res.i_val=(int)n1-(int)n2;} }
                if(p->op=='*') { if(isF) {res.type=1; res.f_val=n1*n2;} else {res.type=0; res.i_val=(int)n1*(int)n2;} }
                if(p->op=='/') { if(isF) {res.type=1; res.f_val=n1/n2;} else {res.type=0; res.i_val=(int)n1/(int)n2;} }
                
                if(p->op=='g') { res.type=0; res.i_val = (n1 > n2); }
                if(p->op=='l') { res.type=0; res.i_val = (n1 < n2); }
                if(p->op=='e') { res.type=0; res.i_val = (n1 == n2); }
                return res;
            }

            case NODE_ASSIGN: {
                Data v = run(p->left);
                set_var(p->varName, v);
                return v;
            }
            
            case NODE_SEQ:
                run(p->left);
                run(p->right);
                return (Data){0};

            case NODE_PRINT: {
                Data v = run(p->left);
                if(v.type==0) printf("Output: %d\n", v.i_val);
                else if(v.type==1) printf("Output: %.2f\n", v.f_val);
                else if(v.type==2) printf("Output: %s\n", v.s_val);
                return (Data){0};
            }

            case NODE_IF:
                if(run(p->cond).i_val) run(p->body);
                else if(p->elseBody) run(p->elseBody);
                return (Data){0};

            case NODE_WHILE:
                while(run(p->cond).i_val) run(p->body);
                return (Data){0};

            /* NEW: FOR LOOP EXECUTION */
            case NODE_FOR:
                run(p->left);               // 1. Initialization (dhori i=0)
                while(run(p->cond).i_val) { // 2. Check Condition (i<5)
                    run(p->body);           // 3. Run Body
                    run(p->right);          // 4. Increment (i=i+1)
                }
                return (Data){0};

            case NODE_ARRAY_DECL: {
                Data d = {0};
                d.is_array = 1;
                d.arr_size = p->value.i_val;
                d.arr_vals = (int*)calloc(d.arr_size, sizeof(int));
                set_var(p->varName, d);
                return (Data){0};
            }
            case NODE_ARRAY_ASSIGN: {
                Data idx = run(p->left);
                Data val = run(p->right);
                Data arr = get_var(p->varName);
                if(arr.is_array && idx.i_val < arr.arr_size) {
                    arr.arr_vals[idx.i_val] = val.i_val;
                } 
                return (Data){0}; 
            }
            case NODE_ARRAY_ACCESS: {
                Data idx = run(p->left);
                Data arr = get_var(p->varName);
                Data res = {0};
                if(arr.is_array && idx.i_val < arr.arr_size) {
                    res.type = 0;
                    res.i_val = arr.arr_vals[idx.i_val];
                }
                return res;
            }
        }
        return (Data){0};
    }

#line 323 "stylaxx.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   238,   242,   243,   246,   247,   250,   251,
     252,   256,   261,   265,   266,   270,   271,   272,   273,   274,
     276,   277,   278,   279,   281,   282,   283,   285
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_NUM", "FLOAT_NUM",
  "STRING_LIT", "VARIABLE", "DEKHAO", "DHORI", "IF", "ELSE", "WHILE",
  "FOR", "EQ", "NEQ", "GE", "LE", "GT", "LT", "ASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "LBRACKET", "RBRACKET", "$accept", "program", "statement",
  "statement_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,   200,   -28,   -18,   -11,    13,    -2,    17,    20,   -28,
      59,    59,    59,   -15,    59,    59,   207,   -28,   -28,   -28,
      16,    59,    95,    73,   143,    59,    43,   154,   165,    59,
      59,   176,    59,    59,    59,    59,    59,    59,    59,   -28,
      29,    25,   107,    22,    46,    50,   119,    84,   -28,   -13,
     -13,   -13,    -5,    -5,   -28,   -28,    59,   -28,   -28,    51,
     207,   207,   207,   -28,   131,   -28,   -28,    24,    31,    55,
     -28,    71,   -28,   -28,    56,    58,   207,   207,    48,    62,
     -28,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    26,
      24,    25,    20,    21,    22,    23,     0,     4,     5,     0,
       0,     0,     0,    19,     0,     6,    13,     0,     0,     0,
       7,     8,    14,    10,     0,     0,     0,     0,     0,     0,
      11,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    -1,   -27,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    66,    67,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       9,    10,    23,    24,    25,    27,    28,    35,    36,    37,
      38,    11,    31,    12,    26,    29,    42,    37,    38,    13,
      46,    47,    14,    49,    50,    51,    52,    53,    54,    55,
       3,     4,     5,     6,    68,     7,     8,     3,     4,     5,
       6,    15,     7,     8,    16,    30,    43,    64,    56,    78,
      79,    71,    59,    57,     3,     4,     5,     6,    73,     7,
       8,    69,    17,    18,    19,    20,    72,    72,     3,     4,
       5,     6,    60,     7,     8,    80,    61,    72,    72,    65,
      74,    75,    76,    21,    77,     0,    32,     0,     0,    81,
      33,    34,     0,    35,    36,    37,    38,    32,     0,     0,
       0,    33,    34,    40,    35,    36,    37,    38,    32,     0,
       0,     0,    33,    34,    63,    35,    36,    37,    38,     0,
      32,     0,     0,    39,    33,    34,     0,    35,    36,    37,
      38,     0,    32,     0,     0,    58,    33,    34,     0,    35,
      36,    37,    38,     0,    32,     0,     0,    62,    33,    34,
       0,    35,    36,    37,    38,     0,    32,     0,     0,    70,
      33,    34,     0,    35,    36,    37,    38,    32,    41,     0,
       0,    33,    34,     0,    35,    36,    37,    38,    32,    44,
       0,     0,    33,    34,     0,    35,    36,    37,    38,    32,
      45,     0,     0,    33,    34,     0,    35,    36,    37,    38,
       2,    48,     0,     0,     0,     0,     3,     4,     5,     6,
       0,     7,     8,     3,     4,     5,     6,     0,     7,     8
};

static const yytype_int8 yycheck[] =
{
       1,    19,    11,    12,    19,    14,    15,    20,    21,    22,
      23,    29,    21,    24,    29,    16,    25,    22,    23,     6,
      29,    30,    24,    32,    33,    34,    35,    36,    37,    38,
       6,     7,     8,     9,    61,    11,    12,     6,     7,     8,
       9,    24,    11,    12,    24,    29,     3,    56,    19,    76,
      77,    27,    30,    28,     6,     7,     8,     9,    27,    11,
      12,    62,     3,     4,     5,     6,    67,    68,     6,     7,
       8,     9,    26,    11,    12,    27,    26,    78,    79,    28,
      25,    10,    26,    24,    26,    -1,    13,    -1,    -1,    27,
      17,    18,    -1,    20,    21,    22,    23,    13,    -1,    -1,
      -1,    17,    18,    30,    20,    21,    22,    23,    13,    -1,
      -1,    -1,    17,    18,    30,    20,    21,    22,    23,    -1,
      13,    -1,    -1,    28,    17,    18,    -1,    20,    21,    22,
      23,    -1,    13,    -1,    -1,    28,    17,    18,    -1,    20,
      21,    22,    23,    -1,    13,    -1,    -1,    28,    17,    18,
      -1,    20,    21,    22,    23,    -1,    13,    -1,    -1,    28,
      17,    18,    -1,    20,    21,    22,    23,    13,    25,    -1,
      -1,    17,    18,    -1,    20,    21,    22,    23,    13,    25,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    23,    13,
      25,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
       0,    25,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      -1,    11,    12,     6,     7,     8,     9,    -1,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,     0,     6,     7,     8,     9,    11,    12,    33,
      19,    29,    24,     6,    24,    24,    24,     3,     4,     5,
       6,    24,    35,    35,    35,    19,    29,    35,    35,    33,
      29,    35,    13,    17,    18,    20,    21,    22,    23,    28,
      30,    25,    35,     3,    25,    25,    35,    35,    25,    35,
      35,    35,    35,    35,    35,    35,    19,    28,    28,    30,
      26,    26,    28,    30,    35,    28,    33,    34,    34,    33,
      28,    27,    33,    27,    25,    10,    26,    26,    34,    34,
      27,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     5,     5,     6,     7,     7,    11,
       7,    10,     4,     1,     2,     1,     1,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program: program statement  */
#line 238 "stylaxx.y"
                        { run((yyvsp[0].nodePtr)); }
#line 1343 "stylaxx.tab.c"
    break;

  case 4: /* statement: DEKHAO LPAREN expression RPAREN SEMICOLON  */
#line 242 "stylaxx.y"
                                              { (yyval.nodePtr) = makePrint((yyvsp[-2].nodePtr)); }
#line 1349 "stylaxx.tab.c"
    break;

  case 5: /* statement: DHORI VARIABLE ASSIGN expression SEMICOLON  */
#line 243 "stylaxx.y"
                                                 { (yyval.nodePtr) = makeAssign((yyvsp[-3].strVal), (yyvsp[-1].nodePtr)); }
#line 1355 "stylaxx.tab.c"
    break;

  case 6: /* statement: DHORI VARIABLE LBRACKET INT_NUM RBRACKET SEMICOLON  */
#line 246 "stylaxx.y"
                                                         { (yyval.nodePtr) = makeArrayDecl((yyvsp[-4].strVal), (yyvsp[-2].intVal)); }
#line 1361 "stylaxx.tab.c"
    break;

  case 7: /* statement: VARIABLE LBRACKET expression RBRACKET ASSIGN expression SEMICOLON  */
#line 247 "stylaxx.y"
                                                                        { (yyval.nodePtr) = makeArrayAss((yyvsp[-6].strVal), (yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr)); }
#line 1367 "stylaxx.tab.c"
    break;

  case 8: /* statement: IF LPAREN expression RPAREN LBRACE statement_list RBRACE  */
#line 250 "stylaxx.y"
                                                               { (yyval.nodePtr) = makeIf((yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr), NULL); }
#line 1373 "stylaxx.tab.c"
    break;

  case 9: /* statement: IF LPAREN expression RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE  */
#line 251 "stylaxx.y"
                                                                                                 { (yyval.nodePtr) = makeIf((yyvsp[-8].nodePtr), (yyvsp[-5].nodePtr), (yyvsp[-1].nodePtr)); }
#line 1379 "stylaxx.tab.c"
    break;

  case 10: /* statement: WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE  */
#line 252 "stylaxx.y"
                                                                  { (yyval.nodePtr) = makeWhile((yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr)); }
#line 1385 "stylaxx.tab.c"
    break;

  case 11: /* statement: FOR LPAREN statement expression SEMICOLON statement RPAREN LBRACE statement_list RBRACE  */
#line 256 "stylaxx.y"
                                                                                              { 
        (yyval.nodePtr) = makeFor((yyvsp[-7].nodePtr), (yyvsp[-6].nodePtr), (yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr)); 
    }
#line 1393 "stylaxx.tab.c"
    break;

  case 12: /* statement: VARIABLE ASSIGN expression SEMICOLON  */
#line 261 "stylaxx.y"
                                           { (yyval.nodePtr) = makeAssign((yyvsp[-3].strVal), (yyvsp[-1].nodePtr)); }
#line 1399 "stylaxx.tab.c"
    break;

  case 13: /* statement_list: statement  */
#line 265 "stylaxx.y"
              { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1405 "stylaxx.tab.c"
    break;

  case 14: /* statement_list: statement_list statement  */
#line 266 "stylaxx.y"
                               { (yyval.nodePtr) = makeSeq((yyvsp[-1].nodePtr), (yyvsp[0].nodePtr)); }
#line 1411 "stylaxx.tab.c"
    break;

  case 15: /* expression: INT_NUM  */
#line 270 "stylaxx.y"
                            { (yyval.nodePtr) = makeNum((yyvsp[0].intVal)); }
#line 1417 "stylaxx.tab.c"
    break;

  case 16: /* expression: FLOAT_NUM  */
#line 271 "stylaxx.y"
                            { (yyval.nodePtr) = makeFloat((yyvsp[0].floatVal)); }
#line 1423 "stylaxx.tab.c"
    break;

  case 17: /* expression: STRING_LIT  */
#line 272 "stylaxx.y"
                            { (yyval.nodePtr) = makeStr((yyvsp[0].strVal)); }
#line 1429 "stylaxx.tab.c"
    break;

  case 18: /* expression: VARIABLE  */
#line 273 "stylaxx.y"
                            { (yyval.nodePtr) = makeVar((yyvsp[0].strVal)); }
#line 1435 "stylaxx.tab.c"
    break;

  case 19: /* expression: VARIABLE LBRACKET expression RBRACKET  */
#line 274 "stylaxx.y"
                                            { (yyval.nodePtr) = makeArrayAcc((yyvsp[-3].strVal), (yyvsp[-1].nodePtr)); }
#line 1441 "stylaxx.tab.c"
    break;

  case 20: /* expression: expression PLUS expression  */
#line 276 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), '+'); }
#line 1447 "stylaxx.tab.c"
    break;

  case 21: /* expression: expression MINUS expression  */
#line 277 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), '-'); }
#line 1453 "stylaxx.tab.c"
    break;

  case 22: /* expression: expression MUL expression  */
#line 278 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), '*'); }
#line 1459 "stylaxx.tab.c"
    break;

  case 23: /* expression: expression DIV expression  */
#line 279 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), '/'); }
#line 1465 "stylaxx.tab.c"
    break;

  case 24: /* expression: expression GT expression  */
#line 281 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), 'g'); }
#line 1471 "stylaxx.tab.c"
    break;

  case 25: /* expression: expression LT expression  */
#line 282 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), 'l'); }
#line 1477 "stylaxx.tab.c"
    break;

  case 26: /* expression: expression EQ expression  */
#line 283 "stylaxx.y"
                                  { (yyval.nodePtr) = makeOp((yyvsp[-2].nodePtr), (yyvsp[0].nodePtr), 'e'); }
#line 1483 "stylaxx.tab.c"
    break;

  case 27: /* expression: LPAREN expression RPAREN  */
#line 285 "stylaxx.y"
                                  { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1489 "stylaxx.tab.c"
    break;


#line 1493 "stylaxx.tab.c"

      default: break;
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 288 "stylaxx.y"


int main(int argc, char *argv[]) {
    if (argc < 2) { printf("Usage: %s <file>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
void yyerror(const char *s) { fprintf(stderr, "Error: %s near '%s'\n", s, yytext); }
