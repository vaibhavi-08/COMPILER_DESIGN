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

#ifndef YY_YY_SRC_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_SRC_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "src/grammar.y"

    // Forward declarations
    class Node;
    class Function_Definition;
    class Declaration_Specifiers;
    class Declarator;
    class Declaration_List;
    class Compound_Statement;
	class Declaration;
	class Init_Declarator_List;
	class Typedef_Specifier;
	class Type_Specifier;
	class Struct_or_Union_Specifier;
	class Enum_Specifier;
	class Struct_Declaration_List;
	class Struct_Declaration;
	class Global_Symbol_Table;
	class Local_Symbol_Table;
	class Specifier_Qualifier_List;
	class Struct_Declarator_List;
	class Struct_Declarator;
	class Class_Member_Declaration;
	class Class_Member_Declaration_List;
	class Class_Specifier;
	class Base_Class;
	class Base_Class_List;
	class Inheritance_Specifier;
	class Member_Declaration;
	class Constructor_Declaration;
	class Enum_Specifier;
	class Enumerator_List;
	class Enumerator;
	class Function_Declaration;
	class Init_Declarator;
	class Parameter_List;
	class Pointer;
	class Direct_Declarator;
	class Type_Qualifier_List;
	class Parameter_Declaration;
	class Expression;
	class Type_Name;
	class Abstract_Declarator;
	class Direct_Abstract_Declarator;
	class Type;
	class Initializer;
	class Initializer_List;
	class Argument_Expression_List;
	class Init_Declarator_List;
	class FCRB;


#line 101 "src/grammar.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    CONST_FLOAT = 261,             /* CONST_FLOAT  */
    CONST_CHAR = 262,              /* CONST_CHAR  */
    CONST_EXP = 263,               /* CONST_EXP  */
    SIZEOF = 264,                  /* SIZEOF  */
    PTR_OP = 265,                  /* PTR_OP  */
    INC_OP = 266,                  /* INC_OP  */
    DEC_OP = 267,                  /* DEC_OP  */
    LEFT_OP = 268,                 /* LEFT_OP  */
    RIGHT_OP = 269,                /* RIGHT_OP  */
    LE_OP = 270,                   /* LE_OP  */
    GE_OP = 271,                   /* GE_OP  */
    EQ_OP = 272,                   /* EQ_OP  */
    NE_OP = 273,                   /* NE_OP  */
    AND_OP = 274,                  /* AND_OP  */
    OR_OP = 275,                   /* OR_OP  */
    MUL_ASSIGN = 276,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 277,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 278,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 279,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 280,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 281,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 282,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 283,              /* AND_ASSIGN  */
    XOR_ASSIGN = 284,              /* XOR_ASSIGN  */
    OR_ASSIGN = 285,               /* OR_ASSIGN  */
    TYPE_NAME = 286,               /* TYPE_NAME  */
    TYPEDEF = 287,                 /* TYPEDEF  */
    EXTERN = 288,                  /* EXTERN  */
    STATIC = 289,                  /* STATIC  */
    AUTO = 290,                    /* AUTO  */
    REGISTER = 291,                /* REGISTER  */
    CHAR = 292,                    /* CHAR  */
    SHORT = 293,                   /* SHORT  */
    INT = 294,                     /* INT  */
    LONG = 295,                    /* LONG  */
    SIGNED = 296,                  /* SIGNED  */
    UNSIGNED = 297,                /* UNSIGNED  */
    FLOAT = 298,                   /* FLOAT  */
    DOUBLE = 299,                  /* DOUBLE  */
    CONST = 300,                   /* CONST  */
    VOLATILE = 301,                /* VOLATILE  */
    VOID = 302,                    /* VOID  */
    STRUCT = 303,                  /* STRUCT  */
    UNION = 304,                   /* UNION  */
    ENUM = 305,                    /* ENUM  */
    ELLIPSIS = 306,                /* ELLIPSIS  */
    NULL_TOKEN = 307,              /* NULL_TOKEN  */
    MEMBER = 308,                  /* MEMBER  */
    CASE = 309,                    /* CASE  */
    DEFAULT = 310,                 /* DEFAULT  */
    IF = 311,                      /* IF  */
    ELSE = 312,                    /* ELSE  */
    SWITCH = 313,                  /* SWITCH  */
    WHILE = 314,                   /* WHILE  */
    DO = 315,                      /* DO  */
    FOR = 316,                     /* FOR  */
    GOTO = 317,                    /* GOTO  */
    CONTINUE = 318,                /* CONTINUE  */
    BREAK = 319,                   /* BREAK  */
    RETURN = 320,                  /* RETURN  */
    CLASS = 321,                   /* CLASS  */
    DELETE = 322,                  /* DELETE  */
    NEW = 323,                     /* NEW  */
    PRIVATE = 324,                 /* PRIVATE  */
    PUBLIC = 325,                  /* PUBLIC  */
    PROTECTED = 326,               /* PROTECTED  */
    THIS = 327,                    /* THIS  */
    UNTIL = 328,                   /* UNTIL  */
    BOOL = 329,                    /* BOOL  */
    TRUE = 330,                    /* TRUE  */
    FALSE = 331                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "src/grammar.y"

	Node* node;
	Function_Definition* fun_def;
	Declaration* declaration;
	Declaration_Specifiers* dec_spec;
	Declarator* dec;
	Declaration_List* dec_list;
	Init_Declarator_List* init_dec_list;
	Typedef_Specifier* typedef_spec;
	Type_Specifier* type_spec;
	Struct_or_Union_Specifier* str_union;
	Enum_Specifier* enum_spec;
	Struct_Declaration_List* struc_dec_list;
	Struct_Declaration * struc_dec;
	Specifier_Qualifier_List* sql;
	Struct_Declarator_List* sdl;
	Struct_Declarator* sd;
	Class_Specifier* class_spec;
	Base_Class* bc;
	Base_Class_List* bcl;
	Inheritance_Specifier* inh_spec;
	Member_Declaration* memd;
	Constructor_Declaration* constrdec;
	Enumerator_List* enuml;
	Enumerator* enumer;
	Function_Declaration* func_decl;
	char* str;
	Class_Member_Declaration* class_mem_dec;
	Class_Member_Declaration_List* class_mem_dec_list;
	Pointer* point;
	Direct_Declarator* dir_dec;
	Parameter_List* pl;
	Type_Qualifier_List* tql;
	Parameter_Declaration* par_dec;
	Compound_Statement* comp_stmt;
	std::vector<int>* vec_int;
	int int_value;
	Type* typ;
	Argument_Expression_List* arg_ex_list;
	Type_Name* ty_nm;
	Abstract_Declarator* abs_d;
	Direct_Abstract_Declarator* dir_ad;
	Initializer_List* ini_lst;
	Initializer* ini;
	FCRB* for_cb;

#line 241 "src/grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_GRAMMAR_TAB_H_INCLUDED  */
