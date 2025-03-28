#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst){
    for(auto i:symbol->name_type_list){
        Symbol_Info info={i.first,i.second,symbol->size,symbol->level_name,symbol->level,symbol->scope,false,{}};
        Symbol_Info* x=&info;
        if(gst->gst.find(i.first)!=gst->gst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            return; 
        }
        gst->gst[i.first]=x;
    }

}
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst){
    Symbol_Info info={symbol->name,symbol->type,symbol->size,symbol->level_name,symbol->level,symbol->scope,true,symbol->parameters};
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

Function_Definition* create_fun_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,dl,cs);
    fd->type=create_type(ds,dc);
    fd->parameters=get_func_params(dc);
    fd->name=get_name(dc);
    return fd;
}

Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts){
    Declaration* d=new Declaration(ds,init_dl,ts);
    d->name_type_list=create_name_type_list(ds,init_dl);
    d->size=
}