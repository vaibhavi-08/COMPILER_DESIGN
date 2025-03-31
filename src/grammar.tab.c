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
#line 43 "grammar.y"

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



#line 100 "grammar.tab.c"

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
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_CLASS = 61,                     /* CLASS  */
  YYSYMBOL_DELETE = 62,                    /* DELETE  */
  YYSYMBOL_NEW = 63,                       /* NEW  */
  YYSYMBOL_PRIVATE = 64,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 65,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 66,                 /* PROTECTED  */
  YYSYMBOL_THIS = 67,                      /* THIS  */
  YYSYMBOL_UNTIL = 68,                     /* UNTIL  */
  YYSYMBOL_BOOL = 69,                      /* BOOL  */
  YYSYMBOL_TRUE = 70,                      /* TRUE  */
  YYSYMBOL_FALSE = 71,                     /* FALSE  */
  YYSYMBOL_72_ = 72,                       /* '('  */
  YYSYMBOL_73_ = 73,                       /* ')'  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_76_ = 76,                       /* '.'  */
  YYSYMBOL_77_ = 77,                       /* ','  */
  YYSYMBOL_78_ = 78,                       /* '&'  */
  YYSYMBOL_79_ = 79,                       /* '*'  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '~'  */
  YYSYMBOL_83_ = 83,                       /* '!'  */
  YYSYMBOL_84_ = 84,                       /* '/'  */
  YYSYMBOL_85_ = 85,                       /* '%'  */
  YYSYMBOL_86_ = 86,                       /* '<'  */
  YYSYMBOL_87_ = 87,                       /* '>'  */
  YYSYMBOL_88_ = 88,                       /* '^'  */
  YYSYMBOL_89_ = 89,                       /* '|'  */
  YYSYMBOL_90_ = 90,                       /* '?'  */
  YYSYMBOL_91_ = 91,                       /* ':'  */
  YYSYMBOL_92_ = 92,                       /* '='  */
  YYSYMBOL_93_ = 93,                       /* ';'  */
  YYSYMBOL_94_ = 94,                       /* '{'  */
  YYSYMBOL_95_ = 95,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_primary_expression = 97,        /* primary_expression  */
  YYSYMBOL_class_name = 98,                /* class_name  */
  YYSYMBOL_postfix_expression = 99,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 100, /* argument_expression_list  */
  YYSYMBOL_argument_list_opt = 101,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 102,            /* argument_list  */
  YYSYMBOL_unary_expression = 103,         /* unary_expression  */
  YYSYMBOL_unary_operator = 104,           /* unary_operator  */
  YYSYMBOL_cast_expression = 105,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 106, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 107,      /* additive_expression  */
  YYSYMBOL_shift_expression = 108,         /* shift_expression  */
  YYSYMBOL_relational_expression = 109,    /* relational_expression  */
  YYSYMBOL_equality_expression = 110,      /* equality_expression  */
  YYSYMBOL_and_expression = 111,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 112,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 113,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 114,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 115,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 116,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 117,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 118,      /* assignment_operator  */
  YYSYMBOL_expression = 119,               /* expression  */
  YYSYMBOL_constant_expression = 120,      /* constant_expression  */
  YYSYMBOL_declaration = 121,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 122,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 123,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 124,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 125,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 126,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 127, /* struct_or_union_specifier  */
  YYSYMBOL_struct_id = 128,                /* struct_id  */
  YYSYMBOL_union_id = 129,                 /* union_id  */
  YYSYMBOL_struct = 130,                   /* struct  */
  YYSYMBOL_union = 131,                    /* union  */
  YYSYMBOL_struct_declaration_list = 132,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 133,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 134, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 135,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 136,        /* struct_declarator  */
  YYSYMBOL_class_specifier = 137,          /* class_specifier  */
  YYSYMBOL_inheritance_specifier = 138,    /* inheritance_specifier  */
  YYSYMBOL_base_class_list = 139,          /* base_class_list  */
  YYSYMBOL_base_class = 140,               /* base_class  */
  YYSYMBOL_access_specifier = 141,         /* access_specifier  */
  YYSYMBOL_class_body = 142,               /* class_body  */
  YYSYMBOL_class_member_declaration_list = 143, /* class_member_declaration_list  */
  YYSYMBOL_constructor_declaration = 144,  /* constructor_declaration  */
  YYSYMBOL_class_member_declaration = 145, /* class_member_declaration  */
  YYSYMBOL_member_declaration = 146,       /* member_declaration  */
  YYSYMBOL_enum_specifier = 147,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 148,          /* enumerator_list  */
  YYSYMBOL_enumerator = 149,               /* enumerator  */
  YYSYMBOL_type_qualifier = 150,           /* type_qualifier  */
  YYSYMBOL_declarator = 151,               /* declarator  */
  YYSYMBOL_direct_declarator = 152,        /* direct_declarator  */
  YYSYMBOL_pointer = 153,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 154,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 155,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 156,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 157,    /* parameter_declaration  */
  YYSYMBOL_type_name = 158,                /* type_name  */
  YYSYMBOL_abstract_declarator = 159,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 160, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 161,              /* initializer  */
  YYSYMBOL_initializer_list = 162,         /* initializer_list  */
  YYSYMBOL_statement = 163,                /* statement  */
  YYSYMBOL_delete_statement = 164,         /* delete_statement  */
  YYSYMBOL_labeled_statement = 165,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 166,       /* compound_statement  */
  YYSYMBOL_declaration_list = 167,         /* declaration_list  */
  YYSYMBOL_statement_list = 168,           /* statement_list  */
  YYSYMBOL_expression_statement = 169,     /* expression_statement  */
  YYSYMBOL_selection_statement = 170,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 171,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 172,           /* jump_statement  */
  YYSYMBOL_translation_unit = 173,         /* translation_unit  */
  YYSYMBOL_external_declaration = 174      /* external_declaration  */
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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


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
       2,     2,     2,    83,     2,     2,     2,    85,    78,     2,
      72,    73,    79,    80,    77,    81,    76,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    89,    95,    82,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   164,   164,   165,   166,   167,   171,   175,   176,   177,
     178,   179,   180,   181,   182,   186,   187,   190,   191,   195,
     196,   199,   200,   201,   202,   203,   204,   208,   209,   210,
     211,   212,   213,   217,   218,   222,   223,   224,   225,   229,
     230,   231,   235,   236,   237,   241,   242,   243,   244,   245,
     249,   250,   251,   255,   256,   260,   261,   265,   266,   270,
     271,   275,   276,   280,   281,   285,   286,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   304,   305,
     309,   315,   316,   325,   326,   327,   328,   329,   330,   334,
     335,   339,   340,   344,   345,   346,   347,   348,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     368,   369,   370,   371,   372,   373,   377,   380,   383,   386,
     390,   391,   395,   399,   400,   401,   402,   406,   407,   411,
     412,   413,   417,   418,   419,   423,   427,   428,   432,   433,
     437,   438,   439,   443,   444,   448,   449,   454,   455,   460,
     461,   462,   466,   471,   472,   473,   477,   478,   482,   483,
     487,   488,   492,   493,   497,   498,   499,   500,   501,   503,
     507,   508,   509,   510,   514,   515,   520,   521,   525,   526,
     530,   541,   542,   546,   547,   548,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   564,   565,   566,   567,   571,
     572,   576,   577,   578,   579,   580,   581,   582,   589,   590,
     594,   595,   596,   600,   601,   602,   603,   607,   608,   612,
     613,   617,   618,   622,   623,   624,   628,   629,   630,   631,
     632,   636,   637,   638,   639,   640,   644,   645,   650
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
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "CLASS", "DELETE",
  "NEW", "PRIVATE", "PUBLIC", "PROTECTED", "THIS", "UNTIL", "BOOL", "TRUE",
  "FALSE", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "class_name", "postfix_expression", "argument_expression_list",
  "argument_list_opt", "argument_list", "unary_expression",
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
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-118)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1324,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,     8,    28,
    -304,    22,  1324,  1324,  -304,    19,    20,  -304,  -304,  1324,
     985,  -304,   -52,    75,  -304,    82,  -304,    11,    -4,  -304,
     -25,  -304,   -46,    62,    21,  -304,  -304,    73,  1352,    84,
      87,  1352,    90,  -304,  -304,  -304,    75,    95,   -42,  -304,
      66,   535,    98,  -304,   158,  -304,  -304,    -4,    11,  -304,
     665,  1192,   775,    62,  1352,  1013,  -304,    27,  1352,  1352,
    1041,  1352,   -14,   856,    75,  -304,  -304,  -304,  -304,  -304,
     159,  -304,   206,  -304,   169,  -304,   155,   580,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   897,
     921,   921,    28,   757,  -304,  -304,  -304,  -304,  -304,  -304,
     665,  -304,   114,   922,   856,  -304,    56,   136,   238,    52,
     132,   165,   164,   166,   244,     1,  -304,  -304,  -304,  -304,
      11,   188,   185,  -304,  -304,  -304,  -304,   189,  -304,  -304,
    -304,   856,   -16,  -304,   174,  -304,  1076,  -304,  1104,  -304,
    -304,  -304,    66,  -304,  1236,  -304,  -304,  -304,   757,  -304,
     856,  -304,  -304,   201,  -304,    34,    38,   203,  -304,     3,
     274,  -304,  -304,   285,   856,   275,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,   856,  -304,   856,
     856,   856,   856,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   856,  -304,  -304,
     920,  -304,  -304,    27,  -304,   856,  -304,  -304,  -304,   187,
      43,   210,   856,  -304,   856,  1142,   802,   151,  -304,   152,
     856,   584,  -304,  -304,  -304,    51,  -304,   157,  -304,  -304,
    -304,  -304,  -304,    56,    56,   136,   136,   238,   238,   238,
     238,    52,    52,   132,   165,   164,   166,   244,    12,  -304,
    -304,  -304,  -304,   266,  -304,   187,  1324,  -304,   211,   202,
    -304,  -304,  -304,   212,   213,  -304,   220,   152,  1280,   816,
    -304,  -304,  -304,  -304,   856,  -304,   856,   196,   856,   223,
     246,   257,   258,   631,   259,   329,   240,   242,   367,    10,
     264,  -304,  -304,    -5,  -304,  -304,  -304,  -304,  -304,   347,
     408,  -304,  -304,  -304,  -304,  -304,  -304,   856,  -304,  -304,
    -304,  -304,   267,  -304,   262,  -304,  -304,   631,   248,   631,
     856,   856,   856,   287,   428,   249,  -304,  -304,  -304,    -1,
    -304,   268,   856,  -304,  -304,  -304,   469,  -304,  -304,  -304,
    -304,  -304,  -304,   631,  -304,   106,   120,   133,   282,   428,
    -304,  -304,   359,   134,  -304,  -304,   631,   631,   631,   856,
     840,  -304,   631,   317,  -304,  -304,   135,   631,   141,  -304,
     631,   281,  -304,   631,  -304,  -304,  -304
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      93,    94,    95,    96,    97,    99,   100,   101,   102,   105,
     106,   103,   104,   160,   161,    98,   118,   119,     0,     0,
     238,     0,    83,    85,   107,     0,     0,   108,   109,    87,
      93,   236,   155,     0,     6,   134,   164,     0,   170,    81,
       0,    89,    91,   163,     0,    84,    86,   112,     0,     0,
     115,     0,     0,    88,     1,   237,     0,   158,     0,   156,
       0,    93,     0,   132,     0,   174,   172,   171,     0,    82,
       0,    93,     0,   162,   124,     0,   120,     0,   126,     0,
       0,     0,     0,     0,     0,   153,   139,   141,   140,   142,
     135,   136,     0,   144,     0,   152,     0,    93,   151,   145,
     150,   133,   165,   175,   173,    90,     2,     3,     4,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
       0,     7,    21,    33,     0,    35,    39,    42,    45,    50,
      53,    55,    57,    59,    61,    63,    65,   195,    92,   169,
       0,     0,   176,   178,   167,    33,    80,     0,   123,   111,
     121,     0,     0,   127,   129,   125,     0,   114,     0,   154,
     159,   157,     0,   138,    93,   149,   143,   146,     0,    25,
       0,    22,    23,     0,    78,     0,   181,     0,   199,     0,
       0,    13,    14,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    67,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   168,
      93,   166,   130,     0,   122,     0,   110,   113,   137,     0,
       0,     0,    17,     5,     0,    93,     0,   183,   182,   184,
       0,     0,   196,    12,     9,     0,    15,     0,    11,    66,
      36,    37,    38,    40,    41,    43,    44,    48,    49,    46,
      47,    51,    52,    54,    56,    58,    60,    62,     0,   177,
     179,   128,   131,     0,   148,     0,    93,    26,     0,    18,
      19,    79,   191,     0,     0,   187,     0,   185,    93,     0,
      34,   197,   200,    10,     0,     8,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   213,     0,   217,   219,   207,   201,   202,     0,
       0,   203,   204,   205,   206,   147,   198,     0,   192,   186,
     188,   193,     0,   189,     0,    16,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,     0,
     208,     0,     0,   222,   215,   218,     0,   214,   220,    20,
     194,   190,   210,     0,   212,     0,     0,     0,     0,     0,
     231,   235,     0,     0,   216,   211,     0,     0,     0,     0,
       0,   209,     0,   223,   225,   226,     0,     0,     0,   227,
       0,     0,   229,     0,   224,   228,   230
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,    -7,  -304,  -304,  -304,  -304,   -51,  -304,  -114,
      48,    49,    13,    47,   183,   186,   204,   195,   205,  -304,
     -56,   -64,  -304,  -113,   -54,   -60,   -20,  -304,   352,  -304,
     124,  -304,  -304,  -304,  -304,  -304,   115,   -13,   -59,  -304,
     199,  -304,  -304,  -304,   261,   -27,   362,  -304,  -304,   338,
    -304,  -304,   382,   360,   -31,   -32,   399,   -34,  -304,  -209,
     288,  -180,   283,   218,   217,  -112,  -304,   395,  -304,  -304,
    -201,  -304,   137,  -303,  -304,  -304,  -304,  -304,   425
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   121,    94,   122,   245,   278,   279,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   174,   197,   313,   147,    20,    21,    40,    41,    22,
      23,    24,    49,    52,    25,    26,    75,    76,    77,   152,
     153,    27,    62,    90,    91,    92,    63,    97,    98,    99,
     100,    28,    58,    59,    29,    42,    43,    44,    67,   141,
     142,   143,   177,   238,   239,   138,   179,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     175,    95,    45,    46,    66,    64,   137,    65,   178,    53,
     198,    32,    35,   350,    36,   148,   146,    78,   216,   155,
      78,   145,    47,    50,    36,    36,   283,   146,   274,   160,
      36,    34,   145,   104,    96,    84,   103,    95,    13,    14,
     270,   369,    56,    78,    78,   154,    70,    78,    78,    78,
      78,   140,    68,    85,   176,   175,   137,   175,   169,   171,
     172,   223,   150,    84,   206,   207,   380,   150,    69,    86,
      96,   247,   234,   145,   325,    38,   234,   224,    57,   332,
     241,   159,    78,    37,   351,   250,   251,   252,   353,   234,
      38,   217,   371,    37,    37,   146,   270,   222,   242,    37,
     145,    38,    33,   296,   268,   173,    38,   233,   218,   176,
     235,   234,   236,    48,    51,    39,   275,    38,   151,   246,
     276,   180,   181,   182,   293,    78,   290,    78,   294,   292,
      87,    88,    89,   249,    71,   199,    72,    78,   208,   209,
     200,   201,   237,   150,   140,   150,   210,   211,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,    80,  -116,   280,   146,
     281,   272,    74,    60,   145,    74,    61,   137,    79,   376,
     146,  -117,   286,   234,    81,   145,   183,    83,   184,   145,
     185,   154,    61,   377,   156,   349,   158,   234,    74,    74,
     140,   237,    74,    74,    74,    74,   378,   382,   391,   163,
     234,   234,   234,   314,   393,   140,   202,   203,   234,   257,
     258,   259,   260,   235,   288,   236,   289,   365,   366,   367,
     335,   102,   295,   146,   234,   334,   162,    74,   145,   373,
     336,   164,   146,   212,   338,   145,   165,   145,   204,   205,
     253,   254,   213,   255,   256,   214,   140,   261,   262,   355,
     215,   219,   220,   359,   221,   225,   386,   388,   140,   297,
     107,   108,   109,   232,   110,   111,   240,   243,   248,   327,
      74,   273,    74,   277,   326,   328,   329,   337,   106,   107,
     108,   109,    74,   110,   111,   330,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   339,   298,   299,   300,   340,   301,
     302,   303,   304,   305,   306,   307,   308,    19,   309,   341,
     342,   344,   345,   346,   310,   347,   352,   361,   113,   363,
     360,   368,   370,   372,   114,   115,   116,   117,   118,   119,
     297,   107,   108,   109,   379,   110,   111,   113,   244,   311,
     273,   312,   381,   114,   115,   116,   117,   118,   119,   390,
     106,   107,   108,   109,   395,   110,   111,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   263,   298,   299,   300,   264,
     301,   302,   303,   304,   305,   306,   307,   308,    19,   309,
     266,   297,   107,   108,   109,   310,   110,   111,   265,   113,
     105,   267,   271,   228,   101,   114,   115,   116,   117,   118,
     119,   106,   107,   108,   109,   167,   110,   111,    82,   113,
     311,   273,   354,    73,   161,   114,   115,   116,   117,   118,
     119,   231,   230,   284,   287,    55,   356,   298,   299,   300,
     348,   301,   302,   303,   304,   305,   306,   307,   308,     0,
     309,     0,   297,   107,   108,   109,   310,   110,   111,     0,
     113,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   311,   273,   357,     0,     0,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,   298,   299,
     300,   311,   301,   302,   303,   304,   305,   306,   307,   308,
       0,   309,     0,     0,     0,     0,     0,   310,    34,     0,
       0,   113,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   311,   273,   374,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    34,     0,     0,     0,   106,   107,   108,
     109,     0,   110,   111,     0,     0,    19,     0,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
      93,     0,     0,     0,   297,   107,   108,   109,     0,   110,
     111,    19,     0,     0,    87,    88,    89,   112,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   106,   107,
     108,   109,     0,   110,   111,   166,     0,     0,   120,   291,
     298,   299,   300,     0,   301,   302,   303,   304,   305,   306,
     307,   308,     0,   309,     0,     0,     0,     0,   343,   310,
       0,     0,     0,   113,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   358,     0,     0,     0,     0,
       0,     0,     0,     0,   311,   273,     0,     0,   112,     0,
       0,     0,   362,     0,   364,     0,     0,   113,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,     0,
       0,   358,     0,     0,     0,     0,     0,     0,   375,   120,
     106,   107,   108,   109,     0,   110,   111,     0,     0,     0,
       0,   383,   384,   385,     0,     0,     0,   389,   106,   107,
     108,   109,   392,   110,   111,   394,     0,     0,   396,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   106,   107,   108,   109,     0,
     110,   111,     0,     0,     0,     0,     0,     0,    19,   106,
     107,   108,   109,     0,   110,   111,     0,     0,     0,   113,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,     0,     0,   106,   107,   108,   109,   113,   110,   111,
     144,     0,     0,   114,   115,   116,   117,   118,   119,   106,
     107,   108,   109,     0,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,   285,     0,     0,
     114,   115,   116,   117,   118,   119,     0,     0,   113,     0,
       0,   333,     0,     0,   114,   115,   116,   117,   118,   119,
     106,   107,   108,   109,     0,   110,   111,     0,     0,     0,
       0,     0,   113,   387,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   106,   107,   108,   109,   113,   110,
     111,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   269,   168,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,    19,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,   149,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,    19,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,   226,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   282,   236,     0,     0,     0,
       0,    38,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   229,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
     113,    61,    22,    23,    38,    37,    70,    38,   120,    29,
     124,     3,    19,     3,     3,    74,    72,    48,    17,    78,
      51,    72,     3,     3,     3,     3,   235,    83,   229,    83,
       3,     3,    83,    67,    61,    77,    67,    97,    42,    43,
     220,   344,    94,    74,    75,    77,    92,    78,    79,    80,
      81,    71,    77,    95,   113,   168,   120,   170,   109,   110,
     111,    77,    75,    77,    12,    13,   369,    80,    93,     3,
      97,   184,    77,   124,   275,    79,    77,    93,     3,   288,
      77,    95,   113,    72,    74,   199,   200,   201,    93,    77,
      79,    90,    93,    72,    72,   151,   276,   151,    95,    72,
     151,    79,    94,    91,   217,   112,    79,    73,   140,   168,
      72,    77,    74,    94,    94,    93,    73,    79,    91,   183,
      77,     7,     8,     9,    73,   156,   240,   158,    77,   241,
      64,    65,    66,   197,    72,    79,    74,   168,    86,    87,
      84,    85,   176,   156,   164,   158,    14,    15,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    51,    94,   232,   225,
     234,   225,    48,    91,   225,    51,    94,   241,    94,    73,
     236,    94,   236,    77,    94,   236,    72,    92,    74,   240,
      76,   223,    94,    73,    79,   308,    81,    77,    74,    75,
     220,   235,    78,    79,    80,    81,    73,    73,    73,     3,
      77,    77,    77,   273,    73,   235,    80,    81,    77,   206,
     207,   208,   209,    72,    72,    74,    74,   340,   341,   342,
     294,    73,    75,   289,    77,   289,    77,   113,   289,   352,
     296,    72,   298,    78,   298,   296,    91,   298,    10,    11,
     202,   203,    88,   204,   205,    89,   276,   210,   211,   319,
      16,    73,    77,   327,    75,    91,   379,   380,   288,     3,
       4,     5,     6,    72,     8,     9,    73,     3,     3,    77,
     156,    94,   158,    73,    73,    73,    73,    91,     3,     4,
       5,     6,   168,     8,     9,    75,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    91,    49,    50,    51,    72,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    72,
      72,    72,     3,    93,    68,    93,    72,    75,    72,    91,
      73,    54,    93,    75,    78,    79,    80,    81,    82,    83,
       3,     4,     5,     6,    72,     8,     9,    72,    73,    93,
      94,    95,     3,    78,    79,    80,    81,    82,    83,    52,
       3,     4,     5,     6,    93,     8,     9,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   212,    49,    50,    51,   213,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     215,     3,     4,     5,     6,    68,     8,     9,   214,    72,
      68,   216,   223,   162,    62,    78,    79,    80,    81,    82,
      83,     3,     4,     5,     6,    97,     8,     9,    56,    72,
      93,    94,    95,    44,    84,    78,    79,    80,    81,    82,
      83,   168,   164,   235,   237,    30,   319,    49,    50,    51,
      93,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    -1,     3,     4,     5,     6,    68,     8,     9,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    93,    94,    95,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    93,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,     3,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     3,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      95,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    61,    -1,    -1,    64,    65,    66,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,     3,     4,
       5,     6,    -1,     8,     9,    95,    -1,    -1,    94,    95,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,   303,    68,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    63,    -1,
      -1,    -1,   337,    -1,   339,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,   356,    -1,    -1,    -1,    -1,    -1,    -1,   363,    94,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,   376,   377,   378,    -1,    -1,    -1,   382,     3,     4,
       5,     6,   387,     8,     9,   390,    -1,    -1,   393,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,     3,     4,     5,     6,    72,     8,     9,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    81,    82,    83,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,     3,     4,     5,     6,    72,     8,
       9,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    61,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    61,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    95,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    61,
     121,   122,   125,   126,   127,   130,   131,   137,   147,   150,
     173,   174,     3,    94,     3,    98,     3,    72,    79,    93,
     123,   124,   151,   152,   153,   122,   122,     3,    94,   128,
       3,    94,   129,   122,     0,   174,    94,     3,   148,   149,
      91,    94,   138,   142,   151,   150,   153,   154,    77,    93,
      92,    72,    74,   152,   126,   132,   133,   134,   150,    94,
     132,    94,   148,    92,    77,    95,     3,    64,    65,    66,
     139,   140,   141,    95,    98,   121,   141,   143,   144,   145,
     146,   142,    73,   150,   153,   124,     3,     4,     5,     6,
       8,     9,    63,    72,    78,    79,    80,    81,    82,    83,
      94,    97,    99,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   161,    73,
     122,   155,   156,   157,    75,   103,   116,   120,   134,    95,
     133,    91,   135,   136,   151,   134,   132,    95,   132,    95,
     120,   149,    77,     3,    72,    91,    95,   145,    72,   103,
      72,   103,   103,    98,   117,   119,   134,   158,   161,   162,
       7,     8,     9,    72,    74,    76,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    92,   118,   105,    79,
      84,    85,    80,    81,    10,    11,    12,    13,    86,    87,
      14,    15,    78,    88,    89,    16,    17,    90,   151,    73,
      77,    75,   120,    77,    93,    91,    95,    95,   140,    73,
     156,   158,    72,    73,    77,    72,    74,   153,   159,   160,
      73,    77,    95,     3,    73,   100,   117,   119,     3,   117,
     105,   105,   105,   106,   106,   107,   107,   108,   108,   108,
     108,   109,   109,   110,   111,   112,   113,   114,   119,    48,
     157,   136,   120,    94,   166,    73,    77,    73,   101,   102,
     117,   117,    73,   155,   159,    75,   120,   160,    72,    74,
     105,    95,   161,    73,    77,    75,    91,     3,    49,    50,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    62,
      68,    93,    95,   119,   121,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   166,    73,    77,    73,    73,
      75,    73,   155,    75,   120,   117,   116,    91,   120,    91,
      72,    72,    72,   163,    72,     3,    93,    93,    93,   119,
       3,    74,    72,    93,    95,   121,   168,    95,   163,   117,
      73,    75,   163,    91,   163,   119,   119,   119,    54,   169,
      93,    93,    75,   119,    95,   163,    73,    73,    73,    72,
     169,     3,    73,   163,   163,   163,   119,    73,   119,   163,
      52,    73,   163,    73,   163,    93,   163
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    97,    97,    98,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   122,   122,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   128,   129,   130,   131,
     132,   132,   133,   134,   134,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   143,   143,   144,   144,   145,
     145,   145,   146,   147,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   158,   158,   159,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   161,   161,   162,
     162,   163,   163,   163,   163,   163,   163,   163,   164,   164,
     165,   165,   165,   166,   166,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   170,   171,   171,   171,   171,
     171,   172,   172,   172,   172,   172,   173,   173,   174
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     0,     1,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     5,     4,     2,     1,     1,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     3,     4,     2,     2,     1,     3,     2,     1,
       1,     1,     1,     3,     2,     1,     2,     5,     4,     2,
       1,     1,     1,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     3,     4,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1
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
  case 6: /* class_name: IDENTIFIER  */
#line 171 "grammar.y"
                            { (yyval.str) = (yyvsp[0].str); lvl_name.push(std::string("class") + (yyvsp[0].str)); }
#line 1774 "grammar.tab.c"
    break;

  case 81: /* declaration: declaration_specifiers ';'  */
#line 315 "grammar.y"
                                     {(yyval.declaration)=create_declaration_object((yyvsp[-1].dec_spec),nullptr,nullptr);}
#line 1780 "grammar.tab.c"
    break;

  case 82: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 316 "grammar.y"
                                                          {(yyval.declaration)=create_declaration_object((yyvsp[-2].dec_spec),(yyvsp[-1].init_dec_list),nullptr);func_ret_type="";current_params_list.clear();}
#line 1786 "grammar.tab.c"
    break;

  case 83: /* declaration_specifiers: storage_class_specifier  */
#line 325 "grammar.y"
                                  {Declaration_Specifiers* ds=create_decl_spec_object(); ds->scs.push_back((yyvsp[0].str));(yyval.dec_spec)=ds;}
#line 1792 "grammar.tab.c"
    break;

  case 84: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 326 "grammar.y"
                                                         {Declaration_Specifiers* ds=(yyvsp[0].dec_spec);ds->scs.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;}
#line 1798 "grammar.tab.c"
    break;

  case 85: /* declaration_specifiers: type_specifier  */
#line 327 "grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back((yyvsp[0].type_spec));(yyval.dec_spec)=ds;}
#line 1804 "grammar.tab.c"
    break;

  case 86: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 328 "grammar.y"
                                                {Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->ts.push_back((yyvsp[-1].type_spec));(yyval.dec_spec)=ds;}
#line 1810 "grammar.tab.c"
    break;

  case 87: /* declaration_specifiers: type_qualifier  */
#line 329 "grammar.y"
                         {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back((yyvsp[0].str));(yyval.dec_spec)=ds;}
#line 1816 "grammar.tab.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 330 "grammar.y"
                                                {Declaration_Specifiers* ds=(yyvsp[0].dec_spec); ds->tq.push_back((yyvsp[-1].str));(yyval.dec_spec)=ds;}
#line 1822 "grammar.tab.c"
    break;

  case 89: /* init_declarator_list: init_declarator  */
#line 334 "grammar.y"
                          {Init_Declarator_List* x=new Init_Declarator_List();x->idl.push_back((yyvsp[0].init_dec));(yyval.init_dec_list)=x;}
#line 1828 "grammar.tab.c"
    break;

  case 90: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 335 "grammar.y"
                                                   { (yyvsp[-2].init_dec_list)->idl.push_back((yyvsp[0].init_dec)); (yyval.init_dec_list) = (yyvsp[-2].init_dec_list);}
#line 1834 "grammar.tab.c"
    break;

  case 91: /* init_declarator: declarator  */
#line 339 "grammar.y"
                     {Init_Declarator* d=new Init_Declarator((yyvsp[0].dec),nullptr);(yyval.init_dec)=d;}
#line 1840 "grammar.tab.c"
    break;

  case 92: /* init_declarator: declarator '=' initializer  */
#line 340 "grammar.y"
                                     {Init_Declarator* d=new Init_Declarator((yyvsp[-2].dec),(yyvsp[0].node));(yyval.init_dec)=d;}
#line 1846 "grammar.tab.c"
    break;

  case 94: /* storage_class_specifier: EXTERN  */
#line 345 "grammar.y"
                 {(yyval.str)="EXTERN";}
#line 1852 "grammar.tab.c"
    break;

  case 95: /* storage_class_specifier: STATIC  */
#line 346 "grammar.y"
                 {(yyval.str)="STATIC";}
#line 1858 "grammar.tab.c"
    break;

  case 96: /* storage_class_specifier: AUTO  */
#line 347 "grammar.y"
               {(yyval.str)="AUTO";}
#line 1864 "grammar.tab.c"
    break;

  case 97: /* storage_class_specifier: REGISTER  */
#line 348 "grammar.y"
                   {(yyval.str)="REGISTER";}
#line 1870 "grammar.tab.c"
    break;

  case 98: /* type_specifier: VOID  */
#line 352 "grammar.y"
           { (yyval.type_spec) = create_ts_obj(std::string("VOID"), nullptr, nullptr, nullptr); }
#line 1876 "grammar.tab.c"
    break;

  case 99: /* type_specifier: CHAR  */
#line 353 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("CHAR",nullptr,nullptr,nullptr);}
#line 1882 "grammar.tab.c"
    break;

  case 100: /* type_specifier: SHORT  */
#line 354 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("SHORT",nullptr,nullptr,nullptr);}
#line 1888 "grammar.tab.c"
    break;

  case 101: /* type_specifier: INT  */
#line 355 "grammar.y"
              {(yyval.type_spec)=create_ts_obj("INT",nullptr,nullptr,nullptr);}
#line 1894 "grammar.tab.c"
    break;

  case 102: /* type_specifier: LONG  */
#line 356 "grammar.y"
               {(yyval.type_spec)=create_ts_obj("LONG",nullptr,nullptr,nullptr);}
#line 1900 "grammar.tab.c"
    break;

  case 103: /* type_specifier: FLOAT  */
#line 357 "grammar.y"
                {(yyval.type_spec)=create_ts_obj("FLOAT",nullptr,nullptr,nullptr);}
#line 1906 "grammar.tab.c"
    break;

  case 104: /* type_specifier: DOUBLE  */
#line 358 "grammar.y"
                 {(yyval.type_spec)=create_ts_obj("DOUBLE",nullptr,nullptr,nullptr);}
#line 1912 "grammar.tab.c"
    break;

  case 105: /* type_specifier: SIGNED  */
#line 359 "grammar.y"
                 {(yyval.type_spec)=create_ts_obj("SIGNED",nullptr,nullptr,nullptr);}
#line 1918 "grammar.tab.c"
    break;

  case 106: /* type_specifier: UNSIGNED  */
#line 360 "grammar.y"
                   {(yyval.type_spec)=create_ts_obj("UNSIGNED",nullptr,nullptr,nullptr);}
#line 1924 "grammar.tab.c"
    break;

  case 107: /* type_specifier: struct_or_union_specifier  */
#line 361 "grammar.y"
                                    {(yyval.type_spec)=create_ts_obj("",(yyvsp[0].str_union),nullptr,nullptr);}
#line 1930 "grammar.tab.c"
    break;

  case 108: /* type_specifier: class_specifier  */
#line 362 "grammar.y"
                      {(yyval.type_spec)=create_ts_obj("",nullptr,(yyvsp[0].class_spec),nullptr);}
#line 1936 "grammar.tab.c"
    break;

  case 109: /* type_specifier: enum_specifier  */
#line 363 "grammar.y"
                         {(yyval.type_spec)=create_ts_obj("",nullptr,nullptr,(yyvsp[0].enum_spec));}
#line 1942 "grammar.tab.c"
    break;

  case 110: /* struct_or_union_specifier: struct struct_id '{' struct_declaration_list '}'  */
#line 368 "grammar.y"
                                                            { (yyval.str_union)=create_struct_union_spec_obj(std::string((yyvsp[-4].str)),std::string((yyvsp[-3].str)),(yyvsp[-1].struc_dec_list)); current_level--; current_table=current_table->get_parent(); lvl_name.pop(); }
#line 1948 "grammar.tab.c"
    break;

  case 111: /* struct_or_union_specifier: struct '{' struct_declaration_list '}'  */
#line 369 "grammar.y"
                                                {(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-3].str),"",(yyvsp[-1].struc_dec_list));current_level--;current_table=current_table->get_parent();lvl_name.pop();}
#line 1954 "grammar.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct IDENTIFIER  */
#line 370 "grammar.y"
                            {check_if_declared(current_table,(yyvsp[0].str),"struct");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);}
#line 1960 "grammar.tab.c"
    break;

  case 113: /* struct_or_union_specifier: union union_id '{' struct_declaration_list '}'  */
#line 371 "grammar.y"
                                                         {(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].struc_dec_list));current_level--;current_table=current_table->get_parent();lvl_name.pop();}
#line 1966 "grammar.tab.c"
    break;

  case 114: /* struct_or_union_specifier: union '{' struct_declaration_list '}'  */
#line 372 "grammar.y"
                                                {(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-3].str),"",(yyvsp[-1].struc_dec_list));current_level--;current_table=current_table->get_parent();lvl_name.pop();}
#line 1972 "grammar.tab.c"
    break;

  case 115: /* struct_or_union_specifier: union IDENTIFIER  */
#line 373 "grammar.y"
                           {check_if_declared(current_table,(yyvsp[0].str),"union");(yyval.str_union)=create_struct_union_spec_obj((yyvsp[-1].str),(yyvsp[0].str),nullptr);/* whether this identifier is declared before use */}
#line 1978 "grammar.tab.c"
    break;

  case 116: /* struct_id: IDENTIFIER  */
#line 377 "grammar.y"
                     {lvl_name.push("struct " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);}
#line 1984 "grammar.tab.c"
    break;

  case 117: /* union_id: IDENTIFIER  */
#line 380 "grammar.y"
                     {lvl_name.push("union " + std::string((yyvsp[0].str)));(yyval.str)=(yyvsp[0].str);}
#line 1990 "grammar.tab.c"
    break;

  case 118: /* struct: STRUCT  */
#line 383 "grammar.y"
                                {(yyval.str)="STRUCT";}
#line 1996 "grammar.tab.c"
    break;

  case 119: /* union: UNION  */
#line 386 "grammar.y"
                {(yyval.str)="UNION";}
#line 2002 "grammar.tab.c"
    break;

  case 120: /* struct_declaration_list: struct_declaration  */
#line 390 "grammar.y"
                             {Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;current_table=next_table(current_table);add_to_local_table(current_table,(yyvsp[0].struc_dec));}
#line 2008 "grammar.tab.c"
    break;

  case 121: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 391 "grammar.y"
                                                     {Struct_Declaration_List* x=(yyvsp[-1].struc_dec_list);x->sdl.push_back((yyvsp[0].struc_dec));(yyval.struc_dec_list)=x;add_to_local_table(current_table,(yyvsp[0].struc_dec));}
#line 2014 "grammar.tab.c"
    break;

  case 122: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 395 "grammar.y"
                                                             {(yyval.struc_dec)=create_struct_dec_obj((yyvsp[-2].sql),(yyvsp[-1].sdl));}
#line 2020 "grammar.tab.c"
    break;

  case 123: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 399 "grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->ts.push_back((yyvsp[-1].type_spec));}
#line 2026 "grammar.tab.c"
    break;

  case 124: /* specifier_qualifier_list: type_specifier  */
#line 400 "grammar.y"
                         {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->ts.push_back((yyvsp[0].type_spec));}
#line 2032 "grammar.tab.c"
    break;

  case 125: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 401 "grammar.y"
                                                  {Specifier_Qualifier_List* x=(yyvsp[0].sql);x->tq.push_back((yyvsp[-1].str));}
#line 2038 "grammar.tab.c"
    break;

  case 126: /* specifier_qualifier_list: type_qualifier  */
#line 402 "grammar.y"
                         {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->tq.push_back((yyvsp[0].str));}
#line 2044 "grammar.tab.c"
    break;

  case 127: /* struct_declarator_list: struct_declarator  */
#line 406 "grammar.y"
                             {Struct_Declarator_List* x=new Struct_Declarator_List();x->sd.push_back((yyvsp[0].sd));}
#line 2050 "grammar.tab.c"
    break;

  case 128: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 407 "grammar.y"
                                                        {Struct_Declarator_List* x=(yyvsp[-2].sdl);x->sd.push_back((yyvsp[0].sd));}
#line 2056 "grammar.tab.c"
    break;

  case 129: /* struct_declarator: declarator  */
#line 411 "grammar.y"
                                           {(yyval.sd)=create_struct_declarator_obj((yyvsp[0].dec),nullptr);}
#line 2062 "grammar.tab.c"
    break;

  case 130: /* struct_declarator: ':' constant_expression  */
#line 412 "grammar.y"
                                  {(yyval.sd)=create_struct_declarator_obj(nullptr,(yyvsp[0].node));}
#line 2068 "grammar.tab.c"
    break;

  case 131: /* struct_declarator: declarator ':' constant_expression  */
#line 413 "grammar.y"
                                              {(yyval.sd)=create_struct_declarator_obj((yyvsp[-2].dec),(yyvsp[0].node));}
#line 2074 "grammar.tab.c"
    break;

  case 132: /* class_specifier: CLASS class_name class_body  */
#line 417 "grammar.y"
                                   {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[-1].str)),nullptr,(yyvsp[0].class_mem_dec_list));}
#line 2080 "grammar.tab.c"
    break;

  case 133: /* class_specifier: CLASS class_name inheritance_specifier class_body  */
#line 418 "grammar.y"
                                                        {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[-2].str)),(yyvsp[-1].inh_spec),(yyvsp[0].class_mem_dec_list));}
#line 2086 "grammar.tab.c"
    break;

  case 134: /* class_specifier: CLASS class_name  */
#line 419 "grammar.y"
                           {(yyval.class_spec)=new Class_Specifier(std::string((yyvsp[0].str)),nullptr,nullptr);check_if_declared(current_table,std::string((yyvsp[0].str)),"class");}
#line 2092 "grammar.tab.c"
    break;

  case 135: /* inheritance_specifier: ':' base_class_list  */
#line 423 "grammar.y"
                                     {(yyval.inh_spec)=new Inheritance_Specifier((yyvsp[0].bcl));}
#line 2098 "grammar.tab.c"
    break;

  case 136: /* base_class_list: base_class  */
#line 427 "grammar.y"
                                                                     {Base_Class_List* x=new Base_Class_List();x->bc.push_back((yyvsp[0].bc));}
#line 2104 "grammar.tab.c"
    break;

  case 137: /* base_class_list: base_class_list ',' base_class  */
#line 428 "grammar.y"
                                     {Base_Class_List* x=(yyvsp[-2].bcl);x->bc.push_back((yyvsp[0].bc));}
#line 2110 "grammar.tab.c"
    break;

  case 138: /* base_class: access_specifier IDENTIFIER  */
#line 432 "grammar.y"
                                                                            {check_if_declared(current_table,std::string((yyvsp[0].str)),"class");(yyval.bc)=new Base_Class((yyvsp[-1].str),std::string((yyvsp[0].str)));}
#line 2116 "grammar.tab.c"
    break;

  case 139: /* base_class: IDENTIFIER  */
#line 433 "grammar.y"
                 {check_if_declared(current_table,(yyvsp[0].str),"class");(yyval.bc)=new Base_Class("",std::string((yyvsp[0].str)));}
#line 2122 "grammar.tab.c"
    break;

  case 140: /* access_specifier: PUBLIC  */
#line 437 "grammar.y"
                        {(yyval.str)="PUBLIC";}
#line 2128 "grammar.tab.c"
    break;

  case 141: /* access_specifier: PRIVATE  */
#line 438 "grammar.y"
              {(yyval.str)="PRIVATE";}
#line 2134 "grammar.tab.c"
    break;

  case 142: /* access_specifier: PROTECTED  */
#line 439 "grammar.y"
                {(yyval.str)="PROTECTED";}
#line 2140 "grammar.tab.c"
    break;

  case 143: /* class_body: '{' class_member_declaration_list '}'  */
#line 443 "grammar.y"
                                            {(yyval.class_mem_dec_list)=(yyvsp[-1].class_mem_dec_list); current_level--;current_table=current_table->get_parent();lvl_name.pop();while(!access_spec_stk.empty())access_spec_stk.pop();}
#line 2146 "grammar.tab.c"
    break;

  case 144: /* class_body: '{' '}'  */
#line 444 "grammar.y"
              {lvl_name.pop();}
#line 2152 "grammar.tab.c"
    break;

  case 145: /* class_member_declaration_list: class_member_declaration  */
#line 448 "grammar.y"
                               {Class_Member_Declaration_List* x=new Class_Member_Declaration_List();x->cd.push_back((yyvsp[0].class_mem_dec));current_level++;current_table=next_table(current_table);}
#line 2158 "grammar.tab.c"
    break;

  case 146: /* class_member_declaration_list: class_member_declaration_list class_member_declaration  */
#line 449 "grammar.y"
                                                             { (yyvsp[-1].class_mem_dec_list)->cd.push_back((yyvsp[0].class_mem_dec));
    (yyval.class_mem_dec_list) = (yyvsp[-1].class_mem_dec_list);}
#line 2165 "grammar.tab.c"
    break;

  case 147: /* constructor_declaration: class_name '(' parameter_list ')' compound_statement  */
#line 454 "grammar.y"
                                                          {current_params_list.clear();add_params_to_map((yyvsp[-2].pl));(yyval.constrdec)=new Constructor_Declaration(std::string((yyvsp[-4].str)),(yyvsp[-2].pl),(yyvsp[0].comp_stmt));}
#line 2171 "grammar.tab.c"
    break;

  case 148: /* constructor_declaration: class_name '(' ')' compound_statement  */
#line 455 "grammar.y"
                                                {current_params_list.clear();(yyval.constrdec)=new Constructor_Declaration(std::string((yyvsp[-3].str)),nullptr,(yyvsp[0].comp_stmt));}
#line 2177 "grammar.tab.c"
    break;

  case 149: /* class_member_declaration: access_specifier ':'  */
#line 460 "grammar.y"
                           {access_spec_stk.push((yyvsp[-1].str));}
#line 2183 "grammar.tab.c"
    break;

  case 150: /* class_member_declaration: member_declaration  */
#line 461 "grammar.y"
                         {(yyval.class_mem_dec)=new Class_Member_Declaration((yyvsp[0].memd),nullptr);}
#line 2189 "grammar.tab.c"
    break;

  case 151: /* class_member_declaration: constructor_declaration  */
#line 462 "grammar.y"
                              {(yyval.class_mem_dec)=new Class_Member_Declaration(nullptr,(yyvsp[0].constrdec));add_to_local_table(current_table,(yyvsp[0].constrdec));}
#line 2195 "grammar.tab.c"
    break;

  case 152: /* member_declaration: declaration  */
#line 466 "grammar.y"
                  {add_to_local_table(current_table,(yyvsp[0].declaration));(yyval.memd)=new Member_Declaration((yyvsp[0].declaration),nullptr);}
#line 2201 "grammar.tab.c"
    break;

  case 153: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 471 "grammar.y"
                                       {(yyval.enum_spec)=new Enum_Specifier(std::string(""),(yyvsp[-1].enuml));}
#line 2207 "grammar.tab.c"
    break;

  case 154: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 472 "grammar.y"
                                                  {(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[-3].str)),(yyvsp[-1].enuml));}
#line 2213 "grammar.tab.c"
    break;

  case 155: /* enum_specifier: ENUM IDENTIFIER  */
#line 473 "grammar.y"
                          {(yyval.enum_spec)=new Enum_Specifier(std::string((yyvsp[0].str)),nullptr);check_if_declared(current_table,std::string((yyvsp[0].str)),"enum");}
#line 2219 "grammar.tab.c"
    break;

  case 156: /* enumerator_list: enumerator  */
#line 477 "grammar.y"
                     {Enumerator_List* x=new Enumerator_List();x->e.push_back((yyvsp[0].enumer));}
#line 2225 "grammar.tab.c"
    break;

  case 157: /* enumerator_list: enumerator_list ',' enumerator  */
#line 478 "grammar.y"
                                         {Enumerator_List* x=(yyvsp[-2].enuml);x->e.push_back((yyvsp[0].enumer));}
#line 2231 "grammar.tab.c"
    break;

  case 158: /* enumerator: IDENTIFIER  */
#line 482 "grammar.y"
                     {(yyval.enumer)=new Enumerator(std::string((yyvsp[0].str)),nullptr);}
#line 2237 "grammar.tab.c"
    break;

  case 159: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 483 "grammar.y"
                                             {(yyval.enumer)=new Enumerator(std::string((yyvsp[-2].str)),(yyvsp[0].node));}
#line 2243 "grammar.tab.c"
    break;

  case 160: /* type_qualifier: CONST  */
#line 487 "grammar.y"
                 {(yyval.str)="CONST";}
#line 2249 "grammar.tab.c"
    break;

  case 161: /* type_qualifier: VOLATILE  */
#line 488 "grammar.y"
                   {(yyval.str)="VOLATILE";}
#line 2255 "grammar.tab.c"
    break;

  case 162: /* declarator: pointer direct_declarator  */
#line 492 "grammar.y"
                                    {(yyval.dec)=create_new_declarator((yyvsp[-1].point),(yyvsp[0].dir_dec));}
#line 2261 "grammar.tab.c"
    break;

  case 163: /* declarator: direct_declarator  */
#line 493 "grammar.y"
                            {(yyval.dec)=create_new_declarator(nullptr,(yyvsp[0].dir_dec));}
#line 2267 "grammar.tab.c"
    break;

  case 164: /* direct_declarator: IDENTIFIER  */
#line 497 "grammar.y"
                     {(yyval.dir_dec)=create_direct_declarator(std::string("id"),(yyvsp[0].str),nullptr,nullptr,nullptr,nullptr);}
#line 2273 "grammar.tab.c"
    break;

  case 165: /* direct_declarator: '(' declarator ')'  */
#line 498 "grammar.y"
                             {(yyval.dir_dec)=create_direct_declarator(std::string("declarator"),"",(yyvsp[-1].dec),nullptr,nullptr,nullptr);}
#line 2279 "grammar.tab.c"
    break;

  case 166: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 499 "grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,nullptr);}
#line 2285 "grammar.tab.c"
    break;

  case 167: /* direct_declarator: direct_declarator '[' ']'  */
#line 500 "grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("array"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2291 "grammar.tab.c"
    break;

  case 168: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 501 "grammar.y"
                                                        {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-3].dir_dec),nullptr,(yyvsp[-1].pl));}
#line 2297 "grammar.tab.c"
    break;

  case 169: /* direct_declarator: direct_declarator '(' ')'  */
#line 503 "grammar.y"
                                    {(yyval.dir_dec)=create_direct_declarator(std::string("function"),"",nullptr,(yyvsp[-2].dir_dec),nullptr,nullptr);}
#line 2303 "grammar.tab.c"
    break;

  case 170: /* pointer: '*'  */
#line 507 "grammar.y"
              {(yyval.point)=new Pointer(nullptr,nullptr);}
#line 2309 "grammar.tab.c"
    break;

  case 171: /* pointer: '*' type_qualifier_list  */
#line 508 "grammar.y"
                                  {(yyval.point)=new Pointer(nullptr,(yyvsp[0].tql));}
#line 2315 "grammar.tab.c"
    break;

  case 172: /* pointer: '*' pointer  */
#line 509 "grammar.y"
                      {(yyval.point)=new Pointer((yyvsp[0].point),nullptr);}
#line 2321 "grammar.tab.c"
    break;

  case 173: /* pointer: '*' type_qualifier_list pointer  */
#line 510 "grammar.y"
                                          {(yyval.point)=new Pointer((yyvsp[0].point),(yyvsp[-1].tql));}
#line 2327 "grammar.tab.c"
    break;

  case 174: /* type_qualifier_list: type_qualifier  */
#line 514 "grammar.y"
                         {Type_Qualifier_List* x=new Type_Qualifier_List();x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2333 "grammar.tab.c"
    break;

  case 175: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 515 "grammar.y"
                                             {Type_Qualifier_List* x=(yyvsp[0].str);x->tq.push_back((yyvsp[0].str));(yyval.tql)=x;}
#line 2339 "grammar.tab.c"
    break;

  case 176: /* parameter_type_list: parameter_list  */
#line 520 "grammar.y"
                         {(yyval.pl)=(yyvsp[0].pl);}
#line 2345 "grammar.tab.c"
    break;

  case 177: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 521 "grammar.y"
                                      {Parameter_List* x=(yyvsp[-2].pl); x->ellipses=true;}
#line 2351 "grammar.tab.c"
    break;

  case 178: /* parameter_list: parameter_declaration  */
#line 525 "grammar.y"
                                {Parameter_List* x=new Parameter_List();x->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=x;}
#line 2357 "grammar.tab.c"
    break;

  case 179: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 526 "grammar.y"
                                                   {(yyvsp[-2].pl)->pl.push_back((yyvsp[0].par_dec));(yyval.pl)=(yyvsp[-2].pl);}
#line 2363 "grammar.tab.c"
    break;

  case 180: /* parameter_declaration: declaration_specifiers declarator  */
#line 530 "grammar.y"
                                            {(yyval.par_dec)=new Parameter_Declaration((yyvsp[-1].dec_spec),(yyvsp[0].dec));}
#line 2369 "grammar.tab.c"
    break;

  case 236: /* translation_unit: external_declaration  */
#line 644 "grammar.y"
                               {Node* ext=create_node();ext->add_child((yyvsp[0].node));root->add_child(ext);}
#line 2375 "grammar.tab.c"
    break;

  case 237: /* translation_unit: translation_unit external_declaration  */
#line 645 "grammar.y"
                                                {Node* ext=create_node();ext->add_child((yyvsp[0].node));root->add_child(ext);}
#line 2381 "grammar.tab.c"
    break;

  case 238: /* external_declaration: declaration  */
#line 650 "grammar.y"
                      {add_to_gst((yyvsp[0].declaration),gst);(yyval.node)=(yyvsp[0].declaration);}
#line 2387 "grammar.tab.c"
    break;


#line 2391 "grammar.tab.c"

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

#line 662 "grammar.y"

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
int line_num = 1;
vector<pair<string, int>> error;
unordered_map<string, string> symtab;
vector<string> program;

void yyerror(const char *s) {
    fflush(stdout);
	
}
int main(int argc, char *argv[]){
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
	Node* root= new Node();
	gst=new Global_Symbol_Table();
	current_params_list.clear();
	labelset.clear();
	func_ret_type="";
	while (!lvl_name.empty()){
    lvl_name.pop();
	}
	current_table=nullptr;
	current_level=0;
    int abc=yyparse();
    if(abc){
        cout << "parsing failed!" << endl;
    }
    else{
        cout << "parsing successful" << endl;
    }
    return 0;
}
