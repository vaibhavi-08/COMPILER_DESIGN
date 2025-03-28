#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;

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
    this->type="";
    this->size=0;
    this->parameters={};
}
Function_Definition* create_fun_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,dl,cs);
    fd->type=create_type(ds);
    fd->parameters=get_func_params(dc);
    fd->size=calc_func_size(dl,cs);
    return fd;
}