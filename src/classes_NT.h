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
class Expression;
class Type_Name;
class Abstract_Declarator;
class Direct_Abstract_Declarator;
extern Global_Symbol_Table* gst;
extern unordered_map<string,string> current_params_list;
extern stack<string> lvl_name;
extern Local_Symbol_Table* current_table;
extern int current_level;
extern stack<string> access_spec_stk;
extern string func_ret_type;
extern set<string> labelset;
extern set<pair<string,Local_Symbol_Table*>> current_class_struct_union_info;
void add_to_local_table(Local_Symbol_Table* current_table,Struct_Declaration* sd);
pair<string,bool> get_type_id(string id);
void check_if_declared(Local_Symbol_Table* current_table,const string& var_name,const string& var_type);
Node* create_node();
Function_Definition* create_func_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs);
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst);
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst);
Declaration_Specifiers* create_decl_spec_object();
Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl);
Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts);
Struct_or_Union_Specifier* create_struct_union_spec_obj(const std::string& sou, const std::string& name, Struct_Declaration_List* sdl);
Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl);
Local_Symbol_Table* next_table(Local_Symbol_Table* current_table);
Struct_Declarator* create_struct_declarator_obj(Declarator* d,Constant_Expression* ce);
Type_Specifier* create_ts_obj(const std::string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type);
string create_type(Declaration_Specifiers* ds,Declarator* d);
vector<string> get_func_params(Declarator* d);
string get_level_name();
string get_name(Declarator* d);
vector<pair<string,string>> create_name_type_list(Declaration_Specifiers* ds,Init_Declarator_List* idl);
vector<string> get_const_params(Parameter_List* p);
vector<pair<string,string>> get_params(Parameter_List* p);
void add_params_to_map(Parameter_List* pl);
Direct_Declarator* create_direct_declarator(string& type,string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl);
Declarator* create_new_declarator(Pointer* p,Direct_Declarator* dd);
struct Symbol_Info{
    string name;
    string type;//return type of function
    string level_name;
    int level;
    string scope;
    string access;
    bool isfunction;// indicate if symbol is function 
    vector<string> function_parameters;// store parameter types in order if symbol is function
    bool isenum;
    Enumerator_List* enumerator_list;
};
class Global_Symbol_Table{
    public:
    vector<Local_Symbol_Table*> children;
    set<pair<string,Local_Symbol_Table*>> current_class_struct_union_info;
    unordered_map<string,Symbol_Info*> gst;
    Global_Symbol_Table();
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
    Declaration_List* decl_list;
    Compound_Statement* cs;
    string name;
    string type;
    string level_name; 
    int level; // level in any function or struct;
    string scope; //global/local
    vector<string> parameters;
    Function_Definition(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs);
};
class Function_Declaration: public Node{
    public:
    Declaration_Specifiers* ds;
    Declarator* d;
    Function_Declaration(Declaration_Specifiers* ds,Declarator* d);
};
class Declaration : public Node{
    public:
    vector<pair<string,string>> name_type_list;
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
    vector<Expression*> vec_exp;
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
    Node* st;
    int have_ret;
    Declaration_List* dl;
    Compound_Statement(Node* st,Declaration_List* dl);
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
    string type;
    string name;
    Initializer_List* ini_lst;
    string class_id;
    Argument_Expression_List* arg_exp_lst;
    Initializer(string type,string name,Initializer_List* ini_lst,string class_id,Argument_Expression_List* arg_exp_lst);
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
    vector<pair<string,string>> name_type_list;
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
    Declaration_Specifiers* ds;
    Declarator* dec;
    Function_Definition* fd;
    Member_Declaration(Declaration_Specifiers* ds,  Declarator* dec,Function_Definition* fd);
};
class Constructor_Declaration: public Node{
    public:
    string class_name;
    Parameter_List* params;
    vector<string> pvec;/*=get_const_params(this->params) do this in constructor*/
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
    string type;
    Specifier_Qualifier_List* sql;
    Abstract_Declarator* ad;
    Type_Name(Specifier_Qualifier_List* sql,Abstract_Declarator* ad);
    string create_type(Specifier_Qualifier_List* sql,Abstract_Declarator* ad);
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
    Constant_Expression* con_exp;
    Direct_Abstract_Declarator(string type,Abstract_Declarator* ad,Direct_Abstract_Declarator* dad,Constant_Expression* con_exp,Parameter_List* pl);
};
class Declaration_List:public Node{
    public:
    vector<Declaration*> dv;
    Declaration_List();
};

class Enumerator:public Node{
    public:
    string id;
    Constant_Expression* ce;
    Enumerator(const std::string& id, Constant_Expression* ce);
};
class Declarator: public Node{
    public:
    Pointer* p;
    Direct_Declarator* dd;
    string type;
    string id;
    Initializer* ini;
    vector<pair<string,string>> prms;
    bool isfunction;
    void check_declarator();
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
    Direct_Declarator(string& type,string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl);
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
    Parameter_List();
};
class Expression : public Node{
    public:
    string type;
    string name;
    Expression(const std::string& type,const std::string& name);
};
class Parameter_Declaration:public Node{
    public:
    Declaration_Specifiers* ds;
    Declarator* dec;
    Parameter_Declaration(Declaration_Specifiers* ds,Declarator* d);
};
#endif