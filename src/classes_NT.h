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
class Init_Declarator;
class Class_Member_Declaration_List;
class Class_Member_Declaration;
class Parameter_List;
extern Global_Symbol_Table* gst;
extern unordered_map<string,string> current_params_list;
extern stack<string> lvl_name;
extern Local_Symbol_Table* current_table;
extern int current_level;
extern stack<string> access_spec_stk;
extern string func_ret_type;
void add_to_local_table(Local_Symbol_Table* current_table,Struct_Declaration* sd);
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
    unordered_map<string,Symbol_Info*> gst;
    Global_Symbol_Table();
};
class Local_Symbol_Table{
    public:
    vector<Local_Symbol_Table*> children;
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
    vector<Init_Declarator*> idl;
    Init_Declarator_List();
};
class Init_Declarator : public Node {
    public:
        Declarator* d;
        Initializer* i;  
        Init_Declarator(Declarator* d, Initializer* i);
};
class Declaration_Specifiers : public Node{
    public:
    vector<string> scs;
    vector<Type_Specifier*> ts;
    vector<string> tq;
    Declaration_Specifiers();
};
class Declaration_List : public Node{

};
class Compound_Statement : public Node{

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
    Constant_Expression* ce;
    Struct_Declarator(Declarator* d,Constant_Expression* ce);

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
    Declaration* d;
    Function_Definition* fd;
    Member_Declaration(Declaration* d,Function_Definition* fd);
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
class Enumerator:public Node{
    public:
    string id;
    Constant_Expression* ce;
    Enumerator(const std::string& id, Constant_Expression* ce);
};
class Declarator : public Node{
    public:
    Pointer* p;
    Direct_Declarator* dd;
    string type;
    string id;
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
class Parameter_Declaration:public Node{
    public:
    Declaration_Specifiers* ds;
    Declarator* dec;
    Parameter_Declaration(Declaration_Specifiers* ds,Declarator* d);
}
// class Primary_expresssion{

// };
// class Class_Name{

// };
// class Postfix_Expression{

// };
// class Argument_Expression_List{

// };
// class Argument_List_Opt{

// };
// class Argument_List{

// };
// class Unary_Expression{

// };
// class Unary_Operator{

// };
// class Cast_Expression{

// };
// class Multiplicative_Expresssion{

// };
// class Additive_Expression{

// };
// class Shift_Expression{

// };
// class Relational_Expression{

// };
// class Equality_Expression{

// };
// class And_Expression{

// };
// class Exclusive_Or_Expression{

// };
// class Inclusive_Or_Expression{

// };
// class Logical_And_Expression{

// };
// class Logical_Or_Expression{

// };
// class Conditional_Expression{

// };
// class Assignment_Expression{

// };
// class Assignment_Operator{

// };
// class Expression{

// };
class Constant_Expression{

};
// class Declaration{

// };
// class Typedef_Specifier{

// };
// class Declaration_Specifiers{

// };
// class Init_Declarator_List{

// };
// class Init_Declarator{

// };


// class Struct_or_Union_Specifier{

// };

// class Struct_or_Union{

// };


// class Struct_Declaration{

// };


// class Struct_Declarator{

// };

// class Class_Specifier{

// };

// class Inheritance_Specifier{

// };

// class Base_Class_List{

// };

// class Base_Class{

// };

// class Access_Specifier{

// };

// class Class_Body{

// };

// class Class_Member_Declaration_List{

// };

// class Constructor_Declaration{

// };

// class Parameter_List_Opt{

// };

// class Class_Member_Declaration{

// };

// class Member_Declaration{

// };

// class Enum_Specifier{

// };

// class Enumerator_List{

// };

// class Enumerator{

// };

// class Type_Qualifier{

// };

// class Declarator{

// };

// class Direct_Declarator{

// };

// class Pointer{

// };

// class Type_Qualifier_List{

// };

// class Parameter_Type_List{

// };

// class Parameter_List{

// };

// class Parameter_Declaration{

// };

// class Identifier_List{

// };

// class Type_Name{

// };

// class Abstract_Declarator{

// };

// class Direct_Abstract_Declarator{

// };

// class Initializer{

// };

// class Initializer_List{

// };

// class Statement{

// };

// class Delete_Statement{

// };

// class Labeled_Statement{

// };

// class Compound_Statement{

// };

// class Statement_List{

// };

// class Expression_Statement{

// };

// class Selection_Statement{

// };

// class Iteration_Statement{

// };

// class Jump_Statement{

// };

// class Translation_Unit{
    
// };

// class External_Declaration{

// };

// class Function_Definition{

// };
#endif