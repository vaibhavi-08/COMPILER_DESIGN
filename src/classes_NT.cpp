#include <bits/stdc++.h>
using namespace std;
struct Symbol_Info{
    string type;//return type of function
    int size;
    int level;
    string scope;
    Local_Symbol_Table* table;// if suppose it is a class or function or struct then we need to create its seperate local symbol table, pointer to that
    bool isfunction;// indicate if symbol is function 
    vector<string> function_parameters;// store parameter types in order if symbol is function
};
class Global_Symbol_Table{
    unordered_map<string,Symbol_Info> gst;
};
class Local_Symbol_Table{
    unordered_map<string,Symbol_Info> lst;
    bool ispargst;
    Global_Symbol_Table* gparent;
    Local_Symbol_Table* lparent;
};
class Primary_expresssion{

};
class Class_Name{

};
class Postfix_Expression{

};
class Argument_Expression_List{

};
class Argument_List_Opt{

};
class Argument_List{

};
class Unary_Expression{

};
class Unary_Operator{

};
class Cast_Expression{

};
class Multiplicative_Expresssion{

};
class Additive_Expression{

};
class Shift_Expression{

};
class Relational_Expression{

};
class Equality_Expression{

};
class And_Expression{

};
class Exclusive_Or_Expression{

};
class Inclusive_Or_Expression{

};
class Logical_And_Expression{

};
class Logical_Or_Expression{

};
class Conditional_Expression{

};
class Assignment_Expression{

};
class Assignment_Operator{

};
class Expression{

};
class Constant_Expression{

};
class Declaration{

};
class Typedef_Specifier{

};
class Declaration_Specifiers{

};
class Init_Declarator_List{

};
class Init_Declarator{

};
class Storage_Class_Specifier{

};
class Type_Specifier{

};

class Struct_or_Union_Specifier{

};

class Struct_or_Union{

};

class Struct_Declaration_List{

};

class Struct_Declaration{

};

class Specifier_Qualifier_List{

};

class Struct_Declaration_List{

};

class Struct_Declarator{

};

class Class_Specifier{

};

class Inheritance_Specifier{

};

class Base_Class_List{

};

class Base_Class{

};

class Access_Specifier{

};

class Class_Body{

};

class Class_Member_Declaration_List{

};

class Constructor_Declaration{

};

class Parameter_List_Opt{

};

class Class_Member_Declaration{

};

class Member_Declaration{

};

class Enum_Specifier{

};

class Enumerator_List{

};

class Enumerator{

};

class Type_Qualifier{

};

class Declarator{

};

class Direct_Declarator{

};

class Pointer{

};

class Type_Qualifier_List{

};

class Parameter_Type_List{

};

class Parameter_List{

};

class Parameter_Declaration{

};

class Identifier_List{

};

class Type_Name{

};

class Abstract_Declarator{

};

class Direct_Abstract_Declarator{

};

class Initializer{

};

class Initializer_List{

};

class Statement{

};

class Delete_Statement{

};

class Labeled_Statement{

};

class Compound_Statement{

};

class Statement_List{

};

class Expression_Statement{

};

class Selection_Statement{

};

class Iteration_Statement{

};

class Jump_Statement{

};

class Translation_Unit{
    
};

class External_Declaration{

};

class Function_Definition{

};
