#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
// Definition
Global_Symbol_Table* gst = nullptr; // Definition
std::unordered_map<std::string, std::string> current_params_list; // Definition
std::stack<std::string> lvl_name; // Definition
Local_Symbol_Table* current_table = nullptr; // Definition
stack<string> access_spec_stk;
string func_ret_type;
int current_level = 0; 
string get_level_name(){
    stack<string> temp;
    string ans="";
    while(!lvl_name.empty()){
        temp.push(lvl_name.top());
        lvl_name.pop();
    }
    while(!temp.empty()){
        string x=temp.top();
        lvl_name.push(x);
        ans+=x;
        ans+=":";
        temp.pop();
    }
    return ans;
}
string create_type(Declaration_Specifiers* ds,Declarator* d)string create_type(Declaration_Specifiers* ds,Declarator* d){
    string type="";
    bool isconst=false;
    bool isvolatile=false;
    for(auto i : ds->tq){
        if(i=="CONST")isconst=true;
        else isvolatile=true;
    }
    if(isconst){
        type+="CONST ";
    }
    if(isvolatile){
        type+="VOLATILE ";
    }
    if(ds->scs.size()==1){
        type+=ds->scs[0];
        type+=" ";
    }
    else if(ds->scs.size()!=0){
        cout << "incorrect storage class specs in type of " << d->id << endl;
        exit(1);
    }
    vector<Type_Specifier*> z=ds->ts;
    reverse(z.begin(),z.end());
    if(z.size()==3){
        if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type="LONG"&&z[2]->string_type="LONG"){
            return type + "UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type="UNSIGNED"&&z[1].string_type="CHAR"){
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type="UNSIGNED"&&z[1].string_type="SHORT"){
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type="UNSIGNED"&&z[1].string_type="INT"){
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type="UNSIGNED"&&z[1].string_type="LONG"){
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type="SIGNED"&&z[1].string_type="CHAR"){
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type="SIGNED"&&z[1].string_type="SHORT"){
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type="SIGNED"&&z[1].string_type="INT"){
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type="SIGNED"&&z[1].string_type="LONG"){
            type+=" SIGNED LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        type+=z->string_type;
    }
    else if(z.size()>3) {
        cout << "incorrect type specs in type of " << d->id << endl;
        exit(1);
    }
    Pointer* y=d->p;
    while(y!=nullptr){
        type+='*';
        y=y->p;
    }
    return type;
     


}

vector<string> get_const_params(Parameter_List* p){
    /*for each parameter declaration get type from declaration specifiers and declarator or abstract declarator*/
    vector<string> ans;
    if(p==nullptr)return ans;
    vector<pair<string,string>> prms=get_params(p);
    set<string> s;
    for(auto i:prms){
        s.insert(i.second);
        ans.push_back(i.first);
    }
    if(s.size()!=prms.size()){
        cout << "error: " << "all parameters should have unique name" << endl;
        exit(0);
    }
    return ans;
}
vector<<pair<string,string>> get_params(Parameter_List* p){
    vector<pair<string,string>> ans;
    if(p==nullptr)return ans;
    for(auto i:p->pl){
        string type=create_type(i->ds,i->dec);
        string name=get_name(i->dec);
        pair<string,string> x={type,name};
        ans.push_back(x);
    }
    return ans;
}
string Declarator :: check_declarator(){
    //return which type of declarator
    Direct_Declarator* z=this->dd;
    if(dd->type=="function"){
        Direct_Declarator* nxt=z->dd;
        assert(nxt!=nullptr);
        if(nxt->type="id"){
            return "function";
        }
        else if(nxt->type="declarator"){
            if(nxt->d->dd->type="id"&&nxt->d->p!=nullptr){
                return "function pointer";
            }
            else{
                cout << "error: " << z->id << "is not valid declarator" << endl;
                exit(1);
            }
        }
        else{
            cout << "error: " << z->id << "is not valid declarator" << endl;
             exit(1);
        }
    }
    else if(z->type=="id"){
        return "id";
    }
    else if(z->type=="declarator"){
        cout << "error: " << z->id << "is not valid declarator" << endl;
        exit(1);
    }
    else if(z->type=="array"){
        Direct_Declarator* x=z;
        while(x->type=="array"){
            x=x->dd;
        }
        if(x->type=="id"){
            return "array";
        }
        else{
            cout << "error: " << z->id << "is not valid declarator" << endl;
            exit(1);
        }
    }
}
void Declarator :: check_for_func(){
    string t=this->check_declarator()
    if(t!="function"){
        cout << "error : invalid function declarator " << this->id << endl;
        exit(0); 
    }
}
void add_params_to_map(Parameter_List* pl) {
    std::vector<std::pair<std::string, std::string>> params = get_params(pl);
    
    for (const auto& param : params) {
        if (current_params_list.find(param.second) != current_params_list.end()) {
            std::cerr << "error: parameter '" << param.second 
                      << "' of type '" << param.first 
                      << "' conflicts with previous declaration of type '" 
                      << current_params_list[param.second] ;
            exit(1);
        }
        current_params_list[param.second] = param.first;
    }
}

string get_name(Declarator* d){
    return d->id;
}

vector<string> get_func_params(Declarator* d){
    if (!d->isfunction) {
        cerr << "error: declarator is not a function"<< endl;
        exit(1);
    }
    Parameter_List* tpl = d->dd->pl;
    return get_const_params(tpl);
}


vector<pair<string, string>> create_name_type_list(Declaration_Specifiers* ds, Init_Declarator_List* idl) {
    vector<pair<string, string>> result;
    if (!idl) return result;
    for (Init_Declarator* init_decl : idl->idl) {
        Declarator* d = init_decl->d;
        string type = create_type(ds, d);
        string name = d->id;
        result.emplace_back(name, type);
    }
    return result;
}


Direct_Declarator* create_direct_declarator(string& type,string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl){
    Direct_Declarator* z=new Direct_Declarator(type,id,d,dd,ce,pl);
    if(z->id==""){
        if(z->dd!=nullptr){
            z->id=z->dd->id;
        }
        else if(z->d!=nullptr) {
            z->id=z->d->id;
        }
    }
    return z;
}
Declarator* create_new_declarator(Pointer* p,Direct_Declarator* dd){
    Declarator* z=new Declarator(p,dd);
    z->id=z->dd->id;
    string t=check_declarator();
    if(t=="function"){
        z->isfunction=true;
        z->prms=get_params(dd->pl);
        for(auto i:z->prms){
            current_params_list[i.second]=i.first;
        }
    }
    z->type=t;
}
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
        Enumerator_List* z=nullptr;
        bool isenum=false;
        if(i.second=="enum"){
            isenum=true;
            z=symbol->dec_spec->ts.front()->enum_type->enuml;
        }
        Symbol_Info info={i.first,i.second,symbol->level_name,symbol->level,symbol->scope,"-",false,{},isenum,z};
        Symbol_Info* x=&info;
        if(gst->gst.find(i.first)!=gst->gst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        gst->gst[i.first]=x;
    }

}
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst){
    Symbol_Info info={symbol->name,symbol->type,symbol->level_name,symbol->level,symbol->scope,"-",true,symbol->parameters,false,nullptr};
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
        Symbol_Info info={i.first,i.second,sd->level_name,sd->level,sd->scope,"-",false,{},false,nullptr};
        Symbol_Info* x=&info;
        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
    }
}
void add_to_local_table(Local_Symbol_Table* current_table,Declaration* d){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    for(auto i:d->name_type_list){
        Enumerator_List* z=nullptr;
        bool isenum=false;
        if(i.second=="enum"){
            isenum=true;
            z=d->dec_spec->ts.front()->enum_type->enuml;
        }
        Symbol_Info info={i.first,i.second,d->level_name,d->level,d->scope,access,false,{},isenum,z};
        Symbol_Info* x=&info;
        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
    }
}
void add_to_local_table(Local_Symbol_Table* current_table,Constructor_Declaration* cd){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    string name=cd->class_name;
    string type="constructor";
    string level_name=get_level_name();
    int level=current_level-lvl_name.size()+1;
    vector<string> prms=cd->pvec;
    Symbol_Info info={name,type,level_name,level,"local",access,false,prms,false,nullptr};
    Symbol_Info* x=&info;
    current_table->lst[name]=x;/*redefinition of same type of constructor not handled. also multiple constructors case not handled. can handle by adding params to name*/
}
void add_to_local_table(Local_Symbol_Table* current_table,Function_Definition* fd){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    Symbol_Info info={fd->name,fd->type,fd->level_name,fd->level,fd->scope,access,true,fd->parameters,false,nullptr};
    Symbol_Info* x=&info;
    if(current_table->lst.find(fd->name)!=current_table->lst.end()){
        cout << "error :" << "redeclaration of function " << fd->name << endl;
        exit(1);
    }
    current_table->lst[fd->name]=x;
}
Node* create_node(){
    Node* node = new Node();
    return node;
}
Init_Declarator_List::Init_Declarator_List() {
    this->idl={};
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
    fd->level_name=get_level_name();//stack se
    if(current_level==0){
        fd->scope="global";
    }
    else{
        fd->scope="local";
    }
    return fd;
}

Declaration* create_declaration_object(Declaration_Specifiers* ds, Init_Declarator_List* init_dl,Typedef_Specifier* ts){
    Declaration* d=new Declaration(ds,init_dl,ts);
    d->name_type_list=create_name_type_list(ds,init_dl);
    d->level_name=get_level_name();
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

Type_Specifier::Type_Specifier(const string& str, Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type) 
    : string_type(str),
    struct_union_type(struct_union_type),
    class_type(class_type),
    enum_type(enum_type){
    if(struct_union_type) {
        const string& sou = struct_union_type->str_or_union;
        const string& name = struct_union_type->name;
        Struct_Declaration_List* sdl = struct_union_type->strdec_list;
        if (!sou.empty()) {
            if (sdl) { 
                if (name.empty()) {
                    string_type = sou + " anonymous";
                } 
                else {
                    string_type = sou;
                }
            } 
            else {
                if (!name.empty()) {
                    string_type = sou + " " + name;
                }
            }
        }
    }
    else if (class_type) { 
        if (class_type->cb == nullptr) {
            string_type = "class " + class_type->class_name;
        }
        else {
            if (class_type->class_name.empty()) {
                string_type = "class anonymous";
            } 
            else {
                string_type = "class";
            }
        }
    }
    else if (enum_type) {
        if (enum_type->enuml == nullptr) {
            string_type = "enum " + enum_type->id;
        } else {
            if (enum_type->id.empty()) {
                string_type = "enum anonymous"; 
            } else {
                string_type = "enum";  
            }
        }
    }
    else{
        cout<<"Not struct_or_union,enum or class"<<endl;
    }
}


Enum_Specifier::Enum_Specifier(const std::string& id, Enumerator_List* enuml)
    : id(id), enuml(enuml) { 
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

Enumerator::Enumerator(const std::string& id, Constant_Expression* ce)
    : id(id), ce(ce) { 
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

Constructor_Declaration::Constructor_Declaration(
    const std::string& class_name, 
    Parameter_List* params, 
    Compound_Statement* cs
) : class_name(class_name), params(params), cs(cs) {
}


Base_Class::Base_Class(const std::string& asp, const std::string& id)
    : asp(asp), id(id) {  
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
    Struct_Declarator* sd=new Struct_Declarator(d,ce);
    return sd;
}
Init_Declarator:: Init_Declarator(Declarator* d,Initializer* i){
    this->d=d;
    this->i=i;
    d->check_declarator();
}



