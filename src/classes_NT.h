#ifndef CLASSES_NT_H
#define CLASSES_NT_H
#include <bits/stdc++.h>
using namespace std;
extern Global_Symbol_Table* gst;
extern unordered_map<string,string> current_params_list;
extern stack<string> lvl_name;
extern Local_Symbol_Table* current_table;
extern int current_level;
class Node;
class Local_Symbol_Table;
class Global_Symbol_Table;
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
Node* create_node();
Function_Definition* create_fun_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs);
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst);
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst);
Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts);
struct Symbol_Info{
    string name;
    string type;//return type of function
    string level_name;
    int level;
    string scope;
    bool isfunction;// indicate if symbol is function 
    vector<string> function_parameters;// store parameter types in order if symbol is function
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
    Global_Symbol_Table* gparent;
    Local_Symbol_Table* lparent;
    Local_Symbol_Table();

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
    vector<pair<string,string>> params_with_name;
    Function_Definition(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs);
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

};
class Declaration_Specifiers : public Node{
    public:
    vector<string> scs;
    vector<Type_Specifier*> ts;
    vector<string> tq;
    Declaration_Specifiers();
};
class Declarator : public Node{

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
    Type_Specifier(string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type);
};
class Struct_or_Union_Specifier{

} ;
class Class_Specifier{

};
class Enum_Specifier{

};
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
// class Constant_Expression{

// };
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

// class Struct_Declaration_List{

// };

// class Struct_Declaration{

// };

// class Specifier_Qualifier_List{

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