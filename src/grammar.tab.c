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
#line 53 "grammar.y"

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



#line 101 "grammar.tab.c"

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
  YYSYMBOL_CASE = 53,                      /* CASE  */
  YYSYMBOL_DEFAULT = 54,                   /* DEFAULT  */
  YYSYMBOL_IF = 55,                        /* IF  */
  YYSYMBOL_ELSE = 56,                      /* ELSE  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_WHILE = 58,                     /* WHILE  */
  YYSYMBOL_DO = 59,                        /* DO  */
  YYSYMBOL_FOR = 60,                       /* FOR  */
  YYSYMBOL_GOTO = 61,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 62,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 63,                     /* BREAK  */
  YYSYMBOL_RETURN = 64,                    /* RETURN  */
  YYSYMBOL_CLASS = 65,                     /* CLASS  */
  YYSYMBOL_DELETE = 66,                    /* DELETE  */
  YYSYMBOL_NEW = 67,                       /* NEW  */
  YYSYMBOL_PRIVATE = 68,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 69,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 70,                 /* PROTECTED  */
  YYSYMBOL_THIS = 71,                      /* THIS  */
  YYSYMBOL_UNTIL = 72,                     /* UNTIL  */
  YYSYMBOL_BOOL = 73,                      /* BOOL  */
  YYSYMBOL_TRUE = 74,                      /* TRUE  */
  YYSYMBOL_FALSE = 75,                     /* FALSE  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* '['  */
  YYSYMBOL_79_ = 79,                       /* ']'  */
  YYSYMBOL_80_ = 80,                       /* '.'  */
  YYSYMBOL_81_ = 81,                       /* ','  */
  YYSYMBOL_82_ = 82,                       /* '&'  */
  YYSYMBOL_83_ = 83,                       /* '*'  */
  YYSYMBOL_84_ = 84,                       /* '+'  */
  YYSYMBOL_85_ = 85,                       /* '-'  */
  YYSYMBOL_86_ = 86,                       /* '~'  */
  YYSYMBOL_87_ = 87,                       /* '!'  */
  YYSYMBOL_88_ = 88,                       /* '/'  */
  YYSYMBOL_89_ = 89,                       /* '%'  */
  YYSYMBOL_90_ = 90,                       /* '<'  */
  YYSYMBOL_91_ = 91,                       /* '>'  */
  YYSYMBOL_92_ = 92,                       /* '^'  */
  YYSYMBOL_93_ = 93,                       /* '|'  */
  YYSYMBOL_94_ = 94,                       /* '?'  */
  YYSYMBOL_95_ = 95,                       /* ':'  */
  YYSYMBOL_96_ = 96,                       /* '='  */
  YYSYMBOL_97_ = 97,                       /* ';'  */
  YYSYMBOL_98_ = 98,                       /* '{'  */
  YYSYMBOL_99_ = 99,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_primary_expression = 101,       /* primary_expression  */
  YYSYMBOL_class_name = 102,               /* class_name  */
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
  YYSYMBOL_class_specifier = 139,          /* class_specifier  */
  YYSYMBOL_inheritance_specifier = 140,    /* inheritance_specifier  */
  YYSYMBOL_base_class_list = 141,          /* base_class_list  */
  YYSYMBOL_base_class = 142,               /* base_class  */
  YYSYMBOL_access_specifier = 143,         /* access_specifier  */
  YYSYMBOL_class_body = 144,               /* class_body  */
  YYSYMBOL_class_member_declaration_list = 145, /* class_member_declaration_list  */
  YYSYMBOL_constructor_declaration = 146,  /* constructor_declaration  */
  YYSYMBOL_class_member_declaration = 147, /* class_member_declaration  */
  YYSYMBOL_member_declaration = 148,       /* member_declaration  */
  YYSYMBOL_enum_specifier = 149,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 150,          /* enumerator_list  */
  YYSYMBOL_enumerator = 151,               /* enumerator  */
  YYSYMBOL_type_qualifier = 152,           /* type_qualifier  */
  YYSYMBOL_declarator = 153,               /* declarator  */
  YYSYMBOL_direct_declarator = 154,        /* direct_declarator  */
  YYSYMBOL_pointer = 155,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 156,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 157,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 158,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 159,    /* parameter_declaration  */
  YYSYMBOL_type_name = 160,                /* type_name  */
  YYSYMBOL_abstract_declarator = 161,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 162, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 163,              /* initializer  */
  YYSYMBOL_initializer_list = 164,         /* initializer_list  */
  YYSYMBOL_statement = 165,                /* statement  */
  YYSYMBOL_delete_statement = 166,         /* delete_statement  */
  YYSYMBOL_labeled_statement = 167,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 168,       /* compound_statement  */
  YYSYMBOL_declaration_list = 169,         /* declaration_list  */
  YYSYMBOL_statement_list = 170,           /* statement_list  */
  YYSYMBOL_expression_statement = 171,     /* expression_statement  */
  YYSYMBOL_selection_statement = 172,      /* selection_statement  */
  YYSYMBOL_m = 173,                        /* m  */
  YYSYMBOL_crb = 174,                      /* crb  */
  YYSYMBOL_els = 175,                      /* els  */
  YYSYMBOL_iteration_statement = 176,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 177,           /* jump_statement  */
  YYSYMBOL_translation_unit = 178,         /* translation_unit  */
  YYSYMBOL_external_declaration = 179,     /* external_declaration  */
  YYSYMBOL_function_declaration = 180,     /* function_declaration  */
  YYSYMBOL_function_definition = 181       /* function_definition  */
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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1568

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  401

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
       2,     2,     2,    87,     2,     2,     2,    89,    82,     2,
      76,    77,    83,    84,    81,    85,    80,    88,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    95,    97,
      90,    96,    91,    94,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    98,    93,    99,    86,     2,     2,     2,
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
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   195,   195,   196,   197,   198,   199,   200,   201,   202,
     206,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     222,   226,   227,   228,   229,   230,   231,   235,   236,   237,
     238,   239,   240,   244,   245,   249,   250,   252,   254,   259,
     260,   262,   267,   268,   270,   276,   277,   279,   282,   285,
     291,   292,   295,   300,   301,   307,   308,   313,   314,   319,
     322,   331,   332,   338,   339,   343,   344,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   362,   363,
     367,   373,   374,   383,   386,   387,   388,   389,   390,   394,
     395,   399,   400,   404,   405,   406,   407,   408,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     428,   430,   431,   433,   437,   440,   443,   446,   450,   451,
     455,   459,   460,   461,   462,   466,   467,   471,   477,   478,
     479,   483,   487,   488,   492,   493,   497,   498,   499,   503,
     504,   507,   510,   511,   515,   516,   521,   522,   523,   527,
     528,   533,   534,   538,   539,   543,   544,   548,   549,   554,
     555,   559,   560,   561,   562,   563,   565,   569,   570,   571,
     572,   576,   577,   582,   583,   587,   588,   592,   603,   604,
     608,   609,   610,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   626,   627,   628,   629,   630,   634,   635,   639,
     640,   641,   642,   643,   644,   645,   649,   650,   654,   655,
     656,   660,   661,   662,   663,   667,   668,   672,   673,   677,
     678,   682,   686,   692,   695,   698,   701,   703,   704,   705,
     706,   707,   711,   712,   713,   714,   715,   718,   719,   723,
     724,   727,   731
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
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "NULL_TOKEN", "CASE", "DEFAULT",
  "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "CLASS", "DELETE", "NEW", "PRIVATE", "PUBLIC",
  "PROTECTED", "THIS", "UNTIL", "BOOL", "TRUE", "FALSE", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "class_name",
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
  "struct_declarator", "class_specifier", "inheritance_specifier",
  "base_class_list", "base_class", "access_specifier", "class_body",
  "class_member_declaration_list", "constructor_declaration",
  "class_member_declaration", "member_declaration", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "delete_statement",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement", "m",
  "crb", "els", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-267)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-242)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1503,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,    56,    59,
    -267,    29,  1503,  1503,  -267,    65,    86,  -267,  -267,  1503,
     857,  -267,    13,  -267,    51,  -267,   -15,  -267,    11,   -18,
    -267,   -39,  -267,    69,   -29,    30,  -267,  -267,    61,    64,
      70,    88,  -267,  -267,  -267,   353,  -267,    93,    16,   527,
     102,  -267,   147,  -267,  -267,   -18,    11,  -267,   876,  1335,
     926,   -29,   871,   871,   130,  -267,  -267,  -267,  -267,  -267,
    1103,  1188,  1188,  -267,  1200,   140,   137,   163,   165,   757,
     169,   243,   150,   151,   780,    12,   173,   942,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,   204,   345,  1200,
    -267,   -17,    71,   190,    25,   189,   168,   159,   161,   240,
       1,  -267,  -267,   -36,  -267,    29,  -267,  -267,  -267,  -267,
     450,   547,  -267,  -267,  -267,  -267,   164,   -56,  -267,  -267,
    -267,  -267,  -267,   180,  -267,   260,  -267,   192,    11,  1503,
      11,   171,   624,  -267,  -267,  -267,  1503,  -267,  -267,  -267,
    -267,  -267,  -267,   174,  -267,    59,   876,  -267,  -267,  -267,
      11,   194,   188,  -267,  -267,  -267,  -267,   193,   871,  1178,
    -267,    11,   871,  1251,   757,   942,  -267,  1200,  -267,  -267,
     178,   757,  1200,  1200,  1200,   218,   136,   181,  -267,  -267,
    -267,   182,  -267,   198,  1200,   -21,   -26,   208,   278,  -267,
    -267,   964,  1200,   283,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  1200,  -267,  1200,  1200,  1200,
    1200,  1200,  1200,  1200,  1200,  1200,  1200,  1200,  1200,  1200,
    1200,  1200,  1200,  -267,  -267,  1200,  1200,  -267,  -267,  -267,
     644,  -267,  -267,  1200,    93,  -267,    16,  -267,  1380,  -267,
    -267,   191,  -267,  -267,  -267,  -267,   211,  -267,   -45,  -267,
    -267,  1470,  -267,  -267,  -267,   -33,  -267,  -267,  -267,  -267,
     214,   757,  -267,    -8,    -7,    -2,   216,   136,  -267,  -267,
     291,     0,  -267,  1284,   992,   114,  -267,   115,  1200,  -267,
    -267,    36,  -267,   118,  -267,  -267,  -267,  -267,  -267,   -17,
     -17,    71,    71,   190,   190,   190,   190,    25,    25,   189,
     168,   159,  1200,  1200,   -42,  -267,  -267,  -267,  -267,  -267,
      13,    42,  -267,  1049,   672,  -267,  -267,  -267,    11,  -267,
    -267,  -267,  -267,   757,   757,   757,  1200,  1077,  -267,   757,
    -267,   219,   220,  -267,   223,   115,  1425,  1091,  -267,  -267,
    1200,  -267,   161,   240,  1200,  -267,    13,  1503,  -267,    43,
    -267,  -267,  -267,   239,  -267,  -267,    48,   757,    77,  -267,
    -267,  -267,  -267,  -267,   226,  -267,   225,  -267,  -267,  -267,
    -267,  -267,   757,   212,  -267,   757,  -267,  -267,  -267,  -267,
    -267
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      93,    94,    95,    96,    97,    99,   100,   101,   102,   105,
     106,   103,   104,   157,   158,    98,   116,   117,     0,     0,
     240,     0,    83,    85,   107,     0,     0,   108,   109,    87,
      93,   237,     0,   239,   152,    10,   130,   161,     0,   167,
      81,     0,    89,    91,   160,     0,    84,    86,   111,     0,
     113,     0,    88,     1,   238,     0,   242,     0,     0,    93,
       0,   128,     0,   171,   169,   168,     0,    82,     0,    93,
       0,   159,     0,     0,     2,     3,     4,     6,     5,     7,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,    31,    32,   219,   211,    11,    21,    33,     0,
      35,    39,    42,    45,    50,    53,    55,    57,    59,    61,
      63,    65,    78,     0,   215,     0,   217,   205,   199,   200,
       0,     0,   201,   202,   203,   204,   155,     0,   153,   135,
     137,   136,   138,   131,   132,     0,   140,     0,     0,    85,
       0,     0,    93,   148,   142,   147,    87,   149,   129,   162,
     172,   170,    90,    91,     2,     0,     0,   192,    92,   166,
       0,     0,   173,   175,   164,    33,    80,     0,   122,     0,
     118,     0,   124,     0,     0,     0,    25,     0,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,   206,     0,     0,     0,   178,     0,     0,    17,
      18,     0,     0,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    67,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,   224,     0,     0,   220,   213,   216,
       0,   212,   218,     0,     0,   151,     0,   134,    93,   241,
     121,     0,   146,   139,   143,   123,     0,   197,     0,   177,
     165,    93,   163,   110,   119,     0,   125,   127,   112,   208,
       0,     0,   210,     0,     0,     0,     0,     0,   232,   236,
       0,     0,     8,    93,     0,   180,   179,   181,     0,    16,
      13,     0,    19,     0,    15,    66,    36,    37,    38,    40,
      41,    43,    44,    48,    49,    46,    47,    51,    52,    54,
      56,    58,     0,     0,     0,    79,   214,   156,   154,   133,
       0,     0,   150,     0,     0,   193,   174,   176,     0,   120,
      26,   209,   225,     0,     0,     0,     0,     0,   207,     0,
     188,     0,     0,   184,     0,   182,    93,     0,    34,    14,
       0,    12,    60,    62,     0,   145,     0,    93,   196,     0,
     194,   198,   126,   221,   223,   227,     0,     0,     0,   228,
     189,   183,   185,   190,     0,   186,     0,    20,    64,   144,
     195,   226,     0,     0,   230,     0,   191,   187,   222,   229,
     231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,  -267,   -12,  -267,   -16,   -58,  -267,   -96,   -22,     5,
    -100,   -28,    72,    74,    78,   -11,     2,  -267,   -64,   -59,
    -267,   -94,   -68,   -38,     8,  -267,   247,  -267,   170,  -267,
    -267,  -267,  -267,  -267,   248,  -101,   158,  -267,   -14,  -267,
    -267,  -267,    60,   -49,   263,  -267,  -267,   175,  -267,  -267,
    -267,    75,    49,   -20,   285,   -10,  -267,  -247,    73,  -266,
     143,    39,    38,   -90,  -267,   -87,  -267,  -267,   -32,  -267,
     205,  -185,  -267,    94,  -267,  -267,  -267,  -267,  -267,   307,
    -267,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   106,   147,   107,   301,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     225,   123,   177,    20,   170,    41,    42,    22,    23,    24,
      49,    51,    25,    26,   179,   180,   181,   275,   276,    27,
      60,   143,   144,   145,    61,   152,   153,   154,   155,    28,
     137,   138,    29,   163,    44,    45,    65,   171,   172,   173,
     207,   296,   297,   168,   268,   126,   127,   128,   129,   130,
     131,   132,   133,   322,   343,   392,   134,   135,    30,    31,
      32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    43,   195,   205,   201,   337,   176,    36,    21,   167,
     151,   287,   175,   226,    37,   202,   190,   124,    62,   139,
     176,   244,   186,   188,   189,   254,   175,    13,    14,    64,
      46,    47,    37,    37,   157,   167,   334,    52,    21,   246,
     234,   235,    66,   255,   252,   246,   351,    69,   338,    70,
     293,   175,   294,   364,   335,   161,   292,    39,    67,    34,
     246,   247,    35,   125,   339,    39,   227,   148,    48,   342,
     344,   228,   229,   246,   246,   345,   267,   349,   274,   246,
      58,   246,   274,    59,   140,   141,   142,    38,    63,    50,
     203,   205,   249,   205,    39,   245,   136,   279,   283,   284,
     285,   337,   347,   151,   282,    38,    38,   167,   156,   384,
     291,    55,    39,   359,   160,   236,   237,   360,   303,   366,
     390,   182,   182,   367,   360,   393,    40,   157,   259,   246,
     261,   306,   307,   308,   313,   314,   315,   316,   125,   164,
      75,    76,    77,    78,    79,    80,   182,    81,    82,    57,
     269,   324,   302,   266,   395,   230,   231,    47,   246,  -114,
     148,   277,    72,   252,    52,    68,   305,  -241,  -115,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   327,    73,   325,    83,   176,
     293,   356,   294,   357,   341,   175,   295,   361,   156,   246,
      59,   156,   358,   232,   233,   156,   238,   239,   309,   310,
     317,   318,    97,   192,   208,   209,   210,   150,    98,    99,
     100,   101,   102,   103,   159,   184,   354,   182,   182,   149,
     176,   182,   182,   104,   182,   191,   175,   311,   312,   193,
     175,   194,   178,   178,   371,   196,   197,   198,   199,   204,
     240,   241,   376,   378,   242,   206,   373,   374,   375,   243,
     253,   256,   379,   257,   175,   175,   262,   178,   258,   271,
      68,   270,   272,   281,   302,   167,   286,   290,   288,   289,
     211,   299,   212,   295,   213,   298,   304,   333,   332,   386,
     394,   340,   346,   176,   348,   391,   380,   381,   365,   175,
     388,   387,   382,   396,   397,   398,   175,   260,   400,   399,
     150,   362,   319,   162,   265,   320,   329,   369,   277,   149,
     321,   183,   149,   158,   372,   363,   149,   264,   280,   328,
      71,   331,   352,   355,   389,   250,   260,    54,   323,     0,
     265,     0,     0,   206,     0,     0,     0,     0,   178,   178,
       0,     0,   178,   178,     0,   178,    74,    75,    76,    77,
      78,    79,    80,     0,    81,    82,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,    83,    84,    85,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    19,    95,
       0,     0,     0,     0,     0,    96,     0,     0,     0,    97,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   224,     0,     0,     0,     0,     0,     0,     0,     0,
     104,    55,   105,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,    83,    84,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    19,    95,     0,     0,     0,
       0,     0,    96,     0,     0,     0,    97,     0,     0,     0,
      35,     0,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,    55,   248,
      74,    75,    76,    77,    78,    79,    80,     0,    81,    82,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,   140,   141,   142,     0,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,     0,     0,     0,    96,
       0,     0,     0,    97,     0,     0,   146,    35,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,    55,   251,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   164,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,    19,
       0,     0,   140,   141,   142,     0,    83,    84,    85,    86,
       0,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,     0,     0,     0,    96,     0,     0,     0,
      97,     0,     0,   263,    83,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   165,
       0,   104,    55,   326,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
      74,    75,    76,    77,    78,    79,    80,     0,    81,    82,
     166,   370,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,     0,     0,     0,    96,
       0,     0,    83,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,   165,     0,     0,
       0,     0,     0,     0,   104,    55,    97,    53,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   166,   164,
      75,    76,    77,    78,    79,    80,     0,    81,    82,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    83,   164,
      75,    76,    77,    78,    79,    80,    19,    81,    82,     0,
       0,     0,     0,   165,     0,   164,    75,    76,    77,    78,
      79,    80,    97,    81,    82,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   164,    75,    76,
      77,    78,    79,    80,   166,    81,    82,     0,    83,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,    83,   164,    75,    76,    77,    78,
      79,    80,    97,    81,    82,   174,     0,    19,    98,    99,
     100,   101,   102,   103,     0,     0,    83,     0,    97,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,   300,     0,     0,    83,     0,    98,    99,   100,   101,
     102,   103,   164,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,    97,     0,
       0,   353,     0,     0,    98,    99,   100,   101,   102,   103,
     164,    75,    76,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,     0,   164,    75,    76,    77,    78,    79,
      80,    83,    81,    82,     0,     0,   164,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,   368,     0,     0,    83,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,   377,    83,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,    97,     0,     0,
     385,     0,     0,    98,    99,   100,   101,   102,   103,   185,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   164,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,   164,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,    97,   273,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
     278,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   350,   294,     0,     0,     0,     0,    39,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      32,    21,    89,    97,    94,   271,    70,    19,     0,    68,
      59,   196,    70,   109,     3,     3,    84,    55,    38,     3,
      84,    20,    80,    81,    82,    81,    84,    45,    46,    39,
      22,    23,     3,     3,    59,    94,    81,    29,    30,    81,
      15,    16,    81,    99,   131,    81,   293,    76,    81,    78,
      76,   109,    78,    95,    99,    65,    77,    83,    97,     3,
      81,    97,     3,    55,    97,    83,    83,    59,     3,    77,
      77,    88,    89,    81,    81,    77,   166,    77,   179,    81,
      95,    81,   183,    98,    68,    69,    70,    76,    39,     3,
      78,   185,   130,   187,    83,    94,     3,   184,   192,   193,
     194,   367,   287,   152,   191,    76,    76,   166,    59,   356,
     204,    98,    83,    77,    65,    90,    91,    81,   212,    77,
      77,    72,    73,    81,    81,    77,    97,   152,   148,    81,
     150,   227,   228,   229,   234,   235,   236,   237,   130,     3,
       4,     5,     6,     7,     8,     9,    97,    11,    12,    98,
     170,   245,   211,   165,    77,    84,    85,   149,    81,    98,
     152,   181,    98,   250,   156,    96,   225,    98,    98,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   253,    98,   246,    52,   253,
      76,    76,    78,    78,   281,   253,   206,    79,   149,    81,
      98,   152,   298,    13,    14,   156,    17,    18,   230,   231,
     238,   239,    76,    76,    10,    11,    12,    59,    82,    83,
      84,    85,    86,    87,    77,    95,   294,   178,   179,    59,
     294,   182,   183,    97,   185,    95,   294,   232,   233,    76,
     298,    76,    72,    73,   334,    76,     3,    97,    97,    76,
      82,    92,   346,   347,    93,    97,   343,   344,   345,    19,
      96,    81,   349,     3,   322,   323,    95,    97,    76,    81,
      96,    77,    79,    95,   333,   334,    58,    79,    97,    97,
      76,     3,    78,   293,    80,    77,     3,    76,    97,   357,
     377,    77,    76,   357,     3,    56,    77,    77,   330,   357,
     364,   360,    79,    77,    79,   392,   364,   149,   395,    97,
     152,   322,   240,    66,   156,   241,   256,   333,   338,   149,
     242,    73,   152,    60,   338,   323,   156,   152,   185,   254,
      45,   258,   293,   295,   366,   130,   178,    30,   244,    -1,
     182,    -1,    -1,   185,    -1,    -1,    -1,    -1,   178,   179,
      -1,    -1,   182,   183,    -1,   185,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
       3,    -1,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    99,     3,    -1,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    70,    -1,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    99,    52,    -1,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    97,    98,    99,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    52,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    76,     0,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    65,    -1,    -1,    -1,    -1,    -1,    52,     3,
       4,     5,     6,     7,     8,     9,    65,    11,    12,    -1,
      -1,    -1,    -1,    67,    -1,     3,     4,     5,     6,     7,
       8,     9,    76,    11,    12,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    98,    11,    12,    -1,    52,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    76,    11,    12,    79,    -1,    65,    82,    83,
      84,    85,    86,    87,    -1,    -1,    52,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    52,    -1,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    52,    11,    12,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    52,
      -1,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    52,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    87,    76,    99,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    -1,    83,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    65,
     123,   124,   127,   128,   129,   132,   133,   139,   149,   152,
     178,   179,   180,   181,     3,     3,   102,     3,    76,    83,
      97,   125,   126,   153,   154,   155,   124,   124,     3,   130,
       3,   131,   124,     0,   179,    98,   168,    98,    95,    98,
     140,   144,   153,   152,   155,   156,    81,    97,    96,    76,
      78,   154,    98,    98,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    52,    53,    54,    55,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    72,    76,    82,    83,
      84,    85,    86,    87,    97,    99,   101,   103,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   121,   123,   124,   165,   166,   167,   168,
     169,   170,   171,   172,   176,   177,     3,   150,   151,     3,
      68,    69,    70,   141,   142,   143,    99,   102,   124,   128,
     136,   143,   145,   146,   147,   148,   152,   181,   144,    77,
     152,   155,   126,   153,     3,    67,    98,   119,   163,    77,
     124,   157,   158,   159,    79,   105,   118,   122,   128,   134,
     135,   136,   152,   134,    95,    76,   105,    76,   105,   105,
     122,    95,    76,    76,    76,   165,    76,     3,    97,    97,
      97,   163,     3,    78,    76,   121,   136,   160,    10,    11,
      12,    76,    78,    80,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    96,   120,   107,    83,    88,    89,
      84,    85,    13,    14,    15,    16,    90,    91,    17,    18,
      82,    92,    93,    19,    20,    94,    81,    97,    99,   123,
     170,    99,   165,    96,    81,    99,    81,     3,    76,   153,
     136,   153,    95,    99,   147,   136,   102,   163,   164,   153,
      77,    81,    79,    99,   135,   137,   138,   153,    99,   165,
     160,    95,   165,   121,   121,   121,    58,   171,    97,    97,
      79,   121,    77,    76,    78,   155,   161,   162,    77,     3,
      77,   104,   119,   121,     3,   119,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   112,
     113,   114,   173,   173,   121,   119,    99,   122,   151,   142,
      77,   158,    97,    76,    81,    99,    51,   159,    81,    97,
      77,   165,    77,   174,    77,    77,    76,   171,     3,    77,
      77,   157,   161,    79,   122,   162,    76,    78,   107,    77,
      81,    79,   115,   116,    95,   168,    77,    81,    77,   104,
      99,   163,   138,   165,   165,   165,   121,    77,   121,   165,
      77,    77,    79,    77,   157,    79,   122,   119,   118,   168,
      77,    56,   175,    77,   165,    77,    77,    79,   165,    97,
     165
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     129,   129,   129,   129,   130,   131,   132,   133,   134,   134,
     135,   136,   136,   136,   136,   137,   137,   138,   139,   139,
     139,   140,   141,   141,   142,   142,   143,   143,   143,   144,
     144,   102,   145,   145,   146,   146,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   154,   154,   154,   154,   155,   155,   155,
     155,   156,   156,   157,   157,   158,   158,   159,   160,   160,
     161,   161,   161,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   163,   163,   163,   163,   163,   164,   164,   165,
     165,   165,   165,   165,   165,   165,   166,   166,   167,   167,
     167,   168,   168,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   172,   173,   174,   175,   176,   176,   176,
     176,   176,   177,   177,   177,   177,   177,   178,   178,   179,
     179,   180,   181
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     1,     4,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     5,     2,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     1,     3,     4,
       2,     2,     1,     3,     2,     1,     1,     1,     1,     3,
       2,     1,     1,     2,     5,     4,     2,     1,     1,     1,
       3,     5,     2,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     3,     4,     3,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     5,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     3,     4,
       3,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     0,     1,     1,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     2,     2
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
#line 195 "grammar.y"
                     {Type* t=get_type_id((yyvsp[0].str));cout << t->base << endl;cout << "get type id in primary exp done" << endl;Symbol_Info* x=get_symbol_info_id((yyvsp[0].str));if(x->tempname.empty()){string nn=get_new_temp();x->tempname=nn;final_symtab[nn]=x;}t->place=x->tempname;(yyval.typ)=t;}
#line 1822 "grammar.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 196 "grammar.y"
                   {Type* t=new Type(); t->isbasic=true;t->base="INT";string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1828 "grammar.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 197 "grammar.y"
                         {Type* t=new Type(); t->isbasic=true;t->base="CHAR";t->ptr_level=1;t->ptrtql.emplace_back(false,false);string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1834 "grammar.tab.c"
    break;

  case 5: /* primary_expression: CONST_CHAR  */
#line 198 "grammar.y"
                     {Type* t=new Type(); t->isbasic=true;t->base="CHAR";(yyval.typ)=t;string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1840 "grammar.tab.c"
    break;

  case 6: /* primary_expression: CONST_FLOAT  */
#line 199 "grammar.y"
                      {Type* t=new Type();t->isbasic=true;t->base="FLOAT";(yyval.typ)=t;string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1846 "grammar.tab.c"
    break;

  case 7: /* primary_expression: CONST_EXP  */
#line 200 "grammar.y"
                    {Type* t=get_type_exp((yyvsp[0].str));string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1852 "grammar.tab.c"
    break;

  case 8: /* primary_expression: '(' expression ')'  */
#line 201 "grammar.y"
                             {Type* t=(yyvsp[-1].typ);string nn=get_new_temp();t->place=nn;t->truelist=(yyvsp[-1].typ)->truelist;t->falselist=(yyvsp[-1].typ)->falselist;(yyval.typ)=t;}
#line 1858 "grammar.tab.c"
    break;

  case 9: /* primary_expression: NULL_TOKEN  */
#line 202 "grammar.y"
                     {Type* t=new Type();t->isnull=true;string nn=get_new_temp();t->place=nn;(yyval.typ)=t;}
#line 1864 "grammar.tab.c"
    break;

  case 10: /* class_name: IDENTIFIER  */
#line 206 "grammar.y"
                            { cout<<"IDENTIFIER will be passed to CN"<<endl;(yyval.str) = (yyvsp[0].str); string s="class "; s+=(yyvsp[0].str);lvl_name.push(s);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str), nullptr) );cout<<"identifier passed to class_name"<<endl; }
#line 1870 "grammar.tab.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 210 "grammar.y"
                             {(yyval.typ)=(yyvsp[0].typ);}
#line 1876 "grammar.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 211 "grammar.y"
                                                {check_if_array_or_pointer((yyvsp[-3].typ));(yyval.typ)=(yyvsp[-3].typ);}
#line 1882 "grammar.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 212 "grammar.y"
                                     {Type* t=check_if_function((yyvsp[-2].typ));check_argument_with_params((yyvsp[-2].typ)->prms,vector<Type*>());(yyval.typ)=t;}
#line 1888 "grammar.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 213 "grammar.y"
                                                              {Type* t=check_if_function((yyvsp[-3].typ));check_argument_with_params((yyvsp[-3].typ)->prms,(yyvsp[-1].arg_ex_list)->vec_exp);(yyval.typ)=t;}
#line 1894 "grammar.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 214 "grammar.y"
                                            {check_if_obj((yyvsp[-2].typ));Type* type=check_if_id_in_obj((yyvsp[-2].typ),(yyvsp[0].str));(yyval.typ)=type;(yyval.typ)=type;}
#line 1900 "grammar.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 215 "grammar.y"
                                               {check_if_obj_ptr((yyvsp[-2].typ));Type* type=check_if_id_in_obj((yyvsp[-2].typ),(yyvsp[0].str));(yyval.typ)=type;}
#line 1906 "grammar.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression INC_OP  */
#line 216 "grammar.y"
                                                {check_inc_dec_op((yyvsp[-1].typ));(yyval.typ)=(yyvsp[-1].typ);}
#line 1912 "grammar.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DEC_OP  */
#line 217 "grammar.y"
                                    {check_inc_dec_op((yyvsp[-1].typ));(yyval.typ)=(yyvsp[-1].typ);}
#line 1918 "grammar.tab.c"
    break;

  case 19: /* argument_expression_list: assignment_expression  */
#line 221 "grammar.y"
                                {Argument_Expression_List* z=new Argument_Expression_List();z->vec_exp.push_back((yyvsp[0].typ));(yyval.arg_ex_list)=z;backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 1924 "grammar.tab.c"
    break;

  case 20: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 222 "grammar.y"
                                                             {(yyvsp[-2].arg_ex_list)->vec_exp.push_back((yyvsp[0].typ));(yyval.arg_ex_list)=(yyvsp[-2].arg_ex_list);backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 1930 "grammar.tab.c"
    break;

  case 21: /* unary_expression: postfix_expression  */
#line 226 "grammar.y"
                             {(yyval.typ)=(yyvsp[0].typ);}
#line 1936 "grammar.tab.c"
    break;

  case 22: /* unary_expression: INC_OP unary_expression  */
#line 227 "grammar.y"
                                                                                                {check_inc_dec_op((yyvsp[0].typ));(yyval.typ)=(yyvsp[0].typ);}
#line 1942 "grammar.tab.c"
    break;

  case 23: /* unary_expression: DEC_OP unary_expression  */
#line 228 "grammar.y"
                                   {check_inc_dec_op((yyvsp[0].typ));(yyval.typ)=(yyvsp[0].typ);}
#line 1948 "grammar.tab.c"
    break;

  case 24: /* unary_expression: unary_operator cast_expression  */
#line 229 "grammar.y"
                                         {Type* type=get_type_unary_expression((yyvsp[-1].str),(yyvsp[0].typ));(yyval.typ)=type;cout<<"got &"<<endl;}
#line 1954 "grammar.tab.c"
    break;

  case 25: /* unary_expression: SIZEOF unary_expression  */
#line 230 "grammar.y"
                                  {check_for_sizeof((yyvsp[0].typ)); Type* t=new Type(); t->isbasic=true; t->base="INT";(yyval.typ)=t;}
#line 1960 "grammar.tab.c"
    break;

  case 26: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 231 "grammar.y"
                                   {check_for_sizeof((yyvsp[-1].ty_nm)->type);Type* t=new Type();t->isbasic=true;t->base="INT";(yyval.typ)=t;}
#line 1966 "grammar.tab.c"
    break;

  case 27: /* unary_operator: '&'  */
#line 235 "grammar.y"
              {(yyval.str)="&";}
#line 1972 "grammar.tab.c"
    break;

  case 28: /* unary_operator: '*'  */
#line 236 "grammar.y"
              {(yyval.str)="*";}
#line 1978 "grammar.tab.c"
    break;

  case 29: /* unary_operator: '+'  */
#line 237 "grammar.y"
              {(yyval.str)="+";}
#line 1984 "grammar.tab.c"
    break;

  case 30: /* unary_operator: '-'  */
#line 238 "grammar.y"
              {(yyval.str)="-";}
#line 1990 "grammar.tab.c"
    break;

  case 31: /* unary_operator: '~'  */
#line 239 "grammar.y"
              {(yyval.str)="~";}
#line 1996 "grammar.tab.c"
    break;

  case 32: /* unary_operator: '!'  */
#line 240 "grammar.y"
              {(yyval.str)="!";}
#line 2002 "grammar.tab.c"
    break;

  case 33: /* cast_expression: unary_expression  */
#line 244 "grammar.y"
                           {(yyval.typ)=(yyvsp[0].typ);}
#line 2008 "grammar.tab.c"
    break;

  case 34: /* cast_expression: '(' type_name ')' cast_expression  */
#line 245 "grammar.y"
                                            {check_typecast_compatibility((yyvsp[-2].ty_nm)->type,(yyvsp[0].typ));(yyval.typ)=(yyvsp[-2].ty_nm)->type;}
#line 2014 "grammar.tab.c"
    break;

  case 35: /* multiplicative_expression: cast_expression  */
#line 249 "grammar.y"
                          {(yyval.typ)=(yyvsp[0].typ);}
#line 2020 "grammar.tab.c"
    break;

  case 36: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 250 "grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"*",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2027 "grammar.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 252 "grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"/",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2034 "grammar.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 254 "grammar.y"
                                                        {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"%",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2041 "grammar.tab.c"
    break;

  case 39: /* additive_expression: multiplicative_expression  */
#line 259 "grammar.y"
                                    {(yyval.typ)=(yyvsp[0].typ);}
#line 2047 "grammar.tab.c"
    break;

  case 40: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 260 "grammar.y"
                                                            {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"+",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2054 "grammar.tab.c"
    break;

  case 41: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 262 "grammar.y"
                                                            {Type* type=check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();
		type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"-",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2061 "grammar.tab.c"
    break;

  case 42: /* shift_expression: additive_expression  */
#line 267 "grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2067 "grammar.tab.c"
    break;

  case 43: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 268 "grammar.y"
                                                        {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<<",nn);
		merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);type->place=nn;(yyval.typ)=type;}
#line 2074 "grammar.tab.c"
    break;

  case 44: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 270 "grammar.y"
                                                        {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">>",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;}
#line 2082 "grammar.tab.c"
    break;

  case 45: /* relational_expression: shift_expression  */
#line 276 "grammar.y"
                           {(yyval.typ)=(yyvsp[0].typ);}
#line 2088 "grammar.tab.c"
    break;

  case 46: /* relational_expression: relational_expression '<' shift_expression  */
#line 277 "grammar.y"
                                                     {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2095 "grammar.tab.c"
    break;

  case 47: /* relational_expression: relational_expression '>' shift_expression  */
#line 279 "grammar.y"
                                                     {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2103 "grammar.tab.c"
    break;

  case 48: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 282 "grammar.y"
                                                       {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"<=",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2111 "grammar.tab.c"
    break;

  case 49: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 285 "grammar.y"
                                                       {check_for_arithmatic_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=new Type();type->isbasic=true;
		type->base="INT";string nn=get_new_temp();type->place=nn;string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,">=",nn);
		merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2119 "grammar.tab.c"
    break;

  case 50: /* equality_expression: relational_expression  */
#line 291 "grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ);}
#line 2125 "grammar.tab.c"
    break;

  case 51: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 292 "grammar.y"
                                                          {Type* type=check_for_eq_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"==",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);;(yyval.typ)=type;}
#line 2133 "grammar.tab.c"
    break;

  case 52: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 295 "grammar.y"
                                                          {Type* type=check_for_eq_op((yyvsp[-2].typ),(yyvsp[0].typ));string nn=get_new_temp();type->place=nn;
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"!=",nn);merge_code(type->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);(yyval.typ)=type;}
#line 2140 "grammar.tab.c"
    break;

  case 53: /* and_expression: equality_expression  */
#line 300 "grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 2146 "grammar.tab.c"
    break;

  case 54: /* and_expression: and_expression '&' equality_expression  */
#line 301 "grammar.y"
                                                 {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"&",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;(yyval.typ)=type;}
#line 2154 "grammar.tab.c"
    break;

  case 55: /* exclusive_or_expression: and_expression  */
#line 307 "grammar.y"
                         {(yyval.typ)=(yyvsp[0].typ);}
#line 2160 "grammar.tab.c"
    break;

  case 56: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 308 "grammar.y"
                                                     {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"^",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);type->place=nn;(yyval.typ)=type;}
#line 2167 "grammar.tab.c"
    break;

  case 57: /* inclusive_or_expression: exclusive_or_expression  */
#line 313 "grammar.y"
                                  {(yyval.typ)=(yyvsp[0].typ);}
#line 2173 "grammar.tab.c"
    break;

  case 58: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 314 "grammar.y"
                                                              {check_for_shift_op((yyvsp[-2].typ),(yyvsp[0].typ));Type* type=(yyvsp[-2].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-2].typ)->place,(yyvsp[0].typ)->place,"|",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);global_code.push_back(cod);type->place=nn;(yyval.typ)=type;}
#line 2180 "grammar.tab.c"
    break;

  case 59: /* logical_and_expression: inclusive_or_expression  */
#line 319 "grammar.y"
                                  {cout << "logical end done" << endl;Type* type=(yyvsp[0].typ);
		type->truelist.push_back(global_code.size());type->falselist.push_back(global_code.size()+1);
		global_code.push_back(get_if_true_code(type->place));global_code.push_back(get_if_false_code());(yyval.typ)=type;}
#line 2188 "grammar.tab.c"
    break;

  case 60: /* logical_and_expression: logical_and_expression AND_OP m inclusive_or_expression  */
#line 322 "grammar.y"
                                                                  {check_for_shift_op((yyvsp[-3].typ),(yyvsp[0].typ));Type* type=(yyvsp[-3].typ);string nn=get_new_temp();
		string cod=get_code4((yyvsp[-3].typ)->place,(yyvsp[0].typ)->place,"&&",nn);merge_code1(type->code,(yyvsp[0].typ)->code);type->code.push_back(cod);
		(yyvsp[0].typ)->truelist.push_back(global_code.size());(yyvsp[0].typ)->falselist.push_back(global_code.size()+1);
		global_code.push_back(get_if_true_code((yyvsp[0].typ)->place));global_code.push_back(get_if_false_code());
		global_code.push_back(cod);type->place=nn;
		backpatch(type->truelist,(yyvsp[-1].int_value));type->falselist=merge(type->falselist,(yyvsp[0].typ)->falselist);type->truelist=(yyvsp[0].typ)->truelist;(yyval.typ)=type;}
#line 2199 "grammar.tab.c"
    break;

  case 61: /* logical_or_expression: logical_and_expression  */
#line 331 "grammar.y"
                                 {(yyval.typ)=(yyvsp[0].typ);}
#line 2205 "grammar.tab.c"
    break;

  case 62: /* logical_or_expression: logical_or_expression OR_OP m logical_and_expression  */
#line 332 "grammar.y"
                                                               { cout << "logical or done" << endl;check_for_shift_op((yyvsp[-3].typ),(yyvsp[0].typ));Type* type=(yyvsp[-3].typ);string nn=get_new_temp();string cod=get_code4((yyvsp[-3].typ)->place,(yyvsp[0].typ)->place,"||",nn);merge_code1(type->code,(yyvsp[0].typ)->code);
		type->code.push_back(cod);global_code.push_back(cod);type->place=nn;
		backpatch(type->falselist,(yyvsp[-1].int_value));type->truelist=merge(type->truelist,(yyvsp[0].typ)->truelist);type->falselist=(yyvsp[0].typ)->falselist;(yyval.typ)=type;}
#line 2213 "grammar.tab.c"
    break;

  case 63: /* conditional_expression: logical_or_expression  */
#line 338 "grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ);}
#line 2219 "grammar.tab.c"
    break;

  case 64: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 339 "grammar.y"
                                                                            {Type* type=check_for_assign((yyvsp[-2].typ),(yyvsp[0].typ),"=");(yyval.typ)=type;}
#line 2225 "grammar.tab.c"
    break;

  case 65: /* assignment_expression: conditional_expression  */
#line 343 "grammar.y"
                                  {(yyval.typ)=(yyvsp[0].typ); }
#line 2231 "grammar.tab.c"
    break;

  case 66: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 344 "grammar.y"
                                                                      {Type* t=check_for_assign((yyvsp[-2].typ),(yyvsp[0].typ),(yyvsp[-1].str));merge_code(t->code,(yyvsp[-2].typ)->code,(yyvsp[0].typ)->code);string cod=get_code4((yyvsp[0].typ)->place,"","",(yyvsp[-2].typ)->place);global_code.push_back(cod);(yyval.typ)=t;
		backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 2238 "grammar.tab.c"
    break;

  case 67: /* assignment_operator: '='  */
#line 348 "grammar.y"
              {(yyval.str)="=";}
#line 2244 "grammar.tab.c"
    break;

  case 68: /* assignment_operator: MUL_ASSIGN  */
#line 349 "grammar.y"
                     {(yyval.str)="*=";}
#line 2250 "grammar.tab.c"
    break;

  case 69: /* assignment_operator: DIV_ASSIGN  */
#line 350 "grammar.y"
                     {(yyval.str)="/=";}
#line 2256 "grammar.tab.c"
    break;

  case 70: /* assignment_operator: MOD_ASSIGN  */
#line 351 "grammar.y"
                     {(yyval.str)="%=";}
#line 2262 "grammar.tab.c"
    break;

  case 71: /* assignment_operator: ADD_ASSIGN  */
#line 352 "grammar.y"
                     {(yyval.str)="+=";}
#line 2268 "grammar.tab.c"
    break;

  case 72: /* assignment_operator: SUB_ASSIGN  */
#line 353 "grammar.y"
                     {(yyval.str)="-=";}
#line 2274 "grammar.tab.c"
    break;

  case 73: /* assignment_operator: LEFT_ASSIGN  */
#line 354 "grammar.y"
                      {(yyval.str)="<<=";}
#line 2280 "grammar.tab.c"
    break;

  case 74: /* assignment_operator: RIGHT_ASSIGN  */
#line 355 "grammar.y"
                       {(yyval.str)=">>=";}
#line 2286 "grammar.tab.c"
    break;

  case 75: /* assignment_operator: AND_ASSIGN  */
#line 356 "grammar.y"
                     {(yyval.str)="&=";}
#line 2292 "grammar.tab.c"
    break;

  case 76: /* assignment_operator: XOR_ASSIGN  */
#line 357 "grammar.y"
                     {(yyval.str)="^=";}
#line 2298 "grammar.tab.c"
    break;

  case 77: /* assignment_operator: OR_ASSIGN  */
#line 358 "grammar.y"
                    {(yyval.str)="|=";}
#line 2304 "grammar.tab.c"
    break;

  case 78: /* expression: assignment_expression  */
#line 362 "grammar.y"
                                {(yyval.typ)=(yyvsp[0].typ); cout<<"finally expression has identifier"<<endl;}
#line 2310 "grammar.tab.c"
    break;

  case 79: /* expression: expression ',' assignment_expression  */
#line 363 "grammar.y"
                                               {Type* t=new Type();(yyval.typ)=t;backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 2316 "grammar.tab.c"
    break;

  case 80: /* constant_expression: conditional_expression  */
#line 367 "grammar.y"
                                 {(yyval.typ)=(yyvsp[0].typ);}
#line 2322 "grammar.tab.c"
    break;

  case 81: /* declaration: declaration_specifiers ';'  */
#line 373 "grammar.y"
                                     {(yyval.declaration)=create_declaration_object((yyvsp[-1].dec_spec),nullptr,nullptr);}
#line 2328 "grammar.tab.c"
    break;

  case 82: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 374 "grammar.y"
                                                          {(yyval.declaration)=create_declaration_object((yyvsp[-2].dec_spec),(yyvsp[-1].init_dec_list),nullptr);current_params_list.clear();cout << "current params list cleared" << endl;}
#line 2334 "grammar.tab.c"
    break;

  case 83: /* declaration_specifiers: storage_class_specifier  */
#line 383 "grammar.y"
                                  {Declaration_Specifiers* ds=create_decl_spec_object(); if(ds==nullptr){assert(0);}
	ds->scs.push_back((yyvsp[0].str));
	(yyval.dec_spec)=ds;}
#line 2342 "grammar.tab.c"
    break;

  case 84: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 386 "grammar.y"
                                                         {Declaration_Specifiers* ds=(yyvsp[0].dec_spec);ds->scs.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;cout << "declaration specifier done scs" << endl;}
#line 2348 "grammar.tab.c"
    break;

  case 85: /* declaration_specifiers: type_specifier  */
#line 387 "grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back((yyvsp[0].type_spec));(yyval.dec_spec)=ds;cout << ds->ts.back()->string_type << endl;cout<<"got type specifier"<<endl;}
#line 2354 "grammar.tab.c"
    break;

  case 86: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 388 "grammar.y"
                                                {cout<<"declaration_specifier started"<<endl;Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->ts.push_back((yyvsp[-1].type_spec));(yyval.dec_spec)=ds;cout<<"declaration specifier completed"<<endl;}
#line 2360 "grammar.tab.c"
    break;

  case 87: /* declaration_specifiers: type_qualifier  */
#line 389 "grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back((yyvsp[0].str));(yyval.dec_spec)=ds;}
#line 2366 "grammar.tab.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 390 "grammar.y"
                                                {Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->tq.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;}
#line 2372 "grammar.tab.c"
    break;

  case 89: /* init_declarator_list: init_declarator  */
#line 394 "grammar.y"
                          {Init_Declarator_List* x=new Init_Declarator_List();x->idl.push_back((yyvsp[0].dec));(yyval.init_dec_list)=x;cout<<"idl completeted"<<endl;}
#line 2378 "grammar.tab.c"
    break;

  case 90: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 395 "grammar.y"
                                                   { (yyvsp[-2].init_dec_list)->idl.push_back((yyvsp[0].dec)); (yyval.init_dec_list) = (yyvsp[-2].init_dec_list);}
#line 2384 "grammar.tab.c"
    break;

  case 91: /* init_declarator: declarator  */
#line 399 "grammar.y"
                     {(yyval.dec)=(yyvsp[0].dec);}
#line 2390 "grammar.tab.c"
    break;

  case 92: /* init_declarator: declarator '=' initializer  */
#line 400 "grammar.y"
                                     {cout<<"init_declartor started"<<endl;(yyvsp[-2].dec)->ini=(yyvsp[0].ini);(yyval.dec)=(yyvsp[-2].dec);cout<<"init_declarator done"<<endl;}
#line 2396 "grammar.tab.c"
    break;

  case 94: /* storage_class_specifier: EXTERN  */
#line 405 "grammar.y"
                 {(yyval.str)="EXTERN";}
#line 2402 "grammar.tab.c"
    break;

  case 95: /* storage_class_specifier: STATIC  */
#line 406 "grammar.y"
                 {(yyval.str)="STATIC";cout << "STATIC" << endl;}
#line 2408 "grammar.tab.c"
    break;

  case 96: /* storage_class_specifier: AUTO  */
#line 407 "grammar.y"
               {(yyval.str)="AUTO";}
#line 2414 "grammar.tab.c"
    break;

  case 97: /* storage_class_specifier: REGISTER  */
#line 408 "grammar.y"
                   {(yyval.str)="REGISTER";}
#line 2420 "grammar.tab.c"
    break;

  case 98: /* type_specifier: VOID  */
#line 412 "grammar.y"
           { (yyval.type_spec) = create_ts_obj(std::string("VOID"), nullptr, nullptr, nullptr); }
#line 2426 "grammar.tab.c"
    break;

  case 99: /* type_specifier: CHAR  */
#line 413 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("CHAR",nullptr,nullptr,nullptr);}
#line 2432 "grammar.tab.c"
    break;

  case 100: /* type_specifier: SHORT  */
#line 414 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("SHORT",nullptr,nullptr,nullptr);}
#line 2438 "grammar.tab.c"
    break;

  case 101: /* type_specifier: INT  */
#line 415 "grammar.y"
              {(yyval.type_spec)=create_ts_obj("INT",nullptr,nullptr,nullptr);cout<<"INT Passed"<<endl;}
#line 2444 "grammar.tab.c"
    break;

  case 102: /* type_specifier: LONG  */
#line 416 "grammar.y"
               {(yyval.type_spec)=create_ts_obj("LONG",nullptr,nullptr,nullptr);}
#line 2450 "grammar.tab.c"
    break;

  case 103: /* type_specifier: FLOAT  */
#line 417 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("FLOAT",nullptr,nullptr,nullptr);}
#line 2456 "grammar.tab.c"
    break;

  case 104: /* type_specifier: DOUBLE  */
#line 418 "grammar.y"
                 {(yyval.type_spec)=create_ts_obj("DOUBLE",nullptr,nullptr,nullptr);}
#line 2462 "grammar.tab.c"
    break;

  case 105: /* type_specifier: SIGNED  */
#line 419 "grammar.y"
                 {(yyval.type_spec)=create_ts_obj("SIGNED",nullptr,nullptr,nullptr);}
#line 2468 "grammar.tab.c"
    break;

  case 106: /* type_specifier: UNSIGNED  */
#line 420 "grammar.y"
                   {(yyval.type_spec)=create_ts_obj("UNSIGNED",nullptr,nullptr,nullptr);cout<<"hurrah"<<endl;}
#line 2474 "grammar.tab.c"
    break;

  case 107: /* type_specifier: struct_or_union_specifier  */
#line 421 "grammar.y"
                                    {cout<<"struct_or_union_specifier found"<<endl;(yyval.type_spec)=create_ts_obj("",(yyvsp[0].str_union),nullptr,nullptr);}
#line 2480 "grammar.tab.c"
    break;

  case 108: /* type_specifier: class_specifier  */
#line 422 "grammar.y"
                      {cout<<"completed class specifier"<<endl;(yyval.type_spec)=create_ts_obj("",nullptr,(yyvsp[0].class_spec),nullptr);}
#line 2486 "grammar.tab.c"
    break;

  case 109: /* type_specifier: enum_specifier  */
#line 423 "grammar.y"
                         {(yyval.type_spec)=create_ts_obj("",nullptr,nullptr,(yyvsp[0].enum_spec));}
#line 2492 "grammar.tab.c"
    break;

  case 110: /* struct_or_union_specifier: struct struct_id '{' struct_declaration_list '}'  */
#line 428 "grammar.y"
                                                            { (yyval.str_union)=create_struct_union_spec_obj(std::string((yyvsp[-4].str)),std::string((yyvsp[-3].str)),(yyvsp[-1].struc_dec_list)); current_level--; current_table=current_table->get_parent(); lvl_name.pop();add_to_local_class_struct_union_info(); }
#line 2498 "grammar.tab.c"
    break;

  case 111: /* struct_or_union_specifier: struct IDENTIFIER  */
#line 430 "grammar.y"
                            {cout<<"struct identifier reached"<<endl;check_if_declared(current_table,(yyvsp[0].str),"struct");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);}
#line 2504 "grammar.tab.c"
    break;

  case 112: /* struct_or_union_specifier: union union_id '{' struct_declaration_list '}'  */
#line 431 "grammar.y"
                                                         {(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].struc_dec_list));current_level--;current_table=current_table->get_parent();lvl_name.pop();add_to_local_class_struct_union_info();}
#line 2510 "grammar.tab.c"
    break;

  case 113: /* struct_or_union_specifier: union IDENTIFIER  */
#line 433 "grammar.y"
                           {check_if_declared(current_table,(yyvsp[0].str),"union");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);/* whether this identifier is declared before use */}
#line 2516 "grammar.tab.c"
    break;

  case 114: /* struct_id: IDENTIFIER  */
#line 437 "grammar.y"
                     {lvl_name.push("struct " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str),nullptr));cout<<"got struct identifier"<<endl;}
#line 2522 "grammar.tab.c"
    break;

  case 115: /* union_id: IDENTIFIER  */
#line 440 "grammar.y"
                     {lvl_name.push("union " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str),nullptr));}
#line 2528 "grammar.tab.c"
    break;

  case 116: /* struct: STRUCT  */
#line 443 "grammar.y"
                                {(yyval.str)="STRUCT";cout <<"finally reached to struct"<<endl;}
#line 2534 "grammar.tab.c"
    break;

  case 117: /* union: UNION  */
#line 446 "grammar.y"
                {(yyval.str)="UNION";}
#line 2540 "grammar.tab.c"
    break;

  case 118: /* struct_declaration_list: struct_declaration  */
#line 450 "grammar.y"
                             {current_level++;Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;current_table=next_table(current_table);add_to_local_table(current_table,(yyvsp[0].struc_dec));if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}}
#line 2546 "grammar.tab.c"
    break;

  case 119: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 451 "grammar.y"
                                                     {Struct_Declaration_List* x=(yyvsp[-1].struc_dec_list);x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;add_to_local_table(current_table,(yyvsp[0].struc_dec));}
#line 2552 "grammar.tab.c"
    break;

  case 120: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 455 "grammar.y"
                                                             {cout<<"struct declaration started"<<endl;(yyval.struc_dec)=create_struct_dec_obj((yyvsp[-2].sql),(yyvsp[-1].sdl));cout<<"struct declaration done"<<endl;}
#line 2558 "grammar.tab.c"
    break;

  case 121: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 459 "grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->ts.push_back((yyvsp[-1].type_spec));}
#line 2564 "grammar.tab.c"
    break;

  case 122: /* specifier_qualifier_list: type_specifier  */
#line 460 "grammar.y"
                         {cout<<"type spec in sql started"<<endl;Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->ts.push_back((yyvsp[0].type_spec));cout<<"type spec in sql ended"<<endl;}
#line 2570 "grammar.tab.c"
    break;

  case 123: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 461 "grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->tq.push_back((yyvsp[-1].str));}
#line 2576 "grammar.tab.c"
    break;

  case 124: /* specifier_qualifier_list: type_qualifier  */
#line 462 "grammar.y"
                         {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->tq.push_back((yyvsp[0].str));}
#line 2582 "grammar.tab.c"
    break;

  case 125: /* struct_declarator_list: struct_declarator  */
#line 466 "grammar.y"
                             {Struct_Declarator_List* x=new Struct_Declarator_List();x->sd.push_back((yyvsp[0].sd));}
#line 2588 "grammar.tab.c"
    break;

  case 126: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 467 "grammar.y"
                                                        {Struct_Declarator_List* x=(yyvsp[-2].sdl);x->sd.push_back((yyvsp[0].sd));}
#line 2594 "grammar.tab.c"
    break;

  case 127: /* struct_declarator: declarator  */
#line 471 "grammar.y"
                                           {(yyval.sd)=create_struct_declarator_obj((yyvsp[0].dec));}
#line 2600 "grammar.tab.c"
    break;

  case 128: /* class_specifier: CLASS class_name class_body  */
#line 477 "grammar.y"
                                   {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[-1].str)),nullptr,(yyvsp[0].class_mem_dec_list));}
#line 2606 "grammar.tab.c"
    break;

  case 129: /* class_specifier: CLASS class_name inheritance_specifier class_body  */
#line 478 "grammar.y"
                                                        {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[-2].str)),(yyvsp[-1].inh_spec),(yyvsp[0].class_mem_dec_list));}
#line 2612 "grammar.tab.c"
    break;

  case 130: /* class_specifier: CLASS class_name  */
#line 479 "grammar.y"
                           {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[0].str)),nullptr,nullptr);check_if_declared(current_table,std::string((yyvsp[0].str)),"class");}
#line 2618 "grammar.tab.c"
    break;

  case 131: /* inheritance_specifier: ':' base_class_list  */
#line 483 "grammar.y"
                                     {(yyval.inh_spec)=new Inheritance_Specifier((yyvsp[0].bcl));}
#line 2624 "grammar.tab.c"
    break;

  case 132: /* base_class_list: base_class  */
#line 487 "grammar.y"
                                                                     {Base_Class_List* x=new Base_Class_List();x->bc.push_back((yyvsp[0].bc));}
#line 2630 "grammar.tab.c"
    break;

  case 133: /* base_class_list: base_class_list ',' base_class  */
#line 488 "grammar.y"
                                     {Base_Class_List* x=(yyvsp[-2].bcl);x->bc.push_back((yyvsp[0].bc));}
#line 2636 "grammar.tab.c"
    break;

  case 134: /* base_class: access_specifier IDENTIFIER  */
#line 492 "grammar.y"
                                                                            {check_if_declared(current_table,std::string((yyvsp[0].str)),"class");(yyval.bc)=new Base_Class((yyvsp[-1].str),std::string((yyvsp[0].str)));}
#line 2642 "grammar.tab.c"
    break;

  case 135: /* base_class: IDENTIFIER  */
#line 493 "grammar.y"
                 {check_if_declared(current_table,(yyvsp[0].str),"class");(yyval.bc)=new Base_Class("",std::string((yyvsp[0].str)));}
#line 2648 "grammar.tab.c"
    break;

  case 136: /* access_specifier: PUBLIC  */
#line 497 "grammar.y"
                        {(yyval.str)="PUBLIC";}
#line 2654 "grammar.tab.c"
    break;

  case 137: /* access_specifier: PRIVATE  */
#line 498 "grammar.y"
              {(yyval.str)="PRIVATE";}
#line 2660 "grammar.tab.c"
    break;

  case 138: /* access_specifier: PROTECTED  */
#line 499 "grammar.y"
                {(yyval.str)="PROTECTED";}
#line 2666 "grammar.tab.c"
    break;

  case 139: /* class_body: '{' class_member_declaration_list '}'  */
#line 503 "grammar.y"
                                            {(yyval.class_mem_dec_list)=(yyvsp[-1].class_mem_dec_list); current_level--;current_table=current_table->get_parent();lvl_name.pop();while(!access_spec_stk.empty())access_spec_stk.pop();add_to_local_class_struct_union_info();}
#line 2672 "grammar.tab.c"
    break;

  case 140: /* class_body: '{' '}'  */
#line 504 "grammar.y"
              {lvl_name.pop();add_to_local_class_struct_union_info();}
#line 2678 "grammar.tab.c"
    break;

  case 141: /* class_name: IDENTIFIER  */
#line 507 "grammar.y"
                            { (yyval.str) = (yyvsp[0].str); string s="class "; s+=(yyvsp[0].str);lvl_name.push(s);current_class_struct_union_info.push(std::make_pair((yyvsp[0].str), nullptr) ); }
#line 2684 "grammar.tab.c"
    break;

  case 142: /* class_member_declaration_list: class_member_declaration  */
#line 510 "grammar.y"
                               {Class_Member_Declaration_List* x=new Class_Member_Declaration_List();x->cd.push_back((yyvsp[0].class_mem_dec));current_level++;current_table=next_table(current_table);if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}}
#line 2690 "grammar.tab.c"
    break;

  case 143: /* class_member_declaration_list: class_member_declaration_list class_member_declaration  */
#line 511 "grammar.y"
                                                             { (yyvsp[-1].class_mem_dec_list)->cd.push_back((yyvsp[0].class_mem_dec)); (yyval.class_mem_dec_list) = (yyvsp[-1].class_mem_dec_list);}
#line 2696 "grammar.tab.c"
    break;

  case 144: /* constructor_declaration: class_name '(' parameter_list ')' compound_statement  */
#line 515 "grammar.y"
                                                          {current_params_list.clear();add_params_to_map((yyvsp[-2].pl));(yyval.constrdec)=new Constructor_Declaration(std::string((yyvsp[-4].str)),(yyvsp[-2].pl),(yyvsp[0].comp_stmt));}
#line 2702 "grammar.tab.c"
    break;

  case 145: /* constructor_declaration: class_name '(' ')' compound_statement  */
#line 516 "grammar.y"
                                                {current_params_list.clear();(yyval.constrdec)=new Constructor_Declaration(std::string((yyvsp[-3].str)),nullptr,(yyvsp[0].comp_stmt));}
#line 2708 "grammar.tab.c"
    break;

  case 146: /* class_member_declaration: access_specifier ':'  */
#line 521 "grammar.y"
                           {access_spec_stk.push((yyvsp[-1].str));}
#line 2714 "grammar.tab.c"
    break;

  case 147: /* class_member_declaration: member_declaration  */
#line 522 "grammar.y"
                         {(yyval.class_mem_dec)=new Class_Member_Declaration((yyvsp[0].memd),nullptr);}
#line 2720 "grammar.tab.c"
    break;

  case 148: /* class_member_declaration: constructor_declaration  */
#line 523 "grammar.y"
                              {(yyval.class_mem_dec)=new Class_Member_Declaration(nullptr,(yyvsp[0].constrdec));add_to_local_table(current_table,(yyvsp[0].constrdec));}
#line 2726 "grammar.tab.c"
    break;

  case 149: /* member_declaration: function_definition  */
#line 527 "grammar.y"
                              {(yyval.memd)=new Member_Declaration(nullptr,nullptr,(yyvsp[0].fun_def));add_to_local_table(current_table,(yyvsp[0].fun_def));}
#line 2732 "grammar.tab.c"
    break;

  case 150: /* member_declaration: specifier_qualifier_list declarator ';'  */
#line 528 "grammar.y"
                                              {(yyval.memd)=new Member_Declaration((yyvsp[-2].sql),(yyvsp[-1].dec),nullptr);add_to_local_table(current_table,(yyvsp[-2].sql),(yyvsp[-1].dec));}
#line 2738 "grammar.tab.c"
    break;

  case 151: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 533 "grammar.y"
                                                  {(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[-3].str)),(yyvsp[-1].enuml));Type* t=new Type();t->isenum=true;t->isobj=true;t->obj_class=(yyvsp[-3].str);t->objtype="enum";add_to_local_table((yyvsp[-1].enuml),t);}
#line 2744 "grammar.tab.c"
    break;

  case 152: /* enum_specifier: ENUM IDENTIFIER  */
#line 534 "grammar.y"
                          {(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[0].str)),nullptr);check_if_declared(current_table,std::string((yyvsp[0].str)),"enum");}
#line 2750 "grammar.tab.c"
    break;

  case 153: /* enumerator_list: enumerator  */
#line 538 "grammar.y"
                     {Enumerator_List* x=new Enumerator_List();x->e.push_back((yyvsp[0].enumer));}
#line 2756 "grammar.tab.c"
    break;

  case 154: /* enumerator_list: enumerator_list ',' enumerator  */
#line 539 "grammar.y"
                                         {Enumerator_List* x=(yyvsp[-2].enuml);x->e.push_back((yyvsp[0].enumer));}
#line 2762 "grammar.tab.c"
    break;

  case 155: /* enumerator: IDENTIFIER  */
#line 543 "grammar.y"
                     {(yyval.enumer)=new Enumerator(std::string((yyvsp[0].str)),nullptr);}
#line 2768 "grammar.tab.c"
    break;

  case 156: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 544 "grammar.y"
                                             {(yyval.enumer)=new Enumerator(std::string((yyvsp[-2].str)),(yyvsp[0].typ));check_int_comp((yyvsp[0].typ));}
#line 2774 "grammar.tab.c"
    break;

  case 157: /* type_qualifier: CONST  */
#line 548 "grammar.y"
                 {(yyval.str)="CONST";}
#line 2780 "grammar.tab.c"
    break;

  case 158: /* type_qualifier: VOLATILE  */
#line 549 "grammar.y"
                   {(yyval.str)="VOLATILE";}
#line 2786 "grammar.tab.c"
    break;

  case 159: /* declarator: pointer direct_declarator  */
#line 554 "grammar.y"
                                    {(yyval.dec)=create_new_declarator((yyvsp[-1].point),(yyvsp[0].dir_dec));cout<<"got pointer direct declarator"<<endl;}
#line 2792 "grammar.tab.c"
    break;

  case 160: /* declarator: direct_declarator  */
#line 555 "grammar.y"
                            {(yyval.dec)=create_new_declarator(nullptr,(yyvsp[0].dir_dec));cout<<"##"<<endl;}
#line 2798 "grammar.tab.c"
    break;

  case 161: /* direct_declarator: IDENTIFIER  */
#line 559 "grammar.y"
                     {(yyval.dir_dec)=create_direct_declarator(std::string("id"),(yyvsp[0].str),nullptr,nullptr,nullptr,nullptr);}
#line 2804 "grammar.tab.c"
    break;

  case 162: /* direct_declarator: '(' declarator ')'  */
#line 560 "grammar.y"
                             {(yyval.dir_dec)=create_direct_declarator(std::string("declarator"),"",(yyvsp[-1].dec),nullptr,nullptr,nullptr);}
#line 2810 "grammar.tab.c"
    break;

  case 163: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 561 "grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,nullptr);check_int_comp((yyvsp[-1].typ));}
#line 2816 "grammar.tab.c"
    break;

  case 164: /* direct_declarator: direct_declarator '[' ']'  */
#line 562 "grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2822 "grammar.tab.c"
    break;

  case 165: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 563 "grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,(yyvsp[-1].pl));}
#line 2828 "grammar.tab.c"
    break;

  case 166: /* direct_declarator: direct_declarator '(' ')'  */
#line 565 "grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2834 "grammar.tab.c"
    break;

  case 167: /* pointer: '*'  */
#line 569 "grammar.y"
              {(yyval.point)=new Pointer(nullptr,nullptr);}
#line 2840 "grammar.tab.c"
    break;

  case 168: /* pointer: '*' type_qualifier_list  */
#line 570 "grammar.y"
                                  {(yyval.point)=new Pointer((yyvsp[0].tql),nullptr);}
#line 2846 "grammar.tab.c"
    break;

  case 169: /* pointer: '*' pointer  */
#line 571 "grammar.y"
                      {(yyval.point)=new Pointer(nullptr,(yyvsp[0].point));}
#line 2852 "grammar.tab.c"
    break;

  case 170: /* pointer: '*' type_qualifier_list pointer  */
#line 572 "grammar.y"
                                          {(yyval.point)=new Pointer((yyvsp[-1].tql),(yyvsp[0].point));}
#line 2858 "grammar.tab.c"
    break;

  case 171: /* type_qualifier_list: type_qualifier  */
#line 576 "grammar.y"
                         {Type_Qualifier_List* x=new Type_Qualifier_List();x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2864 "grammar.tab.c"
    break;

  case 172: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 577 "grammar.y"
                                             {Type_Qualifier_List* x=(yyvsp[-1].tql);x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2870 "grammar.tab.c"
    break;

  case 173: /* parameter_type_list: parameter_list  */
#line 582 "grammar.y"
                         {(yyval.pl)=(yyvsp[0].pl);}
#line 2876 "grammar.tab.c"
    break;

  case 174: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 583 "grammar.y"
                                      {Parameter_List* x=(yyvsp[-2].pl); x->ellipses=true;}
#line 2882 "grammar.tab.c"
    break;

  case 175: /* parameter_list: parameter_declaration  */
#line 587 "grammar.y"
                                {Parameter_List* x=new Parameter_List();x->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=x;}
#line 2888 "grammar.tab.c"
    break;

  case 176: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 588 "grammar.y"
                                                   {(yyvsp[-2].pl)->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=(yyvsp[-2].pl);}
#line 2894 "grammar.tab.c"
    break;

  case 177: /* parameter_declaration: declaration_specifiers declarator  */
#line 592 "grammar.y"
                                            {(yyval.par_dec)=new Parameter_Declaration((yyvsp[-1].dec_spec),(yyvsp[0].dec));}
#line 2900 "grammar.tab.c"
    break;

  case 178: /* type_name: specifier_qualifier_list  */
#line 603 "grammar.y"
                                    { (yyval.ty_nm)=new Type_Name((yyvsp[0].sql),nullptr);}
#line 2906 "grammar.tab.c"
    break;

  case 179: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 604 "grammar.y"
                                                       {(yyval.ty_nm)=new Type_Name((yyvsp[-1].sql),(yyvsp[0].abs_d));(yyvsp[0].abs_d)->type=(yyvsp[0].abs_d)->check_abstract_declarator();}
#line 2912 "grammar.tab.c"
    break;

  case 180: /* abstract_declarator: pointer  */
#line 608 "grammar.y"
                  {Abstract_Declarator* x=new Abstract_Declarator((yyvsp[0].point),nullptr);(yyval.abs_d)=x;}
#line 2918 "grammar.tab.c"
    break;

  case 181: /* abstract_declarator: direct_abstract_declarator  */
#line 609 "grammar.y"
                                     {Abstract_Declarator* x=new Abstract_Declarator(nullptr,(yyvsp[0].dir_ad));(yyval.abs_d)=x;}
#line 2924 "grammar.tab.c"
    break;

  case 182: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 610 "grammar.y"
                                             {Abstract_Declarator* x=new Abstract_Declarator((yyvsp[-1].point),(yyvsp[0].dir_ad));(yyval.abs_d)=x;}
#line 2930 "grammar.tab.c"
    break;

  case 183: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 614 "grammar.y"
                                      {(yyval.dir_ad)=new Direct_Abstract_Declarator("abs_dec",(yyvsp[-1].abs_d),nullptr,nullptr,nullptr);}
#line 2936 "grammar.tab.c"
    break;

  case 184: /* direct_abstract_declarator: '[' ']'  */
#line 615 "grammar.y"
                                                                {(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,nullptr,nullptr,nullptr);}
#line 2942 "grammar.tab.c"
    break;

  case 185: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 616 "grammar.y"
                                      {check_int_comp((yyvsp[-1].typ));(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,nullptr,(yyvsp[-1].typ),nullptr);}
#line 2948 "grammar.tab.c"
    break;

  case 186: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 617 "grammar.y"
                                             {(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,(yyvsp[-2].dir_ad),nullptr,nullptr);}
#line 2954 "grammar.tab.c"
    break;

  case 187: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 618 "grammar.y"
                                                                 {check_int_comp((yyvsp[-1].typ));(yyval.dir_ad)=new Direct_Abstract_Declarator("array",nullptr,(yyvsp[-3].dir_ad),(yyvsp[-1].typ),nullptr);}
#line 2960 "grammar.tab.c"
    break;

  case 188: /* direct_abstract_declarator: '(' ')'  */
#line 619 "grammar.y"
                        {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,nullptr);}
#line 2966 "grammar.tab.c"
    break;

  case 189: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 620 "grammar.y"
                                       {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,(yyvsp[-1].pl));}
#line 2972 "grammar.tab.c"
    break;

  case 190: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 621 "grammar.y"
                                             {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,(yyvsp[-2].dir_ad),nullptr,nullptr);}
#line 2978 "grammar.tab.c"
    break;

  case 191: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 622 "grammar.y"
                                                                 {(yyval.dir_ad)=new Direct_Abstract_Declarator("func",nullptr,(yyvsp[-3].dir_ad),nullptr,(yyvsp[-1].pl));}
#line 2984 "grammar.tab.c"
    break;

  case 192: /* initializer: assignment_expression  */
#line 626 "grammar.y"
                                 {Initializer* x=new Initializer((yyvsp[0].typ),"",nullptr,"",nullptr);x->type=(yyvsp[0].typ);(yyval.ini)=x;backpatch((yyvsp[0].typ)->truelist,global_code.size());backpatch((yyvsp[0].typ)->falselist,global_code.size());}
#line 2990 "grammar.tab.c"
    break;

  case 193: /* initializer: '{' initializer_list '}'  */
#line 627 "grammar.y"
                                   {(yyval.ini)=new Initializer(new Type(),"",(yyvsp[-1].ini_lst),"",nullptr);}
#line 2996 "grammar.tab.c"
    break;

  case 194: /* initializer: '{' initializer_list ',' '}'  */
#line 628 "grammar.y"
                                       {(yyval.ini)=new Initializer(new Type(),"",(yyvsp[-2].ini_lst),"",nullptr);}
#line 3002 "grammar.tab.c"
    break;

  case 195: /* initializer: NEW class_name '(' argument_expression_list ')'  */
#line 629 "grammar.y"
                                                          {Type* t=get_type_id((yyvsp[-3].str));check_if_constructor(t);check_argument_with_params(t->prms,(yyvsp[-1].arg_ex_list)->vec_exp);Type* z=new Type();z->isobj=true;z->objtype="class";z->obj_class=(yyvsp[-3].str);Initializer* gg=new Initializer(z,"",nullptr,(yyvsp[-3].str),(yyvsp[-1].arg_ex_list));(yyval.ini)=gg;}
#line 3008 "grammar.tab.c"
    break;

  case 196: /* initializer: NEW class_name '(' ')'  */
#line 630 "grammar.y"
                                 {Type* t=get_type_id((yyvsp[-2].str));check_if_constructor(t);check_argument_with_params(t->prms,vector<Type*>());Type*z=new Type();z->isobj=true;z->objtype=="class";z->obj_class=(yyvsp[-2].str);Initializer* gg=new Initializer(z,"",nullptr,(yyvsp[-2].str),nullptr);(yyval.ini)=gg;}
#line 3014 "grammar.tab.c"
    break;

  case 197: /* initializer_list: initializer  */
#line 634 "grammar.y"
                      {Initializer_List* x=new Initializer_List();x->iv.push_back((yyvsp[0].ini));(yyval.ini_lst)=x;}
#line 3020 "grammar.tab.c"
    break;

  case 198: /* initializer_list: initializer_list ',' initializer  */
#line 635 "grammar.y"
                                           {(yyvsp[-2].ini_lst)->iv.push_back((yyvsp[0].ini));(yyval.ini_lst)=(yyvsp[-2].ini_lst);}
#line 3026 "grammar.tab.c"
    break;

  case 199: /* statement: labeled_statement  */
#line 639 "grammar.y"
                            {(yyval.typ)=(yyvsp[0].typ);}
#line 3032 "grammar.tab.c"
    break;

  case 200: /* statement: compound_statement  */
#line 640 "grammar.y"
                             {(yyval.typ)=(yyvsp[0].comp_stmt)->st;cout<<"finally statement has compound statement"<<endl;}
#line 3038 "grammar.tab.c"
    break;

  case 201: /* statement: expression_statement  */
#line 641 "grammar.y"
                               {(yyval.typ)=(yyvsp[0].typ);}
#line 3044 "grammar.tab.c"
    break;

  case 202: /* statement: selection_statement  */
#line 642 "grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 3050 "grammar.tab.c"
    break;

  case 203: /* statement: iteration_statement  */
#line 643 "grammar.y"
                              {(yyval.typ)=(yyvsp[0].typ);}
#line 3056 "grammar.tab.c"
    break;

  case 204: /* statement: jump_statement  */
#line 644 "grammar.y"
                         {(yyval.typ)=(yyvsp[0].typ);}
#line 3062 "grammar.tab.c"
    break;

  case 205: /* statement: delete_statement  */
#line 645 "grammar.y"
                           {}
#line 3068 "grammar.tab.c"
    break;

  case 206: /* delete_statement: DELETE IDENTIFIER  */
#line 649 "grammar.y"
                            {check_if_pointer(get_type_id((yyvsp[0].str)));}
#line 3074 "grammar.tab.c"
    break;

  case 207: /* delete_statement: DELETE '[' ']' IDENTIFIER  */
#line 650 "grammar.y"
                                    {check_if_array(get_type_id((yyvsp[0].str)));}
#line 3080 "grammar.tab.c"
    break;

  case 208: /* labeled_statement: IDENTIFIER ':' statement  */
#line 654 "grammar.y"
                                   {if(labelset.find((yyvsp[-2].str))==labelset.end())labelset.insert((yyvsp[-2].str));else {cout << "label declared twice" << endl;exit(1);}(yyval.typ)=(yyvsp[0].typ);}
#line 3086 "grammar.tab.c"
    break;

  case 209: /* labeled_statement: CASE constant_expression ':' statement  */
#line 655 "grammar.y"
                                                 {(yyval.typ)=(yyvsp[0].typ);}
#line 3092 "grammar.tab.c"
    break;

  case 210: /* labeled_statement: DEFAULT ':' statement  */
#line 656 "grammar.y"
                                {cout<<"finally reached to default"<<endl;(yyval.typ)=(yyvsp[0].typ);}
#line 3098 "grammar.tab.c"
    break;

  case 211: /* compound_statement: '{' '}'  */
#line 660 "grammar.y"
                  {Compound_Statement* x=new Compound_Statement(new Type(),nullptr);(yyval.comp_stmt)=x;}
#line 3104 "grammar.tab.c"
    break;

  case 212: /* compound_statement: '{' statement_list '}'  */
#line 661 "grammar.y"
                                 {Compound_Statement* x=new Compound_Statement((yyvsp[-1].typ),nullptr);cout<<"obj of compound statement done for st_lst"<<endl; cout<<"loop completed"<<endl;(yyval.comp_stmt)=x;cout<<"statement_list done in compound_statement"<<endl;}
#line 3110 "grammar.tab.c"
    break;

  case 213: /* compound_statement: '{' declaration_list '}'  */
#line 662 "grammar.y"
                                   {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),(yyvsp[-1].dec_list));cout << "compound_statement parsed" << endl;current_level--;current_table->get_parent();(yyval.comp_stmt)=x;}
#line 3116 "grammar.tab.c"
    break;

  case 214: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 663 "grammar.y"
                                                  {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),(yyvsp[-2].dec_list));current_level--;current_table->get_parent();(yyval.comp_stmt)=x;cout << "compound_statement parsed" << endl;}
#line 3122 "grammar.tab.c"
    break;

  case 215: /* declaration_list: declaration  */
#line 667 "grammar.y"
                      {current_level++;cout << "checking for next table" << endl;Declaration_List* x=new Declaration_List();x->dv.push_back((yyvsp[0].declaration));current_table=next_table(current_table);cout << "next table working fine" << endl;add_to_local_table(current_table,(yyvsp[0].declaration));cout << "declaration list done successfully" << endl;(yyval.dec_list)=x;}
#line 3128 "grammar.tab.c"
    break;

  case 216: /* declaration_list: declaration_list declaration  */
#line 668 "grammar.y"
                                       {cout<<"declaration_list done"<<endl;(yyvsp[-1].dec_list)->dv.push_back((yyvsp[0].declaration));(yyval.dec_list)=(yyvsp[-1].dec_list);add_to_local_table(current_table,(yyvsp[0].declaration));}
#line 3134 "grammar.tab.c"
    break;

  case 217: /* statement_list: statement  */
#line 672 "grammar.y"
                    { cout << "statement parsed" << endl;(yyval.typ)=(yyvsp[0].typ);}
#line 3140 "grammar.tab.c"
    break;

  case 218: /* statement_list: statement_list statement  */
#line 673 "grammar.y"
                                   {(yyval.typ)=(yyvsp[0].typ);}
#line 3146 "grammar.tab.c"
    break;

  case 219: /* expression_statement: ';'  */
#line 677 "grammar.y"
              {(yyval.typ)=new Type();cout<<"semi colon"<<endl;}
#line 3152 "grammar.tab.c"
    break;

  case 220: /* expression_statement: expression ';'  */
#line 678 "grammar.y"
                         {(yyval.typ)=new Type();}
#line 3158 "grammar.tab.c"
    break;

  case 221: /* selection_statement: IF '(' expression crb statement  */
#line 682 "grammar.y"
                                          { cout << "other if else done" << endl;
		backpatch((yyvsp[-2].typ)->truelist,(yyvsp[-1].int_value)); Type* zz=new Type();
		zz->nextlist=merge((yyvsp[-2].typ)->falselist, (yyvsp[0].typ)->nextlist);backpatch(zz->nextlist,global_code.size());(yyval.typ)=zz; 
	}
#line 3167 "grammar.tab.c"
    break;

  case 222: /* selection_statement: IF '(' expression crb statement els statement  */
#line 686 "grammar.y"
                                                         {cout << "if_else done" << endl;
		backpatch((yyvsp[-4].typ)->truelist,(yyvsp[-3].int_value));
		backpatch ((yyvsp[-4].typ)->falselist,(yyvsp[-1].int_value));
		Type* zz=new Type(); zz->nextlist=merge((yyvsp[-2].typ)->nextlist,(yyvsp[0].typ)->nextlist);
		backpatch(zz->nextlist,global_code.size()); (yyval.typ)=zz;}
#line 3177 "grammar.tab.c"
    break;

  case 223: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 692 "grammar.y"
                                              {(yyval.typ)=(yyvsp[0].typ);}
#line 3183 "grammar.tab.c"
    break;

  case 224: /* m: %empty  */
#line 695 "grammar.y"
          {(yyval.int_value)=global_code.size();}
#line 3189 "grammar.tab.c"
    break;

  case 225: /* crb: ')'  */
#line 698 "grammar.y"
              {(yyval.int_value)=global_code.size();}
#line 3195 "grammar.tab.c"
    break;

  case 226: /* els: ELSE  */
#line 701 "grammar.y"
               {(yyval.int_value)=global_code.size();}
#line 3201 "grammar.tab.c"
    break;

  case 227: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 703 "grammar.y"
                                             {(yyval.typ)=(yyvsp[0].typ);}
#line 3207 "grammar.tab.c"
    break;

  case 228: /* iteration_statement: UNTIL '(' expression ')' statement  */
#line 704 "grammar.y"
                                             {(yyval.typ)=(yyvsp[0].typ);}
#line 3213 "grammar.tab.c"
    break;

  case 229: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 705 "grammar.y"
                                                    {(yyval.typ)=(yyvsp[-5].typ);}
#line 3219 "grammar.tab.c"
    break;

  case 230: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 706 "grammar.y"
                                                                          {(yyval.typ)=(yyvsp[0].typ);}
#line 3225 "grammar.tab.c"
    break;

  case 231: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 707 "grammar.y"
                                                                                     {(yyval.typ)=(yyvsp[0].typ);}
#line 3231 "grammar.tab.c"
    break;

  case 232: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 711 "grammar.y"
                              {(yyval.typ)=new Type();}
#line 3237 "grammar.tab.c"
    break;

  case 233: /* jump_statement: CONTINUE ';'  */
#line 712 "grammar.y"
                       {(yyval.typ)=new Type();}
#line 3243 "grammar.tab.c"
    break;

  case 234: /* jump_statement: BREAK ';'  */
#line 713 "grammar.y"
                    {(yyval.typ)=new Type();cout<<"found break"<<endl;}
#line 3249 "grammar.tab.c"
    break;

  case 237: /* translation_unit: external_declaration  */
#line 718 "grammar.y"
                               {cout<<"reached ext declaration"<<endl;Node* ext=create_node();cout<<"create node done"<<endl;}
#line 3255 "grammar.tab.c"
    break;

  case 238: /* translation_unit: translation_unit external_declaration  */
#line 719 "grammar.y"
                                                {Node* ext=create_node();}
#line 3261 "grammar.tab.c"
    break;

  case 239: /* external_declaration: function_definition  */
#line 723 "grammar.y"
                               {add_to_gst((yyvsp[0].fun_def),gst);cout<<"add to gst"<<endl;(yyval.node)=(yyvsp[0].fun_def);}
#line 3267 "grammar.tab.c"
    break;

  case 240: /* external_declaration: declaration  */
#line 724 "grammar.y"
                      {add_to_gst((yyvsp[0].declaration),gst);(yyval.node)=(yyvsp[0].declaration);}
#line 3273 "grammar.tab.c"
    break;

  case 241: /* function_declaration: declaration_specifiers declarator  */
#line 727 "grammar.y"
                                            { Function_Declaration* x=new Function_Declaration((yyvsp[-1].dec_spec),(yyvsp[0].dec));Type* type=new Type();string t=create_type((yyvsp[-1].dec_spec),(yyvsp[0].dec),type);cout << "create type for func decl done successfully"<<endl;(yyvsp[0].dec)->check_for_func();cout << "check for func done successfully in func decl" << endl;(yyval.func_decl)=x;func_ret_type=type->func_ret_type ; lvl_name.push(get_name((yyvsp[0].dec)));cout<<"final func decl done huuh"<<endl;}
#line 3279 "grammar.tab.c"
    break;

  case 242: /* function_definition: function_declaration compound_statement  */
#line 731 "grammar.y"
                                                  {Function_Declaration* x=(yyvsp[-1].func_decl);(yyval.fun_def)=create_func_def(x->ds,x->d,(yyvsp[0].comp_stmt));cout<<"create func def done"<< endl;current_params_list.clear();cout << "current params list cleared" << endl;lvl_name.pop();}
#line 3285 "grammar.tab.c"
    break;


#line 3289 "grammar.tab.c"

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

#line 736 "grammar.y"

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
		exit(0);
	}
	ofstream outputFile(outputFileName);
	
	Node* root= new Node();
	gst=new Global_Symbol_Table();
	current_params_list.clear();
	labelset.clear();
	while (!lvl_name.empty()){
    lvl_name.pop();
	}
	current_table=nullptr;
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

	cout << "FINAL SYMTAB: " << endl;
	for(auto i:final_symtab){
		cout << i.first << ":" << endl;
		cout << i.second->name << " " << i.second->type << " " << i.second->level_name << " " << i.second->level << endl;
	}
	cout << "==================================================" << endl;
	cout << endl;
	cout << endl;
	for(int i=0;i<global_code.size();i++){
		cout <<  i << ": " << global_code[i] <<  endl;
	}
	cout << "==================================================" << endl;
    return 0;
}
