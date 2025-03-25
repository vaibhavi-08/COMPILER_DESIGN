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
#line 1 "grammar.y"

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstring> // Required for strdup

void yyerror(const char *s);

using namespace std;


// Existing symbol table and other declarations
extern unordered_map<string, string> symtab;
extern vector<string> program;
extern vector<pair<string, int>> error;
extern int line_num;
extern bool iserror;
extern int yylex();



#line 98 "grammar.tab.c"

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
  YYSYMBOL_struct_or_union = 128,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 129,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 130,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 131, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 132,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 133,        /* struct_declarator  */
  YYSYMBOL_class_specifier = 134,          /* class_specifier  */
  YYSYMBOL_inheritance_specifier = 135,    /* inheritance_specifier  */
  YYSYMBOL_base_class_list = 136,          /* base_class_list  */
  YYSYMBOL_base_class = 137,               /* base_class  */
  YYSYMBOL_access_specifier = 138,         /* access_specifier  */
  YYSYMBOL_class_body = 139,               /* class_body  */
  YYSYMBOL_class_member_declaration_list = 140, /* class_member_declaration_list  */
  YYSYMBOL_constructor_declaration = 141,  /* constructor_declaration  */
  YYSYMBOL_parameter_list_opt = 142,       /* parameter_list_opt  */
  YYSYMBOL_class_member_declaration = 143, /* class_member_declaration  */
  YYSYMBOL_member_declaration = 144,       /* member_declaration  */
  YYSYMBOL_enum_specifier = 145,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 146,          /* enumerator_list  */
  YYSYMBOL_enumerator = 147,               /* enumerator  */
  YYSYMBOL_type_qualifier = 148,           /* type_qualifier  */
  YYSYMBOL_declarator = 149,               /* declarator  */
  YYSYMBOL_direct_declarator = 150,        /* direct_declarator  */
  YYSYMBOL_pointer = 151,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 152,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 153,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 154,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 155,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 156,          /* identifier_list  */
  YYSYMBOL_type_name = 157,                /* type_name  */
  YYSYMBOL_abstract_declarator = 158,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 159, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 160,              /* initializer  */
  YYSYMBOL_initializer_list = 161,         /* initializer_list  */
  YYSYMBOL_statement = 162,                /* statement  */
  YYSYMBOL_object_statement = 163,         /* object_statement  */
  YYSYMBOL_labeled_statement = 164,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 165,       /* compound_statement  */
  YYSYMBOL_declaration_list = 166,         /* declaration_list  */
  YYSYMBOL_statement_list = 167,           /* statement_list  */
  YYSYMBOL_expression_statement = 168,     /* expression_statement  */
  YYSYMBOL_selection_statement = 169,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 170,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 171,           /* jump_statement  */
  YYSYMBOL_translation_unit = 172,         /* translation_unit  */
  YYSYMBOL_external_declaration = 173,     /* external_declaration  */
  YYSYMBOL_function_definition = 174       /* function_definition  */
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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1684

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  245
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  411

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
       0,    47,    47,    48,    49,    50,    51,    54,    58,    59,
      60,    61,    62,    63,    64,    65,    69,    70,    73,    74,
      78,    79,    82,    83,    84,    85,    86,    87,    91,    92,
      93,    94,    95,    96,   100,   101,   105,   106,   107,   108,
     112,   113,   114,   118,   119,   120,   124,   125,   126,   127,
     128,   132,   133,   134,   138,   139,   143,   144,   148,   149,
     153,   154,   158,   159,   163,   164,   168,   169,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   187,
     188,   192,   196,   197,   201,   202,   203,   204,   205,   206,
     210,   211,   215,   216,   220,   221,   222,   223,   224,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   244,   245,   246,   250,   251,   255,   256,   260,
     264,   265,   266,   267,   271,   272,   276,   277,   278,   281,
     282,   286,   290,   291,   295,   296,   300,   301,   302,   306,
     307,   311,   312,   313,   317,   321,   322,   326,   327,   328,
     332,   333,   337,   338,   339,   343,   344,   348,   349,   353,
     354,   358,   359,   363,   364,   365,   366,   367,   368,   369,
     373,   374,   375,   376,   380,   381,   386,   387,   391,   392,
     396,   397,   398,   402,   403,   407,   408,   412,   413,   414,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   430,
     431,   432,   436,   437,   441,   442,   443,   444,   445,   446,
     447,   451,   452,   456,   457,   458,   462,   463,   464,   465,
     469,   470,   474,   475,   479,   480,   484,   485,   486,   490,
     491,   492,   493,   497,   498,   499,   500,   501,   505,   506,
     510,   511,   515,   516,   517,   518
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
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "class_specifier", "inheritance_specifier",
  "base_class_list", "base_class", "access_specifier", "class_body",
  "class_member_declaration_list", "constructor_declaration",
  "parameter_list_opt", "class_member_declaration", "member_declaration",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "object_statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-297)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1235,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,    17,    56,    74,     6,  -297,    69,  1595,  1595,  -297,
      28,  -297,  -297,  1595,  1429,   -30,    54,  1131,  -297,  -297,
      15,    68,   145,    82,  -297,  -297,     6,  -297,   -23,  -297,
    1395,  -297,  -297,    35,  1623,  -297,   330,  -297,    69,  -297,
    1429,  1287,   879,   -30,  -297,  -297,    68,    55,   -40,  -297,
     258,   491,    71,  -297,  -297,  -297,  -297,    74,  -297,   746,
    -297,  1429,  1623,  1623,  1327,  -297,     7,  1623,    25,  -297,
    -297,  1025,  1046,  1046,  1067,    84,    88,   126,   151,   714,
     170,   260,   174,   178,   775,   285,   858,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,    38,    85,   192,  1067,
    -297,   156,   199,   272,   191,   271,   197,   205,   206,   288,
       5,  -297,  -297,   -15,  -297,  -297,  -297,  -297,   423,   538,
    -297,  -297,  -297,  -297,   209,  -297,  -297,  -297,  -297,    77,
     234,   238,  -297,    11,  -297,  -297,  -297,  -297,   242,   -27,
    1067,    68,  -297,  -297,  -297,  -297,  -297,   241,  -297,   317,
     249,  -297,  -297,   235,   606,  -297,  -297,  -297,  -297,  -297,
    -297,   746,  -297,  -297,  -297,  1355,  -297,  -297,  -297,  1067,
     -10,  -297,   236,  -297,   714,   858,  -297,  1067,  -297,  -297,
     237,   714,  1067,  1067,  1067,   277,   797,   239,  -297,  -297,
    -297,    -4,  -297,   265,    14,   148,   274,   273,   345,   346,
    -297,  -297,   903,  1067,   348,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,  1067,  -297,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  -297,  -297,
     653,  -297,  -297,  1183,   940,  -297,    78,  -297,   181,  -297,
    1561,  -297,   349,  -297,  -297,  -297,  -297,   258,  -297,  1595,
    -297,  -297,  -297,  -297,  -297,   -19,  -297,  -297,     7,  -297,
    1067,  -297,   280,   714,  -297,    99,   128,   152,   282,   797,
    -297,  -297,  1067,  -297,  1463,   196,  -297,  1067,  1067,   263,
    -297,  -297,   177,  -297,    22,  -297,  -297,  -297,  -297,  -297,
     156,   156,   199,   199,   272,   272,   272,   272,   191,   191,
     271,   197,   205,   206,   288,    86,  -297,  -297,  -297,   283,
     284,  -297,   303,   181,  1515,   964,  -297,  -297,  -297,  -297,
     309,   315,   165,  -297,  -297,  -297,  -297,  -297,   714,   714,
     714,  1067,   985,   321,   318,  -297,  -297,   323,   334,  -297,
    1067,  -297,  1067,  -297,  -297,  -297,  -297,   325,  -297,   324,
     306,  1595,  -297,  -297,   351,  -297,  -297,   179,   714,   185,
    -297,  1067,  -297,   285,  -297,  -297,  -297,  -297,  -297,   714,
     308,  -297,   714,  -297,   332,  -297,  -297,  -297,  1067,   333,
    -297
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   163,   111,    94,    95,    96,    97,    98,   100,   101,
     102,   103,   106,   107,   104,   105,   159,   160,    99,   115,
     116,     0,     0,     0,   170,   241,     0,    84,    86,   108,
       0,   109,   110,    88,     0,   162,     0,     0,   238,   240,
     154,     0,     0,     0,   174,   172,   171,    82,     0,    90,
      92,    85,    87,   114,     0,    89,     0,   220,     0,   245,
       0,     0,     0,   161,     1,   239,     0,   157,     0,   155,
       0,     0,     0,   129,   164,   175,   173,     0,    83,     0,
     243,     0,     0,   121,     0,   117,     0,   123,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,   224,   216,     8,     0,    22,    34,     0,
      36,    40,    43,    46,    51,    54,    56,    58,    60,    62,
      64,    66,    79,     0,   222,   210,   204,   205,     0,     0,
     206,   207,   208,   209,    92,   221,   244,   183,   169,   182,
       0,   176,   178,     0,     2,   166,    34,    81,     0,     0,
       0,     0,   152,   135,   137,   136,   138,   131,   132,     0,
     163,   140,   150,     0,     0,   143,   141,   148,   151,   130,
      91,     0,   199,    93,   242,     0,   120,   113,   118,     0,
       0,   124,   126,   122,     0,     0,    26,     0,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
     236,     0,     7,     0,     0,   185,     0,     0,     0,     0,
      14,    15,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    68,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   218,
       0,   217,   223,     0,     0,   180,   187,   181,   188,   167,
       0,   168,     0,   165,   153,   158,   156,     0,   134,   146,
     147,   139,   149,   142,   202,     0,   112,   127,     0,   119,
       0,   213,     0,     0,   215,     0,     0,     0,     0,     0,
     233,   237,    18,     5,     0,   187,   186,     0,    18,     0,
      13,    10,     0,    16,     0,    12,    67,    37,    38,    39,
      41,    42,    44,    45,    49,    50,    47,    48,    52,    53,
      55,    57,    59,    61,    63,     0,    80,   219,   195,     0,
       0,   191,     0,   189,     0,     0,   177,   179,   184,   133,
       0,   145,     0,   200,   125,   128,    27,   214,     0,     0,
       0,     0,     0,     0,    19,    20,    35,     0,     0,    11,
       0,     9,     0,   196,   190,   192,   197,     0,   193,     0,
       0,     0,   201,   203,   226,   228,   229,     0,     0,     0,
       6,     0,   212,     0,    17,    65,   198,   194,   144,     0,
       0,   231,     0,    21,     0,   227,   230,   232,    18,     0,
     211
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -297,  -297,  -103,  -297,  -297,  -296,  -297,   -58,  -297,  -100,
      58,    66,    96,    62,   154,   162,   163,   161,   164,  -297,
     -56,   -78,  -297,   -89,   -64,    64,   269,  -297,   340,  -297,
     -31,  -297,  -297,   336,   -55,   -74,  -297,   132,  -297,  -297,
    -297,   144,   -47,   350,  -297,   256,  -297,   259,  -297,  -297,
     368,   275,    36,   -12,   -33,    -6,  -297,   -53,   158,  -249,
    -297,   240,  -110,  -239,  -174,  -297,   -94,  -297,  -297,   -34,
      13,   300,  -163,  -297,  -297,  -297,  -297,   402,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   115,   116,   117,   312,   363,   364,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   236,   133,   158,    57,   149,    48,    49,    27,
      28,    29,    30,    84,    85,    86,   190,   191,    31,    72,
     167,   168,   169,    73,   174,   175,   350,   176,   177,    32,
      68,    69,    33,    34,    35,    36,    46,   339,   151,   152,
     153,   216,   340,   268,   183,   285,   134,   135,   136,   137,
      60,   139,   140,   141,   142,   143,    37,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   182,   213,    63,   156,   205,   157,   284,   150,   186,
       1,    43,   367,   193,    50,   211,    80,   214,    45,   237,
      40,   347,   255,    83,   173,   178,   146,   343,    -7,   188,
     200,    53,   215,   196,   198,   199,   156,   161,   157,   267,
      76,   217,    61,   299,    62,   262,   144,   184,    16,    17,
     161,    83,    83,    83,    77,   162,    83,     1,   352,    42,
      44,   156,   257,    81,    25,   144,   343,   288,   274,   138,
      78,    67,     1,   257,   192,    83,   353,     1,   258,    23,
       1,     1,    75,   289,   271,    24,    24,   303,   272,   301,
      87,   257,   219,   220,   221,   256,   275,   371,   189,   257,
     291,    25,   156,   182,   157,   306,   214,   294,   214,    66,
     218,    41,   409,   295,   296,   297,   194,    24,    87,    87,
      87,   215,    54,    87,   145,   287,    23,   173,   178,    82,
     188,   156,   347,   157,   314,   172,   362,   265,   317,   318,
     319,    23,    87,   266,   313,   145,    23,   160,    24,   263,
     263,   264,   264,    24,    83,    74,    24,   222,   316,   223,
     202,   224,    47,   257,    83,    71,   262,   335,   154,    89,
      90,    91,   358,    92,    93,   201,   257,   372,   383,   336,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   203,   357,
     342,   359,   145,   245,   246,   257,   156,   366,   157,   305,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     304,    87,   264,   204,   365,   360,   355,    24,   105,   257,
     365,    87,   156,    63,   157,   238,    70,   106,   172,    71,
     239,   240,   206,   107,   108,   109,   110,   111,   112,   156,
     369,    43,   400,   344,   370,   345,   257,   266,   402,   181,
     382,   163,   257,   207,   384,   385,   386,   208,   304,    26,
     264,   209,   387,   389,   182,   251,   192,   247,   248,   241,
     242,   379,   243,   244,   235,   249,   250,   156,   212,   157,
     404,   377,   394,   252,   401,   253,    51,    52,   305,   320,
     321,    79,    55,    58,   254,   405,    26,   269,   407,   322,
     323,   328,   329,   403,   156,   270,   395,   273,   277,    58,
     278,   279,   164,   165,   166,    58,   280,   290,   293,    58,
     365,   298,   300,    88,    89,    90,    91,   302,    92,    93,
      26,   324,   325,   326,   327,   308,   398,   307,   309,   310,
      58,   315,   348,   356,   361,   368,   373,   374,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   375,    94,
      95,    96,   380,    97,    98,    99,   100,   101,   102,   103,
     104,    22,   381,   105,   390,   391,   392,   393,   396,   397,
      56,   406,   106,   399,   408,   330,   410,    58,   107,   108,
     109,   110,   111,   112,   331,   333,   332,   180,   185,   334,
     354,   349,   179,   113,    56,   114,    88,    89,    90,    91,
     282,    92,    93,   283,   159,   292,   276,   351,   260,    65,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    94,    95,    96,     0,    97,    98,    99,   100,
     101,   102,   103,   104,    22,     0,   105,     0,     0,     0,
       0,     0,     0,     0,   170,   106,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,    56,   259,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,    88,    89,    90,    91,     0,    92,    93,     0,     0,
       0,     0,    22,     0,     0,   164,   165,   166,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,    94,    95,    96,
       0,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,   170,
     106,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,    56,   261,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    88,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,    22,     0,     0,
     164,   165,   166,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,    94,    95,    96,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   105,    88,    89,    90,
      91,     0,    92,    93,     0,   106,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,    56,   337,   154,
      89,    90,    91,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,   105,   154,    89,
      90,    91,     0,    92,    93,     0,   106,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
     154,    89,    90,    91,     0,    92,    93,   113,    56,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
     181,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,     0,
     105,   154,    89,    90,    91,     0,    92,    93,   210,   106,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,     0,   154,    89,    90,    91,     2,    92,    93,     0,
     113,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   154,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,     0,    22,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   105,   154,    89,    90,    91,     0,    92,    93,
       0,   106,     0,     0,   155,     0,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,   105,   154,    89,    90,
      91,     0,    92,    93,     0,   106,   311,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,   154,    89,
      90,    91,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,   341,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,   105,   154,    89,
      90,    91,     0,    92,    93,     0,   106,     0,     0,   378,
       0,     0,   107,   108,   109,   110,   111,   112,   105,   154,
      89,    90,    91,     0,    92,    93,     0,   106,   388,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,     0,
     154,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   197,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     105,    64,     0,     0,     1,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   338,   264,     0,     0,
       0,     0,    24,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    24,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
     148,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,    22,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,   187,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,     0,    22,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,    56,
      22,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   338,   264,     0,     0,
       0,     0,    24,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,    22,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
      34,    79,   105,    36,    62,    99,    62,   181,    61,    83,
       3,    23,   308,    87,    26,   104,    50,   106,    24,   119,
       3,   270,    17,    54,    71,    71,    60,   266,     3,    84,
      94,     3,   106,    91,    92,    93,    94,    77,    94,   149,
      46,     3,    72,   206,    74,   139,    58,    81,    42,    43,
      77,    82,    83,    84,    77,    95,    87,     3,    77,     3,
      24,   119,    77,    50,     0,    77,   305,    77,    95,    56,
      93,     3,     3,    77,    86,   106,    95,     3,    93,    72,
       3,     3,    46,    93,    73,    79,    79,    73,    77,    93,
      54,    77,     7,     8,     9,    90,   160,    75,    91,    77,
     194,    37,   160,   181,   160,   215,   195,   201,   197,    94,
     116,    94,   408,   202,   203,   204,    91,    79,    82,    83,
      84,   195,    94,    87,    60,   189,    72,   174,   174,    94,
     185,   189,   381,   189,   223,    71,   299,   149,   238,   239,
     240,    72,   106,   149,   222,    81,    72,    92,    79,    72,
      72,    74,    74,    79,   185,    73,    79,    72,   236,    74,
      72,    76,    93,    77,   195,    94,   260,   256,     3,     4,
       5,     6,    73,     8,     9,    91,    77,    91,   352,   257,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    72,   293,
     264,    73,   138,    12,    13,    77,   264,   307,   264,   215,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      72,   185,    74,    72,   302,    73,   290,    79,    63,    77,
     308,   195,   290,   266,   290,    79,    91,    72,   174,    94,
      84,    85,    72,    78,    79,    80,    81,    82,    83,   307,
      73,   263,    73,    72,    77,    74,    77,   263,    73,    94,
      95,     3,    77,     3,   358,   359,   360,    93,    72,     0,
      74,    93,   361,   362,   352,    78,   288,    86,    87,    80,
      81,   345,    10,    11,    92,    14,    15,   345,     3,   345,
     393,   344,   370,    88,   388,    89,    27,    28,   304,   241,
     242,    92,    33,    34,    16,   399,    37,    73,   402,   243,
     244,   249,   250,   391,   372,    77,   372,    75,    77,    50,
       3,    72,    64,    65,    66,    56,    91,    91,    91,    60,
     408,    54,    93,     3,     4,     5,     6,    72,     8,     9,
      71,   245,   246,   247,   248,    72,   380,    73,     3,     3,
      81,     3,     3,    73,    72,    92,    73,    73,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    75,    49,
      50,    51,    73,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    77,    63,    73,    77,    73,    63,    73,    75,
      94,    93,    72,    52,    72,   251,    73,   138,    78,    79,
      80,    81,    82,    83,   252,   254,   253,    77,    82,   255,
     288,   277,    72,    93,    94,    95,     3,     4,     5,     6,
     174,     8,     9,   174,    66,   195,   161,   279,   138,    37,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    72,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,     3,     4,     5,
       6,    -1,     8,     9,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,     3,     4,
       5,     6,    -1,     8,     9,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    93,    94,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      63,     3,     4,     5,     6,    -1,     8,     9,    93,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,     3,     4,     5,     6,    28,     8,     9,    -1,
      93,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    63,     3,     4,     5,     6,    -1,     8,     9,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    63,     3,     4,     5,
       6,    -1,     8,     9,    -1,    72,    73,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    63,     3,     4,
       5,     6,    -1,     8,     9,    -1,    72,    -1,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    63,     3,
       4,     5,     6,    -1,     8,     9,    -1,    72,    73,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      63,     0,    -1,    -1,     3,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    79,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      73,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    61,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    95,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    61,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    94,
      61,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    79,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    61,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    72,    79,   121,   122,   125,   126,   127,
     128,   134,   145,   148,   149,   150,   151,   172,   173,   174,
       3,    94,     3,   149,   148,   151,   152,    93,   123,   124,
     149,   122,   122,     3,    94,   122,    94,   121,   122,   165,
     166,    72,    74,   150,     0,   173,    94,     3,   146,   147,
      91,    94,   135,   139,    73,   148,   151,    77,    93,    92,
     165,   166,    94,   126,   129,   130,   131,   148,     3,     4,
       5,     6,     8,     9,    49,    50,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    63,    72,    78,    79,    80,
      81,    82,    83,    93,    95,    97,    98,    99,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   119,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   149,   121,   165,     3,    73,   122,
     153,   154,   155,   156,     3,    75,   103,   116,   120,   146,
      92,    77,    95,     3,    64,    65,    66,   136,   137,   138,
       3,    95,   121,   138,   140,   141,   143,   144,   174,   139,
     124,    94,   117,   160,   165,   129,   131,    95,   130,    91,
     132,   133,   149,   131,    91,    72,   103,    72,   103,   103,
     120,    91,    72,    72,    72,   162,    72,     3,    93,    93,
      93,   119,     3,    98,   119,   131,   157,     3,   151,     7,
       8,     9,    72,    74,    76,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    92,   118,   105,    79,    84,
      85,    80,    81,    10,    11,    12,    13,    86,    87,    14,
      15,    78,    88,    89,    16,    17,    90,    77,    93,    95,
     167,    95,   162,    72,    74,   149,   151,   158,   159,    73,
      77,    73,    77,    75,    95,   120,   147,    77,     3,    72,
      91,    95,   141,   143,   160,   161,    95,   120,    77,    93,
      91,   162,   157,    91,   162,   119,   119,   119,    54,   168,
      93,    93,    72,    73,    72,   151,   158,    73,    72,     3,
       3,    73,   100,   117,   119,     3,   117,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     110,   111,   112,   113,   114,   119,   117,    95,    73,   153,
     158,    75,   120,   159,    72,    74,    48,   155,     3,   137,
     142,   154,    77,    95,   133,   120,    73,   162,    73,    73,
      73,    72,   168,   101,   102,   117,   105,   101,    92,    73,
      77,    75,    91,    73,    73,    75,    73,   153,    75,   120,
      73,    77,    95,   160,   162,   162,   162,   119,    73,   119,
      73,    77,    73,    63,   117,   116,    73,    75,   165,    52,
      73,   162,    73,   117,    98,   162,    93,   162,    72,   101,
      73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    97,    97,    97,    98,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   105,   105,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     109,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   122,   122,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   125,   125,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     131,   131,   131,   131,   132,   132,   133,   133,   133,   134,
     134,   135,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   140,   141,   142,   142,   143,   143,   143,
     144,   144,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     151,   151,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   156,   156,   157,   157,   158,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   161,   161,   162,   162,   162,   162,   162,   162,
     162,   163,   163,   164,   164,   164,   165,   165,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   169,   170,
     170,   170,   170,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   174,   174,   174,   174
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     5,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     0,     1,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     2,     3,     3,
       4,     2,     1,     3,     2,     1,     1,     1,     1,     3,
       2,     1,     2,     1,     5,     1,     0,     2,     1,     1,
       1,     1,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     9,     5,     3,     4,     3,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     3,     2
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

#line 1834 "grammar.tab.c"

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

#line 521 "grammar.y"

#include <stdio.h>

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
		std::cout << "Input file does not exist!";
		exit(0);
	}
    int abc=yyparse();
    if(abc){
        cout << "parsing failed!" << endl;
    }
    else{
        cout << "parsing successful" << endl;
    }
    return 0;
}
