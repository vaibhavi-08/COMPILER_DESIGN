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
	class Type_Name
	class Abstract_Declarator
	class Direct_Abstract_Declarator
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
	Init_Declarator* init_dec;
	char* str;
	Class_Member_Declaration* class_mem_dec;
	Class_Member_Declaration_List* class_mem_dec_list;
	Pointer* point;
	Direct_Declarator* dir_dec;
	Parameter_List* pl;
	Type_Qualifier_List* tql;
	Parameter_Declaration* par_dec;
	Compound_Statement* comp_stmt;
	Expression* expr;
	vector<int> vec_int;
	int int_value;
}
%token <str> IDENTIFIER CONSTANT STRING_LITERAL CONST_FLOAT CONST_CHAR CONST_EXP
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID 
%token STRUCT UNION ENUM ELLIPSIS NULL

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token CLASS DELETE NEW PRIVATE PUBLIC PROTECTED THIS UNTIL BOOL TRUE FALSE
%type <node> translation_unit external_declaration
%type <init_value> statement statement_list labeled_statement jump_statement
%type <init_value> delete_statement selection_statement expression_statement iteration_statement
%type <declaration> declaration
%type <fun_def> function_definition
%type <dec_spec> declaration_specifiers
%type <dec> declarator
%type <dec_list> declaration_list
%type <comp_stmt> compound_statement
%type <init_dec_list> init_declarator_list
%type <str> storage_class_specifier class_name access_specifier assignment_operator
%type<type_spec> type_specifier
%type<class_spec> class_specifier
%type<str_union> struct_or_union_specifier
%type <str> type_qualifier unary_operator
%type <vec_int> statement_list
%type <str> struct_id union_id struct union
%type <struc_dec_list> struct_declaration_list
%type <struc_dec> struct_declaration
%type <sql> specifier_qualifier_list 
%type <sdl> struct_declarator_list 
%type <sd> struct_declarator
%type <bc> base_class
%type <bcl> base_class_list
%type <inh_spec> inheritance_specifier
%type <node> initializer
%type <class_mem_dec_list> class_body class_member_declaration_list
%type <class_mem_dec> class_member_declaration
%type <memd> member_declaration
%type <expr> primary_expression postfix_expression assignment_expression
%type <expr> constant_expression unary_expression cast multiplicative_expression
%type <expr> additive_expression shift_expression relational_expression equality_expression
%type <expr> and_expression exclusive_or_expression inclusive_or_expression
%type <expr> logical_and_expression logical_or_expression conditional_expression
%type <expr> assignment_expression
%type <constrdec> constructor_declaration
%type <enum_spec> enum_specifier
%type <enuml> enumerator_list
%type <enumer> enumerator
%type <point> pointer
%type <dir_dec> direct_declarator
%type <func_decl> function_declaration
%type <init_dec> init_declarator 
%type <pl> parameter_list parameter_type_list
%type <tql> type_qualifier_list
%type <par_dec> parameter_declaration
%start translation_unit
%%

primary_expression
	: IDENTIFIER (pair<string,string> x=get_type_id($1);$$=new Expression(x.first,x.second);)
	| CONSTANT {$$=new Expression("INT","");} 
	| STRING_LITERAL {$$=new Expression("CONST CHAR*","");}
	| CONST_CHAR {$$=new Expression("CHAR","");}
	| CONST_FLOAT {$$=new Expression("FLOAT","");}
	| CONST_EXP {$$=new Expression(get_type_exp($1),"");}
	| '(' expression ')' {$$=new Expression($1->type,"");}
	| NULL {$$=new Expression("NULL","");}
	;

class_name
    : IDENTIFIER /* pass */ { $$ = $1; lvl_name.push("class " + $1);current_class_struct_union_info.push(std::make_pair($1, nullptr) ); }
    ;

postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression '[' expression ']' {string type=check_if_array_or_pointer($1);$$=new Expression(type,"");}
	| postfix_expression '(' ')' {vector<Parameter_Declaration*> prms=check_if_function($1->name);check_argument_with_params($1,prms);$$=new Expression($1->type,"");}
	| postfix_expression '(' argument_expression_list ')' {vector<Parameter_Declaration*> prms=check_if_function($1->name);check_argument_with_params($1,prms);$$=new Expression($1->type,"");}
	| postfix_expression '.' IDENTIFIER {check_obj($1);string type=check_if_id_in_obj($1->type,$3);$$=new Expression(type,"");}/*check if $1 is object and idenfier is the member of that class*/}
	| postfix_expression PTR_OP IDENTIFIER {check_obj_ptr($1);string type=check_if_id_in_obj($1->type,$3);$$=new Expression(type,"");/*check if $1 is an pointer to class struct or union*/}
	| postfix_expression INC_OP /* later */ {type=check_inc_dec_op_right();$$=new Expression(type,"");}
	| postfix_expression DEC_OP {type=check_inc_dec_op_right();$$=new Expression(type,"");}
	;

argument_expression_list
	: assignment_expression {Argument_Expression_List* z=new Argument_Expression_List();z->vec_exp.push_back($1);$$=z;}
	| argument_expression_list ',' assignment_expression {$1->vec_exp.push_back($3);$$=$1;}
	;

unary_expression
<<<<<<< HEAD
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression 
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
=======
	: postfix_expression {$$=$1;}
	| INC_OP unary_expression /*array function and constant struct union bool class void */ {check_inc_dec_op($2);$$=$1;}
	| DEC_OP unary_expression  {check_inc_dec_op($2);$$=$1;}
	| unary_operator cast_expression {string type=get_type_unary_expression($1,$2);$$=new Expression(type,"");}
	| SIZEOF unary_expression {check_for_sizeof($2->type); $$=new Expression("UNSIGNED INT","");}/* void , functiions */
	| SIZEOF '(' type_name ')' {check_for_sizeof($3->type);$$=new Expression("UNSIGNED INT","");}
>>>>>>> fffed73e09192fc175fa42f84e1006c77167d5af
	;

unary_operator
	: '&' {$$="&";}
	| '*' {$$="*";}//dereference
	| '+' {$$="+";}
	| '-' {$$="-";}
	| '~' {$$=""~";}//bitwise not
	| '!' {$$="!";} 
	;

cast_expression
	: unary_expression {$$=$1;}
	| '(' type_name ')' cast_expression {check_typecast_compatibility($2->type,$4);$$=new Expression($2->type,"");}
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| multiplicative_expression '/' cast_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| multiplicative_expression '%' cast_expression	{string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| additive_expression '-' multiplicative_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_OP additive_expression  {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	| shift_expression RIGHT_OP additive_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| relational_expression '>' shift_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| relational_expression LE_OP shift_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	| relational_expression GE_OP shift_expression {string type=check_for_arithmatic_op($1,$3);$$=new Expression(type,"");}
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ_OP relational_expression {string type=check_for_eq_op($1,$3);$$=new Expression(type,"");}
	| equality_expression NE_OP relational_expression {string type=check_for_eq_op($1,$3);$$=new Expression(type,"");}
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

logical_and_expression
	: inclusive_or_expression {$$=$1;}
	| logical_and_expression AND_OP inclusive_or_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR_OP logical_and_expression {string type=check_for_shift_op($1,$3);$$=new Expression(type,"");}
	;

conditional_expression
	: logical_or_expression {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression   {string type=check_for_assign($3,$5);$$=new Expression(type,"");}
	;

assignment_expression
	: conditional_expression  {$$=$1;}
	| unary_expression assignment_operator assignment_expression  {string type=check_for_assign($1,$3,$2);$$=new Expression(type,"");}
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
	: assignment_expression 
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression {$$=$1;}
	;
/* stack dekho and level name vali fied bharo iski */
/* fix error notebook ka 1 */
/*check whether type is correct*/
declaration
	: declaration_specifiers ';' {$$=create_declaration_object($1,nullptr,nullptr);} /* make declaration object and assign its pointer to $$. add declaration specifiers to declaration object created. find the type using declaration specifiers. */
	| declaration_specifiers init_declarator_list ';' {$$=create_declaration_object($1,$2,nullptr);func_ret_type="";current_params_list.clear();}/* create object as above but add both fields*/
/* thik karna hai action*/	/*| typedef_specifier declarator ';' {$$=create_declaration_object($1,nullptr,nullptr);}*//* same as above . check whether typedef specifier is there in typedef table. */
	;

/*typedef_specifier
	:IDENTIFIER 
	;*/

declaration_specifiers
	: storage_class_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->scs.push_back($1);$$=ds;} /* create object of declaration specifier. add storage class specifier to vector of storage class specifier* in decl spec. and pass it above.*/ 
	| storage_class_specifier declaration_specifiers {Declaration_Specifiers* ds=$2;ds->scs.push_back($1);$$=ds;}/* add storage_class_specifier to $2*/
	| type_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back($1);$$=ds;}/* create declaration specifier object . add type specifier to it . pass it above. */
	| type_specifier declaration_specifiers {Declaration_Specifiers* ds=$2; ds->ts.push_back($1);$$=ds;}/* add type_specifier to $2 */
	| type_qualifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back($1);$$=ds;}/* create declaration_specifiers object . add type qualifier to it . pass it above. */
	| type_qualifier declaration_specifiers {Declaration_Specifiers* ds=$2; ds->tq.push_back($1);$$=ds;}/* add type_qualifier to $2 */
	;

init_declarator_list
	: init_declarator {Init_Declarator_List* x=new Init_Declarator_List();x->idl.push_back($1);$$=x;}
	| init_declarator_list ',' init_declarator { $1->idl.push_back($3); $$ = $1;}
	;

init_declarator
	: declarator {$$=$1;}
	| declarator '=' initializer {$1->ini=$3;$$=$1;}
	;

storage_class_specifier
	:/* TYPEDEF */
	| EXTERN {$$="EXTERN";}
	| STATIC {$$="STATIC";}
	| AUTO {$$="AUTO";}
	| REGISTER {$$="REGISTER";}
	;

type_specifier
    : VOID { $$ = create_ts_obj(std::string("VOID"), nullptr, nullptr, nullptr); }
	| CHAR	{$$=create_ts_obj("CHAR",nullptr,nullptr,nullptr);}
	| SHORT {$$=create_ts_obj("SHORT",nullptr,nullptr,nullptr);}
	| INT {$$=create_ts_obj("INT",nullptr,nullptr,nullptr);}
	| LONG {$$=create_ts_obj("LONG",nullptr,nullptr,nullptr);}
	| FLOAT {$$=create_ts_obj("FLOAT",nullptr,nullptr,nullptr);}
	| DOUBLE {$$=create_ts_obj("DOUBLE",nullptr,nullptr,nullptr);}
	| SIGNED {$$=create_ts_obj("SIGNED",nullptr,nullptr,nullptr);}
	| UNSIGNED {$$=create_ts_obj("UNSIGNED",nullptr,nullptr,nullptr);}
	| struct_or_union_specifier {$$=create_ts_obj("",$1,nullptr,nullptr);}
    | class_specifier {$$=create_ts_obj("",nullptr,$1,nullptr);}
	| enum_specifier {$$=create_ts_obj("",nullptr,nullptr,$1);}
	/*| TYPE_NAME {$$=create_ts_obj("TYPE_NAME",nullptr,nullptr,nullptr);}*/
	;

struct_or_union_specifier
	:  struct struct_id '{' struct_declaration_list '}' { $$=create_struct_union_spec_obj(std::string($1),std::string($2),$4); current_level--; current_table=current_table->get_parent(); lvl_name.pop();add_to_local_class_struct_union_info(); }/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	/*| struct'{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->get_parent();lvl_name.pop();add_to_local_class_struct_union_info();}*//* same as above */
	| struct IDENTIFIER {check_if_declared(current_table,$2,"struct");$$=create_struct_union_spec_obj($1,$2,nullptr);}/* whether this identifier is declared before use */
	| union union_id '{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,$2,$4);current_level--;current_table=current_table->get_parent();lvl_name.pop();add_to_local_class_struct_union_info();}/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	/*| union '{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->get_parent();lvl_name.pop();add_to_local_class_struct_union_info();}*/ /* same as above */
	| union IDENTIFIER {check_if_declared(current_table,$2,"union");$$=create_struct_union_spec_obj($1,$2,nullptr);/* whether this identifier is declared before use */}
	;

struct_id 
	: IDENTIFIER {lvl_name.push("struct " + std::string($1));$$=$1;current_class_struct_union_info.push(std::make_pair($1,nullptr));}
	;
union_id
	: IDENTIFIER {lvl_name.push("union " + std::string($1));$$=$1;current_class_struct_union_info.push(std::make_pair($1,nullptr));}
	;
struct
	: STRUCT /*just pass */ {$$="STRUCT";}
	;
union
	: UNION {$$="UNION";}
	;

struct_declaration_list
	: struct_declaration {Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back($1);$$=x;current_table=next_table(current_table);add_to_local_table(current_table,$1);if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}} /* create struct declaration list object . add struct decl to it. make a new local table push it in children of current table. move to new table. add struct declaration to it . */
	| struct_declaration_list struct_declaration {Struct_Declaration_List* x=$1;x->sdl.push_back($2);$$=x;add_to_local_table(current_table,$2);} /* add struct decl. to already made object.  add struct declaration to current table*/
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'{$$=create_struct_dec_obj($1,$2);} /* create type. */ 
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {Specifier_Qualifier_List* x=$2;x->ts.push_back($1);} /* add type_specifier to specifier_qualifier_list object already created */
	| type_specifier {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->ts.push_back($1);}/* create object of specifier_qualifier_list . add type_specifier to it */
	| type_qualifier specifier_qualifier_list {Specifier_Qualifier_List* x=$2;x->tq.push_back($1);}  /* same as above rule */
	| type_qualifier {Specifier_Qualifier_List* x=new Specifier_Qualifier_List();x->tq.push_back($1);} /* same as above rule */
	;

struct_declarator_list
	: struct_declarator  {Struct_Declarator_List* x=new Struct_Declarator_List();x->sd.push_back($1);}/* create struct declarator list object . add struct declarator to it . */
	| struct_declarator_list ',' struct_declarator  {Struct_Declarator_List* x=$1;x->sd.push_back($3);}/* add struct declarator to existing list */
	;

struct_declarator
	: declarator /* pass this above */ {$$=create_struct_declarator_obj($1);}
	/*| ':' constant_expression {$$=create_struct_declarator_obj(nullptr,$2);}*//* will find out what this is for later */
	/*| declarator ':' constant_expression  {$$=create_struct_declarator_obj($1,$3);}*/ /* will find out what this is for later */
	;

class_specifier
    : CLASS class_name class_body  {$$=new Class_Specifier(std::string($2),nullptr,$3);} /*  make class_specifier object and add all info.  */
    | CLASS class_name inheritance_specifier class_body {$$=new Class_Specifier(std::string($2),$3,$4);}/* make object add all info . add base classes also in class_specifier */
	| CLASS class_name {$$=new Class_Specifier(std::string($2),nullptr,nullptr);check_if_declared(current_table,std::string($2),"class");}/* check whether variable already declared */
    ;

inheritance_specifier
    : ':' base_class_list /* pass */ {$$=new Inheritance_Specifier($2);}
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
    : '{' class_member_declaration_list '}' {$$=$2; current_level--;current_table=current_table->get_parent();lvl_name.pop();while(!access_spec_stk.empty())access_spec_stk.pop();add_to_local_class_struct_union_info();}/*come to parent table from current table. pass above*/ 
    | '{' '}' {lvl_name.pop();add_to_local_class_struct_union_info();}/* pass empty class member declaration list object */
    ;

class_member_declaration_list
    : class_member_declaration {Class_Member_Declaration_List* x=new Class_Member_Declaration_List();x->cd.push_back($1);current_level++;current_table=next_table(current_table);if(!current_class_struct_union_info.empty()){current_class_struct_union_info.top().second=current_table;}else{cout << "classname not pushed" << endl;}}  /* make obj class_member_declaration_list . add class_member_declaration. */
    | class_member_declaration_list class_member_declaration { $1->cd.push_back($2); $$ = $1;}/* add class_member_declaration to existing obj */
    ;

constructor_declaration
    : class_name'(' parameter_list ')' compound_statement {current_params_list.clear();add_params_to_map($3);$$=new Constructor_Declaration(std::string($1),$3,$5);} /* make a constructor declaration with class name and parameter list and body */
	| class_name '(' ')' compound_statement {current_params_list.clear();$$=new Constructor_Declaration(std::string($1),nullptr,$4);}
    ;


class_member_declaration
    : access_specifier ':' {access_spec_stk.push($1);} /* make class_member_declaration obj and add access specifier to it . pass */
    | member_declaration {$$=new Class_Member_Declaration($1,nullptr);}/* make class_member_declaration obj and add member decl to it . pass */
    | constructor_declaration {$$=new Class_Member_Declaration(nullptr,$1);add_to_local_table(current_table,$1);}/* make class_member_declaration obj and add constructor_declaration to it . pass */
    ;

member_declaration
    : specifier_qualifier_list declarator ';' {$$=new Member_Declaration($1,$2,nullptr);add_to_local_table(current_table,$1,$2);} /* do not add directly in local symtab , change grammar*/
    | function_definition {$$=new Member_Declaration(nullptr,nullptr,$1);add_to_local_table(current_table,$1);}
    ;

enum_specifier
	/*: ENUM '{' enumerator_list '}' {$$=new Enum_Specifier(std::string(""),$3);}*/
	: ENUM IDENTIFIER '{' enumerator_list '}' {$$=new Enum_Specifier(std::string($2),$4);}
	| ENUM IDENTIFIER {$$=new Enum_Specifier(std::string($2),nullptr);check_if_declared(current_table,std::string($2),"enum");}
	;

enumerator_list
	: enumerator {Enumerator_List* x=new Enumerator_List();x->e.push_back($1);}
	| enumerator_list ',' enumerator {Enumerator_List* x=$1;x->e.push_back($3);}
	;

enumerator
	: IDENTIFIER {$$=new Enumerator(std::string($1),nullptr);}
	| IDENTIFIER '=' constant_expression {$$=new Enumerator(std::string($1),$3);}
	;

type_qualifier
	: CONST  {$$="CONST";}/* just pass */
	| VOLATILE {$$="VOLATILE";}/* just pass */
	;

declarator
	: pointer direct_declarator {$$=create_new_declarator($1,$2);}
	| direct_declarator {$$=create_new_declarator(nullptr,$1);}/* check if is a function . if yes then add its name to stack */
	;

direct_declarator
	: IDENTIFIER {$$=create_direct_declarator(std::string("id"),$1,nullptr,nullptr,nullptr,nullptr);}
	| '(' declarator ')' {$$=create_direct_declarator(std::string("declarator"),"",$2,nullptr,nullptr,nullptr);}
	| direct_declarator '[' constant_expression ']' {$$=create_direct_declarator(std::string("array"),"",nullptr,$1,nullptr,nullptr);check_int_comp($3->type);}
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
	| specifier_qualifier_list abstract_declarator {$$=new Type_Name($1,$2);$1->type=$1->check_abstract_declarator();}
	;

abstract_declarator
	: pointer {Abstract_Declarator* x=new Abstract_Declarator($1,nullptr);$$=x;}
	| direct_abstract_declarator {Abstract_Declarator* x=new Abstract_Declarator(nullptr,$2);$$=x;}
	| pointer direct_abstract_declarator {Abstract_Declarator* x=new Abstract_Declarator($1,$2);$$=x;}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {$$=new Direct_Abstract_Declarator("abs_dec",$3,nullptr,nullptr,nullptr);}
	| '[' ']'						{$$=new Direct_Abstract_Declarator("array",nullptr,nullptr,nullptr,nullptr);}
	| '[' constant_expression ']' {check_int_comp($1->type);$$=new Direct_Abstract_Declarator("array",nullptr,nullptr,$2,nullptr);}
	| direct_abstract_declarator '[' ']' {$$=new Direct_Abstract_Declarator("array",nullptr,$1,nullptr,nullptr);}
	| direct_abstract_declarator '[' constant_expression ']' {new Direct_Abstract_Declarator("array",nullptr,$1,$3,nullptr);}
	| '(' ')'	{$$=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,nullptr);}
	| '(' parameter_type_list ')'  {$$=new Direct_Abstract_Declarator("func",nullptr,nullptr,nullptr,$2);}
	| direct_abstract_declarator '(' ')' {$$=new Direct_Abstract_Declarator("func",nullptr,$1,nullptr,nullptr);}
	| direct_abstract_declarator '(' parameter_type_list ')' {$$=new Direct_Abstract_Declarator("func",nullptr,$1,nullptr,$3);}
	;

initializer
	: assignment_expression  {$$=new Initializer($1->type,$1->name,nullptr,"",nullptr);}
	| '{' initializer_list '}' {$$=new Initializer("","",$2,"",nullptr);} 
	| '{' initializer_list ',' '}' {$$=new Initializer("","",$2,"",nullptr);} 
	| NEW class_name '(' argument_expression_list ')' {$$=new Initializer("","",nullptr,$2,$4);} 
	| NEW class_name '(' ')' {$$=new Initializer("","",nullptr,$2,nullptr);}
	;

initializer_list
	: initializer {Initializer_List* x=new Initializer_List();x->iv.push_back($1);$$=$1;}
	| initializer_list ',' initializer {$1->iv.push_back($3);$$=$1;}
	;

statement
	: labeled_statement 
	| compound_statement 
	| expression_statement 
	| selection_statement 
	| iteration_statement 
	| jump_statement 
	| delete_statement 
	;

delete_statement
	: DELETE IDENTIFIER (check_if_pointer();)
	| DELETE '[' ']' IDENTIFIER (check_if_array();)
	;

labeled_statement
	: IDENTIFIER ':' statement {if(labelset.find($1)==labelset.end())labelset.insert($1);else {cout << "label declared twice" << endl;exit(1);}}
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}' {Compound_Statement* x=new Compound_Statement(nullptr,nullptr);}
	| '{' statement_list '}' {Compound_Statement* x=new Compound_Statement($2,nullptr);for(int i:$2){if(i==1)x->have_ret=1;}}
	| '{' declaration_list '}' {Compound_Statement* x=new Compound_Statement(nullptr,$2);}
	| '{' declaration_list statement_list '}' {Compound_Statement* x=new Compound_Statement($3,$2);for(int i:$3){if(i==1)x->have_ret=1;}}
	;

declaration_list
	: declaration {Declaration_list* x=new Declaration_List();x->dv.push_back($1);$$=x;current_level++;current_table->get_parent();add_to_local_table(current_table,$1);}
	| declaration_list declaration {$1->dv.push_back($2);$$=$1;add_to_local_table(current_table,$2);}
	;

statement_list
	: statement {vector<int> z;z.push_back($1);$$=$1;}
	| statement_list statement {$1.push_back($2);$$=$1;}
	;

expression_statement
	: ';' {$$=0;}
	| expression ';' {$$=0;}
	;

selection_statement
	: IF '(' expression ')' statement {$$=$4;}
	| IF '(' expression ')' statement ELSE statement {$$=($4|$6);}
	| SWITCH '(' expression ')' statement {$$=$5;}
	;

iteration_statement
	: WHILE '(' expression ')' statement {$$=$5;}
	| UNTIL '(' expression ')' statement {$$=$5;}
	| DO statement WHILE '(' expression ')' ';' {$$=$5;}
	| FOR '(' expression_statement expression_statement ')' statement {$$=$6;}
	| FOR '(' expression_statement expression_statement expression ')' statement {$$=$7;}
	;

jump_statement
	: GOTO IDENTIFIER ';' {$$=0;}
	| CONTINUE ';' {$$=0;}
	| BREAK ';' {$$=0;}
	| RETURN ';' {if(current_level==lvl_name.size()){check_if_function(lvl_name.top());}else{cout << "return not allowed here" << endl;exit(0);}$$=1;}
	| RETURN initializer ';' {if(current_level==lvl_name.size()){check_if_function(lvl_name.top());}else{cout << "return not allowed here" << endl;exit(0);} check_compatibility($2,func_ret_type);$$=$1;}
	;

translation_unit /* (type:node*) nothing much just keep pointers to all external declarations */
	: external_declaration {Node* ext=create_node();ext->add_child($1);root->add_child(ext);}
	| translation_unit external_declaration {Node* ext=create_node();ext->add_child($2);root->add_child(ext);}
	;

external_declaration /* (type:node*) storing pointers to function_definition and declaration */
	: function_definition  {add_to_gst($1,gst);$$=$1;}/* assign pointer of function declaration to external declaration pointer. add function definition to gst*/
	| declaration {add_to_gst($1,gst);$$=$1;}/* add this declaration to global symbol table. assign this pointer to ext declaration object*/
	;
function_declaration
	: declaration_specifiers declarator { Function_Declaration* x=new Function_Declaration($1,$2);string t=create_type($1,$2);$2->check_for_func();$$=x;func_ret_type=t; lvl_name.push(get_name($2));}
	;
function_definition /*(function_definition <- node ) */
	/*: declaration_specifiers declarator declaration_list compound_statement {Function_Definition* x=create_func_def($1,$2,$3,$4);current_params_list.clear();lvl_name.pop();if(!$2->have_ret){cout << "return type needed in func" << endl;exit(1);}}*/ /* create function definition object.parameter. assign type. assign size. */
	: function_declaration compound_statement {Function_Declaration* x=$1;$$=create_func_def(x->ds,x->d,$2);current_params_list.clear();lvl_name.pop();}/*same as above */
	/*| declarator declaration_list compound_statement {$$=create_func_def(nullptr,$1,$2,$3);lvl_name.pop();} *//*same as above */
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