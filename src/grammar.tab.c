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
#line 54 "src/grammar.y"

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstring> // Required for strdup
#include <classes_NT.h>
#include <tac.h>
#include "symtab_print.h"
void yyerror(const char *s);

using namespace std;


// Existing symbol table and other declarations
extern unordered_map<string, string> symtab;
extern vector<string> program;
extern vector<pair<string, int>> error;
extern int line_num;
extern bool iserror;
extern int yylex();
Node* root;



#line 101 "src/grammar.tab.c"

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

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_CONST_FLOAT = 6,                /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 7,                 /* CONST_CHAR  */
  YYSYMBOL_CONST_EXP = 8,                  /* CONST_EXP  */
  YYSYMBOL_SIZEOF = 9,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 10,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 11,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 12,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 13,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 14,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 15,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 16,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 17,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 18,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 19,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 20,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 21,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 22,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 23,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 26,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 27,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 28,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 29,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 30,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 31,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_CHAR = 37,                      /* CHAR  */
  YYSYMBOL_SHORT = 38,                     /* SHORT  */
  YYSYMBOL_INT = 39,                       /* INT  */
  YYSYMBOL_LONG = 40,                      /* LONG  */
  YYSYMBOL_SIGNED = 41,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 42,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 43,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 44,                    /* DOUBLE  */
  YYSYMBOL_CONST = 45,                     /* CONST  */
  YYSYMBOL_VOLATILE = 46,                  /* VOLATILE  */
  YYSYMBOL_VOID = 47,                      /* VOID  */
  YYSYMBOL_STRUCT = 48,                    /* STRUCT  */
  YYSYMBOL_UNION = 49,                     /* UNION  */
  YYSYMBOL_ENUM = 50,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 51,                  /* ELLIPSIS  */
  YYSYMBOL_NULL_TOKEN = 52,                /* NULL_TOKEN  */
  YYSYMBOL_MEMBER = 53,                    /* MEMBER  */
  YYSYMBOL_CASE = 54,                      /* CASE  */
  YYSYMBOL_DEFAULT = 55,                   /* DEFAULT  */
  YYSYMBOL_IF = 56,                        /* IF  */
  YYSYMBOL_ELSE = 57,                      /* ELSE  */
  YYSYMBOL_SWITCH = 58,                    /* SWITCH  */
  YYSYMBOL_WHILE = 59,                     /* WHILE  */
  YYSYMBOL_DO = 60,                        /* DO  */
  YYSYMBOL_FOR = 61,                       /* FOR  */
  YYSYMBOL_GOTO = 62,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 63,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 64,                     /* BREAK  */
  YYSYMBOL_RETURN = 65,                    /* RETURN  */
  YYSYMBOL_CLASS = 66,                     /* CLASS  */
  YYSYMBOL_DELETE = 67,                    /* DELETE  */
  YYSYMBOL_NEW = 68,                       /* NEW  */
  YYSYMBOL_PRIVATE = 69,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 70,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 71,                 /* PROTECTED  */
  YYSYMBOL_THIS = 72,                      /* THIS  */
  YYSYMBOL_UNTIL = 73,                     /* UNTIL  */
  YYSYMBOL_BOOL = 74,                      /* BOOL  */
  YYSYMBOL_TRUE = 75,                      /* TRUE  */
  YYSYMBOL_FALSE = 76,                     /* FALSE  */
  YYSYMBOL_77_ = 77,                       /* '('  */
  YYSYMBOL_78_ = 78,                       /* ')'  */
  YYSYMBOL_79_ = 79,                       /* '['  */
  YYSYMBOL_80_ = 80,                       /* ']'  */
  YYSYMBOL_81_ = 81,                       /* '.'  */
  YYSYMBOL_82_ = 82,                       /* ','  */
  YYSYMBOL_83_ = 83,                       /* '&'  */
  YYSYMBOL_84_ = 84,                       /* '*'  */
  YYSYMBOL_85_ = 85,                       /* '+'  */
  YYSYMBOL_86_ = 86,                       /* '-'  */
  YYSYMBOL_87_ = 87,                       /* '~'  */
  YYSYMBOL_88_ = 88,                       /* '!'  */
  YYSYMBOL_89_ = 89,                       /* '/'  */
  YYSYMBOL_90_ = 90,                       /* '%'  */
  YYSYMBOL_91_ = 91,                       /* '<'  */
  YYSYMBOL_92_ = 92,                       /* '>'  */
  YYSYMBOL_93_ = 93,                       /* '^'  */
  YYSYMBOL_94_ = 94,                       /* '|'  */
  YYSYMBOL_95_ = 95,                       /* '?'  */
  YYSYMBOL_96_ = 96,                       /* ':'  */
  YYSYMBOL_97_ = 97,                       /* '='  */
  YYSYMBOL_98_ = 98,                       /* ';'  */
  YYSYMBOL_99_ = 99,                       /* '{'  */
  YYSYMBOL_100_ = 100,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 101,                 /* $accept  */
  YYSYMBOL_primary_expression = 102,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 103,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 104, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 105,         /* unary_expression  */
  YYSYMBOL_unary_operator = 106,           /* unary_operator  */
  YYSYMBOL_cast_expression = 107,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 108, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 109,      /* additive_expression  */
  YYSYMBOL_shift_expression = 110,         /* shift_expression  */
  YYSYMBOL_relational_expression = 111,    /* relational_expression  */
  YYSYMBOL_equality_expression = 112,      /* equality_expression  */
  YYSYMBOL_and_expression = 113,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 114,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 115,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 116,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 117,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 118,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 119,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 120,      /* assignment_operator  */
  YYSYMBOL_expression = 121,               /* expression  */
  YYSYMBOL_constant_expression = 122,      /* constant_expression  */
  YYSYMBOL_declaration = 123,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 124,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 125,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 126,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 127,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 128,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 129, /* struct_or_union_specifier  */
  YYSYMBOL_struct_id = 130,                /* struct_id  */
  YYSYMBOL_union_id = 131,                 /* union_id  */
  YYSYMBOL_struct = 132,                   /* struct  */
  YYSYMBOL_union = 133,                    /* union  */
  YYSYMBOL_struct_declaration_list = 134,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 135,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 136, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 137,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 138,        /* struct_declarator  */
  YYSYMBOL_class_name = 139,               /* class_name  */
  YYSYMBOL_enum_specifier = 140,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 141,          /* enumerator_list  */
  YYSYMBOL_enumerator = 142,               /* enumerator  */
  YYSYMBOL_type_qualifier = 143,           /* type_qualifier  */
  YYSYMBOL_declarator = 144,               /* declarator  */
  YYSYMBOL_direct_declarator = 145,        /* direct_declarator  */
  YYSYMBOL_pointer = 146,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 147,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 148,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 149,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 150,    /* parameter_declaration  */
  YYSYMBOL_type_name = 151,                /* type_name  */
  YYSYMBOL_abstract_declarator = 152,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 153, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 154,              /* initializer  */
  YYSYMBOL_initializer_list = 155,         /* initializer_list  */
  YYSYMBOL_statement = 156,                /* statement  */
  YYSYMBOL_delete_statement = 157,         /* delete_statement  */
  YYSYMBOL_labeled_statement = 158,        /* labeled_statement  */
  YYSYMBOL_colon = 159,                    /* colon  */
  YYSYMBOL_compound_statement = 160,       /* compound_statement  */
  YYSYMBOL_declaration_list = 161,         /* declaration_list  */
  YYSYMBOL_statement_list = 162,           /* statement_list  */
  YYSYMBOL_expression_statement = 163,     /* expression_statement  */
  YYSYMBOL_smc = 164,                      /* smc  */
  YYSYMBOL_selection_statement = 165,      /* selection_statement  */
  YYSYMBOL_emp = 166,                      /* emp  */
  YYSYMBOL_m = 167,                        /* m  */
  YYSYMBOL_iteration_statement = 168,      /* iteration_statement  */
  YYSYMBOL_fcrb = 169,                     /* fcrb  */
  YYSYMBOL_doo = 170,                      /* doo  */
  YYSYMBOL_crb = 171,                      /* crb  */
  YYSYMBOL_els = 172,                      /* els  */
  YYSYMBOL_srb = 173,                      /* srb  */
  YYSYMBOL_jump_statement = 174,           /* jump_statement  */
  YYSYMBOL_translation_unit = 175,         /* translation_unit  */
  YYSYMBOL_external_declaration = 176,     /* external_declaration  */
  YYSYMBOL_function_declaration = 177,     /* function_declaration  */
  YYSYMBOL_function_definition = 178       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
       2,     2,     2,    88,     2,     2,     2,    90,    83,     2,
      77,    78,    84,    85,    82,    86,    81,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,    98,
      91,    97,    92,    95,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,    94,   100,    87,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   199,   199,   202,   203,   204,   205,   206,   207,   208,
     211,   212,   214,   218,   226,   234,   240,   241,   245,   247,
     253,   254,   256,   259,   262,   265,   271,   272,   273,   274,
     275,   276,   280,   281,   285,   286,   290,   293,   299,   300,
     303,   309,   310,   313,   320,   321,   324,   327,   330,   336,
     337,   340,   346,   347,   353,   354,   360,   361,   367,   371,
     380,   381,   387,   388,   392,   393,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   448,   449,   453,
     459,   460,   469,   472,   473,   474,   475,   476,   480,   487,
     491,   492,   500,   501,   502,   503,   504,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   519,   524,   531,
     532,   534,   538,   541,   544,   547,   551,   553,   557,   561,
     562,   563,   564,   568,   569,   573,   610,   644,   645,   649,
     650,   654,   655,   659,   660,   665,   666,   670,   671,   672,
     673,   674,   676,   680,   681,   682,   683,   687,   688,   693,
     694,   698,   699,   703,   714,   715,   719,   720,   721,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   737,   738,
     739,   740,   741,   745,   746,   750,   751,   752,   753,   754,
     755,   756,   760,   761,   765,   770,   776,   780,   790,   791,
     792,   795,   801,   805,   809,   810,   814,   815,   818,   820,
     825,   831,   839,   847,   851,   862,   872,   880,   890,   904,
     907,   910,   913,   916,   921,   929,   932,   935,   936,   939,
     940,   944,   945,   948,   982
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "CONST_FLOAT", "CONST_CHAR", "CONST_EXP",
  "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF",
  "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "NULL_TOKEN", "MEMBER", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "CLASS", "DELETE", "NEW", "PRIVATE",
  "PUBLIC", "PROTECTED", "THIS", "UNTIL", "BOOL", "TRUE", "FALSE", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_id", "union_id",
  "struct", "union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "class_name", "enum_specifier", "enumerator_list",
  "enumerator", "type_qualifier", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "delete_statement", "labeled_statement",
  "colon", "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "smc", "selection_statement", "emp", "m",
  "iteration_statement", "fcrb", "doo", "crb", "els", "srb",
  "jump_statement", "translation_unit", "external_declaration",
  "function_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-232)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-224)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1218,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,    32,  -232,
      17,  1218,  1218,  -232,    46,    59,  -232,  1218,   461,  -232,
     -22,  -232,    -8,  -232,    18,   -21,  -232,   -56,  -232,    65,
      27,    26,  -232,  -232,    28,    39,    64,    80,  -232,  -232,
    -232,   271,  -232,   154,   113,  -232,  -232,   -21,    18,  -232,
     795,  1135,   824,    27,   541,   541,    87,  -232,  -232,  -232,
    -232,  -232,   975,  1013,  1013,  -232,  1063,    98,   121,   131,
     132,  -232,   133,   208,   117,   118,   698,     6,   132,   812,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,    33,
     263,  1063,  -232,   -23,   -15,    83,     7,   158,   130,   124,
     126,   199,    -2,  -232,  -232,   139,  -232,    17,  -232,  -232,
    -232,  -232,   369,   467,  -232,  -232,  -232,   675,  -232,   125,
     -50,  -232,  -232,  -232,  -232,  -232,   127,  -232,   220,   795,
    -232,  -232,  -232,    18,   147,   148,  -232,  -232,  -232,  -232,
     149,   541,   345,  -232,    18,   541,   443,  -232,   812,  -232,
    1063,  -232,  -232,   135,   675,  1063,  1063,  -232,  1063,  1063,
     134,  -232,  -232,  -232,   136,  -232,   153,  1063,    -6,   -31,
     159,   233,  -232,  -232,   862,  1063,   235,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  1063,  -232,
    1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,  1063,  -232,  -232,  1063,  1063,
    -232,  -232,   565,  -232,  -232,   180,  1063,   154,  -232,  -232,
     163,  -232,   -49,  -232,  -232,  1199,  -232,  -232,  -232,  -232,
     -46,  -232,  -232,  -232,  -232,   675,   165,  -232,   675,  -232,
       0,     0,     0,   -44,  -232,  -232,   242,     0,  -232,  1083,
     912,    58,  -232,   105,  1063,  -232,  -232,    38,  -232,   115,
    -232,  -232,  -232,  -232,  -232,   -23,   -23,   -15,   -15,    83,
      83,    83,    83,     7,     7,   158,   130,   124,  1063,  1063,
     -55,  -232,  -232,   132,  -232,  -232,   924,   589,  -232,  -232,
    -232,    18,  -232,  -232,  -232,  -232,  -232,   675,  -232,   675,
    -232,  1063,  -232,   675,  -232,   168,   170,  -232,   169,   105,
    1153,   951,  -232,  -232,  1063,  -232,   126,   199,  1063,  1063,
    -232,    47,  -232,  -232,  -232,   194,   675,  -232,   -44,  -232,
    -232,  -232,  -232,  -232,   174,  -232,   173,  -232,  -232,    48,
    -232,  -232,   675,  -232,   963,  -232,  -232,   156,  -232,   675,
      54,  -232,  -232,  -232,   675,  -232
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      92,    93,    94,    95,    96,    98,    99,   100,   101,   104,
     105,   102,   103,   133,   134,    97,   114,   115,     0,   222,
       0,    82,    84,   106,     0,     0,   107,    86,    92,   219,
       0,   221,   128,   137,     0,   143,    80,     0,    88,    90,
     136,     0,    83,    85,   109,     0,   111,     0,    87,     1,
     220,     0,   224,     0,     0,   147,   145,   144,     0,    81,
       0,    92,     0,   135,     0,     0,     2,     3,     4,     6,
       5,     7,     0,     0,     0,     9,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,   196,   188,    10,    20,
      32,     0,    34,    38,    41,    44,    49,    52,    54,    56,
      58,    60,    62,    64,    77,   197,   192,     0,   194,   181,
     175,   176,     0,     0,   177,   178,   179,     0,   180,   131,
       0,   129,   138,   148,   146,    89,    90,     2,     0,     0,
     168,    91,   142,     0,     0,   149,   151,   140,    32,    79,
       0,   120,     0,   116,     0,   122,     0,   203,     0,    24,
       0,    21,    22,     0,     0,     0,     0,   213,     0,     0,
       0,   215,   216,   217,     0,   182,     0,     0,     0,   154,
       0,     0,    16,    17,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    66,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   203,     0,     0,
     190,   193,     0,   189,   195,     0,     0,     0,   127,   126,
       0,   173,     0,   153,   141,    92,   139,   119,   108,   117,
       0,   123,   125,   121,   110,     0,     0,   187,     0,   186,
       0,     0,     0,     0,   214,   218,     0,     0,     8,    92,
       0,   156,   155,   157,     0,    15,    12,     0,    18,     0,
      14,    65,    35,    36,    37,    39,    40,    42,    43,    47,
      48,    45,    46,    50,    51,    53,    55,    57,     0,     0,
       0,    78,   191,     0,   132,   130,     0,     0,   169,   150,
     152,     0,   118,   184,    25,   185,   211,     0,   202,     0,
     198,     0,   183,     0,   164,     0,     0,   160,     0,   158,
      92,     0,    33,    13,     0,    11,    59,    61,     0,     0,
     172,     0,   170,   174,   124,   199,     0,   204,     0,   205,
     165,   159,   161,   166,     0,   162,     0,    19,    63,     0,
     171,   212,     0,   201,     0,   167,   163,     0,   200,     0,
       0,   206,   207,   209,     0,   208
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,  -232,   -41,   -61,  -232,   -93,   -17,    -4,   -40,
      -7,    43,    44,    42,   -29,   -27,  -232,   -60,   -26,  -232,
     -85,   -71,   -32,    37,  -232,   205,  -232,   -34,  -232,  -232,
    -232,  -232,  -232,   200,     4,    30,  -232,   -37,  -232,  -232,
    -232,    45,    22,   -20,   225,   -18,  -232,  -231,  -232,    60,
     138,    14,    36,   -83,  -232,  -117,  -232,  -232,  -232,   264,
    -232,   177,  -232,   -38,  -232,  -232,   -10,  -232,  -232,  -232,
    -183,  -232,   -81,  -232,  -232,   273,  -232,  -232
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    98,    99,   267,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   198,
     115,   150,    19,   143,    37,    38,    21,    22,    23,    45,
      47,    24,    25,   152,   153,   154,   240,   241,   230,    26,
     130,   131,    27,   136,    40,    41,    57,   144,   145,   146,
     180,   262,   263,   141,   232,   118,   119,   120,   248,   121,
     122,   123,   124,   311,   125,   336,   245,   126,   364,   127,
     307,   352,   168,   128,    28,    29,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   148,   149,   174,   178,   163,   224,   177,   199,   175,
     225,   159,   161,   162,    54,   148,   149,    56,   217,   116,
      33,    33,   207,   208,    13,    14,    58,   219,   315,    33,
     151,   151,   227,   297,   140,    32,   301,    20,   219,   134,
     148,   328,    59,   181,   182,   183,   259,   249,   260,    44,
     228,   298,   302,    35,   310,   151,   231,    55,    42,    43,
     140,   200,    46,    35,    48,    20,   201,   202,   308,   309,
     203,   204,   258,   178,   313,   178,   219,    51,   306,   133,
     250,   251,   219,   252,   253,   176,   155,   155,   117,   344,
     221,    53,   257,   218,    34,    34,   205,   206,   209,   210,
     269,    35,    35,    34,    61,   224,    62,   272,   273,   274,
     184,   155,   185,   140,   186,    36,   323,   151,   151,   179,
     324,   151,   151,   233,   151,   350,   357,  -112,   303,   324,
     219,   305,   363,   290,   242,   259,   219,   260,    64,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   294,   239,   129,   268,   117,
     239,   261,    60,  -113,  -223,   148,   149,   279,   280,   281,
     282,   322,   271,   155,   155,   211,   212,   155,   155,    65,
     155,   237,   320,   157,   321,   243,   275,   276,   179,   318,
     335,   132,   337,   291,   164,   325,   339,   219,   165,   148,
     149,   277,   278,   148,   283,   284,   288,   289,   166,   167,
     169,   170,   329,   213,   333,   171,   172,   214,   216,   353,
     215,   219,   226,   229,    60,   234,   338,   148,   148,   236,
     235,   247,   254,   256,   255,   358,   265,   264,   270,   293,
     296,   261,   362,   304,   349,   312,   340,   365,   341,   342,
     346,   351,   355,   356,   361,   331,   285,   287,   286,   326,
     148,   149,   327,   135,   334,   156,    63,   148,   348,   360,
     268,   140,   295,   316,    66,    67,    68,    69,    70,    71,
      72,   242,    73,    74,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    52,   300,   246,   319,   347,   222,
     354,    50,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,    75,     0,    76,    77,    78,     0,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    87,     0,
       0,     0,     0,     0,    88,     0,     0,     0,    89,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
     197,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      51,    97,    66,    67,    68,    69,    70,    71,    72,     0,
      73,    74,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,    75,     0,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,     0,    87,     0,     0,     0,
       0,     0,    88,     0,     0,   238,    89,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    49,     0,     0,     0,     0,     0,    96,    51,   220,
      66,    67,    68,    69,    70,    71,    72,     0,    73,    74,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    76,    77,    78,     0,    79,    80,    81,    82,    83,
      84,    85,    86,     0,    87,     0,     0,     0,     0,     0,
      88,     0,     0,   244,    89,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    51,   223,    66,    67,
      68,    69,    70,    71,    72,     0,    73,    74,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   137,    67,    68,    69,    70,    71,    72,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,    76,
      77,    78,     0,    79,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,     0,     0,     0,     0,    88,     0,
       0,    75,    89,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,   138,     0,     0,
       0,     0,     0,    96,    51,   292,    89,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    66,    67,
      68,    69,    70,    71,    72,     0,    73,    74,   139,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,    67,    68,    69,    70,    71,    72,     0,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,    76,
      77,    78,     0,    79,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,     0,     0,     0,     0,    88,     0,
      75,     0,    89,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,     0,   138,     0,     0,     0,
       0,     0,     0,    96,    51,    89,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   139,   137,    67,
      68,    69,    70,    71,    72,     0,    73,    74,     0,     0,
       0,     0,     0,     0,     0,   137,    67,    68,    69,    70,
      71,    72,     0,    73,    74,     0,     0,   137,    67,    68,
      69,    70,    71,    72,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   138,    75,   137,    67,    68,    69,    70,
      71,    72,    89,    73,    74,     0,    75,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,   139,    90,    91,    92,    93,    94,
      95,    89,     0,     0,   147,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    75,   137,    67,    68,    69,    70,
      71,    72,     0,    73,    74,     0,     0,   137,    67,    68,
      69,    70,    71,    72,     0,    73,    74,     0,     0,    89,
     266,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,     0,     0,   137,    67,    68,    69,    70,    71,
      72,     0,    73,    74,    75,     0,   137,    67,    68,    69,
      70,    71,    72,     0,    73,    74,    75,     0,   137,    67,
      68,    69,    70,    71,    72,     0,    73,    74,     0,    89,
       0,     0,   317,     0,     0,    90,    91,    92,    93,    94,
      95,    89,   330,    75,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     0,     0,    75,   137,    67,    68,    69,
      70,    71,    72,     0,    73,    74,     0,    75,    89,     0,
       0,   345,     0,     0,    90,    91,    92,    93,    94,    95,
      89,   359,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,   158,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    75,   137,    67,    68,    69,
      70,    71,    72,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   314,   260,     0,     0,     0,     0,    35,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   343,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     299,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
      20,    62,    62,    86,    89,    76,   123,    88,   101,     3,
     127,    72,    73,    74,    34,    76,    76,    35,    20,    51,
       3,     3,    15,    16,    45,    46,    82,    82,   259,     3,
      64,    65,    82,    82,    60,     3,    82,     0,    82,    57,
     101,    96,    98,    10,    11,    12,    77,   164,    79,     3,
     100,   100,    98,    84,    98,    89,   139,    35,    21,    22,
      86,    84,     3,    84,    27,    28,    89,    90,   251,   252,
      85,    86,    78,   158,   257,   160,    82,    99,    78,    57,
     165,   166,    82,   168,   169,    79,    64,    65,    51,   320,
     122,    99,   177,    95,    77,    77,    13,    14,    91,    92,
     185,    84,    84,    77,    77,   222,    79,   200,   201,   202,
      77,    89,    79,   139,    81,    98,    78,   151,   152,    89,
      82,   155,   156,   143,   158,    78,    78,    99,   245,    82,
      82,   248,    78,   218,   154,    77,    82,    79,    99,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   226,   152,     3,   184,   122,
     156,   179,    97,    99,    99,   226,   226,   207,   208,   209,
     210,   264,   198,   151,   152,    17,    18,   155,   156,    99,
     158,   151,    77,    96,    79,   155,   203,   204,   158,   260,
     307,    78,   309,   219,    96,    80,   313,    82,    77,   260,
     260,   205,   206,   264,   211,   212,   216,   217,    77,    77,
      77,     3,   293,    83,   297,    98,    98,    93,    19,   336,
      94,    82,    97,     3,    97,    78,   311,   288,   289,    80,
      82,    96,    98,    80,    98,   352,     3,    78,     3,    59,
      77,   259,   359,    78,   329,     3,    78,   364,    78,    80,
     321,    57,    78,    80,    98,   296,   213,   215,   214,   288,
     321,   321,   289,    58,   301,    65,    41,   328,   328,   354,
     296,   297,   227,   259,     3,     4,     5,     6,     7,     8,
       9,   301,    11,    12,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    30,   235,   158,   261,   324,   122,
     338,    28,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,    88,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    -1,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,   100,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,   100,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    52,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      52,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    68,    52,     3,     4,     5,     6,     7,
       8,     9,    77,    11,    12,    -1,    52,    -1,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    99,    83,    84,    85,    86,    87,
      88,    77,    -1,    -1,    80,    -1,    -1,    83,    84,    85,
      86,    87,    88,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    52,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    52,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    77,
      -1,    -1,    80,    -1,    -1,    83,    84,    85,    86,    87,
      88,    77,    78,    52,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    -1,    -1,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    52,    77,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    -1,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    84,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   123,
     124,   127,   128,   129,   132,   133,   140,   143,   175,   176,
     177,   178,     3,     3,    77,    84,    98,   125,   126,   144,
     145,   146,   124,   124,     3,   130,     3,   131,   124,     0,
     176,    99,   160,    99,   144,   143,   146,   147,    82,    98,
      97,    77,    79,   145,    99,    99,     3,     4,     5,     6,
       7,     8,     9,    11,    12,    52,    54,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    67,    73,    77,
      83,    84,    85,    86,    87,    88,    98,   100,   102,   103,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,   123,   124,   156,   157,
     158,   160,   161,   162,   163,   165,   168,   170,   174,     3,
     141,   142,    78,   143,   146,   126,   144,     3,    68,    99,
     119,   154,    78,   124,   148,   149,   150,    80,   105,   118,
     122,   128,   134,   135,   136,   143,   134,    96,    77,   105,
      77,   105,   105,   122,    96,    77,    77,    77,   173,    77,
       3,    98,    98,    98,   154,     3,    79,   173,   121,   136,
     151,    10,    11,    12,    77,    79,    81,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    97,   120,   107,
      84,    89,    90,    85,    86,    13,    14,    15,    16,    91,
      92,    17,    18,    83,    93,    94,    19,    20,    95,    82,
     100,   123,   162,   100,   156,   156,    97,    82,   100,     3,
     139,   154,   155,   144,    78,    82,    80,   136,   100,   135,
     137,   138,   144,   136,   100,   167,   151,    96,   159,   156,
     121,   121,   121,   121,    98,    98,    80,   121,    78,    77,
      79,   146,   152,   153,    78,     3,    78,   104,   119,   121,
       3,   119,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   113,   114,   167,   167,
     121,   119,   100,    59,   122,   142,    77,    82,   100,    51,
     150,    82,    98,   156,    78,   156,    78,   171,   171,   171,
      98,   164,     3,   171,    78,   148,   152,    80,   122,   153,
      77,    79,   107,    78,    82,    80,   115,   116,    96,   173,
      78,   104,   100,   154,   138,   156,   166,   156,   121,   156,
      78,    78,    80,    78,   148,    80,   122,   119,   118,   121,
      78,    57,   172,   156,   164,    78,    80,    78,   156,    78,
     121,    98,   156,    78,   169,   156
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   130,   131,   132,   133,   134,   134,   135,   136,
     136,   136,   136,   137,   137,   138,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   146,   146,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   154,
     154,   154,   154,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   157,   157,   158,   158,   158,   159,   160,   160,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   165,
     165,   165,   166,   167,   168,   168,   168,   168,   168,   169,
     170,   171,   172,   173,   174,   174,   174,   174,   174,   175,
     175,   176,   176,   177,   178
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     3,     4,     3,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     4,
       1,     4,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       5,     2,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     2,     1,     1,     3,     1,     1,     5,     2,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     3,     4,
       3,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     5,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     3,     1,     2,     3,
       3,     4,     1,     2,     1,     2,     1,     1,     1,     5,
       7,     6,     0,     0,     5,     5,     7,     8,     9,     1,
       1,     1,     1,     1,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     2,     2
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 199 "src/grammar.y"
                     {Type* t=get_type_id((yyvsp[0].str));
	cout << t->base << endl;cout << "get type id in primary exp done" << endl;Symbol_Info* x=get_symbol_info_id((yyvsp[0].str));
	if(x->tempname.empty()){string nn=get_new_temp();x->tempname=nn;final_symtab[nn]=x;temp_and_type[nn]=t;}t->place=x->tempname;(yyval.typ)=t;}
#line 1738 "src/grammar.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 202 "src/grammar.y"
                   {Type* t=new Type(); t->isbasic=true;t->base="INT";string nn=get_new_temp();global_code.push_back(get_code4((yyvsp[0].str),"","",nn));t->place=nn;(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1744 "src/grammar.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 203 "src/grammar.y"
                         {Type* t=new Type(); t->isbasic=true;t->base="CHAR";t->ptr_level=1;t->ptrtql.emplace_back(false,false);string nn=get_new_temp();global_code.push_back(get_code4((yyvsp[0].str),"","",nn));t->place=nn;(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1750 "src/grammar.tab.c"
    break;

  case 5: /* primary_expression: CONST_CHAR  */
#line 204 "src/grammar.y"
                     {Type* t=new Type(); t->isbasic=true;t->base="CHAR";(yyval.typ)=t;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4((yyvsp[0].str),"","",nn));(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1756 "src/grammar.tab.c"
    break;

  case 6: /* primary_expression: CONST_FLOAT  */
#line 205 "src/grammar.y"
                      {Type* t=new Type();t->isbasic=true;t->base="FLOAT";(yyval.typ)=t;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4((yyvsp[0].str),"","",nn));(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1762 "src/grammar.tab.c"
    break;

  case 7: /* primary_expression: CONST_EXP  */
#line 206 "src/grammar.y"
                    {Type* t=get_type_exp((yyvsp[0].str));string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4((yyvsp[0].str),"","",nn));(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1768 "src/grammar.tab.c"
    break;

  case 8: /* primary_expression: '(' expression ')'  */
#line 207 "src/grammar.y"
                             {(yyval.typ)=(yyvsp[-1].typ);backpatch((yyval.typ)->truelist,global_code.size());backpatch((yyval.typ)->falselist,global_code.size());(yyval.typ)->truelist=vector<int>();(yyval.typ)->falselist=vector<int>();}
#line 1774 "src/grammar.tab.c"
    break;

  case 9: /* primary_expression: NULL_TOKEN  */
#line 208 "src/grammar.y"
                     {Type* t=new Type();t->isnull=true;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4("nullptr","","",nn));(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1780 "src/grammar.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 211 "src/grammar.y"
                             {(yyval.typ)=(yyvsp[0].typ);}
#line 1786 "src/grammar.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 212 "src/grammar.y"
                                                {Type* type=check_if_array_or_pointer((yyvsp[-3].typ));(yyval.typ)=type;string nn=get_new_temp();
	backpatch((yyvsp[-1].typ)->truelist,global_code.size());backpatch((yyvsp[-1].typ)->falselist,global_code.size());global_code.push_back(get_code_array((yyvsp[-3].typ)->place,(yyvsp[-1].typ)->place,nn));(yyval.typ)->place=nn;temp_and_type[nn]=type;}
#line 1793 "src/grammar.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression '(' ')'  */
#line 214 "src/grammar.y"
                                     {Type* t=check_if_function((yyvsp[-2].typ));check_argument_with_params((yyvsp[-2].typ)->prms,vector<Type*>(),false);
		string nn=get_new_temp();
		global_code.push_back(get_code_func(nn,(yyvsp[-2].typ)->place));
		(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1802 "src/grammar.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 218 "src/grammar.y"
                                                              {Type* t=check_if_function((yyvsp[-3].typ));cout << "hello ##  vargs: " << (yyvsp[-3].typ)->isvarargs << endl; check_argument_with_params((yyvsp[-3].typ)->prms,(yyvsp[-1].arg_ex_list)->vec_exp,(yyvsp[-3].typ)->isvarargs);
		for(auto i:(yyvsp[-1].arg_ex_list)->prm_temps){
			global_code.push_back(get_param_code(i));
		}
		string nn=get_new_temp();
		global_code.push_back(get_code_func(nn,(yyvsp[-3].typ)->place));
		cout << "got argument list here" << endl;t->place=nn;
		(yyval.typ)=t;temp_and_type[nn]=t;}
#line 1815 "src/grammar.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 226 "src/grammar.y"
                                            {check_if_obj((yyvsp[-2].typ));Type* type=check_if_id_in_obj((yyvsp[-2].typ),(yyvsp[0].str));
		string nn1=get_new_temp();
		string nn2=get_new_temp();
		global_code.push_back(get_code4((yyvsp[-2].typ)->place, nn1, ".",nn2));(yyval.typ)=type;
		(yyval.typ)->place=nn2;

		;
	}
#line 1828 "src/grammar.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 234 "src/grammar.y"
                                               {check_if_obj_ptr((yyvsp[-2].typ));Type* type=check_if_id_in_obj((yyvsp[-2].typ),(yyvsp[0].str));
		string nn1=get_new_temp();
		string nn2=get_new_temp();
		global_code.push_back(get_code4((yyvsp[-2].typ)->place, nn1, "->",nn2));
		(yyval.typ)=type;
		(yyval.typ)->place=nn2;}
#line 1839 "src/grammar.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression INC_OP  */
#line 240 "src/grammar.y"
                                     {check_inc_dec_op((yyvsp[-1].typ));Type* xx=(yyvsp[-1].typ);(yyval.typ)=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4((yyvsp[-1].typ)->place,"","++",nn));global_code.push_back(get_code4("",nn,"",(yyvsp[-1].typ)->place));(yyval.typ)->place=(yyvsp[-1].typ)->place;(yyval.typ)->truelist=vector<int>();(yyval.typ)->falselist=vector<int>();temp_and_type[nn]=(yyval.typ);}
#line 1845 "src/grammar.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression DEC_OP  */
#line 241 "src/grammar.y"
                                    {check_inc_dec_op((yyvsp[-1].typ));Type* xx=(yyvsp[-1].typ);(yyval.typ)=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4((yyvsp[-1].typ)->place,"","--",nn));global_code.push_back(get_code4("",nn,"",(yyvsp[-1].typ)->place));(yyval.typ)->place=(yyvsp[-1].typ)->place;(yyval.typ)->truelist=vector<int>();(yyval.typ)->falselist=vector<int>();temp_and_type[nn]=(yyval.typ);}
#line 1851 "src/grammar.tab.c"
    break;

  case 18: /* argument_expression_list: assignment_expression  */
#line 245 "src/grammar.y"
                                {Argument_Expression_List* z=new Argument_Expression_List();z->vec_exp.push_back((yyvsp[0].typ));(yyval.arg_ex_list)=z;
	backpatch((yyvsp[0].typ)->truelist,global_code.size());(yyval.arg_ex_list)->prm_temps.push_back((yyvsp[0].typ)->place);backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 1858 "src/grammar.tab.c"
    break;

  case 19: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 247 "src/grammar.y"
                                                             {(yyvsp[-2].arg_ex_list)->vec_exp.push_back((yyvsp[0].typ));(yyval.arg_ex_list)=(yyvsp[-2].arg_ex_list);
	cout << "backpatching of second arg done" << endl;
	backpatch((yyvsp[0].typ)->truelist,global_code.size());(yyval.arg_ex_list)->prm_temps.push_back((yyvsp[0].typ)->place);backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 1866 "src/grammar.tab.c"
    break;

  case 20: /* unary_expression: postfix_expression  */
#line 253 "src/grammar.y"
                             {(yyval.typ)=(yyvsp[0].typ);}
#line 1872 "src/grammar.tab.c"
    break;

  case 21: /* unary_expression: INC_OP unary_expression  */
#line 254 "src/grammar.y"
                                                                                                {check_inc_dec_op((yyvsp[0].typ));Type* xx=(yyvsp[0].typ);(yyval.typ)=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4("",(yyvsp[0].typ)->place,"++",nn));global_code.push_back(get_code4("",nn,"",(yyvsp[0].typ)->place));(yyval.typ)->place=(yyvsp[0].typ)->place;(yyval.typ)->truelist=vector<int>();(yyval.typ)->falselist=vector<int>();
		temp_and_type[nn]=(yyval.typ);}
#line 1879 "src/grammar.tab.c"
    break;

  case 22: /* unary_expression: DEC_OP unary_expression  */
#line 256 "src/grammar.y"
                                   {check_inc_dec_op((yyvsp[0].typ));Type* xx=(yyvsp[0].typ);(yyval.typ)=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4("",(yyvsp[0].typ)->place,"--",nn));
		global_code.push_back(get_code4("",nn,"",(yyvsp[0].typ)->place));(yyval.typ)->place=(yyvsp[0].typ)->place;(yyval.typ)->truelist=vector<int>();(yyval.typ)->falselist=vector<int>();
		temp_and_type[nn]=(yyval.typ);}
#line 1887 "src/grammar.tab.c"
    break;

  case 23: /* unary_expression: unary_operator cast_expression  */
#line 259 "src/grammar.y"
                                         {Type* type=get_type_unary_expression((yyvsp[-1].str),(yyvsp[0].typ));(yyval.typ)=type;cout<<"got &"<<endl;string nn=get_new_temp();
		global_code.push_back(get_code4("",(yyvsp[0].typ)->place,(yyvsp[-1].str),nn));(yyval.typ)->place=nn;
		temp_and_type[nn]=(yyval.typ);}
#line 1895 "src/grammar.tab.c"
    break;

  case 24: /* unary_expression: SIZEOF unary_expression  */
#line 262 "src/grammar.y"
                                  {check_for_sizeof((yyvsp[0].typ)); Type* t=new Type(); t->isbasic=true; t->base="INT";(yyval.typ)=t;string nn=get_new_temp();
		global_code.push_back(get_code4("",(yyvsp[0].typ)->place,"SIZEOF",nn));(yyval.typ)->place=nn;
		temp_and_type[nn]=(yyval.typ);}
#line 1903 "src/grammar.tab.c"
    break;

  case 25: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 265 "src/grammar.y"
                                   {check_for_sizeof((yyvsp[-1].ty_nm)->type);Type* t=new Type();t->isbasic=true;t->base="INT";(yyval.typ)=t;
		string nn=get_new_temp();global_code.push_back(get_code4("",get_string_type((yyvsp[-1].ty_nm)->type),"SIZEOF ",nn));(yyval.typ)->place=nn;
		temp_and_type[nn]=(yyval.typ);}
#line 1911 "src/grammar.tab.c"
    break;

  case 26: /* unary_operator: '&'  */
#line 271 "src/grammar.y"
              {(yyval.str)="&";}
#line 1917 "src/grammar.tab.c"
    break;

  case 27: /* unary_operator: '*'  */
#line 272 "src/grammar.y"
              {(yyval.str)="*";}
#line 1923 "src/grammar.tab.c"
    break;

  case 28: /* unary_operator: '+'  */
#line 273 "src/grammar.y"
              {(yyval.str)="+";}
#line 1929 "src/grammar.tab.c"
    break;

  case 29: /* unary_operator: '-'  */
#line 274 "src/grammar.y"
              {(yyval.str)="-";}
#line 1935 "src/grammar.tab.c"
    break;

  case 30: /* unary_operator: '~'  */
#line 275 "src/grammar.y"
              {(yyval.str)="~";}
#line 1941 "src/grammar.tab.c"
    break;

  case 31: /* unary_operator: '!'  */
#line 276 "src/grammar.y"
              {(yyval.str)="!";}
#line 1947 "src/grammar.tab.c"
    break;

  case 32: /* cast_expression: unary_expression  */
#line 280 "src/grammar.y"
                           {(yyval.typ)=(yyvsp[0].typ);}
#line 1953 "src/grammar.tab.c"
    break;

  case 33: /* cast_expression: '(' type_name ')' cast_expression  */
#line 281 "src/grammar.y"
                                            {check_typecast_compatibility((yyvsp[-2].ty_nm)->type,(yyvsp[0].typ));(yyval.typ)=(yyvsp[-2].ty_nm)->type;}
#line 1959 "src/grammar.tab.c"
    break;

  case 34: /* multiplicative_expression: cast_expression  */
#line 285 "src/grammar.y"
                          {(yyval.typ)=(yyvsp[0].typ);}
#line 1965 "src/grammar.tab.c"
    break;

  case 35: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 286 "src/grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"*");string nn=get_new_temp();
		type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"*",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 1974 "src/grammar.tab.c"
    break;

  case 36: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 290 "src/grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"/");string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"/",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 1982 "src/grammar.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 293 "src/grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"%");string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"%",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 1990 "src/grammar.tab.c"
    break;

  case 38: /* additive_expression: multiplicative_expression  */
#line 299 "src/grammar.y"
                                    {(yyval.typ)=(yyvsp[0].typ);}
#line 1996 "src/grammar.tab.c"
    break;

  case 39: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 300 "src/grammar.y"
                                                            {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"+");string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"+",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 2004 "src/grammar.tab.c"
    break;

  case 40: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 303 "src/grammar.y"
                                                            {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"-");string nn=get_new_temp();
		type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"-",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 2012 "src/grammar.tab.c"
    break;

  case 41: /* shift_expression: additive_expression  */
#line 309 "src/grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2018 "src/grammar.tab.c"
    break;

  case 42: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 310 "src/grammar.y"
                                                        {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<<",nn);
		merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);type->place=nn;(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 2026 "src/grammar.tab.c"
    break;

  case 43: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 313 "src/grammar.y"
                                                        {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">>",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;
		temp_and_type[nn]=(yyval.typ);}
#line 2035 "src/grammar.tab.c"
    break;

  case 44: /* relational_expression: shift_expression  */
#line 320 "src/grammar.y"
                           {(yyval.typ)=(yyvsp[0].typ);}
#line 2041 "src/grammar.tab.c"
    break;

  case 45: /* relational_expression: relational_expression '<' shift_expression  */
#line 321 "src/grammar.y"
                                                     {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"<");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<",nn);/*merge_code(type->code,$1->code,$3->code);
		type->code.push_back(cod);*/global_code.push_back(cod);(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2049 "src/grammar.tab.c"
    break;

  case 46: /* relational_expression: relational_expression '>' shift_expression  */
#line 324 "src/grammar.y"
                                                     {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),">");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2057 "src/grammar.tab.c"
    break;

  case 47: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 327 "src/grammar.y"
                                                       {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),"<=");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<=",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2065 "src/grammar.tab.c"
    break;

  case 48: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 330 "src/grammar.y"
                                                       {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ),">=");Type* type=new Type();type->isbasic=true;
		type->base="INT";string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">=",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2073 "src/grammar.tab.c"
    break;

  case 49: /* equality_expression: relational_expression  */
#line 336 "src/grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ);}
#line 2079 "src/grammar.tab.c"
    break;

  case 50: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 337 "src/grammar.y"
                                                          {Type* type=check_for_eq_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"==",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2087 "src/grammar.tab.c"
    break;

  case 51: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 340 "src/grammar.y"
                                                          {Type* type=check_for_eq_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"!=",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2095 "src/grammar.tab.c"
    break;

  case 52: /* and_expression: equality_expression  */
#line 346 "src/grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2101 "src/grammar.tab.c"
    break;

  case 53: /* and_expression: and_expression '&' equality_expression  */
#line 347 "src/grammar.y"
                                                 {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"&",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2109 "src/grammar.tab.c"
    break;

  case 54: /* exclusive_or_expression: and_expression  */
#line 353 "src/grammar.y"
                         {(yyval.typ)=(yyvsp[0].typ);}
#line 2115 "src/grammar.tab.c"
    break;

  case 55: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 354 "src/grammar.y"
                                                     {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"^",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2123 "src/grammar.tab.c"
    break;

  case 56: /* inclusive_or_expression: exclusive_or_expression  */
#line 360 "src/grammar.y"
                                  {(yyval.typ)=(yyvsp[0].typ);}
#line 2129 "src/grammar.tab.c"
    break;

  case 57: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 361 "src/grammar.y"
                                                              {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"|",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2137 "src/grammar.tab.c"
    break;

  case 58: /* logical_and_expression: inclusive_or_expression  */
#line 367 "src/grammar.y"
                                  {cout << "logical end done" << endl;Type* type=(yyvsp[0].typ);
		type->truelist.push_back(global_code.size());type->falselist.push_back(global_code.size()+1);
		cout << "####pushing if code ###" << endl;
		global_code.push_back(get_if_true_code(type->place));global_code.push_back(get_if_false_code());(yyval.typ)=type;}
#line 2146 "src/grammar.tab.c"
    break;

  case 59: /* logical_and_expression: logical_and_expression AND_OP m inclusive_or_expression  */
#line 371 "src/grammar.y"
                                                                  {check_for_shift_op((yyvsp[-3].typ),(yyvsp[0].typ));Type* type=(yyvsp[-3].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-3].typ)->place,(yyvsp[0].typ)->place,"&&",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		(yyvsp[0].typ)->truelist.push_back(global_code.size());(yyvsp[0].typ)->falselist.push_back(global_code.size()+1);
		global_code.push_back(get_if_true_code((yyvsp[0].typ)->place));global_code.push_back(get_if_false_code());
		global_code.push_back(cod);type->place=nn;
		backpatch(type->truelist,(yyvsp[-1].int_value));type->falselist=merge(type->falselist,(yyvsp[0].typ)->falselist);type->truelist=(yyvsp[0].typ)->truelist;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2157 "src/grammar.tab.c"
    break;

  case 60: /* logical_or_expression: logical_and_expression  */
#line 380 "src/grammar.y"
                                 {(yyval.typ)=(yyvsp[0].typ);}
#line 2163 "src/grammar.tab.c"
    break;

  case 61: /* logical_or_expression: logical_or_expression OR_OP m logical_and_expression  */
#line 381 "src/grammar.y"
                                                               { cout << "logical or done" << endl;check_for_shift_op((yyvsp[-3].typ),(yyvsp[0].typ));Type* type=(yyvsp[-3].typ);string nn=get_new_temp();string cod=get_code4((yyvsp[-3].typ)->place,(yyvsp[0].typ)->place,"||",nn);merge_code1(type->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);type->place=nn;
		backpatch(type->falselist,(yyvsp[-1].int_value));type->truelist=merge(type->truelist,(yyvsp[0].typ)->truelist);type->falselist=(yyvsp[0].typ)->falselist;(yyval.typ)=type;temp_and_type[nn]=(yyval.typ);}
#line 2171 "src/grammar.tab.c"
    break;

  case 62: /* conditional_expression: logical_or_expression  */
#line 387 "src/grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ);}
#line 2177 "src/grammar.tab.c"
    break;

  case 63: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 388 "src/grammar.y"
                                                                            {Type* type=check_for_assign((yyvsp[-2].typ),(yyvsp[0].typ),"=");(yyval.typ)=type;}
#line 2183 "src/grammar.tab.c"
    break;

  case 64: /* assignment_expression: conditional_expression  */
#line 392 "src/grammar.y"
                                  {(yyval.typ)=(yyvsp[0].typ); }
#line 2189 "src/grammar.tab.c"
    break;

  case 65: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 393 "src/grammar.y"
                                                                      {Type* t=check_for_assign((yyvsp[-2].typ),(yyvsp[0].typ),(yyvsp[-1].str));merge_code(t->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);
		string cod;
		if((yyvsp[-1].str)=="="){
			cod=get_code4((yyvsp[0].typ)->place,"","",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="*="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"*",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="/="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"/",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="%="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"%",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="+="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"+",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="-="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"-",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="<<="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<<",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)==">>="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">>",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="&="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"&",(yyvsp[-2].typ)->place);
		}
		else if((yyvsp[-1].str)=="^="){
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"^",(yyvsp[-2].typ)->place);
		}
		else{
			cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"|",(yyvsp[-2].typ)->place);
		}
		backpatch((yyvsp[0].typ)->truelist,global_code.size());
		backpatch((yyvsp[0].typ)->falselist,global_code.size());
		global_code.push_back(cod);(yyval.typ)=t;
		}
#line 2233 "src/grammar.tab.c"
    break;

  case 66: /* assignment_operator: '='  */
#line 434 "src/grammar.y"
              {(yyval.str)="=";}
#line 2239 "src/grammar.tab.c"
    break;

  case 67: /* assignment_operator: MUL_ASSIGN  */
#line 435 "src/grammar.y"
                     {(yyval.str)="*=";}
#line 2245 "src/grammar.tab.c"
    break;

  case 68: /* assignment_operator: DIV_ASSIGN  */
#line 436 "src/grammar.y"
                     {(yyval.str)="/=";}
#line 2251 "src/grammar.tab.c"
    break;

  case 69: /* assignment_operator: MOD_ASSIGN  */
#line 437 "src/grammar.y"
                     {(yyval.str)="%=";}
#line 2257 "src/grammar.tab.c"
    break;

  case 70: /* assignment_operator: ADD_ASSIGN  */
#line 438 "src/grammar.y"
                     {(yyval.str)="+=";}
#line 2263 "src/grammar.tab.c"
    break;

  case 71: /* assignment_operator: SUB_ASSIGN  */
#line 439 "src/grammar.y"
                     {(yyval.str)="-=";}
#line 2269 "src/grammar.tab.c"
    break;

  case 72: /* assignment_operator: LEFT_ASSIGN  */
#line 440 "src/grammar.y"
                      {(yyval.str)="<<=";}
#line 2275 "src/grammar.tab.c"
    break;

  case 73: /* assignment_operator: RIGHT_ASSIGN  */
#line 441 "src/grammar.y"
                       {(yyval.str)=">>=";}
#line 2281 "src/grammar.tab.c"
    break;

  case 74: /* assignment_operator: AND_ASSIGN  */
#line 442 "src/grammar.y"
                     {(yyval.str)="&=";}
#line 2287 "src/grammar.tab.c"
    break;

  case 75: /* assignment_operator: XOR_ASSIGN  */
#line 443 "src/grammar.y"
                     {(yyval.str)="^=";}
#line 2293 "src/grammar.tab.c"
    break;

  case 76: /* assignment_operator: OR_ASSIGN  */
#line 444 "src/grammar.y"
                    {(yyval.str)="|=";}
#line 2299 "src/grammar.tab.c"
    break;

  case 77: /* expression: assignment_expression  */
#line 448 "src/grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ); cout<<"finally expression has identifier"<<endl;}
#line 2305 "src/grammar.tab.c"
    break;

  case 78: /* expression: expression ',' assignment_expression  */
#line 449 "src/grammar.y"
                                               {(yyval.typ)=(yyvsp[-2].typ);backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 2311 "src/grammar.tab.c"
    break;

  case 79: /* constant_expression: conditional_expression  */
#line 453 "src/grammar.y"
                                 {(yyval.typ)=(yyvsp[0].typ); backpatch((yyval.typ)->truelist, global_code.size()); backpatch((yyval.typ)->falselist,global_code.size());}
#line 2317 "src/grammar.tab.c"
    break;

  case 80: /* declaration: declaration_specifiers ';'  */
#line 459 "src/grammar.y"
                                     {(yyval.declaration)=create_declaration_object((yyvsp[-1].dec_spec),nullptr,nullptr);}
#line 2323 "src/grammar.tab.c"
    break;

  case 81: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 460 "src/grammar.y"
                                                          {(yyval.declaration)=create_declaration_object((yyvsp[-2].dec_spec),(yyvsp[-1].init_dec_list),nullptr);}
#line 2329 "src/grammar.tab.c"
    break;

  case 82: /* declaration_specifiers: storage_class_specifier  */
#line 469 "src/grammar.y"
                                  {Declaration_Specifiers* ds=create_decl_spec_object(); if(ds==nullptr){assert(0);}
	ds->scs.push_back((yyvsp[0].str));
	(yyval.dec_spec)=ds;}
#line 2337 "src/grammar.tab.c"
    break;

  case 83: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 472 "src/grammar.y"
                                                         {Declaration_Specifiers* ds=(yyvsp[0].dec_spec);ds->scs.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;cout << "declaration specifier done scs" << endl;}
#line 2343 "src/grammar.tab.c"
    break;

  case 84: /* declaration_specifiers: type_specifier  */
#line 473 "src/grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back((yyvsp[0].type_spec));(yyval.dec_spec)=ds;cout << ds->ts.back()->string_type << endl;cout<<"got type specifier"<<endl;}
#line 2349 "src/grammar.tab.c"
    break;

  case 85: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 474 "src/grammar.y"
                                                {cout<<"declaration_specifier started"<<endl;Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->ts.push_back((yyvsp[-1].type_spec));(yyval.dec_spec)=ds;cout<<"declaration specifier completed"<<endl;}
#line 2355 "src/grammar.tab.c"
    break;

  case 86: /* declaration_specifiers: type_qualifier  */
#line 475 "src/grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back((yyvsp[0].str));(yyval.dec_spec)=ds;}
#line 2361 "src/grammar.tab.c"
    break;

  case 87: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 476 "src/grammar.y"
                                                {Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->tq.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;}
#line 2367 "src/grammar.tab.c"
    break;

  case 88: /* init_declarator_list: init_declarator  */
#line 480 "src/grammar.y"
                          {Init_Declarator_List* x=new Init_Declarator_List();x->idl.push_back((yyvsp[0].dec));(yyval.init_dec_list)=x;
	if((yyvsp[0].dec)->type=="function"){current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	cout << "current params list cleared" << endl;}
	cout<<"idl completeted"<<endl;}
#line 2379 "src/grammar.tab.c"
    break;

  case 89: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 487 "src/grammar.y"
                                                   { (yyvsp[-2].init_dec_list)->idl.push_back((yyvsp[0].dec)); (yyval.init_dec_list) = (yyvsp[-2].init_dec_list);}
#line 2385 "src/grammar.tab.c"
    break;

  case 90: /* init_declarator: declarator  */
#line 491 "src/grammar.y"
                     {(yyval.dec)=(yyvsp[0].dec);}
#line 2391 "src/grammar.tab.c"
    break;

  case 91: /* init_declarator: declarator '=' initializer  */
#line 492 "src/grammar.y"
                                     {cout<<"init_declartor started"<<endl;(yyvsp[-2].dec)->ini=(yyvsp[0].ini);(yyval.dec)=(yyvsp[-2].dec);
	cout<<"init_declarator done"<<endl;
	(yyvsp[-2].dec)->tempname=get_new_temp();
		global_code.push_back(get_code4((yyvsp[0].ini)->type->place,"","",(yyvsp[-2].dec)->tempname));
	}
#line 2401 "src/grammar.tab.c"
    break;

  case 93: /* storage_class_specifier: EXTERN  */
#line 501 "src/grammar.y"
                 {(yyval.str)="EXTERN";}
#line 2407 "src/grammar.tab.c"
    break;

  case 94: /* storage_class_specifier: STATIC  */
#line 502 "src/grammar.y"
                 {(yyval.str)="STATIC";cout << "STATIC" << endl;}
#line 2413 "src/grammar.tab.c"
    break;

  case 95: /* storage_class_specifier: AUTO  */
#line 503 "src/grammar.y"
               {(yyval.str)="AUTO";}
#line 2419 "src/grammar.tab.c"
    break;

  case 96: /* storage_class_specifier: REGISTER  */
#line 504 "src/grammar.y"
                   {(yyval.str)="REGISTER";}
#line 2425 "src/grammar.tab.c"
    break;

  case 97: /* type_specifier: VOID  */
#line 508 "src/grammar.y"
           { (yyval.type_spec) = create_ts_obj(std::string("VOID"), nullptr, nullptr, nullptr); }
#line 2431 "src/grammar.tab.c"
    break;

  case 98: /* type_specifier: CHAR  */
#line 509 "src/grammar.y"
                {(yyval.type_spec)=create_ts_obj("CHAR",nullptr,nullptr,nullptr);}
#line 2437 "src/grammar.tab.c"
    break;

  case 99: /* type_specifier: SHORT  */
#line 510 "src/grammar.y"
                {(yyval.type_spec)=create_ts_obj("SHORT",nullptr,nullptr,nullptr);}
#line 2443 "src/grammar.tab.c"
    break;

  case 100: /* type_specifier: INT  */
#line 511 "src/grammar.y"
              {(yyval.type_spec)=create_ts_obj("INT",nullptr,nullptr,nullptr);cout<<"INT Passed"<<endl;}
#line 2449 "src/grammar.tab.c"
    break;

  case 101: /* type_specifier: LONG  */
#line 512 "src/grammar.y"
               {(yyval.type_spec)=create_ts_obj("LONG",nullptr,nullptr,nullptr);}
#line 2455 "src/grammar.tab.c"
    break;

  case 102: /* type_specifier: FLOAT  */
#line 513 "src/grammar.y"
                {(yyval.type_spec)=create_ts_obj("FLOAT",nullptr,nullptr,nullptr);}
#line 2461 "src/grammar.tab.c"
    break;

  case 103: /* type_specifier: DOUBLE  */
#line 514 "src/grammar.y"
                 {(yyval.type_spec)=create_ts_obj("DOUBLE",nullptr,nullptr,nullptr);}
#line 2467 "src/grammar.tab.c"
    break;

  case 104: /* type_specifier: SIGNED  */
#line 515 "src/grammar.y"
                 {(yyval.type_spec)=create_ts_obj("SIGNED",nullptr,nullptr,nullptr);}
#line 2473 "src/grammar.tab.c"
    break;

  case 105: /* type_specifier: UNSIGNED  */
#line 516 "src/grammar.y"
                   {(yyval.type_spec)=create_ts_obj("UNSIGNED",nullptr,nullptr,nullptr);cout<<"hurrah"<<endl;}
#line 2479 "src/grammar.tab.c"
    break;

  case 106: /* type_specifier: struct_or_union_specifier  */
#line 517 "src/grammar.y"
                                    {cout<<"struct_or_union_specifier found"<<endl;(yyval.type_spec)=create_ts_obj("",(yyvsp[0].str_union),nullptr,nullptr);}
#line 2485 "src/grammar.tab.c"
    break;

  case 107: /* type_specifier: enum_specifier  */
#line 519 "src/grammar.y"
                         {(yyval.type_spec)=create_ts_obj("",nullptr,nullptr,(yyvsp[0].enum_spec));cout<<" found enum in type specifier"<<endl;}
#line 2491 "src/grammar.tab.c"
    break;

  case 108: /* struct_or_union_specifier: struct struct_id '{' struct_declaration_list '}'  */
#line 524 "src/grammar.y"
                                                            { (yyval.str_union)=create_struct_union_spec_obj(std::string((yyvsp[-4].str)),std::string((yyvsp[-3].str)),(yyvsp[-1].struc_dec_list));
	 cout << "create struct union spec object done" << endl;
	current_level--; current_table=current_table->parent;
	 lvl_name.pop();add_to_local_class_struct_union_info();
	 cout << "add to local class struct union info done" << endl;
	}
#line 2502 "src/grammar.tab.c"
    break;

  case 109: /* struct_or_union_specifier: struct IDENTIFIER  */
#line 531 "src/grammar.y"
                            {cout<<"struct identifier reached"<<endl;check_if_declared(current_table,(yyvsp[0].str),"struct");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);}
#line 2508 "src/grammar.tab.c"
    break;

  case 110: /* struct_or_union_specifier: union union_id '{' struct_declaration_list '}'  */
#line 532 "src/grammar.y"
                                                         {cout<<"union uid sdl started"<<endl;(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].struc_dec_list));current_level--;current_table=current_table->parent;lvl_name.pop();add_to_local_class_struct_union_info();}
#line 2514 "src/grammar.tab.c"
    break;

  case 111: /* struct_or_union_specifier: union IDENTIFIER  */
#line 534 "src/grammar.y"
                           {check_if_declared(current_table,(yyvsp[0].str),"union");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);/* whether this identifier is declared before use */}
#line 2520 "src/grammar.tab.c"
    break;

  case 112: /* struct_id: IDENTIFIER  */
#line 538 "src/grammar.y"
                     {lvl_name.push("struct " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str),nullptr));ccsui_type.push("struct");cout<<"got struct identifier"<<endl;}
#line 2526 "src/grammar.tab.c"
    break;

  case 113: /* union_id: IDENTIFIER  */
#line 541 "src/grammar.y"
                     {cout<<"identifier in uid started"<<endl;lvl_name.push("union " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str),nullptr));ccsui_type.push("union");cout<<"Passed IDENTIFIER to uid"<<endl;}
#line 2532 "src/grammar.tab.c"
    break;

  case 114: /* struct: STRUCT  */
#line 544 "src/grammar.y"
                                {(yyval.str)="struct";cout <<"finally reached to struct"<<endl;}
#line 2538 "src/grammar.tab.c"
    break;

  case 115: /* union: UNION  */
#line 547 "src/grammar.y"
                {(yyval.str)="union";cout<<"passed UNION"<<endl;}
#line 2544 "src/grammar.tab.c"
    break;

  case 116: /* struct_declaration_list: struct_declaration  */
#line 551 "src/grammar.y"
                             {cout << "struct declaration list done" << endl;
	current_level++;Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;current_table=next_table();add_to_local_table(current_table,(yyvsp[0].struc_dec));if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}}
#line 2551 "src/grammar.tab.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 553 "src/grammar.y"
                                                     {Struct_Declaration_List* x=(yyvsp[-1].struc_dec_list);x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;add_to_local_table(current_table,(yyvsp[0].struc_dec));}
#line 2557 "src/grammar.tab.c"
    break;

  case 118: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 557 "src/grammar.y"
                                                             {cout<<"struct declaration started"<<endl;(yyval.struc_dec)=create_struct_dec_obj((yyvsp[-2].sql),(yyvsp[-1].sdl));cout<<"struct declaration done"<<endl;}
#line 2563 "src/grammar.tab.c"
    break;

  case 119: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 561 "src/grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->ts.push_back((yyvsp[-1].type_spec));(yyval.sql)=x;}
#line 2569 "src/grammar.tab.c"
    break;

  case 120: /* specifier_qualifier_list: type_specifier  */
#line 562 "src/grammar.y"
                         {cout<<"type spec in sql started"<<endl;Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->ts.push_back((yyvsp[0].type_spec));cout<<"type spec in sql ended"<<endl;(yyval.sql)=x;}
#line 2575 "src/grammar.tab.c"
    break;

  case 121: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 563 "src/grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->tq.push_back((yyvsp[-1].str));(yyval.sql)=x;}
#line 2581 "src/grammar.tab.c"
    break;

  case 122: /* specifier_qualifier_list: type_qualifier  */
#line 564 "src/grammar.y"
                         {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->tq.push_back((yyvsp[0].str));(yyval.sql)=x;}
#line 2587 "src/grammar.tab.c"
    break;

  case 123: /* struct_declarator_list: struct_declarator  */
#line 568 "src/grammar.y"
                             {cout<<"got struct declarator"<<endl;Struct_Declarator_List* x=new Struct_Declarator_List();x->sd.push_back((yyvsp[0].sd));cout<<"struct declarator done"<<endl;(yyval.sdl)=x;}
#line 2593 "src/grammar.tab.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 569 "src/grammar.y"
                                                        {Struct_Declarator_List* x=(yyvsp[-2].sdl);x->sd.push_back((yyvsp[0].sd));(yyval.sdl)=x;}
#line 2599 "src/grammar.tab.c"
    break;

  case 125: /* struct_declarator: declarator  */
#line 573 "src/grammar.y"
                                           {(yyval.sd)=create_struct_declarator_obj((yyvsp[0].dec));}
#line 2605 "src/grammar.tab.c"
    break;

  case 126: /* class_name: IDENTIFIER  */
#line 610 "src/grammar.y"
                            { (yyval.str) = (yyvsp[0].str); string s="class "; s+=(yyvsp[0].str);lvl_name.push(s);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str), nullptr) );ccsui_type.push("class"); }
#line 2611 "src/grammar.tab.c"
    break;

  case 127: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 644 "src/grammar.y"
                                                  {cout<<"enum id el started"<<endl; cout << (yyvsp[-1].enuml)->e.back()->id << "!!!!" << endl;(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[-3].str)),(yyvsp[-1].enuml));cout<<"enum specifier object created"<<endl;Type* t=new Type();t->isenum=true;t->isobj=true;t->obj_class=(yyvsp[-3].str);t->objtype="enum";cout<<"no bt upto t->objtype"<<endl;add_to_local_table((yyvsp[-1].enuml),t);cout<<"enum id el done"<<endl;}
#line 2617 "src/grammar.tab.c"
    break;

  case 128: /* enum_specifier: ENUM IDENTIFIER  */
#line 645 "src/grammar.y"
                          {(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[0].str)),nullptr);check_if_declared(current_table,std::string((yyvsp[0].str)),"enum");}
#line 2623 "src/grammar.tab.c"
    break;

  case 129: /* enumerator_list: enumerator  */
#line 649 "src/grammar.y"
                     {cout<<"enumerator started"<<endl;Enumerator_List* x=new Enumerator_List();x->e.push_back((yyvsp[0].enumer)); cout<<"got enumerator in el"<<endl;(yyval.enuml)=x;}
#line 2629 "src/grammar.tab.c"
    break;

  case 130: /* enumerator_list: enumerator_list ',' enumerator  */
#line 650 "src/grammar.y"
                                         {cout<<"enumerator list + enumerator started"<<endl;cout << (yyvsp[0].enumer)->id << "$#@$#@" << endl;(yyvsp[-2].enuml)->e.push_back((yyvsp[0].enumer));cout << (yyvsp[-2].enuml)->e.back()->id << "@#$" << endl;cout<<"enumerator list + enumerator returned"<<endl;(yyval.enuml)=(yyvsp[-2].enuml);}
#line 2635 "src/grammar.tab.c"
    break;

  case 131: /* enumerator: IDENTIFIER  */
#line 654 "src/grammar.y"
                     {(yyval.enumer)=new Enumerator(std::string((yyvsp[0].str)),new Type());cout<<"id in enumerator"<<endl;cout<<((yyvsp[0].str))<<endl;}
#line 2641 "src/grammar.tab.c"
    break;

  case 132: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 655 "src/grammar.y"
                                             {(yyval.enumer)=new Enumerator(std::string((yyvsp[-2].str)),(yyvsp[0].typ));check_int_comp((yyvsp[0].typ));}
#line 2647 "src/grammar.tab.c"
    break;

  case 133: /* type_qualifier: CONST  */
#line 659 "src/grammar.y"
                 {(yyval.str)="CONST";}
#line 2653 "src/grammar.tab.c"
    break;

  case 134: /* type_qualifier: VOLATILE  */
#line 660 "src/grammar.y"
                   {(yyval.str)="VOLATILE";}
#line 2659 "src/grammar.tab.c"
    break;

  case 135: /* declarator: pointer direct_declarator  */
#line 665 "src/grammar.y"
                                    {(yyval.dec)=create_new_declarator((yyvsp[-1].point),(yyvsp[0].dir_dec));cout<<"got pointer direct declarator"<<endl;}
#line 2665 "src/grammar.tab.c"
    break;

  case 136: /* declarator: direct_declarator  */
#line 666 "src/grammar.y"
                            {(yyval.dec)=create_new_declarator(nullptr,(yyvsp[0].dir_dec));cout<<"##"<<endl;}
#line 2671 "src/grammar.tab.c"
    break;

  case 137: /* direct_declarator: IDENTIFIER  */
#line 670 "src/grammar.y"
                     {(yyval.dir_dec)=create_direct_declarator(std::string("id"),(yyvsp[0].str),nullptr,nullptr,nullptr,nullptr);}
#line 2677 "src/grammar.tab.c"
    break;

  case 138: /* direct_declarator: '(' declarator ')'  */
#line 671 "src/grammar.y"
                             {(yyval.dir_dec)=create_direct_declarator(std::string("declarator"),"",(yyvsp[-1].dec),nullptr,nullptr,nullptr);}
#line 2683 "src/grammar.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 672 "src/grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,nullptr);check_int_comp((yyvsp[-1].typ));backpatch((yyvsp[-1].typ)->truelist,global_code.size());backpatch((yyvsp[-1].typ)->falselist,global_code.size());}
#line 2689 "src/grammar.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator '[' ']'  */
#line 673 "src/grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2695 "src/grammar.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 674 "src/grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,(yyvsp[-1].pl));}
#line 2701 "src/grammar.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator '(' ')'  */
#line 676 "src/grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2707 "src/grammar.tab.c"
    break;

  case 143: /* pointer: '*'  */
#line 680 "src/grammar.y"
              {(yyval.point)=new Pointer(nullptr,nullptr);}
#line 2713 "src/grammar.tab.c"
    break;

  case 144: /* pointer: '*' type_qualifier_list  */
#line 681 "src/grammar.y"
                                  {(yyval.point)=new Pointer((yyvsp[0].tql),nullptr);}
#line 2719 "src/grammar.tab.c"
    break;

  case 145: /* pointer: '*' pointer  */
#line 682 "src/grammar.y"
                      {(yyval.point)=new Pointer(nullptr,(yyvsp[0].point));}
#line 2725 "src/grammar.tab.c"
    break;

  case 146: /* pointer: '*' type_qualifier_list pointer  */
#line 683 "src/grammar.y"
                                          {(yyval.point)=new Pointer((yyvsp[-1].tql),(yyvsp[0].point));}
#line 2731 "src/grammar.tab.c"
    break;

  case 147: /* type_qualifier_list: type_qualifier  */
#line 687 "src/grammar.y"
                         {Type_Qualifier_List* x=new Type_Qualifier_List();x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2737 "src/grammar.tab.c"
    break;

  case 148: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 688 "src/grammar.y"
                                             {Type_Qualifier_List* x=(yyvsp[-1].tql);x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2743 "src/grammar.tab.c"
    break;

  case 149: /* parameter_type_list: parameter_list  */
#line 693 "src/grammar.y"
                         {(yyval.pl)=(yyvsp[0].pl);}
#line 2749 "src/grammar.tab.c"
    break;

  case 150: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 694 "src/grammar.y"
                                      {Parameter_List* x=(yyvsp[-2].pl); x->ellipses=true;}
#line 2755 "src/grammar.tab.c"
    break;

  case 151: /* parameter_list: parameter_declaration  */
#line 698 "src/grammar.y"
                                {Parameter_List* x=new Parameter_List();x->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=x;}
#line 2761 "src/grammar.tab.c"
    break;

  case 152: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 699 "src/grammar.y"
                                                   {(yyvsp[-2].pl)->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=(yyvsp[-2].pl);}
#line 2767 "src/grammar.tab.c"
    break;

  case 153: /* parameter_declaration: declaration_specifiers declarator  */
#line 703 "src/grammar.y"
                                            {(yyval.par_dec)=new Parameter_Declaration((yyvsp[-1].dec_spec),(yyvsp[0].dec));}
#line 2773 "src/grammar.tab.c"
    break;

  case 154: /* type_name: specifier_qualifier_list  */
#line 714 "src/grammar.y"
                                    { (yyval.ty_nm)=new Type_Name((yyvsp[0].sql),nullptr);}
#line 2779 "src/grammar.tab.c"
    break;

  case 155: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 715 "src/grammar.y"
                                                       {(yyval.ty_nm)=new Type_Name((yyvsp[-1].sql),(yyvsp[0].abs_d));(yyvsp[0].abs_d)->type=(yyvsp[0].abs_d)->check_abstract_declarator();}
#line 2785 "src/grammar.tab.c"
    break;

  case 156: /* abstract_declarator: pointer  */
#line 719 "src/grammar.y"
                  {Abstract_Declarator* x=new Abstract_Declarator((yyvsp[0].point),nullptr);(yyval.abs_d)=x;}
#line 2791 "src/grammar.tab.c"
    break;

  case 157: /* abstract_declarator: direct_abstract_declarator  */
#line 720 "src/grammar.y"
                                     {Abstract_Declarator* x=new Abstract_Declarator(nullptr,(yyvsp[0].dir_ad));(yyval.abs_d)=x;}
#line 2797 "src/grammar.tab.c"
    break;

  case 158: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 721 "src/grammar.y"
                                             {Abstract_Declarator* x=new Abstract_Declarator((yyvsp[-1].point),(yyvsp[0].dir_ad));(yyval.abs_d)=x;}
#line 2803 "src/grammar.tab.c"
    break;

  case 159: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 725 "src/grammar.y"
                                      {(yyval.dir_ad)=new Direct_Abstract_Declarator("abs_dec",(yyvsp[-1].abs_d),nullptr,nullptr,nullptr);}
#line 2809 "src/grammar.tab.c"
    break;

  case 160: /* direct_abstract_declarator: '[' ']'  */
#line 726 "src/grammar.y"
                                                                {(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,nullptr,nullptr,nullptr);}
#line 2815 "src/grammar.tab.c"
    break;

  case 161: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 727 "src/grammar.y"
                                      {check_int_comp((yyvsp[-1].typ));(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,nullptr,(yyvsp[-1].typ),nullptr);}
#line 2821 "src/grammar.tab.c"
    break;

  case 162: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 728 "src/grammar.y"
                                             {(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,(yyvsp[-2].dir_ad),nullptr,nullptr);}
#line 2827 "src/grammar.tab.c"
    break;

  case 163: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 729 "src/grammar.y"
                                                                 {check_int_comp((yyvsp[-1].typ));(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,(yyvsp[-3].dir_ad),(yyvsp[-1].typ),nullptr);}
#line 2833 "src/grammar.tab.c"
    break;

  case 164: /* direct_abstract_declarator: '(' ')'  */
#line 730 "src/grammar.y"
                        {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,nullptr);}
#line 2839 "src/grammar.tab.c"
    break;

  case 165: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 731 "src/grammar.y"
                                       {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,(yyvsp[-1].pl));}
#line 2845 "src/grammar.tab.c"
    break;

  case 166: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 732 "src/grammar.y"
                                             {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,(yyvsp[-2].dir_ad),nullptr,nullptr);}
#line 2851 "src/grammar.tab.c"
    break;

  case 167: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 733 "src/grammar.y"
                                                                 {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,(yyvsp[-3].dir_ad),nullptr,(yyvsp[-1].pl));}
#line 2857 "src/grammar.tab.c"
    break;

  case 168: /* initializer: assignment_expression  */
#line 737 "src/grammar.y"
                                 {Initializer* x=new Initializer((yyvsp[0].typ),"",nullptr,"",nullptr);x->type=(yyvsp[0].typ);(yyval.ini)=x;backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 2863 "src/grammar.tab.c"
    break;

  case 169: /* initializer: '{' initializer_list '}'  */
#line 738 "src/grammar.y"
                                   {(yyval.ini)=new Initializer(new Type(),"",(yyvsp[-1].ini_lst),"",nullptr);}
#line 2869 "src/grammar.tab.c"
    break;

  case 170: /* initializer: '{' initializer_list ',' '}'  */
#line 739 "src/grammar.y"
                                       {(yyval.ini)=new Initializer(new Type(),"",(yyvsp[-2].ini_lst),"",nullptr);}
#line 2875 "src/grammar.tab.c"
    break;

  case 171: /* initializer: NEW class_name '(' argument_expression_list ')'  */
#line 740 "src/grammar.y"
                                                          {Type* t=get_type_id((yyvsp[-3].str));check_if_constructor(t);check_argument_with_params(t->prms,(yyvsp[-1].arg_ex_list)->vec_exp,false);Type* z=new Type();z->isobj=true;z->objtype="class";z->obj_class=(yyvsp[-3].str);Initializer* gg=new Initializer(z,"",nullptr,(yyvsp[-3].str),(yyvsp[-1].arg_ex_list));(yyval.ini)=gg;}
#line 2881 "src/grammar.tab.c"
    break;

  case 172: /* initializer: NEW class_name '(' ')'  */
#line 741 "src/grammar.y"
                                 {Type* t=get_type_id((yyvsp[-2].str));check_if_constructor(t);check_argument_with_params(t->prms,vector<Type*>(),false);Type*z=new Type();z->isobj=true;z->objtype=="class";z->obj_class=(yyvsp[-2].str);Initializer* gg=new Initializer(z,"",nullptr,(yyvsp[-2].str),nullptr);(yyval.ini)=gg;}
#line 2887 "src/grammar.tab.c"
    break;

  case 173: /* initializer_list: initializer  */
#line 745 "src/grammar.y"
                      {Initializer_List* x=new Initializer_List();x->iv.push_back((yyvsp[0].ini));(yyval.ini_lst)=x;}
#line 2893 "src/grammar.tab.c"
    break;

  case 174: /* initializer_list: initializer_list ',' initializer  */
#line 746 "src/grammar.y"
                                           {(yyvsp[-2].ini_lst)->iv.push_back((yyvsp[0].ini));(yyval.ini_lst)=(yyvsp[-2].ini_lst);}
#line 2899 "src/grammar.tab.c"
    break;

  case 175: /* statement: labeled_statement  */
#line 750 "src/grammar.y"
                            {(yyval.typ)=(yyvsp[0].typ); }
#line 2905 "src/grammar.tab.c"
    break;

  case 176: /* statement: compound_statement  */
#line 751 "src/grammar.y"
                             {(yyval.typ)=(yyvsp[0].comp_stmt)->st;cout<<"finally statemeexpression_statementnt has compound statement"<<endl;}
#line 2911 "src/grammar.tab.c"
    break;

  case 177: /* statement: expression_statement  */
#line 752 "src/grammar.y"
                               {(yyval.typ)=(yyvsp[0].typ); cout << "expression statement" << endl;}
#line 2917 "src/grammar.tab.c"
    break;

  case 178: /* statement: selection_statement  */
#line 753 "src/grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2923 "src/grammar.tab.c"
    break;

  case 179: /* statement: iteration_statement  */
#line 754 "src/grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2929 "src/grammar.tab.c"
    break;

  case 180: /* statement: jump_statement  */
#line 755 "src/grammar.y"
                         {(yyval.typ)=(yyvsp[0].typ);}
#line 2935 "src/grammar.tab.c"
    break;

  case 181: /* statement: delete_statement  */
#line 756 "src/grammar.y"
                           {}
#line 2941 "src/grammar.tab.c"
    break;

  case 182: /* delete_statement: DELETE IDENTIFIER  */
#line 760 "src/grammar.y"
                            {check_if_pointer(get_type_id((yyvsp[0].str)));}
#line 2947 "src/grammar.tab.c"
    break;

  case 183: /* delete_statement: DELETE '[' ']' IDENTIFIER  */
#line 761 "src/grammar.y"
                                    {check_if_array(get_type_id((yyvsp[0].str)));}
#line 2953 "src/grammar.tab.c"
    break;

  case 184: /* labeled_statement: IDENTIFIER ':' m statement  */
#line 765 "src/grammar.y"
                                     {if(labelset.find((yyvsp[-3].str))==labelset.end())labelset.insert((yyvsp[-3].str));else {cout << "label declared twice" << endl;exit(1);}(yyval.typ)=(yyvsp[0].typ);
		backpatch(goto_label, (yyvsp[-1].int_value));
		labelgoto.push_back((yyvsp[-3].str));
		labelmap[(yyvsp[-3].str)]=(yyvsp[-1].int_value);
		}
#line 2963 "src/grammar.tab.c"
    break;

  case 185: /* labeled_statement: CASE constant_expression colon statement  */
#line 770 "src/grammar.y"
                                                   {(yyval.typ)=(yyvsp[0].typ); 
	
		fill_eqeq_exp1((yyvsp[-1].int_value)-2,(yyvsp[-2].typ)->place);
		backpatch1((yyvsp[-1].int_value)-2,(yyvsp[-1].int_value));
		backpatch1((yyvsp[-1].int_value)-1, global_code.size());
		}
#line 2974 "src/grammar.tab.c"
    break;

  case 186: /* labeled_statement: DEFAULT ':' statement  */
#line 776 "src/grammar.y"
                                {cout<<"finally reached to default"<<endl;(yyval.typ)=(yyvsp[0].typ);}
#line 2980 "src/grammar.tab.c"
    break;

  case 187: /* colon: ':'  */
#line 780 "src/grammar.y"
              { switch_true.push_back(global_code.size());
			global_code.push_back(get_if_true_code("=="));	
			switch_false.push_back(global_code.size());		
			global_code.push_back(get_if_false_code());
			(yyval.int_value)=global_code.size();

			}
#line 2992 "src/grammar.tab.c"
    break;

  case 188: /* compound_statement: '{' '}'  */
#line 790 "src/grammar.y"
                  {Compound_Statement* x=new Compound_Statement(new Type(),nullptr);(yyval.comp_stmt)=x;}
#line 2998 "src/grammar.tab.c"
    break;

  case 189: /* compound_statement: '{' statement_list '}'  */
#line 791 "src/grammar.y"
                                 {Compound_Statement* x=new Compound_Statement((yyvsp[-1].typ),nullptr);cout<<"obj of compound statement done for st_lst"<<endl; cout<<"loop completed"<<endl;(yyval.comp_stmt)=x;cout<<"statement_list done in compound_statement"<<endl;}
#line 3004 "src/grammar.tab.c"
    break;

  case 190: /* compound_statement: '{' declaration_list '}'  */
#line 792 "src/grammar.y"
                                   {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),(yyvsp[-1].dec_list));cout << "compound_statement parsed" << endl;
	current_level--;current_table=current_table->parent;cout << current_level << "in compound statement" << endl;
	(yyval.comp_stmt)=x;}
#line 3012 "src/grammar.tab.c"
    break;

  case 191: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 795 "src/grammar.y"
                                                  {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),(yyvsp[-2].dec_list));
	current_level--;current_table=current_table->parent;
	(yyval.comp_stmt)=x;cout << "compound_statement parsed" << endl;}
#line 3020 "src/grammar.tab.c"
    break;

  case 192: /* declaration_list: declaration  */
#line 801 "src/grammar.y"
                      {current_level++;cout << "checking for next table" << endl;Declaration_List* x=new Declaration_List();x->dv.push_back((yyvsp[0].declaration));current_table=next_table();
	cout << "next table working fine" << endl;add_to_local_table(current_table,(yyvsp[0].declaration));cout << "declaration list done successfully" << endl;
	cout << current_level << "in declaration_list" << endl;
	(yyval.dec_list)=x;}
#line 3029 "src/grammar.tab.c"
    break;

  case 193: /* declaration_list: declaration_list declaration  */
#line 805 "src/grammar.y"
                                       {cout<<"declaration_list done"<<endl;(yyvsp[-1].dec_list)->dv.push_back((yyvsp[0].declaration));(yyval.dec_list)=(yyvsp[-1].dec_list);add_to_local_table(current_table,(yyvsp[0].declaration));}
#line 3035 "src/grammar.tab.c"
    break;

  case 194: /* statement_list: statement  */
#line 809 "src/grammar.y"
                    { cout << "statement parsed" << endl;(yyval.typ)=(yyvsp[0].typ);}
#line 3041 "src/grammar.tab.c"
    break;

  case 195: /* statement_list: statement_list statement  */
#line 810 "src/grammar.y"
                                   {(yyval.typ)=(yyvsp[0].typ);}
#line 3047 "src/grammar.tab.c"
    break;

  case 196: /* expression_statement: ';'  */
#line 814 "src/grammar.y"
              {(yyval.typ)=new Type();cout<<"semi colon"<<endl;}
#line 3053 "src/grammar.tab.c"
    break;

  case 197: /* expression_statement: expression  */
#line 815 "src/grammar.y"
                     {(yyval.typ)=(yyvsp[0].typ);backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 3059 "src/grammar.tab.c"
    break;

  case 198: /* smc: ';'  */
#line 818 "src/grammar.y"
              {(yyval.int_value)=global_code.size();}
#line 3065 "src/grammar.tab.c"
    break;

  case 199: /* selection_statement: IF '(' expression crb statement  */
#line 820 "src/grammar.y"
                                          { cout << "other if else done" << endl;
		backpatch((yyvsp[-2].typ)->truelist,(yyvsp[-1].int_value));
		 Type* zz=new Type();
		zz->nextlist=merge((yyvsp[-2].typ)->falselist, (yyvsp[0].typ)->nextlist);backpatch(zz->nextlist,global_code.size());(yyval.typ)=zz; 
	}
#line 3075 "src/grammar.tab.c"
    break;

  case 200: /* selection_statement: IF '(' expression crb statement els statement  */
#line 825 "src/grammar.y"
                                                         {cout << "if_else done" << endl;
		backpatch((yyvsp[-4].typ)->truelist,(yyvsp[-3].int_value));
		backpatch ((yyvsp[-4].typ)->falselist,(yyvsp[-1].int_value));
		Type* zz=new Type(); zz->nextlist=merge((yyvsp[-2].typ)->nextlist,(yyvsp[0].typ)->nextlist);
		backpatch(zz->nextlist,global_code.size()); (yyval.typ)=zz;}
#line 3085 "src/grammar.tab.c"
    break;

  case 201: /* selection_statement: SWITCH '(' expression crb emp statement  */
#line 831 "src/grammar.y"
                                                  {(yyval.typ)=(yyvsp[0].typ);
		backpatch((yyvsp[-3].typ)->truelist, (yyvsp[-2].int_value));
		backpatch((yyvsp[-3].typ)->falselist, (yyvsp[-2].int_value));
		backpatch(break_label, global_code.size());
		fill_eqeq_exp2(switch_true, (yyvsp[-3].typ)->place);
		}
#line 3096 "src/grammar.tab.c"
    break;

  case 202: /* emp: %empty  */
#line 839 "src/grammar.y"
          {
		(yyval.int_value)=global_code.size();
		
		
	  }
#line 3106 "src/grammar.tab.c"
    break;

  case 203: /* m: %empty  */
#line 847 "src/grammar.y"
          {(yyval.int_value)=global_code.size();}
#line 3112 "src/grammar.tab.c"
    break;

  case 204: /* iteration_statement: WHILE srb expression crb statement  */
#line 851 "src/grammar.y"
                                             {(yyval.typ)=(yyvsp[0].typ);
	backpatch((yyvsp[0].typ)->nextlist, (yyvsp[-3].int_value));
	backpatch((yyvsp[-2].typ)->truelist, (yyvsp[-1].int_value));
	(yyval.typ)->nextlist=(yyvsp[-2].typ)->falselist;
	global_code.push_back(get_while_code((yyvsp[-3].int_value)));
	backpatch((yyval.typ)->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, (yyvsp[-3].int_value));
	}
#line 3126 "src/grammar.tab.c"
    break;

  case 205: /* iteration_statement: UNTIL srb expression crb statement  */
#line 862 "src/grammar.y"
                                             {(yyval.typ)=(yyvsp[0].typ);
	backpatch((yyvsp[0].typ)->nextlist, (yyvsp[-3].int_value));
	backpatch((yyvsp[-2].typ)->truelist, (yyvsp[-1].int_value));
	(yyval.typ)->nextlist=(yyvsp[-2].typ)->falselist;
	global_code.push_back(get_while_code((yyvsp[-3].int_value)));
	backpatch((yyval.typ)->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, (yyvsp[-3].int_value));
	}
#line 3140 "src/grammar.tab.c"
    break;

  case 206: /* iteration_statement: doo statement WHILE srb expression ')' ';'  */
#line 872 "src/grammar.y"
                                                     {(yyval.typ)=(yyvsp[-5].typ);
	(yyval.typ)->nextlist=(yyvsp[-2].typ)->falselist;
	backpatch((yyvsp[-2].typ)->truelist, (yyvsp[-6].int_value));
	backpatch((yyval.typ)->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, (yyvsp[-6].int_value));
	}
#line 3152 "src/grammar.tab.c"
    break;

  case 207: /* iteration_statement: FOR '(' expression smc expression smc ')' statement  */
#line 880 "src/grammar.y"
                                                              { (yyval.typ)=(yyvsp[0].typ);
		backpatch((yyvsp[-3].typ)->truelist,(yyvsp[-2].int_value));
		(yyval.typ)->nextlist=(yyvsp[-3].typ)->falselist;
		global_code.push_back(get_while_code((yyvsp[-4].int_value)));
		backpatch((yyvsp[-3].typ)->falselist,global_code.size());
		backpatch(break_label, global_code.size());
		backpatch(continue_label, (yyvsp[-4].int_value));
		}
#line 3165 "src/grammar.tab.c"
    break;

  case 208: /* iteration_statement: FOR '(' expression smc expression smc expression fcrb statement  */
#line 890 "src/grammar.y"
                                                                          { (yyval.typ)=(yyvsp[0].typ);
		backpatch((yyvsp[-4].typ)->truelist,(yyvsp[-1].for_cb)->pos);
		backpatch((yyvsp[-1].for_cb)->nextlist,(yyvsp[-5].int_value));
		backpatch((yyvsp[-2].typ)->truelist,(yyvsp[-1].for_cb)->pos-1);
		backpatch((yyvsp[-2].typ)->falselist,(yyvsp[-1].for_cb)->pos-1);
		global_code.push_back(get_while_code((yyvsp[-3].int_value)));
		backpatch((yyvsp[-4].typ)->falselist,global_code.size());
		(yyval.typ)=(yyvsp[0].typ);(yyval.typ)->nextlist=(yyvsp[-4].typ)->falselist;
		backpatch(break_label, global_code.size());
		backpatch(continue_label, (yyvsp[-5].int_value));
		}
#line 3181 "src/grammar.tab.c"
    break;

  case 209: /* fcrb: ')'  */
#line 904 "src/grammar.y"
              {FCRB* t=new FCRB();t->nextlist.push_back(global_code.size());global_code.push_back(get_if_false_code());t->pos=global_code.size();(yyval.for_cb)=t;}
#line 3187 "src/grammar.tab.c"
    break;

  case 210: /* doo: DO  */
#line 907 "src/grammar.y"
             {(yyval.int_value)=global_code.size();}
#line 3193 "src/grammar.tab.c"
    break;

  case 211: /* crb: ')'  */
#line 910 "src/grammar.y"
              {(yyval.int_value)=global_code.size();}
#line 3199 "src/grammar.tab.c"
    break;

  case 212: /* els: ELSE  */
#line 913 "src/grammar.y"
               {(yyval.int_value)=global_code.size();}
#line 3205 "src/grammar.tab.c"
    break;

  case 213: /* srb: '('  */
#line 916 "src/grammar.y"
              {(yyval.int_value)=global_code.size();}
#line 3211 "src/grammar.tab.c"
    break;

  case 214: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 921 "src/grammar.y"
                              {(yyval.typ)=new Type();
 		goto_label.push_back(global_code.size());
 		if(identifier_found(labelgoto, (yyvsp[-1].str))){
 		global_code.push_back(get_while_code(labelmap[(yyvsp[-1].str)]));
 		}
 		else{
 		global_code.push_back(get_if_false_code());}
 		}
#line 3224 "src/grammar.tab.c"
    break;

  case 215: /* jump_statement: CONTINUE ';'  */
#line 929 "src/grammar.y"
                       {(yyval.typ)=new Type();
 		continue_label.push_back(global_code.size());
 		global_code.push_back(get_if_false_code());}
#line 3232 "src/grammar.tab.c"
    break;

  case 216: /* jump_statement: BREAK ';'  */
#line 932 "src/grammar.y"
                    {(yyval.typ)=new Type();cout<<"found break"<<endl;
 		break_label.push_back(global_code.size());
 		global_code.push_back(get_if_false_code());}
#line 3240 "src/grammar.tab.c"
    break;

  case 217: /* jump_statement: RETURN ';'  */
#line 935 "src/grammar.y"
                     {Type* type=new Type();type->isvoid=true;check_for_assign(func_ret_type,type,"=");global_code.push_back(gen_return(""));}
#line 3246 "src/grammar.tab.c"
    break;

  case 218: /* jump_statement: RETURN initializer ';'  */
#line 936 "src/grammar.y"
                                 {check_for_assign(func_ret_type,(yyvsp[-1].ini)->type,"=");global_code.push_back(gen_return((yyvsp[-1].ini)->type->place));}
#line 3252 "src/grammar.tab.c"
    break;

  case 219: /* translation_unit: external_declaration  */
#line 939 "src/grammar.y"
                               {cout<<"reached ext declaration"<<endl;Node* ext=create_node();cout<<"create node done"<<endl;}
#line 3258 "src/grammar.tab.c"
    break;

  case 220: /* translation_unit: translation_unit external_declaration  */
#line 940 "src/grammar.y"
                                                {Node* ext=create_node();cout<<"t_u and e_d"<<endl;}
#line 3264 "src/grammar.tab.c"
    break;

  case 221: /* external_declaration: function_definition  */
#line 944 "src/grammar.y"
                               {cout<<"external declaration started"<<endl;add_to_gst((yyvsp[0].fun_def),gst);cout<<"add to gst"<<endl;(yyval.node)=(yyvsp[0].fun_def);cout<<"external declaration started"<<endl;}
#line 3270 "src/grammar.tab.c"
    break;

  case 222: /* external_declaration: declaration  */
#line 945 "src/grammar.y"
                      {add_to_gst((yyvsp[0].declaration),gst);(yyval.node)=(yyvsp[0].declaration);}
#line 3276 "src/grammar.tab.c"
    break;

  case 223: /* function_declaration: declaration_specifiers declarator  */
#line 948 "src/grammar.y"
                                            { Function_Declaration* x=new Function_Declaration((yyvsp[-1].dec_spec),(yyvsp[0].dec));
		Type* type=new Type();
		string t=create_type((yyvsp[-1].dec_spec),(yyvsp[0].dec),type);
		cout << "create type for func decl done successfully"<<endl;
		(yyvsp[0].dec)->check_for_func();cout << "check for func done successfully in func decl" << endl;
		(yyval.func_decl)=x;
		lvl_name.push(get_name((yyvsp[0].dec)));
		string sc="global";
		if(current_level>0)sc="local";
		Symbol_Info* si=new Symbol_Info((yyvsp[0].dec)->id,t,get_level_name(),current_level-lvl_name.size()+1,sc,"-",type);
		func_ret_type=type->func_ret_type ; 
		current_func_name=(yyvsp[0].dec)->id;
		if(current_level==0&&current_func_name=="main"){
			(yyvsp[0].dec)->tempname="main";
		}
		else{
			(yyvsp[0].dec)->tempname=get_new_temp();
		}
		si->tempname=(yyvsp[0].dec)->tempname;
		current_func_si=si;
		global_code.push_back(get_label((yyvsp[0].dec)->tempname));
		cout<<"@@@"<<endl;
		cout<<get_label((yyvsp[0].dec)->tempname)<<endl;
		for(auto i:current_param_vector){
			string nn=get_new_temp();
			i.second->place=nn;
			current_params_list[i.first]->place=nn;
			global_code.push_back(get_label_param(nn));
		}
		cout<<"final func decl done huuh"<<endl;
		}
#line 3312 "src/grammar.tab.c"
    break;

  case 224: /* function_definition: function_declaration compound_statement  */
#line 982 "src/grammar.y"
                                                  {Function_Declaration* x=(yyvsp[-1].func_decl);(yyval.fun_def)=create_func_def(x->ds,x->d,(yyvsp[0].comp_stmt));
	cout<<"create func def done"<< endl;
	current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	cout << "current params list cleared" << endl;
	func_ret_type==nullptr;
	current_func_name="";
	current_func_si=nullptr;
	lvl_name.pop();}
#line 3328 "src/grammar.tab.c"
    break;


#line 3332 "src/grammar.tab.c"

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

#line 997 "src/grammar.y"

#include <stdio.h>
#include <bits/stdc++.h>
#include <classes_NT.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
extern char yytext[];
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
// Define the global variables here
bool iserror = false;
vector<pair<string, int>> error;
unordered_map<string, string> symtab;
vector<string> program;

void yyerror(const char *s) {
    fflush(stdout);
	
}
int main(int argc, char *argv[]){
	string outputFileName="lexer_output";
    FILE *fh;
	FILE *fo;

	if (argc != 4){
		std::cout << "Incorrect usage. Usage : ./bin/parser <file>.c -o <file>.dot";
	}
	if ((fh = fopen(argv[1], "r"))){
		yyin = fh;
	}
	else{
		std::cout << "Input file does not exist!" << endl;
		exit(1);
	}
	ofstream outputFile(outputFileName);
	
	Node* root= new Node();
	gst=new Global_Symbol_Table();
	current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	labelset.clear();
	while (!lvl_name.empty()){
    lvl_name.pop();
	}
	current_table=nullptr;
	func_ret_type=nullptr;
	current_func_name="";
	current_func_si=nullptr;
	current_level=0;
    int abc=yyparse();
	if (!error.empty()) {
        outputFile << "Errors Found:\n";
        for (const auto &err : error) {
             if(err.first!="unterminated comment")outputFile << "invalid character : " << err.first << " at line no. " << err.second << endl;
            else outputFile  << err.first << " at line no. " << err.second << endl;
        }
		/*cout << "error in lexical phase" << endl;
		exit(1);*/
    } 
	else {
		
        outputFile << "Original Symbol Table:\n";
        outputFile << "-------------------------------------------------------------------------------\n";
        outputFile << "| Lexeme                                | Token                                 |\n";
        outputFile << "-------------------------------------------------------------------------------\n";

        for (const auto &entry : symtab) {
            std::stringstream tokenStream(entry.first);
            std::string line;
            bool firstLine = true;
            while (std::getline(tokenStream, line, '\n')) {
                if (firstLine) {
                    outputFile << "| " << setw(36) << left << line
                               << " | " << setw(36) << left << entry.second << " |\n";
                    firstLine = false;
                } else {
                    outputFile << "| " << setw(36) << left << line
                               << " | " << setw(36) << left << "" << " |\n";
                }
            }
        }
        outputFile << "-------------------------------------------------------------------------------\n";
        outputFile << '\n';
		outputFile << "seperated tokens: "<< endl;
		for(auto i:program)outputFile << i << endl;
		outputFile << endl;

		
	
    cout << "Lexical analysis completed. Check '" << outputFileName << "' for results." << endl;
	
    }
	outputFile.close();
    if(abc){
        cout << "parsing failed!" << endl;
    }
    else{
        cout << "parsing successful" << endl;
    }
	  print_full_symbol_table();
      string tacOutputFile = "output_tac.txt";
	  string final_symtabFile="final_symtab.txt";
    ofstream tacFile(tacOutputFile);
	ofstream fsFile(final_symtabFile);
    
    if (!tacFile.is_open()) {
        cerr << "Error: Could not open file " << tacOutputFile << " for writing." << endl;
    } else {
        fsFile << "====================== FINAL SYMBOL TABLE ======================\n\n";
        for(auto i:final_symtab){
            fsFile << "Temp: " << i.first << "\n";
            fsFile << "  Name: " << i.second->name << "\n";
            fsFile << "  Type: " << i.second->type << "\n";
            fsFile << "  Scope: " << i.second->level_name << "\n";
            fsFile << "  Level: " << i.second->level << "\n\n";
        }
        fsFile << "====================== FINAL TEMP SYMBOL TABLE ======================\n\n";
        for (auto i : temp_and_type) {
		fsFile << "Temp: " << i.first << "\n";

		Type* t = i.second;
		t->size=getBasicTypeSize(t);
		if (!t) {
			fsFile << "  Type: nullptr\n";
			continue;
		}

		fsFile << "  Type Info:\n";
		fsFile << "    size: " << t->size << "\n";
		fsFile << "    base: " << t->base << "\n";
		fsFile << "    ptr_level: " << t->ptr_level << "\n";
		fsFile << "    array_dim: " << t->array_dim << "\n";
		fsFile << "    isbasic: " << t->isbasic << "\n";
		fsFile << "    isobj: " << t->isobj << "\n";
		fsFile << "    isfunction: " << t->isfunction << "\n";
		fsFile << "    isconst: " << t->isconst << "\n";
		fsFile << "    isvolatile: " << t->isvolatile << "\n";
		fsFile << "    isstatic: " << t->isstatic << "\n";
		fsFile << "    isauto: " << t->isauto << "\n";
		fsFile << "    isextern: " << t->isextern << "\n";
		fsFile << "    isregister: " << t->isregister << "\n";
		fsFile << "    isigned: " << t->isigned << "\n";
		fsFile << "    isunsigned: " << t->isunsigned << "\n";
		fsFile << "    isnull: " << t->isnull << "\n";
		fsFile << "    isenum: " << t->isenum << "\n";
		fsFile << "    isvarargs: " << t->isvarargs << "\n";
		fsFile << "    func_ptr_lev: " << t->func_ptr_lev << "\n";
		
		// Optional: print func_ret_type if available
		if (t->isfunction && t->func_ret_type) {
			fsFile << "    func_ret_type.base: " << t->func_ret_type->base << "\n";
		}

	}

        /*tacFile << "====================== THREE ADDRESS CODE ======================\n\n";*/
        for(int i=0; i<global_code.size(); i++){
            tacFile << setw(4) << right << i << ": " << global_code[i] << "\n";
        }
        tacFile.close();
        cout << "Three address code written to '" << tacOutputFile << "'" << endl;
    }

	
    return 0;
}
