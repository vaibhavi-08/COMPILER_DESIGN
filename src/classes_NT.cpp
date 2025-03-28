#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
// Definition
Global_Symbol_Table* gst = nullptr; // Definition
std::unordered_map<std::string, std::string> current_params_list; // Definition
std::stack<std::string> lvl_name; // Definition
Local_Symbol_Table* current_table = nullptr; // Definition
int current_level = 0; 
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst){
    for(auto i:symbol->name_type_list){
        Symbol_Info info={i.first,i.second,symbol->level_name,symbol->level,symbol->scope,false,{}};
        Symbol_Info* x=&info;
        if(gst->gst.find(i.first)!=gst->gst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            return; 
        }
        gst->gst[i.first]=x;
    }

}
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst){
    Symbol_Info info={symbol->name,symbol->type,symbol->level_name,symbol->level,symbol->scope,true,symbol->parameters};
    Symbol_Info* x=&info;
    if(gst->gst.find(symbol->name)!=gst->gst.end()){
        cout << "error :" << "redeclaration of function " << symbol->name << endl;
        return; 
    }
    gst->gst[symbol->name]=x;
}
Node* create_node(){
    Node* node = new Node();
    return node;
}
void Node::add_child(Node* child){
    this->children.push_back(child);
}
Function_Definition:: Function_Definition(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    this->dec_spec=ds;
    this->decl=dc;
    this->decl_list=dl;
    this->cs=cs;
    this->name="";
    this->name="";
    this->type="";
    this->level_name="";
    this->level=0;
    this->scope="";
    this->parameters={};
    this->params_with_name ={};
}

Declaration::Declaration(Declaration_Specifiers* ds,Init_Declarator_List* idl,Typedef_Specifier* ts) {
    this->name_type_list = {};                 
    this->level_name = ""; 
    this->level = 0;     
    this->scope = ""; // assigning default scope
    this->dec_spec=ds;
    this->init_dec_list=idl;
    this->typedef_spec=ts;
}

Global_Symbol_Table::Global_Symbol_Table() {
    this->children = {};
    this->gst = {};
}

Local_Symbol_Table::Local_Symbol_Table() {
    this->children = {};
    this->lst = {};
    this->ispargst = false;
    this->gparent = nullptr;
    this->lparent = nullptr;
}

Function_Definition* create_fun_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,dl,cs);
    fd->type=create_type(ds,dc);
    fd->parameters=get_func_params(dc);
    fd->name=get_name(dc);
    fd->level=0;
    fd->level_name=get_level_name(lvl_name);//stack se
    if(current_table==nullptr){
        fd->scope="global";
    }
    else{
        fd->scope="local";
    }
    return fd;
}
vector<pair<string,string>> create_name_type_list(Declaration_Specifiers* ds,Init_Declarator_List* idl){
    /*for each declarator first generate type and also check whether it is a valid type*/
}
Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts){
    Declaration* d=new Declaration(ds,init_dl,ts);
    d->name_type_list=create_name_type_list(ds,init_dl);
    d->level_name=get_level_name(lvl_name);
    d->level=current_level-lvl_name.size()+1;
    if(current_table==nullptr){
        d->scope="global";
    }
    else{
        d->scope="local";
    }
    return d;
}
Declaration_Specifiers* create_decl_spec_object(){
    Declaration_Specifiers* ds=new Declaration_Specifiers();
    return ds;
}
Type_Specifier* create_ts_obj(string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type){
    Type_Specifier* ts=new Type_Specifier(str,struct_union_type, class_type, enum_type);
    return ts;
}