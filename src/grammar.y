
%code requires {
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

}

%{
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


%}
%union{
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
}
%token <str> IDENTIFIER CONSTANT STRING_LITERAL CONST_FLOAT CONST_CHAR CONST_EXP
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME 

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID 
%token STRUCT UNION ENUM ELLIPSIS NULL_TOKEN MEMBER

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token CLASS DELETE NEW PRIVATE PUBLIC PROTECTED THIS UNTIL BOOL TRUE FALSE
%type <node> translation_unit external_declaration
%type <typ> statement labeled_statement jump_statement
%type <typ> delete_statement selection_statement expression_statement iteration_statement
%type <declaration> declaration
%type <fun_def> function_definition
%type <ini_lst> initializer_list
%type <dec_spec> declaration_specifiers
%type <dec> declarator 
%type <arg_ex_list> argument_expression_list
%type <dec_list> declaration_list
%type <comp_stmt> compound_statement
%type <abs_d> abstract_declarator
%type <dir_ad> direct_abstract_declarator
%type <init_dec_list> init_declarator_list
%type <str> storage_class_specifier class_name access_specifier assignment_operator
%type<type_spec> type_specifier
%type<class_spec> class_specifier
%type<str_union> struct_or_union_specifier
%type <str> type_qualifier unary_operator
%type <typ> statement_list
%type <str> struct_id union_id struct union 
%type <struc_dec_list> struct_declaration_list
%type <struc_dec> struct_declaration
%type <sql> specifier_qualifier_list 
%type <sdl> struct_declarator_list 
%type <sd> struct_declarator
%type <bc> base_class
%type <bcl> base_class_list
%type <ty_nm> type_name
%type <inh_spec> inheritance_specifier
%type <ini> initializer
%type <class_mem_dec_list> class_body class_member_declaration_list
%type <class_mem_dec> class_member_declaration
%type <memd> member_declaration
%type <typ> primary_expression postfix_expression assignment_expression expression
%type <typ> constant_expression unary_expression cast multiplicative_expression
%type <typ> additive_expression shift_expression relational_expression equality_expression
%type <typ> and_expression exclusive_or_expression inclusive_or_expression cast_expression
%type <typ> logical_and_expression logical_or_expression conditional_expression 
%type <for_cb> fcrb;
%type <constrdec> constructor_declaration
%type <enum_spec> enum_specifier
%type <enuml> enumerator_list 
%type <enumer> enumerator
%type <point> pointer
%type <dir_dec> direct_declarator
%type <func_decl> function_declaration
%type <dec> init_declarator 
%type <pl> parameter_list parameter_type_list
%type <tql> type_qualifier_list
%type <par_dec> parameter_declaration
%type <int_value> m crb els srb doo smc colon emp
%type <str> swtch
%start translation_unit
%%

primary_expression
	: IDENTIFIER {Type* t=get_type_id($1);
	cout << t->base << endl;cout << "get type id in primary exp done" << endl;Symbol_Info* x=get_symbol_info_id($1);
	if(x->tempname.empty()){string nn=get_new_temp();x->tempname=nn;final_symtab[nn]=x;temp_and_type[nn]=t;}t->place=x->tempname;$$=t;$$->isreal_var=true;}
	| CONSTANT {Type* t=new Type(); t->isbasic=true;t->base="INT";string nn=get_new_temp();global_code.push_back(get_code4($1,"","",nn));t->place=nn;$$=t;temp_and_type[nn]=t;} 
	| STRING_LITERAL {Type* t=new Type(); t->isbasic=true;t->base="CHAR";t->ptr_level=1;t->ptrtql.emplace_back(false,false);string nn=get_new_temp();global_code.push_back(get_code4($1,"","",nn));t->place=nn;$$=t;temp_and_type[nn]=t;}
	| CONST_CHAR {Type* t=new Type(); t->isbasic=true;t->base="CHAR";$$=t;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4($1,"","",nn));$$=t;temp_and_type[nn]=t;}
	| CONST_FLOAT {Type* t=new Type();t->isbasic=true;t->base="FLOAT";$$=t;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4($1,"","",nn));$$=t;temp_and_type[nn]=t;}
	| CONST_EXP {Type* t=get_type_exp($1);string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4($1,"","",nn));$$=t;temp_and_type[nn]=t;}
	| '(' expression ')' {$$=$2;backpatch($$->truelist,global_code.size());backpatch($$->falselist,global_code.size());$$->truelist=vector<int>();$$->falselist=vector<int>();}
	| NULL_TOKEN {Type* t=new Type();t->isnull=true;string nn=get_new_temp();t->place=nn;global_code.push_back(get_code4("nullptr","","",nn));$$=t;temp_and_type[nn]=t;}
	;
postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression '[' expression ']' {Type* type=check_if_array_or_pointer($1);$$=type;string nn=get_new_temp();
	backpatch($3->truelist,global_code.size());backpatch($3->falselist,global_code.size());global_code.push_back(get_code_array($1->place,$3->place,nn));$$->place=nn;temp_and_type[nn]=type;}
	| postfix_expression '(' ')' {Type* t=check_if_function($1);check_argument_with_params($1->prms,vector<Type*>(),false);
		string nn=get_new_temp();
		global_code.push_back(get_code_func(nn,$1->place));
		$$=t;temp_and_type[nn]=t;}
	| postfix_expression '(' argument_expression_list ')' {Type* t=check_if_function($1);cout << "hello ##  vargs: " << $1->isvarargs << endl; check_argument_with_params($1->prms,$3->vec_exp,$1->isvarargs);
		for(auto i:$3->prm_temps){
			global_code.push_back(get_param_code(i));
		}
		string nn=get_new_temp();
		global_code.push_back(get_code_func(nn,$1->place));
		cout << "got argument list here" << endl;t->place=nn;
		$$=t;temp_and_type[nn]=t;}
	| postfix_expression '.' IDENTIFIER {check_if_obj($1);Type* type=check_if_id_in_obj($1,$3);
		string nn1=get_new_temp();
		string nn2=get_new_temp();
		global_code.push_back(get_code4($1->place, nn1, ".",nn2));$$=type;
		$$->place=nn2;

		;
	}
	| postfix_expression PTR_OP IDENTIFIER {check_if_obj_ptr($1);Type* type=check_if_id_in_obj($1,$3);
		string nn1=get_new_temp();
		string nn2=get_new_temp();
		global_code.push_back(get_code4($1->place, nn1, "->",nn2));
		$$=type;
		$$->place=nn2;}
	| postfix_expression INC_OP  {check_inc_dec_op($1);Type* xx=$1;$$=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4($1->place,"","++",nn));global_code.push_back(get_code4("",nn,"",$1->place));$$->place=$1->place;$$->truelist=vector<int>();$$->falselist=vector<int>();temp_and_type[nn]=$$;}
	| postfix_expression DEC_OP {check_inc_dec_op($1);Type* xx=$1;$$=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4($1->place,"","--",nn));global_code.push_back(get_code4("",nn,"",$1->place));$$->place=$1->place;$$->truelist=vector<int>();$$->falselist=vector<int>();temp_and_type[nn]=$$;}
	;

argument_expression_list
	: assignment_expression {Argument_Expression_List* z=new Argument_Expression_List();z->vec_exp.push_back($1);$$=z;
	backpatch($1->truelist,global_code.size());$$->prm_temps.push_back($1->place);backpatch($1->falselist,global_code.size());}
	| argument_expression_list ',' assignment_expression {$1->vec_exp.push_back($3);$$=$1;
	cout << "backpatching of second arg done" << endl;
	backpatch($3->truelist,global_code.size());$$->prm_temps.push_back($3->place);backpatch($3->falselist,global_code.size());}
	;

unary_expression
	: postfix_expression {$$=$1;}
	| INC_OP unary_expression /*array function and constant struct union bool class void */ {check_inc_dec_op($2);Type* xx=$2;$$=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4("",$2->place,"++",nn));global_code.push_back(get_code4("",nn,"",$2->place));$$->place=$2->place;$$->truelist=vector<int>();$$->falselist=vector<int>();
		temp_and_type[nn]=$$;}
	| DEC_OP unary_expression  {check_inc_dec_op($2);Type* xx=$2;$$=new Type(*xx);string nn=get_new_temp();global_code.push_back(get_code4("",$2->place,"--",nn));
		global_code.push_back(get_code4("",nn,"",$2->place));$$->place=$2->place;$$->truelist=vector<int>();$$->falselist=vector<int>();
		temp_and_type[nn]=$$;}
	| unary_operator cast_expression {Type* type=get_type_unary_expression($1,$2);$$=type;cout<<"got &"<<endl;string nn=get_new_temp();
		global_code.push_back(get_code4("",$2->place,$1,nn));$$->place=nn;
		temp_and_type[nn]=$$;}
	| SIZEOF unary_expression {check_for_sizeof($2); Type* t=new Type(); t->isbasic=true; t->base="INT";$$=t;string nn=get_new_temp();
		global_code.push_back(get_code4("",$2->place,"SIZEOF",nn));$$->place=nn;
		temp_and_type[nn]=$$;}/* void , functiions */
	| SIZEOF '(' type_name ')' {check_for_sizeof($3->type);Type* t=new Type();t->isbasic=true;t->base="INT";$$=t;
		string nn=get_new_temp();global_code.push_back(get_code4("",get_string_type($3->type),"SIZEOF ",nn));$$->place=nn;
		temp_and_type[nn]=$$;}
	;

unary_operator
	: '&' {$$="&";}
	| '*' {$$="*";}//dereference
	| '+' {$$="+";}
	| '-' {$$="-";}
	| '~' {$$="~";}//bitwise not
	| '!' {$$="!";} 
	;

cast_expression
	: unary_expression {$$=$1;}
	| '(' type_name ')' cast_expression {check_typecast_compatibility($2->type,$4);$$=$2->type;}
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression {Type* type=check_for_arithmatic_op($1,$3,"*");string nn=get_new_temp();
		type->place=nn;string cod=get_code4($1->place,$3->place,"*",nn);
		merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;
		temp_and_type[nn]=$$;}
	| multiplicative_expression '/' cast_expression {Type* type=check_for_arithmatic_op($1,$3,"/");string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,"/",nn);
		merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;
		temp_and_type[nn]=$$;}
	| multiplicative_expression '%' cast_expression	{Type* type=check_for_arithmatic_op($1,$3,"%");string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,"%",nn);
		merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;
		temp_and_type[nn]=$$;}
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression {Type* type=check_for_arithmatic_op($1,$3,"+");string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,"+",nn);
		merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;
		temp_and_type[nn]=$$;}
	| additive_expression '-' multiplicative_expression {Type* type=check_for_arithmatic_op($1,$3,"-");string nn=get_new_temp();
		type->place=nn;string cod=get_code4($1->place,$3->place,"-",nn);merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;
		temp_and_type[nn]=$$;}
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_OP additive_expression  {check_for_shift_op($1,$3);Type* type=new Type(*$1);string nn=get_new_temp();string cod=get_code4($1->place,$3->place,"<<",nn);
		merge_code1(type->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);type->place=nn;$$=type;
		temp_and_type[nn]=$$;}
	| shift_expression RIGHT_OP additive_expression {check_for_shift_op($1,$3);Type* type=new Type(*$1);string nn=get_new_temp();
		string cod=get_code4($1->place,$3->place,">>",nn);merge_code1(type->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;$$=type;
		temp_and_type[nn]=$$;}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression {check_for_arithmatic_op($1,$3,"<");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,"<",nn);/*merge_code(type->code,$1->code,$3->code);
		type->code.push_back(cod);*/global_code.push_back(cod);$$=type;temp_and_type[nn]=$$;}
	| relational_expression '>' shift_expression {check_for_arithmatic_op($1,$3,">");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,">",nn);merge_code(type->code,$1->code,$3->code);
		type->code.push_back(cod);global_code.push_back(cod);$$=type;temp_and_type[nn]=$$;}
	| relational_expression LE_OP shift_expression {check_for_arithmatic_op($1,$3,"<=");Type* type=new Type();type->isbasic=true;type->base="INT";
		string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,"<=",nn);merge_code(type->code,$1->code,$3->code);
		type->code.push_back(cod);global_code.push_back(cod);$$=type;temp_and_type[nn]=$$;}
	| relational_expression GE_OP shift_expression {check_for_arithmatic_op($1,$3,">=");Type* type=new Type();type->isbasic=true;
		type->base="INT";string nn=get_new_temp();type->place=nn;string cod=get_code4($1->place,$3->place,">=",nn);
		merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);global_code.push_back(cod);$$=type;temp_and_type[nn]=$$;}
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ_OP relational_expression {Type* type=check_for_eq_op($1,$3);string nn=get_new_temp();type->place=nn;
		string cod=get_code4($1->place,$3->place,"==",nn);merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);;$$=type;temp_and_type[nn]=$$;}
	| equality_expression NE_OP relational_expression {Type* type=check_for_eq_op($1,$3);string nn=get_new_temp();type->place=nn;
		string cod=get_code4($1->place,$3->place,"!=",nn);merge_code(type->code,$1->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);$$=type;temp_and_type[nn]=$$;}
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression {check_for_shift_op($1,$3);Type* type=new Type(*$1);string nn=get_new_temp();
		string cod=get_code4($1->place,$3->place,"&",nn);merge_code1(type->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;$$=type;temp_and_type[nn]=$$;}
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression {check_for_shift_op($1,$3);Type* type=new Type(*$1);string nn=get_new_temp();
		string cod=get_code4($1->place,$3->place,"^",nn);merge_code1(type->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;$$=type;temp_and_type[nn]=$$;}
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression {check_for_shift_op($1,$3);Type* type=new Type(*$1);string nn=get_new_temp();
		string cod=get_code4($1->place,$3->place,"|",nn);merge_code1(type->code,$3->code);type->code.push_back(cod);
		global_code.push_back(cod);type->place=nn;$$=type;temp_and_type[nn]=$$;}
	;

logical_and_expression
	: inclusive_or_expression {cout << "logical end done" << endl;Type* type=$1;
		type->truelist.push_back(global_code.size());type->falselist.push_back(global_code.size()+1);
		cout << "####pushing if code ###" << endl;
		global_code.push_back(get_if_true_code(type->place));global_code.push_back(get_if_false_code());$$=type;}
	| logical_and_expression AND_OP m inclusive_or_expression {check_for_shift_op($1,$4);Type* type=new Type(*$1);type->truelist=$1->truelist;type->falselist=$1->falselist;type->nextlist=$1->nextlist;string nn=get_new_temp();
		string cod=get_code4($1->place,$4->place,"&&",nn);merge_code1(type->code,$4->code);type->code.push_back(cod);
		$4->truelist.push_back(global_code.size());$4->falselist.push_back(global_code.size()+1);
		global_code.push_back(get_if_true_code($4->place));global_code.push_back(get_if_false_code());
		global_code.push_back(cod);type->place=nn;
		backpatch(type->truelist,$3);type->falselist=merge(type->falselist,$4->falselist);type->truelist=$4->truelist;$$=type;temp_and_type[nn]=$$;}
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR_OP m logical_and_expression { cout << "logical or done" << endl;check_for_shift_op($1,$4);Type* type=new Type(*$1);type->truelist=$1->truelist;type->falselist=$1->falselist;type->nextlist=$1->nextlist;string nn=get_new_temp();string cod=get_code4($1->place,$4->place,"||",nn);merge_code1(type->code,$4->code);
		type->code.push_back(cod);global_code.push_back(cod);type->place=nn;
		backpatch(type->falselist,$3);type->truelist=merge(type->truelist,$4->truelist);type->falselist=$4->falselist;$$=type;temp_and_type[nn]=$$;}
	;

conditional_expression
	: logical_or_expression {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression   {Type* type=check_for_assign($3,$5,"=");$$=type;}
	;

assignment_expression
	: conditional_expression  {$$=$1; }
	| unary_expression assignment_operator assignment_expression  {Type* t=check_for_assign($1,$3,$2);merge_code(t->code,$1->code,$3->code);
		string cod;
		if($2=="="){
			cod=get_code4($3->place,"","",$1->place);
		}
		else if($2=="*="){
			cod=get_code4($1->place,$3->place,"*",$1->place);
		}
		else if($2=="/="){
			cod=get_code4($1->place,$3->place,"/",$1->place);
		}
		else if($2=="%="){
			cod=get_code4($1->place,$3->place,"%",$1->place);
		}
		else if($2=="+="){
			cod=get_code4($1->place,$3->place,"+",$1->place);
		}
		else if($2=="-="){
			cod=get_code4($1->place,$3->place,"-",$1->place);
		}
		else if($2=="<<="){
			cod=get_code4($1->place,$3->place,"<<",$1->place);
		}
		else if($2==">>="){
			cod=get_code4($1->place,$3->place,">>",$1->place);
		}
		else if($2=="&="){
			cod=get_code4($1->place,$3->place,"&",$1->place);
		}
		else if($2=="^="){
			cod=get_code4($1->place,$3->place,"^",$1->place);
		}
		else{
			cod=get_code4($1->place,$3->place,"|",$1->place);
		}
		backpatch($3->truelist,global_code.size());
		backpatch($3->falselist,global_code.size());
		global_code.push_back(cod);$$=t;
		}
	;
assignment_operator
	: '=' {$$="=";}
	| MUL_ASSIGN {$$="*=";}
	| DIV_ASSIGN {$$="/=";}
	| MOD_ASSIGN {$$="%=";}
	| ADD_ASSIGN {$$="+=";}
	| SUB_ASSIGN {$$="-=";}
	| LEFT_ASSIGN {$$="<<=";}
	| RIGHT_ASSIGN {$$=">>=";}
	| AND_ASSIGN {$$="&=";}
	| XOR_ASSIGN {$$="^=";}
	| OR_ASSIGN {$$="|=";}
	;

expression
	: assignment_expression {$$=$1; cout<<"finally expression has identifier"<<endl;}
	| expression ',' assignment_expression {$$=$1;backpatch($3->truelist,global_code.size());backpatch($3->falselist,global_code.size());}
	;

constant_expression
	: conditional_expression {$$=$1; backpatch($$->truelist, global_code.size()); backpatch($$->falselist,global_code.size());}
	;
/* stack dekho and level name vali fied bharo iski */
/* fix error notebook ka 1 */
/*check whether type is correct*/
declaration
	: declaration_specifiers ';' {$$=create_declaration_object($1,nullptr,nullptr);} /* make declaration object and assign its pointer to $$. add declaration specifiers to declaration object created. find the type using declaration specifiers. */
	| declaration_specifiers init_declarator_list ';' {$$=create_declaration_object($1,$2,nullptr);}/* create object as above but add both fields*/
/* thik karna hai action*/	/*| typedef_specifier declarator ';' {$$=create_declaration_object($1,nullptr,nullptr);}*//* same as above . check whether typedef specifier is there in typedef table. */
	;

/*typedef_specifier
	:IDENTIFIER 
	;*/

declaration_specifiers
	: storage_class_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); if(ds==nullptr){assert(0);}
	ds->scs.push_back($1);
	$$=ds;} /* create object of declaration specifier. add storage class specifier to vector of storage class specifier* in decl spec. and pass it above.*/ 
	| storage_class_specifier declaration_specifiers {Declaration_Specifiers* ds=$2;ds->scs.push_back($1);$$=ds;cout << "declaration specifier done scs" << endl;}/* add storage_class_specifier to $2*/
	| type_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back($1);$$=ds;cout << ds->ts.back()->string_type << endl;cout<<"got type specifier"<<endl;}/* create declaration specifier object . add type specifier to it . pass it above. */
	| type_specifier declaration_specifiers {cout<<"declaration_specifier started"<<endl;Declaration_Specifiers* ds=$2; ds->ts.push_back($1);$$=ds;cout<<"declaration specifier completed"<<endl;}/* add type_specifier to $2 */
	| type_qualifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back($1);$$=ds;}/* create declaration_specifiers object . add type qualifier to it . pass it above. */
	| type_qualifier declaration_specifiers {Declaration_Specifiers* ds=$2; ds->tq.push_back($1);$$=ds;}/* add type_qualifier to $2 */
	;

init_declarator_list
	: init_declarator {Init_Declarator_List* x=new Init_Declarator_List();x->idl.push_back($1);$$=x;
	if($1->type=="function"){current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	cout << "current params list cleared" << endl;}
	cout<<"idl completeted"<<endl;}
	| init_declarator_list ',' init_declarator { $1->idl.push_back($3); $$ = $1;}
	;

init_declarator
	: declarator {$$=$1;}
	| declarator '=' initializer {cout<<"init_declartor started"<<endl;$1->ini=$3;$$=$1;
	cout<<"init_declarator done"<<endl;
	$1->tempname=get_new_temp();
		global_code.push_back(get_code4($3->type->place,"","",$1->tempname));
	}
	;

storage_class_specifier
	:/* TYPEDEF */
	| EXTERN {$$="EXTERN";}
	| STATIC {$$="STATIC";cout << "STATIC" << endl;}
	| AUTO {$$="AUTO";}
	| REGISTER {$$="REGISTER";}
	;

type_specifier
    : VOID { $$ = create_ts_obj(std::string("VOID"), nullptr, nullptr, nullptr); }
	| CHAR	{$$=create_ts_obj("CHAR",nullptr,nullptr,nullptr);}
	| SHORT {$$=create_ts_obj("SHORT",nullptr,nullptr,nullptr);}
	| INT {$$=create_ts_obj("INT",nullptr,nullptr,nullptr);cout<<"INT Passed"<<endl;}
	| LONG {$$=create_ts_obj("LONG",nullptr,nullptr,nullptr);}
	| FLOAT {$$=create_ts_obj("FLOAT",nullptr,nullptr,nullptr);}
	| DOUBLE {$$=create_ts_obj("DOUBLE",nullptr,nullptr,nullptr);}
	| SIGNED {$$=create_ts_obj("SIGNED",nullptr,nullptr,nullptr);}
	| UNSIGNED {$$=create_ts_obj("UNSIGNED",nullptr,nullptr,nullptr);cout<<"hurrah"<<endl;}
	| struct_or_union_specifier {cout<<"struct_or_union_specifier found"<<endl;$$=create_ts_obj("",$1,nullptr,nullptr);}
   /* | class_specifier {cout<<"completed class specifier"<<endl;$$=create_ts_obj("",nullptr,$1,nullptr);}*/
	| enum_specifier {$$=create_ts_obj("",nullptr,nullptr,$1);cout<<" found enum in type specifier"<<endl;}
	/*| TYPE_NAME {$$=create_ts_obj("TYPE_NAME",nullptr,nullptr,nullptr);}*/
	;

struct_or_union_specifier
	:  struct struct_id '{' struct_declaration_list '}' { $$=create_struct_union_spec_obj(std::string($1),std::string($2),$4);
	 cout << "create struct union spec object done" << endl;
	current_level--; current_table=current_table->parent;
	 lvl_name.pop();add_to_local_class_struct_union_info();
	 cout << "add to local class struct union info done" << endl;
	}/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	/*| struct'{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->parent;lvl_name.pop();add_to_local_class_struct_union_info();}*//* same as above */
	| struct IDENTIFIER {cout<<"struct identifier reached"<<endl;check_if_declared(current_table,$2,"struct");$$=create_struct_union_spec_obj($1,$2,nullptr);}/* whether this identifier is declared before use */
	| union union_id '{' struct_declaration_list '}' {cout<<"union uid sdl started"<<endl;$$=create_struct_union_spec_obj($1,$2,$4);current_level--;current_table=current_table->parent;lvl_name.pop();add_to_local_class_struct_union_info();}/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	/*| union '{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->parent;lvl_name.pop();add_to_local_class_struct_union_info();}*/ /* same as above */
	| union IDENTIFIER {check_if_declared(current_table,$2,"union");$$=create_struct_union_spec_obj($1,$2,nullptr);/* whether this identifier is declared before use */}
	;

struct_id 
	: IDENTIFIER {lvl_name.push("struct " + std::string($1));$$=$1;current_class_struct_union_info.push(std::make_pair($1,nullptr));ccsui_type.push("struct");cout<<"got struct identifier"<<endl;}
	;
union_id
	: IDENTIFIER {cout<<"identifier in uid started"<<endl;lvl_name.push("union " + std::string($1));$$=$1;current_class_struct_union_info.push(std::make_pair($1,nullptr));ccsui_type.push("union");cout<<"Passed IDENTIFIER to uid"<<endl;}
	;
struct
	: STRUCT /*just pass */ {$$="struct";cout <<"finally reached to struct"<<endl;}
	;
union
	: UNION {$$="union";cout<<"passed UNION"<<endl;}
	;

struct_declaration_list
	: struct_declaration {cout << "struct declaration list done" << endl;
	current_level++;Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back($1);$$=x;current_table=next_table();add_to_local_table(current_table,$1);if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}} /* create struct declaration list object . add struct decl to it. make a new local table push it in children of current table. move to new table. add struct declaration to it . */
	| struct_declaration_list struct_declaration {Struct_Declaration_List* x=$1;x->sdl.push_back($2);$$=x;add_to_local_table(current_table,$2);} /* add struct decl. to already made object.  add struct declaration to current table*/
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'{cout<<"struct declaration started"<<endl;$$=create_struct_dec_obj($1,$2);cout<<"struct declaration done"<<endl;} /* create type. */ 
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {Specifier_Qualifier_List* x=$2;x->ts.push_back($1);$$=x;} /* add type_specifier to specifier_qualifier_list object already created */
	| type_specifier {cout<<"type spec in sql started"<<endl;Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->ts.push_back($1);cout<<"type spec in sql ended"<<endl;$$=x;}/* create object of specifier_qualifier_list . add type_specifier to it */
	| type_qualifier specifier_qualifier_list {Specifier_Qualifier_List* x=$2;x->tq.push_back($1);$$=x;}  /* same as above rule */
	| type_qualifier {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->tq.push_back($1);$$=x;} /* same as above rule */
	;

struct_declarator_list
	: struct_declarator  {cout<<"got struct declarator"<<endl;Struct_Declarator_List* x=new Struct_Declarator_List();x->sd.push_back($1);cout<<"struct declarator done"<<endl;$$=x;}/* create struct declarator list object . add struct declarator to it . */
	| struct_declarator_list ',' struct_declarator  {Struct_Declarator_List* x=$1;x->sd.push_back($3);$$=x;}/* add struct declarator to existing list */
	;

struct_declarator
	: declarator /* pass this above */ {$$=create_struct_declarator_obj($1);}
	/*| ':' constant_expression {$$=create_struct_declarator_obj(nullptr,$2);}*//* will find out what this is for later */
	/*| declarator ':' constant_expression  {$$=create_struct_declarator_obj($1,$3);}*/ /* will find out what this is for later */
	;

class_specifier
    : CLASS class_name class_body  {$$=new Class_Specifier(std::string($2),nullptr,$3);} 
    | CLASS class_name inheritance_specifier class_body {$$=new Class_Specifier(std::string($2),$3,$4);}
	| CLASS class_name {$$=new Class_Specifier(std::string($2),nullptr,nullptr);check_if_declared(current_table,std::string($2),"class");}
    ;

inheritance_specifier
    : ':' base_class_list {$$=new Inheritance_Specifier($2);}
    ;

base_class_list
    : base_class /* make base_class_list object and add base class*/ {Base_Class_List* x=new Base_Class_List();x->bc.push_back($1);}
    | base_class_list ',' base_class {Base_Class_List* x=$1;x->bc.push_back($3);}/* add base class to existing list */
    ;

base_class
    : access_specifier IDENTIFIER   /*  make base class object. add info */ {check_if_declared(current_table,std::string($2),"class");$$=new Base_Class($1,std::string($2));}
    | IDENTIFIER {check_if_declared(current_table,$1,"class");$$=new Base_Class("",std::string($1));}/* make base class object. add info with access specifier as default */
    ;

access_specifier
    : PUBLIC /* pass */ {$$="PUBLIC";}
    | PRIVATE {$$="PRIVATE";}
    | PROTECTED {$$="PROTECTED";}
    ;

class_body
    : '{' class_member_declaration_list '}' {$$=$2; current_level--;current_table=current_table->parent;lvl_name.pop();while(!access_spec_stk.empty())access_spec_stk.pop();add_to_local_class_struct_union_info();}/*come to parent table from current table. pass above*/ 
    | '{' '}' {lvl_name.pop();add_to_local_class_struct_union_info();}/* pass empty class member declaration list object */
    ;

class_name
    : IDENTIFIER /* pass */ { $$ = $1; string s="class "; s+=$1;lvl_name.push(s);current_class_struct_union_info.push(std::make_pair($1, nullptr) );ccsui_type.push("class"); }
    ;
class_member_declaration_list
    : class_member_declaration {Class_Member_Declaration_List* x=new Class_Member_Declaration_List();x->cd.push_back($1);current_level++;current_table=next_table();if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}}  /* make obj class_member_declaration_list . add class_member_declaration. */
    | class_member_declaration_list class_member_declaration { $1->cd.push_back($2); $$ = $1;}/* add class_member_declaration to existing obj */
    ;

constructor_declaration
    : class_name'(' parameter_list ')' compound_statement {current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	add_params_to_map($3);$$=new Constructor_Declaration(std::string($1),$3,$5);} /* make a constructor declaration with class name and parameter list and body */
	| class_name '(' ')' compound_statement {current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	$$=new Constructor_Declaration(std::string($1),nullptr,$4);}
    ;


class_member_declaration
    : access_specifier ':' {access_spec_stk.push($1);} /* make class_member_declaration obj and add access specifier to it . pass */
    | member_declaration {$$=new Class_Member_Declaration($1,nullptr);}/* make class_member_declaration obj and add member decl to it . pass */
    | constructor_declaration {$$=new Class_Member_Declaration(nullptr,$1);add_to_local_table(current_table,$1);}/* make class_member_declaration obj and add constructor_declaration to it . pass */
    ;

member_declaration
	: function_definition {$$=new Member_Declaration(nullptr,nullptr,$1);add_to_local_table(current_table,$1);}
    | specifier_qualifier_list declarator ';' {$$=new Member_Declaration($1,$2,nullptr);add_to_local_table(current_table,$1,$2);} /* do not add directly in local symtab , change grammar*/
    ;

enum_specifier
	/*: ENUM '{' enumerator_list '}' {$$=new Enum_Specifier(std::string(""),$3);}*/
	: ENUM IDENTIFIER '{' enumerator_list '}' {cout<<"enum id el started"<<endl; cout << $4->e.back()->id << "!!!!" << endl;$$=new Enum_Specifier(std::string($2),$4);cout<<"enum specifier object created"<<endl;Type* t=new Type();t->isenum=true;t->isobj=true;t->obj_class=$2;t->objtype="enum";cout<<"no bt upto t->objtype"<<endl;add_to_local_table($4,t);cout<<"enum id el done"<<endl;}
	| ENUM IDENTIFIER {$$=new Enum_Specifier(std::string($2),nullptr);check_if_declared(current_table,std::string($2),"enum");}
	;

enumerator_list
	: enumerator {cout<<"enumerator started"<<endl;Enumerator_List* x=new Enumerator_List();x->e.push_back($1); cout<<"got enumerator in el"<<endl;$$=x;}
	| enumerator_list ',' enumerator {cout<<"enumerator list + enumerator started"<<endl;cout << $3->id << "$#@$#@" << endl;$1->e.push_back($3);cout << $1->e.back()->id << "@#$" << endl;cout<<"enumerator list + enumerator returned"<<endl;$$=$1;}
	;

enumerator
	: IDENTIFIER {$$=new Enumerator(std::string($1),new Type());cout<<"id in enumerator"<<endl;cout<<($1)<<endl;}
	| IDENTIFIER '=' constant_expression {$$=new Enumerator(std::string($1),$3);check_int_comp($3);}
	;

type_qualifier
	: CONST  {$$="CONST";}/* just pass */
	| VOLATILE {$$="VOLATILE";}/* just pass */
	;


declarator
	: pointer direct_declarator {$$=create_new_declarator($1,$2);cout<<"got pointer direct declarator"<<endl;}
	| direct_declarator {$$=create_new_declarator(nullptr,$1);cout<<"##"<<endl;}/* check if is a function . if yes then add its name to stack */
	;

direct_declarator
	: IDENTIFIER {$$=create_direct_declarator(std::string("id"),$1,nullptr,nullptr,nullptr,nullptr);}
	| '(' declarator ')' {$$=create_direct_declarator(std::string("declarator"),"",$2,nullptr,nullptr,nullptr);}
	| direct_declarator '[' constant_expression ']' {$$=create_direct_declarator(std::string("array"),"",nullptr,$1,nullptr,nullptr);check_int_comp($3);backpatch($3->truelist,global_code.size());backpatch($3->falselist,global_code.size());}
	| direct_declarator '[' ']' {$$=create_direct_declarator(std::string("array"),"",nullptr,$1,nullptr,nullptr);}
	| direct_declarator '(' parameter_type_list ')' {$$=create_direct_declarator(std::string("function"),"",nullptr,$1,nullptr,$3);}/* add parameters to current params list */
/*	| direct_declarator '(' identifier_list ')' */
	| direct_declarator '(' ')' {$$=create_direct_declarator(std::string("function"),"",nullptr,$1,nullptr,nullptr);}
	;

pointer
	: '*' {$$=new Pointer(nullptr,nullptr);}
	| '*' type_qualifier_list {$$=new Pointer($2,nullptr);}
	| '*' pointer {$$=new Pointer(nullptr,$2);}
	| '*' type_qualifier_list pointer {$$=new Pointer($2,$3);}
	;

type_qualifier_list
	: type_qualifier {Type_Qualifier_List* x=new Type_Qualifier_List();x->tq.push_back($1);$$=x;}
	| type_qualifier_list type_qualifier {Type_Qualifier_List* x=$1;x->tq.push_back($2);$$=x;}
	;


parameter_type_list
	: parameter_list {$$=$1;}
	| parameter_list ',' ELLIPSIS {Parameter_List* x=$1; x->ellipses=true;}
	;

parameter_list
	: parameter_declaration {Parameter_List* x=new Parameter_List();x->pl.push_back($1);$$=x;}
	| parameter_list ',' parameter_declaration {$1->pl.push_back($3);$$=$1;}
	;

parameter_declaration
	: declaration_specifiers declarator {$$=new Parameter_Declaration($1,$2);}
	/*| declaration_specifiers abstract_declarator
	| declaration_specifiers */
	;
/*
identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;
*/
type_name
	: specifier_qualifier_list  { $$=new Type_Name($1,nullptr);}
	| specifier_qualifier_list abstract_declarator {$$=new Type_Name($1,$2);$2->type=$2->check_abstract_declarator();}
	;

abstract_declarator
	: pointer {Abstract_Declarator* x=new Abstract_Declarator($1,nullptr);$$=x;}
	| direct_abstract_declarator {Abstract_Declarator* x=new Abstract_Declarator(nullptr,$1);$$=x;}
	| pointer direct_abstract_declarator {Abstract_Declarator* x=new Abstract_Declarator($1,$2);$$=x;}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {$$=new Direct_Abstract_Declarator("abs_dec",$2,nullptr,nullptr,nullptr);}
	| '[' ']'						{$$=new Direct_Abstract_Declarator("array",nullptr,nullptr,nullptr,nullptr);}
	| '[' constant_expression ']' {check_int_comp($2);$$=new Direct_Abstract_Declarator("array",nullptr,nullptr,$2,nullptr);}
	| direct_abstract_declarator '[' ']' {$$=new Direct_Abstract_Declarator("array",nullptr,$1,nullptr,nullptr);}
	| direct_abstract_declarator '[' constant_expression ']' {check_int_comp($3);$$=new Direct_Abstract_Declarator("array",nullptr,$1,$3,nullptr);}
	| '(' ')'	{$$=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,nullptr);}
	| '(' parameter_type_list ')'  {$$=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,$2);}
	| direct_abstract_declarator '(' ')' {$$=new Direct_Abstract_Declarator("func",nullptr,$1,nullptr,nullptr);}
	| direct_abstract_declarator '(' parameter_type_list ')' {$$=new Direct_Abstract_Declarator("func",nullptr,$1,nullptr,$3);}
	;

initializer
	: assignment_expression  {Initializer* x=new Initializer($1,"",nullptr,"",nullptr);x->type=$1;$$=x;backpatch($1->truelist,global_code.size());backpatch($1->falselist,global_code.size());}
	| '{' initializer_list '}' {$$=new Initializer(new Type(),"",$2,"",nullptr);} 
	| '{' initializer_list ',' '}' {$$=new Initializer(new Type(),"",$2,"",nullptr);} 
	| NEW class_name '(' argument_expression_list ')' {Type* t=get_type_id($2);check_if_constructor(t);check_argument_with_params(t->prms,$4->vec_exp,false);Type* z=new Type();z->isobj=true;z->objtype="class";z->obj_class=$2;Initializer* gg=new Initializer(z,"",nullptr,$2,$4);$$=gg;} 
	| NEW class_name '(' ')' {Type* t=get_type_id($2);check_if_constructor(t);check_argument_with_params(t->prms,vector<Type*>(),false);Type*z=new Type();z->isobj=true;z->objtype=="class";z->obj_class=$2;Initializer* gg=new Initializer(z,"",nullptr,$2,nullptr);$$=gg;}
	;

initializer_list
	: initializer {Initializer_List* x=new Initializer_List();x->iv.push_back($1);$$=x;}
	| initializer_list ',' initializer {$1->iv.push_back($3);$$=$1;}
	;

statement
	: labeled_statement {$$=$1; }
	| compound_statement {$$=$1->st;cout<<"finally statemeexpression_statementnt has compound statement"<<endl;}
	| expression_statement {$$=$1; cout << "expression statement" << endl;}
	| selection_statement {$$=$1;}
	| iteration_statement {$$=$1;}
	| jump_statement {$$=$1;}
	| delete_statement {}
	;

delete_statement
	: DELETE IDENTIFIER {check_if_pointer(get_type_id($2));}
	| DELETE '[' ']' IDENTIFIER {check_if_array(get_type_id($4));}
	;

labeled_statement
	: IDENTIFIER ':' m statement {if(labelset.find($1)==labelset.end())labelset.insert($1);else {cout << "label declared twice" << endl;exit(1);}$$=$4;
		backpatch(goto_label, $3);
		labelgoto.push_back($1);
		labelmap[$1]=$3;
		}
	| CASE constant_expression colon statement {$$=$4; 
	
		fill_eqeq_exp1($3-2,$2->place);
		backpatch1($3-2,$3);
		backpatch1($3-1, global_code.size());
		}
	| DEFAULT ':' statement {cout<<"finally reached to default"<<endl;$$=$3;}
	;

colon
	: ':' { switch_true.push_back(global_code.size());
			global_code.push_back(get_if_true_code("=="));	
			switch_false.push_back(global_code.size());		
			global_code.push_back(get_if_false_code());
			$$=global_code.size();

			}


compound_statement
	: '{' '}' {Compound_Statement* x=new Compound_Statement(new Type(),nullptr);$$=x;}
	| '{' statement_list '}' {Compound_Statement* x=new Compound_Statement($2,nullptr);cout<<"obj of compound statement done for st_lst"<<endl; cout<<"loop completed"<<endl;$$=x;cout<<"statement_list done in compound_statement"<<endl;}
	| '{' declaration_list '}' {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),$2);cout << "compound_statement parsed" << endl;
	current_level--;current_table=current_table->parent;cout << current_level << "in compound statement" << endl;
	$$=x;}
	| '{' declaration_list statement_list '}' {cout << "calling comp statement constr"<<endl;Compound_Statement* x=new Compound_Statement(new Type(),$2);
	current_level--;current_table=current_table->parent;
	$$=x;cout << "compound_statement parsed" << endl;}
	;

declaration_list
	: declaration {current_level++;cout << "checking for next table" << endl;Declaration_List* x=new Declaration_List();x->dv.push_back($1);current_table=next_table();
	cout << "next table working fine" << endl;add_to_local_table(current_table,$1);cout << "declaration list done successfully" << endl;
	cout << current_level << "in declaration_list" << endl;
	$$=x;}
	| declaration_list declaration {cout<<"declaration_list done"<<endl;$1->dv.push_back($2);$$=$1;add_to_local_table(current_table,$2);}
	;

statement_list
	: statement { cout << "statement parsed" << endl;$$=$1;}
	| statement_list statement {$$=$2;}
	;

expression_statement
	: ';' {$$=new Type();cout<<"semi colon"<<endl;}
	| expression {$$=$1;backpatch($1->truelist,global_code.size());backpatch($1->falselist,global_code.size());}
	;
smc
	: ';' {$$=global_code.size();}
selection_statement
	: IF '(' expression crb statement { cout << "other if else done" << endl;
		backpatch($3->truelist,$4);
		 Type* zz=new Type();
		zz->nextlist=merge($3->falselist, $5->nextlist);backpatch(zz->nextlist,global_code.size());$$=zz; 
	}
	| IF '(' expression crb statement els statement  {cout << "if_else done" << endl;
		backpatch($3->truelist,$4);
		backpatch ($3->falselist,$6);
		Type* zz=new Type(); zz->nextlist=merge($5->nextlist,$7->nextlist);
		backpatch(zz->nextlist,global_code.size());
		vector<int> nw;
		nw.push_back($6-1);
		backpatch(nw,global_code.size());
		 $$=zz;}

	| SWITCH '(' expression crb emp statement {$$=$6;
		backpatch($3->truelist, $4);
		backpatch($3->falselist, $4);
		backpatch(break_label, global_code.size());
		fill_eqeq_exp2(switch_true, $3->place);
		}
	;
emp
	: {
		$$=global_code.size();
		
		
	  }


m 
	: {$$=global_code.size();}


iteration_statement
	: WHILE srb expression crb statement {$$=$5;
	backpatch($5->nextlist, $2);
	backpatch($3->truelist, $4);
	$$->nextlist=$3->falselist;
	global_code.push_back(get_while_code($2));
	backpatch($$->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, $2);
	}


	| UNTIL srb expression crb statement {$$=$5;
	backpatch($5->nextlist, $2);
	backpatch($3->truelist, $4);
	$$->nextlist=$3->falselist;
	global_code.push_back(get_while_code($2));
	backpatch($$->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, $2);
	}

	| doo statement WHILE srb expression ')' ';' {$$=$2;
	$$->nextlist=$5->falselist;
	backpatch($5->truelist, $1);
	backpatch($$->nextlist, global_code.size());
	backpatch(break_label, global_code.size());
	backpatch(continue_label, $1);
	}

	| FOR '(' expression smc expression smc ')' statement { $$=$8;
		backpatch($5->truelist,$6);
		$$->nextlist=$5->falselist;
		global_code.push_back(get_while_code($4));
		backpatch($5->falselist,global_code.size());
		backpatch(break_label, global_code.size());
		backpatch(continue_label, $4);
		}


	| FOR '(' expression smc expression smc expression fcrb statement { $$=$9;
		backpatch($5->truelist,$8->pos);
		backpatch($8->nextlist,$4);
		backpatch($7->truelist,$8->pos-1);
		backpatch($7->falselist,$8->pos-1);
		global_code.push_back(get_while_code($6));
		backpatch($5->falselist,global_code.size());
		$$=$9;$$->nextlist=$5->falselist;
		backpatch(break_label, global_code.size());
		backpatch(continue_label, $4);
		}
	;

fcrb
	: ')' {FCRB* t=new FCRB();t->nextlist.push_back(global_code.size());global_code.push_back(get_if_false_code());t->pos=global_code.size();$$=t;}

doo
	: DO {$$=global_code.size();}
   
crb 
	: ')' {$$=global_code.size();}
	;
els 
	: ELSE {global_code.push_back("goto ");$$=global_code.size();}

srb
	: '(' {$$=global_code.size();}
	;


jump_statement
	: GOTO IDENTIFIER ';' {$$=new Type();
 		goto_label.push_back(global_code.size());
 		if(identifier_found(labelgoto, $2)){
 		global_code.push_back(get_while_code(labelmap[$2]));
 		}
 		else{
 		global_code.push_back(get_if_false_code());}
 		}
 	| CONTINUE ';' {$$=new Type();
 		continue_label.push_back(global_code.size());
 		global_code.push_back(get_if_false_code());}
 	| BREAK ';' {$$=new Type();cout<<"found break"<<endl;
 		break_label.push_back(global_code.size());
 		global_code.push_back(get_if_false_code());}
	| RETURN ';' {Type* type=new Type();type->isvoid=true;check_for_assign(func_ret_type,type,"=");global_code.push_back(gen_return(""));}
	| RETURN initializer ';' {check_for_assign(func_ret_type,$2->type,"=");global_code.push_back(gen_return($2->type->place));}

translation_unit /* (type:node*) nothing much just keep pointers to all external declarations */
	: external_declaration {cout<<"reached ext declaration"<<endl;Node* ext=create_node();cout<<"create node done"<<endl;}
	| translation_unit external_declaration {Node* ext=create_node();cout<<"t_u and e_d"<<endl;}
	;

external_declaration /* (type:node*) storing pointers to function_definition and declaration */
	: function_definition  {cout<<"external declaration started"<<endl;add_to_gst($1,gst);cout<<"add to gst"<<endl;$$=$1;cout<<"external declaration started"<<endl;}/* assign pointer of function declaration to external declaration pointer. add function definition to gst*/
	| declaration {add_to_gst($1,gst);$$=$1;}/* add this declaration to global symbol table. assign this pointer to ext declaration object*/
	;
function_declaration
	: declaration_specifiers declarator { Function_Declaration* x=new Function_Declaration($1,$2);
		Type* type=new Type();
		string t=create_type($1,$2,type);
		cout << "create type for func decl done successfully"<<endl;
		$2->check_for_func();cout << "check for func done successfully in func decl" << endl;
		$$=x;
		lvl_name.push(get_name($2));
		string sc="global";
		if(current_level>0)sc="local";
		Symbol_Info* si=new Symbol_Info($2->id,t,get_level_name(),current_level-lvl_name.size()+1,sc,"-",type);
		func_ret_type=type->func_ret_type ; 
		current_func_name=$2->id;
		if(current_level==0&&current_func_name=="main"){
			$2->tempname="main";
		}
		else{
			$2->tempname=get_new_temp();
		}
		si->tempname=$2->tempname;
		current_func_si=si;
		global_code.push_back(get_label($2->tempname));
		cout<<"@@@"<<endl;
		cout<<get_label($2->tempname)<<endl;
		for(auto i:current_param_vector){
			string nn=get_new_temp();
			i.second->place=nn;
			current_params_list[i.first]->place=nn;
			global_code.push_back(get_label_param(nn));
		}
		cout<<"final func decl done huuh"<<endl;
		}
	;
function_definition /*(function_definition <- node ) */
	/*: declaration_specifiers declarator declaration_list compound_statement {Function_Definition* x=create_func_def($1,$2,$3,$4);current_params_list.clear();lvl_name.pop();func_ret_type=nullptr;}*/ /* create function definition object.parameter. assign type. assign size. */
	: function_declaration compound_statement {Function_Declaration* x=$1;$$=create_func_def(x->ds,x->d,$2);
	cout<<"create func def done"<< endl;
	current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	cout << "current params list cleared" << endl;
	func_ret_type==nullptr;
	current_func_name="";
	current_func_si=nullptr;
	lvl_name.pop();}/*same as above */
	/*| declarator declaration_list compound_statement {$$=create_func_def(nullptr,$1,$2,$3);lvl_name.pop();} *//*same as above*/ 
	/*| declarator compound_statement {$$=create_func_def(nullptr,$1,nullptr,$2);lvl_name.pop();}*//* same as above */
	;

%%
#include <stdio.h>
#include <bits/stdc++.h>
#include <classes_NT.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


void yyerror(const char *s) {
    fflush(stdout);
	
}
