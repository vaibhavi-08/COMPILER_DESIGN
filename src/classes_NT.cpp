#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
// Definition
Global_Symbol_Table* gst = nullptr; // Definition
std::unordered_map<std::string, std::string> current_params_list; // Definition
std::stack<std::string> lvl_name; // Definition
Local_Symbol_Table* current_table = nullptr; // Definition
stack<string> access_spec_stk;
int current_level = 0; 
void check_if_declared(Local_Symbol_Table* current_table,const string& var_name,const string& var_type){
    Local_Symbol_Table* x=current_table;
    bool check=false;
    while(x!=nullptr){
        auto y=(x->lst).find(var_name);
        if(y!=nullptr){
            if((y->second)->type==var_type){
                check=true;
                break;
            }
        }
        else{
            x=x->parent;
        }
    }
    if(!check){
        cout << "error: " << var_type << " " << var_name << " not declared!" << endl;
        exit(1);
    }
}
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst){
    for(auto i:symbol->name_type_list){
        Symbol_Info info={i.first,i.second,symbol->level_name,symbol->level,symbol->scope,false,{}};
        Symbol_Info* x=&info;
        if(gst->gst.find(i.first)!=gst->gst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        gst->gst[i.first]=x;
    }

}
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst){
    Symbol_Info info={symbol->name,symbol->type,symbol->level_name,symbol->level,symbol->scope,true,symbol->parameters};
    Symbol_Info* x=&info;
    if(gst->gst.find(symbol->name)!=gst->gst.end()){
        cout << "error :" << "redeclaration of function " << symbol->name << endl;
        exit(1);
    }
    gst->gst[symbol->name]=x;
}
Local_Symbol_Table* next_table(Local_Symbol_Table* current_table){
    bool checkgst=false;
    if(current_table==nullptr)checkgst=true;
    Local_Symbol_Table* new_table=new Local_Symbol_Table(checkgst,current_table);
    current_table->children.push_back(new_table);
    return new_table;
}
void add_to_local_table(Local_Symbol_Table* current_table,Struct_Declaration* sd){
    for(auto i:sd->name_type_list){
        Symbol_Info info={i.first,i.second,sd->level_name,sd->level,sd->scope};
        Symbol_Info* x=&info;
        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
    }
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

Local_Symbol_Table::Local_Symbol_Table(bool ispargst,Local_Symbol_Table* parent) {
    this->children = {};
    this->lst = {};
    this->ispargst = ispargst ;
    this->parent = parent;
}
Local_Symbol_Table* Local_Symbol_Table :: get_parent(){
    if(this->ispargst){
        return nullptr;
    }
    else{
        return this->parent;
    }
}

Declaration_Specifiers::Declaration_Specifiers() {
    this->scs = {};   
    this->ts = {};    
    this->tq = {}; 
}

Function_Definition* create_func_def(Declaration_Specifiers* ds,Declarator* dc,Declaration_List* dl,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,dl,cs);
    fd->type=create_type(ds,dc);
    fd->parameters=get_func_params(dc);
    fd->name=get_name(dc);
    fd->level=0;
    fd->level_name=get_level_name(lvl_name);//stack se
    if(current_level==0){
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
    if(current_level==0){
        d->scope="global";
    }
    else{
        d->scope="local";
    }
    return d;
}
Struct_or_Union_Specifier::Struct_or_Union_Specifier(const string& sou,const string& name, Struct_Declaration_List* sdl) {
    this->str_or_union = sou;    
    this->name = name;           
    this->strdec_list = sdl;   
}

Type_Specifier::Type_Specifier(const string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type){
    this->string_type = str;               
    this->struct_union_type = struct_union_type; 
    this->class_type = class_type;           
    this->enum_type = enum_type;       
}

Struct_Declaration::Struct_Declaration(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl) {
    this->sql = sql;                   
    this->sdl = sdl;                  
    this->name_type_list = {};         
    this->scope = "";                  
    this->level = 0;                  
    this->level_name = "";         
}

Struct_Declarator_List::Struct_Declarator_List() {
   this->sd={};
}

Struct_Declarator::Struct_Declarator(Declarator* d, Constant_Expression* ce){
    this->d=d;
    this->ce=ce;
}

Inheritance_Specifier::Inheritance_Specifier(Base_Class_List* bcl){
    this->bcl=bcl;
}

Base_Class_List::Base_Class_List() {
    this->bc={};
}

// Implementation (.cpp file)
Base_Class::Base_Class(const std::string& asp, const std::string& id)
    : asp(asp), id(id) {  // Use const references to accept temporary strings
}


Specifier_Qualifier_List::Specifier_Qualifier_List() {
    this->ts={};
    this->tq={};
}

Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl){
    Struct_Declaration* sd=new Struct_Declaration(sql,sdl);
    sd->level=current_level-lvl_name.size()+1;
    sd->level_name=get_level_name();
    if(current_level==0)sd->scope="global";
    else sd->scope="local";
    return sd;
}
Declaration_Specifiers* create_decl_spec_object(){
    Declaration_Specifiers* ds=new Declaration_Specifiers();
    return ds;
}

// In your .cpp file
Class_Specifier::Class_Specifier(const std::string class_name, Inheritance_Specifier* is, Class_Member_Declaration_List* cb)
    : class_name(class_name), 
      is(is),
      cb(cb) {
}

Type_Specifier* create_ts_obj(const std::string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type){
    Type_Specifier* ts=new Type_Specifier(str,struct_union_type, class_type, enum_type);
    return ts;
}
Struct_or_Union_Specifier* create_struct_union_spec_obj(const string& sou,const string& name,Struct_Declaration_List* sdl){
    Struct_or_Union_Specifier* sus =new Struct_or_Union_Specifier(sou,name,sdl);
    return sus;
}
Struct_Declarator* create_struct_declarator_obj(Declarator* d,Constant_Expression* ce){
    Struct_Declarator* d=new Struct_Declarator(d,ce);
    return d;
}

