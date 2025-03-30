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
	Compound_Statement* comp_stmt;
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
	char* str;
	Class_Member_Declaration* class_mem_dec;
	Class_Member_Declaration_List* class_mem_dec_list;
}
%token <str> IDENTIFIER CONSTANT STRING_LITERAL 
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token CLASS DELETE NEW PRIVATE PUBLIC PROTECTED THIS UNTIL BOOL TRUE FALSE
%type <node> translation_unit external_declaration
%type <declaration> declaration
%type <fun_def> function_definition
%type <dec_spec> declaration_specifiers
%type <dec> declarator
%type <dec_list> declaration_list
%type <comp_stmt> comp_stmt
%type <init_dec_list> init_declarator_list
%type <str> storage_class_specifier class_name access_specifier
%type<type_spec> type_specifier
%type<class_spec> class_specifier
%type<str_union> struct_or_union_specifier
%type<enum_spec> enum_specifier
%type <str> type_qualifier
%type <str> struct_id union_id struct union
%type <struc_dec_list> struct_declaration_list
%type <struc_dec> struct_declaration
%type <sql> specifier_qualifier_list 
%type <sdl> struct_declarator_list 
%type <sd> struct_declarator
%type <bc> base_class
%type <bcl> base_class_list
%type <inh_spec> inheritance_specifier
%type <node> constant_expression compound_statement
%type <class_mem_dec_list> class_member_declaration_list
%type <class_mem_dec> class_body class_member_declaration

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

class_name
    : IDENTIFIER /* pass */ { $$ = $1; lvl_name.push(std::string("class") + $1); }
    ;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;
argument_list_opt
    : /* empty */
    | argument_list
    ;

argument_list
    : assignment_expression
    | argument_list ',' assignment_expression
    ;
unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
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
	: storage_class_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->scs.push_back($1);$$=ds;} /* create object of declaration specifier. add storage class specifier to vector of storage class specifier* in decl spec. and pass it above.*/ 
	| storage_class_specifier declaration_specifiers {Declaration_Specifiers* ds=$2;ds->scs.push_back($1);}/* add storage_class_specifier to $2*/
	| type_specifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->ts.push_back($1);}/* create declaration specifier object . add type specifier to it . pass it above. */
	| type_specifier declaration_specifiers {Declaration_Specifiers* ds=$2; ds->ts.push_back($1);}/* add type_specifier to $2 */
	| type_qualifier {Declaration_Specifiers* ds=create_decl_spec_object(); ds->tq.push_back($1);}/* create declaration_specifiers object . add type qualifier to it . pass it above. */
	| type_qualifier declaration_specifiers {Declaration_Specifiers* ds=$2; ds->tq.push_back($1);}/* add type_qualifier to $2 */
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
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
	:  struct struct_id '{' struct_declaration_list '}' { $$=create_struct_union_spec_obj(std::string($1),std::string($2),$4); current_level--; current_table=current_table->get_parent(); lvl_name.pop(); }/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	| struct'{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->get_parent();lvl_name.pop();}/* same as above */
	| struct IDENTIFIER {check_if_declared(current_table,$2,"struct");$$=create_struct_union_spec_obj($1,$2,nullptr);}/* whether this identifier is declared before use */
	| union union_id '{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,$2,$4);current_level--;current_table=current_table->get_parent();lvl_name.pop();}/* make a struct_or_union_specifier object. enter all info. move current table pointer to parent table */
	| union '{' struct_declaration_list '}' {$$=create_struct_union_spec_obj($1,"",$3);current_level--;current_table=current_table->get_parent();lvl_name.pop();} /* same as above */
	| union IDENTIFIER {check_if_declared(current_table,$2,"union");$$=create_struct_union_spec_obj($1,$2,nullptr);/* whether this identifier is declared before use */}
	;

struct_id 
	: IDENTIFIER {lvl_name.push("struct " + std::string($1));$$=$1;}
	;
union_id
	: IDENTIFIER {lvl_name.push("union " + std::string($1));$$=$1;}
	;
struct
	: STRUCT /*just pass */ {$$="STRUCT";}
	;
union
	: UNION {$$="UNION";}
	;

struct_declaration_list
	: struct_declaration {Struct_Declaration_List* x=new Struct_Declaration_List();x->sdl.push_back($1);$$=x;current_table=next_table(current_table);add_to_local_table(current_table,$1);} /* create struct declaration list object . add struct decl to it. make a new local table push it in children of current table. move to new table. add struct declaration to it . */
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
	: declarator /* pass this above */ {$$=create_struct_declarator_obj($1,nullptr);}
	| ':' constant_expression {$$=create_struct_declarator_obj(nullptr,$2);}/* will find out what this is for later */
	| declarator ':' constant_expression  {$$=create_struct_declarator_obj($1,$3);} /* will find out what this is for later */
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
    : '{' class_member_declaration_list '}' {$$=$2; current_level--;current_table=current_table->get_parent();lvl_name.pop();}/*come to parent table from current table. pass above*/ 
    | '{' '}' {lvl_name.pop();}/* pass empty class member declaration list object */
    ;

class_member_declaration_list
    : class_member_declaration {Class_Member_Declaration_List* x=new Class_Member_Declaration_List();x->cd.push_back($1);current_level++;current_table=next_table(current_table);}  /* make obj class_member_declaration_list . add class_member_declaration. */
    | class_member_declaration_list class_member_declaration {Class_Member_Declaration_List* x=$1;x->cd.push_back($1);}/* add class_member_declaration to existing obj */
    ;

constructor_declaration
    : class_name'(' parameter_list_opt ')' compound_statement /* make a constructor declaration with class name and parameter list and body */
    ;

parameter_list_opt
    : parameter_list
    | /* empty */
    ;

class_member_declaration
    : access_specifier ':' {access_spec_stk.push($1);} /* make class_member_declaration obj and add access specifier to it . pass */
    | member_declaration /* make class_member_declaration obj and add member decl to it . pass */
    | constructor_declaration /* make class_member_declaration obj and add constructor_declaration to it . pass */
    ;

member_declaration
    : declaration 
    | function_definition

    ;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST  {$$="CONST";}/* just pass */
	| VOLATILE {$$="VOLATILE";}/* just pass */
	;

declarator
	: pointer direct_declarator
	| direct_declarator /* check if is a function . if yes then add its name to stack */
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')' /* add parameters to current params list */
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| NEW class_name '(' argument_list_opt ')'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
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
	: DELETE IDENTIFIER
	| DELETE '[' ']' IDENTIFIER
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| UNTIL '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit /* (type:node*) nothing much just keep pointers to all external declarations */
	: external_declaration {Node* ext=create_node();ext->add_child($1);root->add_child(ext);}
	| translation_unit external_declaration {Node* ext=create_node();ext->add_child($2);root->add_child(ext);}
	;

external_declaration /* (type:node*) storing pointers to function_definition and declaration */
	: function_definition  {add_to_gst($1,gst);$$=$1;}/* assign pointer of function declaration to external declaration pointer. add function definition to gst*/
	| declaration {add_to_gst($1,gst);$$=$1;}/* add this declaration to global symbol table. assign this pointer to ext declaration object*/
	;

function_definition /*(function_definition <- node ) */
	: declaration_specifiers declarator declaration_list compound_statement {Function_Definition* x=create_func_def($1,$2,$3,$4);current_params_list.clear();lvl_name.pop();} /* create function definition object.parameter. assign type. assign size. */
	| declaration_specifiers declarator compound_statement {$$=create_func_def($1,$2,nullptr,$3);lvl_name.pop();}/*same as above */
	| declarator declaration_list compound_statement {$$=create_func_def(nullptr,$1,$2,$3);lvl_name.pop();} /*same as above */
	| declarator compound_statement {$$=create_func_def(nullptr,$1,nullptr,$2);lvl_name.pop();}/* same as above */
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