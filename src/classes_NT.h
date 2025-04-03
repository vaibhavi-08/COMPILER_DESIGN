#ifndef CLASSES_NT_H
#define CLASSES_NT_H
#include <bits/stdc++.h>
using namespace std;
class Local_Symbol_Table;
class Global_Symbol_Table;
class Node;
class Symbol_Info;
class Node;
class Function_Definition;
class Declaration_Specifiers;
class Declarator;
class Declaration_List;
class Compound_Statement;
class Init_Declarator_List;
class Typedef_Specifier;
class Declaration;
class Type_Specifier;
class Struct_or_Union_Specifier;
class Class_Specifier;
class Enum_Specifier;
class Struct_Declaration_List;
class Struct_Declaration;
class Specifier_Qualifier_List;
class Struct_Declarator_List;
class Struct_Declarator;
class Class_Specifier;
class Base_Class;
class Base_Class_List;
class Inheritance_Specifier;
class Constant_Expression;
class Member_Declaration;
class Constructor_Declaration;
class Enum_Specifier;
class Enumerator_List;
class Enumerator;
class Function_Declaration;
class Class_Member_Declaration_List;
class Class_Member_Declaration;
class Parameter_List;
class Pointer;
class Direct_Declarator;
class Type_Qualifier_List;
class Parameter_Declaration;
class Type_Name;
class Abstract_Declarator;
class Direct_Abstract_Declarator;
class Initializer;
class Initializer_List;
class Argument_Expression_List;
class Init_Declarator_List;
class Type;
struct Tq;
extern Global_Symbol_Table* gst;
extern unordered_map<string,Type*> current_params_list;
extern stack<string> lvl_name;
extern Local_Symbol_Table* current_table;
extern int current_level;
extern stack<string> access_spec_stk;
extern Type* func_ret_type;
extern set<string> labelset;
extern stack<pair<string,Local_Symbol_Table*>> current_class_struct_union_info;
Type* myFunction();
void add_to_local_table(Local_Symbol_Table* current_table,Struct_Declaration* sd);
void add_to_local_table(Local_Symbol_Table* current_table,Function_Definition* fd);
void add_to_local_table(Local_Symbol_Table* current_table,Declaration* d);
void add_to_local_table(Local_Symbol_Table* current_table,Specifier_Qualifier_List* ds,Declarator* d);
void add_to_local_table(Local_Symbol_Table* current_table,Constructor_Declaration* cd);
void add_to_local_table(Enumerator_List* e,Type* t);
Type* get_type_id(string id);
Type* get_type_exp(string s);
void check_if_declared(Local_Symbol_Table* current_table,const string& var_name,const string& var_type);
Node* create_node();
struct Tq;
void check_if_array_or_pointer(Type* t);
Type* check_if_function(Type* t);
Function_Definition* create_func_def(Declaration_Specifiers* ds,Declarator* dc,Compound_Statement* cs);
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst);
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst);
void add_to_local_class_struct_union_info();
void check_inc_dec_op(Type* e);
void check_for_sizeof(Type* t);
Type* get_type_unary_expression(string t1, Type* t2);
Declaration_Specifiers* create_decl_spec_object();
Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl);
Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts);
Struct_or_Union_Specifier* create_struct_union_spec_obj(const std::string& sou, const std::string& name, Struct_Declaration_List* sdl);
Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl);
Local_Symbol_Table* next_table(Local_Symbol_Table* current_table);
Struct_Declarator* create_struct_declarator_obj(Declarator* d);
void check_if_obj_ptr(Type* s);
void check_if_obj(Type* s);
void check_if_array_or_pointer(Type* t);
Type* check_if_id_in_obj(Type* t,string id);
void check_argument_with_params(vector<Type*> prms,vector<Type*> args);
Type* check_for_arithmatic_op(Type* s1, Type* s2);
Type_Specifier* create_ts_obj(const std::string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type);
string create_type(Declaration_Specifiers* ds,Declarator* d);
string create_type(Specifier_Qualifier_List* ds,Declarator* d,Type* t);
string create_type(Declaration_Specifiers* ds,Declarator* d,Type* t);
vector<Type*> get_func_params(Declarator* d);
void check_compatibility(Initializer* i,Type* t);
void check_if_pointer(Type* t);
void check_if_array(Type* t);
void check_if_constructor(Type* t);
string get_level_name();
string get_name(Declarator* d);
vector<pair<string,pair<string,Type*>>> create_name_type_list(Declaration_Specifiers* ds,Init_Declarator_List* idl);
vector<Type*> get_const_params(Parameter_List* p);
vector<pair<string,Type*>> get_params(Parameter_List* p);
void check_for_shift_op(Type* t1, Type* t2);
Type* check_for_assign(Type* t1, Type* t2,string op);
void add_params_to_map(Parameter_List* pl);
Type* check_for_eq_op(Type* s1, Type* s2);
bool is_equal(Type* t1,Type* t2);
void check_int_comp(Type* type);
void check_typecast_compatibility(Type* t1,Type* t2);
Type* check_if_function(Type* t);
vector<Type*> get_func_params(Abstract_Declarator* ad);

Direct_Declarator* create_direct_declarator(const string& type,const string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl);
Declarator* create_new_declarator(Pointer* p,Direct_Declarator* dd);
class Symbol_Info{
    public:
    string name;
    string type;//return type of function
    string level_name;
    int level;
    string scope;
    string access;
    Type* t;
    Symbol_Info(string name,string type, string level_name,int level,string scope,string access,Type* t);
};
class Global_Symbol_Table{
    public:
    vector<Local_Symbol_Table*> children;
    unordered_map<string,Local_Symbol_Table*> class_struct_union_info;
    unordered_map<string,Symbol_Info*> gst;
    Global_Symbol_Table();
};
struct Tq{
    bool isconst{false};
    bool isvol{false};
    Tq(bool v1,bool v2):isconst(v1),isvol(v2){}
};

class Type {
    public:
    bool isconst;
    bool isvoid;
    bool isvolatile;
    bool isfunction;
    bool isbasic;
    bool isobj;
    bool isstatic;
    bool isauto;
    bool isextern;
    bool isregister;
    bool isigned;
    bool isunsigned;
    bool isnull;
    bool isenum;
    Type* func_ret_type;
    vector<Type*> prms;
    Enumerator_List* el;
    string base;
    string objtype;
    string obj_class;
    vector<Base_Class*> base_classes;
    int array_dim;
    int ptr_level;
    int func_ptr_lev;
    vector<Tq> ptrtql;  // Now this will work, assuming Tq is defined earlier
    Type();
};



class Local_Symbol_Table{
    public:
    vector<Local_Symbol_Table*> children;
    unordered_map<string,Local_Symbol_Table*> class_struct_union_info;
    unordered_map<string,Symbol_Info*> lst;
    bool ispargst;
    Local_Symbol_Table* parent;
    Local_Symbol_Table(bool ispargst, Local_Symbol_Table* parent);
    Local_Symbol_Table* get_parent();
};
class Node{
    public:
    vector<Node*> children;
    void add_child(Node* par);
    virtual ~Node() = default;
};
class Function_Definition : public Node{
    public:
    Declaration_Specifiers* dec_spec;
    Declarator* decl;
    Compound_Statement* cs;
    string name;
    string type;
    Type* t;
    string level_name; 
    int level; // level in any function or struct;
    string scope; //global/local
    vector<Type*> parameters;
    Function_Definition(Declaration_Specifiers* ds,Declarator* dc,Compound_Statement* cs);
};
class Function_Declaration: public Node{
    public:
    Declaration_Specifiers* ds;
    Declarator* d;
    Function_Declaration(Declaration_Specifiers* ds,Declarator* d);
};
class Declaration : public Node{
    public:
    vector<pair<string,pair<string,Type*>>> name_type_list;
    string level_name;
    int level;
    string scope;
    Declaration_Specifiers* dec_spec;
    Init_Declarator_List* init_dec_list;
    Typedef_Specifier* typedef_spec;
    Declaration(Declaration_Specifiers* ds,Init_Declarator_List* idl,Typedef_Specifier* ts);
};
// class Typedef_Specifier: public Node{

// };
class Init_Declarator_List: public Node{
    public :
    vector<Declarator*> idl;
    Init_Declarator_List();
};
class Argument_Expression_List: public Node{
    public:
    vector<Type*> vec_exp;
    Argument_Expression_List();
};
class Declaration_Specifiers : public Node{
    public:
    vector<string> scs;
    vector<Type_Specifier*> ts;
    vector<string> tq;
    Declaration_Specifiers();
};
class Compound_Statement : public Node{
    public:
    vector<int> st;
    int have_ret;
    Declaration_List* dl;
    Compound_Statement(vector<int> st,Declaration_List* dl);
};


class Type_Specifier: public Node{
    public:
    string string_type;
    Struct_or_Union_Specifier* struct_union_type;
    Class_Specifier* class_type;
	Enum_Specifier* enum_type;
    Type_Specifier(const string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type);
};
class Struct_or_Union_Specifier: public Node{
    public:
    string str_or_union;
    string name;
    Struct_Declaration_List* strdec_list;
    Struct_or_Union_Specifier(const string& sou,const string& name,Struct_Declaration_List* sdl);
};
class Initializer: public Node{
    public:
    Type* type;
    string name;
    Initializer_List* ini_lst;
    string class_id;
    Argument_Expression_List* arg_exp_lst;
    Initializer(Type* type,string name,Initializer_List* ini_lst,string class_id,Argument_Expression_List* arg_exp_lst);
};
class Initializer_List:public Node{
    public:
    vector<Initializer*> iv;
    Initializer_List();
};
class Struct_Declaration_List: public Node{
    public:
    vector<Struct_Declaration*> sdl;
    Struct_Declaration_List();
};
class Struct_Declaration: public Node{
    public:
    Specifier_Qualifier_List* sql;
    Struct_Declarator_List* sdl;
    vector<pair<string,pair<string,Type*>>> name_type_list;
    vector<string> prms;
    bool isfunction;
    string scope;
    int level;
    string level_name; 
    Struct_Declaration(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl);
};

class Struct_Declarator_List:public Node{
    public:
    vector<Struct_Declarator*> sd;
    Struct_Declarator_List();
};
class Class_Specifier : public Node{
    public:
    string class_name;
    Inheritance_Specifier* is;
    Class_Member_Declaration_List* cb;
    Class_Specifier(const std::string& class_name,Inheritance_Specifier* is,Class_Member_Declaration_List* cb);
};
class Inheritance_Specifier: public Node{
    public:
    Base_Class_List* bcl;
    Inheritance_Specifier(Base_Class_List* bcl);
};
class Specifier_Qualifier_List: public Node{
    public:
    vector<Type_Specifier*> ts;
    vector<string> tq;
    Specifier_Qualifier_List();
};
class Struct_Declarator: public Node{
    public:
    Declarator* d;
    Struct_Declarator(Declarator* d);
};
class Base_Class :public Node{
    public:
    string asp;
    string id;
    Base_Class(const std::string& asp, const std::string& id);
};
class Base_Class_List{
    public:
    vector<Base_Class*> bc;
    Base_Class_List();
};
class Class_Member_Declaration_List:public Node{
    public:
    vector<Class_Member_Declaration*> cd;
    Class_Member_Declaration_List();
};
class Class_Member_Declaration:public Node{
    public:
    Member_Declaration* md;
    Constructor_Declaration* cd;
    Class_Member_Declaration(Member_Declaration* md,Constructor_Declaration* cd);
};
class Member_Declaration: public Node{
    public:
    Specifier_Qualifier_List* ds;
    Declarator* dec;
    Function_Definition* fd;
    Member_Declaration(Specifier_Qualifier_List* ds,  Declarator* dec,Function_Definition* fd);
};
class Constructor_Declaration: public Node{
    public:
    string class_name;
    Parameter_List* params;
    vector<Type*> pvec;/*=get_const_params(this->params) do this in constructor*/
    Compound_Statement* cs;
    Constructor_Declaration(const std::string& class_name,Parameter_List* params,Compound_Statement* cs);
};

class Enum_Specifier:public Node{
    public:
    string id;
    Enumerator_List* enuml;
    Enum_Specifier(const std::string& id, Enumerator_List* enuml);
};
class Enumerator_List:public Node{
    public:
    vector<Enumerator*> e;
    Enumerator_List();
};
class Type_Name : public Node{
    public:
    Type* type;
    Specifier_Qualifier_List* sql;
    Abstract_Declarator* ad;
    Type_Name(Specifier_Qualifier_List* sql,Abstract_Declarator* ad);
    Type* create_type_tn(Specifier_Qualifier_List* sql,Abstract_Declarator* ad);
};
class Abstract_Declarator : public Node{
    public:
    string type;
    Pointer* p;
    Direct_Abstract_Declarator* dad;
    string check_abstract_declarator();
    Abstract_Declarator(Pointer* p,Direct_Abstract_Declarator* dad);
};
class Direct_Abstract_Declarator : public Node{
    public:
    string type;
    Abstract_Declarator* ad;
    Direct_Abstract_Declarator* dad;
    Parameter_List* pl;
    Type* con_exp;
    Direct_Abstract_Declarator(string type,Abstract_Declarator* ad,Direct_Abstract_Declarator* dad,Type* con_exp,Parameter_List* pl);
};
class Declaration_List:public Node{
    public:
    vector<Declaration*> dv;
    Declaration_List();
};

class Enumerator:public Node{
    public:
    string id;
    Type* ce;
    Enumerator(const std::string& id, Type* ce);
};

class Declarator: public Node{
    public:
    Pointer* p;
    Direct_Declarator* dd;
    string type;
    string id;
    Initializer* ini;
    vector<pair<string,Type*>> prms;
    bool isfunction;
    string check_declarator();
    void check_for_func();
    Declarator(Pointer* p,Direct_Declarator* dd);
};
class Direct_Declarator:public Node{
    public:
    string type;  
    string id;     
    Declarator* d;
    Direct_Declarator* dd;
    Constant_Expression* ce;
    Parameter_List* pl;
    Direct_Declarator(const string& type,const string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl);
};
class Pointer:public Node{
    public:
    Type_Qualifier_List* tql;
    Pointer* p;
    Pointer(Type_Qualifier_List* tql,Pointer* p);
};
class Type_Qualifier_List:public Node{
    public:
    vector<string> tq;
    Type_Qualifier_List();
};
class Parameter_List:public Node{
    public:
    vector<Parameter_Declaration*> pl;
    bool ellipses;
    Parameter_List();
};
class Parameter_Declaration:public Node{
    public:
    Declaration_Specifiers* ds;
    Declarator* dec;
    string type;
    string name;
    bool isfunction;
    vector<Type*> prms;
    Parameter_Declaration(Declaration_Specifiers* ds,Declarator* d);
};
#endif