#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst){
    Symbol_Info info={symbol->name,symbol->type,symbol->size,symbol->level_name,symbol->level,symbol->scope,false,{}};
    Symbol_Info* x=&info;
    if(gst->gst.find(symbol->name)!=gst->gst.end()){
        cout << "error :" << "redeclaration of " << symbol->name << endl;
        return; 
    }
    gst->gst[symbol->name]=x;

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
    this->type="";
    this->size=0;
    this->level_name="";
    this->level=0;
    this->scope="global";//we have given default scope as global
    this->parameters={};
    this->params_with_name ={};
}

Declaration::Declaration() {
    this->name = "";         
    this->type = "";          
    this->size = 0;  
    this->level_name = ""; 
    this->level = 0;     
    this->scope = "global"; // assigning default scope
}

Function_Definition* create_fun_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,dl,cs);
    fd->type=create_type(ds);
    fd->parameters=get_func_params(dc);
    fd->size=calc_func_size(dl,cs);
    fd->name=get_name(dc);
    return fd;
}