#include <bits/stdc++.h>
#include <classes_NT.h>
#include <tac.h>
using namespace std;
// Definition
Global_Symbol_Table* gst = nullptr; // Definition
std::unordered_map<std::string, Type*> current_params_list; // Definition
std::stack<std::string> lvl_name; // Definition
Local_Symbol_Table* current_table = nullptr; // Definition
stack<string> access_spec_stk;
vector<pair<string,Type*>> current_param_vector;
Type* func_ret_type;
int current_level = 0;
int line_num=1;
set<string> labelset;
stack<pair<string,Local_Symbol_Table*>> current_class_struct_union_info;
Symbol_Info::Symbol_Info(string name,string type, string level_name,int level,string scope,string access,Type* t){
    cout << "symbol info constructor called" << endl;
    this->name=name;
    cout << "name accessed" << endl;
    this->type=type;
    cout << "type accessed" << endl;
    this->level_name=level_name;
    cout << "level name accesed" << endl;
    this->level=level;
    cout << "level accesed" << endl;
    this->scope=scope;
    cout << "scope accesed" << endl;
    this->access=access;
    cout << "access accesed" << endl;
    this->t=t;
    cout << "type accesed" << endl;
    this->tempname="";
    cout << "tempname accesed" << endl;
}
void add_to_local_class_struct_union_info(){
    cout << "entered add to local class struct union info" << endl;
    if(!current_class_struct_union_info.empty()){
        cout << "entered the if part" << endl;
        auto z=current_class_struct_union_info.top();
        cout << "accessed top of the stack" << endl;
        if(current_table==nullptr){
            gst->class_struct_union_info[z.first]=z.second;
            cout <<"added to gst class struct union info" << endl;
        }
        else{
            current_table->class_struct_union_info[z.first]=z.second;
            cout << "added to local table class struct union info" << endl;
        }
        current_class_struct_union_info.pop();
        cout << "popped" << endl;
    }
    else{
        cout << "error class not entered in stack in line: " << line_num << endl;
    }
    
}
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
string create_type(Declaration_Specifiers* ds,Declarator* d,Type* t){
    string type="";
    bool isconst=false;
    bool isvolatile=false;
    for(auto i : ds->tq){
        if(i=="CONST")isconst=true;
        else isvolatile=true;
    }
    if(isconst){
        type+="CONST ";
        t->isconst=true;
    }
    if(isvolatile){
        type+="VOLATILE ";
        t->isvolatile=true;
    }
    if(ds->scs.size()==1){
        type+=ds->scs[0];
        type+=" ";
        if(ds->scs[0]=="STATIC")t->isstatic=true;
        else if(ds->scs[0]=="AUTO"){
            t->isauto=true;
            if(!ds->tq.empty()||!ds->ts.empty()){
                cout << "auto cannot be combined with any other type" << endl;
                exit(1); 
            }
        }
        else if(ds->scs[0]=="EXTERN")t->isextern=true;
        else if (ds->scs[0]=="REGISTER")t->isregister=true;
    }
    else if(ds->scs.size()!=0){
        cout << "incorrect storage class specs in type of " << d->id <<"in line :"<< line_num << endl;
        exit(1);
    }
    vector<Type_Specifier*> z=ds->ts;
    reverse(z.begin(),z.end());
    if(z.size()==3){
        if((z[0]->string_type=="UNSIGNED") && (z[1]->string_type=="LONG") && (z[2]->string_type=="LONG")){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG LONG";
            return type + "UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id <<"in line :"<< line_num<< endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="CHAR"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="SHORT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="INT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="LONG"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type=="SIGNED"&& z[1]->string_type=="CHAR"){
            t->isigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="SHORT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="INT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="LONG"){
            t->isigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" SIGNED LONG";
        }
        else if(z[0]->string_type=="LONG"&&z[1]->string_type=="LONG"){
            t->isigned=false;
            t->isbasic=true;
            t->base="LONG LONG";
            type+="LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id <<"in line :"<< line_num<< endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        if(z[0]->string_type=="class"||z[0]->string_type=="struct"||z[0]->string_type=="enum"||z[0]->string_type=="union"){
            if(ds->scs.empty()&&ds->tq.empty()&&d==nullptr){
                t->objtype=z[0]->string_type;
                if(z[0]->string_type=="class"){
                    auto c=z[0]->class_type;
                    if(c->is!=nullptr){
                        t->base_classes=c->is->bcl->bc;
                    }
                }
                else if(z[0]->string_type=="enum"){
                    t->objtype="enum";
                    t->el=z[0]->enum_type->enuml;
                }
                return z[0]->string_type;
            }
            else{
                cout << "error incorrect declaration ^struct^union^enum^class" <<"in line :"<< line_num<< endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="VOID"){
            if(ds->scs.empty()&&ds->tq.empty()){
                t->isvoid=true;
                if(d->check_declarator()!="function"){
                    cout << "only functions can be declared void" << endl;
                    exit(1);
                }
                t->isfunction=true;
                t->prms=get_func_params(d);
                Type* g=new Type();
                g->isvoid=true;
                t->func_ret_type=g;
                return "VOID";
            }
            else {
                cout << "void cannot be combined with anything else" << endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="CHAR"){
            t->isbasic=true;
            t->base="CHAR";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SHORT"){
            t->isbasic=true;
            t->base="SHORT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="INT"){
            t->isbasic=true;
            t->base="INT";
            type+=z[0]->string_type;
            cout << "create type done succesfully" << endl;
        }
        else if(z[0]->string_type=="LONG"){
            t->isbasic=true;
            t->base="LONG";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="FLOAT"){
            t->isbasic=true;
            t->base="FLOAT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="DOUBLE"){
            t->isbasic=true;
            t->base="DOUBLE";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SIGNED"){
            cout << "just signed type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type=="UNSIGNED"){
            cout << "just unsigned type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type.find("struct")!=string::npos){
            t->isobj=true;
            t->objtype="struct";
            t->obj_class=z[0]->string_type.substr(7);
            type+=z[0]->string_type;

        }
        else if(z[0]->string_type.find("union")!=string::npos){
            t->isobj=true;
            t->objtype="union";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("enum")!=string::npos){
            t->objtype="enum";
            t->obj_class=z[0]->string_type.substr(5);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("class")!=string::npos){
            t->isobj=true;
            t->objtype="class";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else{
            cout << "unknown type" << endl;
            exit(1);
        }

    }
    else if(z.size()>3||(z.size()==0&&!t->isauto)) {
        cout << "incorrect type specs in type of " << d->id <<"in line :"<< line_num<< endl;
        exit(1);
    }
    if(d!=nullptr){
        Pointer* y=d->p;
        cout<< "d not nullptr" << endl;
        while(y!=nullptr){
            type+='*';
            t->ptr_level++;
            Tq rr={false,false};
            if(y->tql){
                for(auto i:y->tql->tq){
                    if(i=="CONST"){
                        rr.isconst=true;
                    }
                    if(i=="VOLATILE"){
                        rr.isvol=true;
                    }
                }
            }
            t->ptrtql.push_back(rr);
            y=y->p;
        }
        string dtype=d->check_declarator();
        cout << "check_declarator done" << endl;
        if(dtype=="array"){
            Direct_Declarator* a=d->dd;
            while(a->type=="array"){
                type+='$';
                t->array_dim++;
                a=a->dd;
            }
        }
        else if(dtype=="function"){
            cout << "this is  function" << endl;
            if(ds->scs.empty()&&ds->tq.empty()){
                t->isfunction=true;
                Type* g=new Type();
                create_type(ds,nullptr,g);
                cout << "create type for int done" << endl;
                t->func_ret_type=g;
                if(g->isobj==false&&g->objtype!=""){
                    cout << "invalid return type for func" << endl;
                    exit(1);
                }
                t->prms=get_func_params(d);
                cout << "function params extracted successfully" << endl;
            }
            else{
                cout << "function cannot be declared with other keywords" << endl;
                exit(1);
            }
        }
        else if(dtype=="function pointer"){
            t->prms=get_func_params(d);
            Type* g=new Type();
            create_type(ds,nullptr,g);
            t->func_ret_type=g;
            if(g->isobj==false&&g->objtype!=""){
                cout << "invalid return type for func" << endl;
                exit(1);
            }
            Declarator* a=d->dd->d;
            Pointer* q=a->p;
            while(q!=nullptr){
                type+='#';
                q=q->p;
                t->func_ptr_lev++;
            }

        }
    }
    return type;
}

Type_Name::Type_Name(Specifier_Qualifier_List* sql, Abstract_Declarator* ad)
    : sql(sql), ad(ad) {
        this->type=this->create_type_tn(this->sql,this->ad);
}
Abstract_Declarator :: Abstract_Declarator(Pointer* p,Direct_Abstract_Declarator* dad) 
{   
    this->p=p;
    this->dad=dad;
    this->type="";
}
Direct_Abstract_Declarator::Direct_Abstract_Declarator(string type, Abstract_Declarator* ad, Direct_Abstract_Declarator* dad,Type* con_exp,Parameter_List* pl)
: type(type), ad(ad), dad(dad), con_exp(con_exp),pl(pl)  {

}

Struct_Declaration_List::Struct_Declaration_List() : sdl() {}

Class_Member_Declaration_List::Class_Member_Declaration_List(){
    // Constructor logic
}

string create_type(Specifier_Qualifier_List* ds,Declarator* d,Type* t){
    string type="";
    bool isconst=false;
    bool isvolatile=false;
    for(auto i : ds->tq){
        if(i=="CONST")isconst=true;
        else isvolatile=true;
    }
    if(isconst){
        type+="CONST ";
        t->isconst=true;
    }
    if(isvolatile){
        type+="VOLATILE ";
        t->isvolatile=true;
    }
    cout << "making type specifier vector" << endl;
    if(!ds) {
        cerr << "CRITICAL: ds is nullptr!" << endl;
    }    
    // assert(ds != nullptr && "DS pointer is null!");
    // assert(ds->ts.size() < 1e6 && "Vector size corrupted");
    vector<Type_Specifier*> z=ds->ts;
    cout << "After modification, ts size: " << ds->ts.size() 
          << ", capacity: " << ds->ts.capacity() << std::endl;
    cout << "create type 2 done till here" << endl;
    reverse(z.begin(),z.end());
    if(z.size()==3){
        if((z[0]->string_type=="UNSIGNED") && (z[1]->string_type=="LONG") && (z[2]->string_type=="LONG")){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG LONG";
            return type + "UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id <<"in line :"<< line_num<< endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="CHAR"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="SHORT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="INT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="LONG"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type=="SIGNED"&& z[1]->string_type=="CHAR"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="SHORT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="INT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="LONG"){
            t->isigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" SIGNED LONG";
        }
        else if(z[0]->string_type=="LONG"&&z[1]->string_type=="LONG"){
            t->isigned=false;
            t->isbasic=true;
            t->base="LONG LONG";
            type+="LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id <<"in line :"<< line_num<< endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        if(z[0]->string_type=="class"||z[0]->string_type=="struct"||z[0]->string_type=="enum"||z[0]->string_type=="union"){
            if(ds->tq.empty()&&d==nullptr){
                t->objtype=z[0]->string_type;
                if(z[0]->string_type=="class"){
                    auto c=z[0]->class_type;
                    if(c->is!=nullptr){
                        t->base_classes=c->is->bcl->bc;
                    }
                }
                else if(z[0]->string_type=="enum"){
                    t->objtype="enum";
                    t->el=z[0]->enum_type->enuml;
                }
                return z[0]->string_type;
            }
            else{
                cout << "error incorrect declaration ^struct^union^enum^class" <<"in line :"<< line_num<< endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="VOID"){
            if(ds->tq.empty()){
                t->isvoid=true;
                if(d->check_declarator()!="function"){
                    cout << "only functions can be declared void" << endl;
                    exit(1);
                }
                t->isfunction=true;
                t->prms=get_func_params(d);
                Type* g=new Type();
                g->isvoid=true;
                t->func_ret_type=g;
                return "VOID";
            }
            else {
                cout << "void cannot be combined with anything else" << endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="CHAR"){
            t->isbasic=true;
            t->base="CHAR";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SHORT"){
            t->isbasic=true;
            t->base="SHORT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="INT"){
            t->isbasic=true;
            t->base="INT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="LONG"){
            t->isbasic=true;
            t->base="LONG";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="FLOAT"){
            t->isbasic=true;
            t->base="FLOAT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="DOUBLE"){
            t->isbasic=true;
            t->base="DOUBLE";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SIGNED"){
            cout << "just signed type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type=="UNSIGNED"){
            cout << "just unsigned type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type.find("struct")!=string::npos){
            t->isobj=true;
            t->objtype="struct";
            t->obj_class=z[0]->string_type.substr(7);
            type+=z[0]->string_type;

        }
        else if(z[0]->string_type.find("union")!=string::npos){
            t->isobj=true;
            t->objtype="union";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("enum")!=string::npos){
            t->objtype="enum";
            t->obj_class=z[0]->string_type.substr(5);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("class")!=string::npos){
            t->isobj=true;
            t->objtype="class";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else{
            cout << "unknown type" << endl;
            exit(1);
        }

    }
    else if(z.size()>3||(z.size()==0)) {
        cout << "incorrect type specs in type of " << d->id << endl;
        exit(1);
    }
    if(d!=nullptr){
        Pointer* y=d->p;
        while(y!=nullptr){
            type+='*';
            t->ptr_level++;
            Tq rr={false,false};
            if(y->tql){
                for(auto i:y->tql->tq){
                    if(i=="CONST"){
                        rr.isconst=true;
                    }
                    if(i=="VOLATILE"){
                        rr.isvol=true;
                    }
                }
            }
            t->ptrtql.push_back(rr);
            y=y->p;
        }
        string dtype=d->check_declarator();
        if(dtype=="array"){
            Direct_Declarator* a=d->dd;
            while(a->type=="array"){
                type+='$';
                t->array_dim++;
                a=a->dd;
            }
        }
        else if (dtype=="function"){
            if(ds->tq.empty()){
                t->isfunction=true;
                Type* g=new Type();
                create_type(ds,nullptr,g);
                cout << "int done" << endl;
                t->func_ret_type=g;
                if(g->isobj==false&&g->objtype!=""){
                    cout << "invalid return type for func" << endl;
                    exit(1);
                }
                t->prms=get_func_params(d);
            }
            else{
                cout << "function cannot be declared with other keywords" << endl;
                exit(1);
            }
        }
        else if(dtype=="function pointer"){
            t->prms=get_func_params(d);
            Type* g=new Type();
            create_type(ds,nullptr,g);
            t->func_ret_type=g;
            if(g->isobj==false&&g->objtype!=""){
                cout << "invalid return type for func" << endl;
                exit(1);
            }
            Declarator* a=d->dd->d;
            Pointer* q=a->p;
            while(q!=nullptr){
                type+='#';
                q=q->p;
                t->func_ptr_lev++;
            }

        }
    }
    return type;
}
Type* Type_Name::create_type_tn(Specifier_Qualifier_List* ds,Abstract_Declarator* ad){
    Type* t=new Type();
    string type="";
    bool isconst=false;
    bool isvolatile=false;
    for(auto i : ds->tq){
        if(i=="CONST")isconst=true;
        else isvolatile=true;
    }
    if(isconst){
        type+="CONST ";
        t->isconst=true;
    }
    if(isvolatile){
        type+="VOLATILE ";
        t->isvolatile=true;
    }
    vector<Type_Specifier*> z=ds->ts;
    reverse(z.begin(),z.end());
    if(z.size()==3){
        if((z[0]->string_type=="UNSIGNED") && (z[1]->string_type=="LONG") && (z[2]->string_type=="LONG")){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG LONG";
            type+="UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << ad->type << endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="CHAR"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="SHORT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="INT"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="LONG"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type=="SIGNED"&& z[1]->string_type=="CHAR"){
            t->isunsigned=true;
            t->isbasic=true;
            t->base="CHAR";
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="SHORT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="SHORT";
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="INT"){
            t->isigned=true;
            t->isbasic=true;
            t->base="INT";
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="LONG"){
            t->isigned=true;
            t->isbasic=true;
            t->base="LONG";
            type+=" SIGNED LONG";
        }
        else if(z[0]->string_type=="LONG"&&z[1]->string_type=="LONG"){
            t->isigned=false;
            t->isbasic=true;
            t->base="LONG LONG";
            type+="LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << ad->type << endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        if(z[0]->string_type=="class"||z[0]->string_type=="struct"||z[0]->string_type=="enum"||z[0]->string_type=="union"){
            if(ds->tq.empty()&&ad==nullptr){
                t->objtype=z[0]->string_type;
                if(z[0]->string_type=="class"){
                    auto c=z[0]->class_type;
                    if(c->is!=nullptr){
                        t->base_classes=c->is->bcl->bc;
                    }
                }
                else if(z[0]->string_type=="enum"){
                    t->objtype="enum";
                    t->el=z[0]->enum_type->enuml;
                }
                return t;
            }
            else{
                cout << "error incorrect declaration ^struct^union^enum^class" << endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="VOID"){
            if(ds->tq.empty()){
                t->isvoid=true;
                if(ad->check_abstract_declarator()!="function"){
                    cout << "only functions can be declared void" << endl;
                    exit(1);
                }
                t->isfunction=true;
                t->prms=get_func_params(ad);
                Type* g=new Type();
                g->isvoid=true;
                t->func_ret_type=g;
                return t;
            }
            else {
                cout << "void cannot be combined with anything else" << endl;
                exit(1);
            }
        }
        else if(z[0]->string_type=="CHAR"){
            t->isbasic=true;
            t->base="CHAR";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SHORT"){
            t->isbasic=true;
            t->base="SHORT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="INT"){
            t->isbasic=true;
            t->base="INT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="LONG"){
            t->isbasic=true;
            t->base="LONG";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="FLOAT"){
            t->isbasic=true;
            t->base="FLOAT";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="DOUBLE"){
            t->isbasic=true;
            t->base="DOUBLE";
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type=="SIGNED"){
            cout << "just signed type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type=="UNSIGNED"){
            cout << "just unsigned type not allowed" << endl;
            exit(1);
        }
        else if(z[0]->string_type.find("struct")!=string::npos){
            t->isobj=true;
            t->objtype="struct";
            t->obj_class=z[0]->string_type.substr(7);
            type+=z[0]->string_type;

        }
        else if(z[0]->string_type.find("union")!=string::npos){
            t->isobj=true;
            t->objtype="union";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("enum")!=string::npos){
            t->objtype="enum";
            t->obj_class=z[0]->string_type.substr(5);
            type+=z[0]->string_type;
        }
        else if(z[0]->string_type.find("class")!=string::npos){
            t->isobj=true;
            t->objtype="class";
            t->obj_class=z[0]->string_type.substr(6);
            type+=z[0]->string_type;
        }
        else{
            cout << "unknown type" << endl;
            exit(1);
        }

    }
    else if(z.size()>3||z.size()==0) {
        cout << "incorrect type specs in type of " << ad->type << endl;
        exit(1);
    }
    if(ad!=nullptr){
        Pointer* y=ad->p;
        while(y!=nullptr){
            type+='*';
            Tq rr={false,false};
            if(y->tql){
                for(auto i:y->tql->tq){
                    if(i=="CONST"){
                        rr.isconst=true;
                    }
                    if(i=="VOLATILE"){
                        rr.isvol=true;
                    }
                }
            }
            t->ptrtql.push_back(rr);
            t->ptr_level++;
            y=y->p;
        }
        string dtype=ad->check_abstract_declarator();
        if(dtype=="array"){
            Direct_Abstract_Declarator* a=ad->dad;
            while(a->type=="array"){
                type+='$';
                t->array_dim++;
                a=a->dad;
            }
        }
        else if (dtype=="function"){
            if(ds->tq.empty()){
                t->isfunction=true;
                Type* g=new Type();
                create_type(ds,nullptr,g);
                t->func_ret_type=g;
                if(g->isobj==false&&g->objtype!=""){
                    cout << "invalid return type for func" << endl;
                    exit(1);
                }
                t->prms=get_func_params(ad);
            }
            else{
                cout << "function cannot be declared with other keywords" << endl;
                exit(1);
            }
        }
        else if(dtype=="function pointer"){
            t->prms=get_func_params(ad);
            Type* g=new Type();
            create_type(ds,nullptr,g);
            t->func_ret_type=g;
            if(g->isobj==false&&g->objtype!=""){
                cout << "invalid return type for func" << endl;
                exit(1);
            }
            Abstract_Declarator* a=ad->dad->ad;
            Pointer* q=a->p;
            while(q!=nullptr){
                type+='#';
                q=q->p;
                t->func_ptr_lev++;
            }

        }
    }
    return t;
}
Type* get_type_exp(string s){
    Type* t=new Type();
    t->isbasic=true;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='-'){
            t->base="FLOAT";
            return t;
        }
    }
    t->base="INT";
    return t;

}

vector<pair<string,pair<string,Type*>>> create_struct_name_type_list(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl){
    vector<pair<string,pair<string,Type*>>> result;
    if(sdl==nullptr){
        Type* t=new Type();
        string type=create_type(sql,nullptr,t);
        cout << "create type in create_struct_name_type_list done" << endl;
        if(type=="class"||type=="struct"||type=="union"||type=="enum"){
            if(sql->ts[0]->string_type=="class"){
                
                    string name=sql->ts[0]->class_type->class_name;
                    result.push_back(make_pair(name,make_pair("class",t)));
                
            }
            else if(sql->ts[0]->string_type=="struct"){
                
                    string name=sql->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,make_pair("struct",t)));
            
                
            }
            else if(sql->ts[0]->string_type=="union"){
               
                    string name=sql->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,make_pair("union",t)));
                
            }
            else if(sql->ts[0]->string_type=="enum"){
                
                    string name=sql->ts[0]->enum_type->id;
                    result.push_back(make_pair(name,make_pair("enum",t)));
            }
            else {
                cout << "error &&&" << endl;
            }
    }
    }
    for(auto i:sdl->sd){
        Type* t=new Type();
        string type=create_type(sql,i->d,t);
        string name=get_name(i->d);
        result.push_back(make_pair(name,make_pair(type,t)));
    }
    return result;
}
void check_if_pointer(Type* t){
    if(t->ptr_level==0){
        cout << "delete must be used with ptr" << endl;
        exit(1);
    }
}

void check_if_constructor(Type* t){
    if(t->obj_class!=""&&t->isobj==false){

    }
    else{
        cout<<"only constructor is called with new"<<endl;
        exit(1);
    }
}
void check_if_array(Type* t){
    if(t->array_dim==0){
        cout << "delete [] should be used with array" << endl;
        exit(1);
    }
}
void check_compatibility(Initializer* i,Type* t){
    if(i->ini_lst!=nullptr){
        if(t->array_dim>0){
            for(auto j:i->ini_lst->iv){
                cout<<"check compatiblity if block"<<endl;
                t->array_dim--;
                check_compatibility(j,t);
                t->array_dim++;
            }
        }
        else{
            cout << "{} can be only used in array initilisation" << endl;
            exit(1);
        }
    }
    else{
        cout<<"check compatiblity else block"<<endl;
        cout << t->base << endl;
        cout << t->isfunction << endl;
        cout << t->func_ptr_lev << endl;
        cout << i->type->isobj << " " << i->type->base << endl;
        check_for_assign(t,i->type,"=");
        cout << "check for assign done" << endl;
    }

}

vector<Type*> get_const_params(Parameter_List* p){
    /*for each parameter declaration get type from declaration specifiers and declarator or abstract declarator*/
    vector<Type*> ans;
    if(p==nullptr)return ans;
    vector<pair<string,Type*>> prms=get_params(p);
    set<string> s;
    for(auto i:prms){
        Type* alpha=i.second;
        if(alpha->isfunction){
            cout << "function params cannot contain function" << endl;
            exit(1);
        }
        else if(alpha->isobj==false&&alpha->objtype!=""){
            cout << "function cannot have whole class declaration as parameter" << endl;
            exit(1);
        }
        else if(alpha->isstatic||alpha->isauto||alpha->isextern||alpha->isregister){
            cout << "storage class specs not allowed in function definition" << endl;
            exit(1);
        }
        s.insert(i.first);
        ans.push_back(alpha);
    }
    if(s.size()!=prms.size()){
        cout << "error: " << "all parameters should have unique name" <<"in line :"<< line_num<< endl;
        exit(1);
    }
    return ans;
}

void check_argument_with_params(vector<Type*> prms,vector<Type*> args){
    if(args.size()!=prms.size()){
        cout << "number of args !=number of prms" << endl;
        exit(1);
    }
    int n=args.size();
    for(int i=0;i<n;i++){
        check_for_assign(prms[i],args[i],"=");
    }
}
void check_inc_dec_op(Type* tp) {
    // Const qualification check
    if (tp->isconst) {
        cout << "Error: INC_OP/DEC_OP cannot be applied to const-qualified type"<<"in line :"<< line_num<<endl;
        exit(1);
    }
    // Check for invalid base types
    if (tp->isvoid) {
        cout << "Error: INC_OP/DEC_OP not allowed for type 'void'"<<"in line :"<< line_num<<endl;
        exit(1);
    }
    if (tp->isnull) {
        cout << "Error: INC_OP/DEC_OP not allowed for nullptr type"<<"in line :"<< line_num<<endl;
        exit(1);
    }
    // Object type checks
    if (tp->isobj) {
        static const unordered_set<string> invalid_obj = {"enum", "struct", "class", "union"};
        if (invalid_obj.count(tp->obj_class)) {
            cout << "Error: INC_OP/DEC_OP not allowed for " << tp->obj_class << " type\n";
            exit(1);
        }
    }
    // Special type checks
    if (tp->func_ptr_lev > 0 || tp->array_dim > 0 || tp->isfunction) {
        const char* type_name = "";
        if (tp->func_ptr_lev > 0) type_name = "function pointers";
        else if (tp->array_dim > 0) type_name = "array types";
        else if (tp->isfunction) type_name = "function types";
        
        cout << "Error: Cannot use INC_OP/DEC_OP on " << type_name <<"in line :"<< line_num<<endl;
        exit(1);
    }
}

void check_for_shift_op(Type* e1, Type* e2) {
    auto check_operand = [](Type* tp, const string& side) {
        if (tp->isnull) {
            cout << "Error: Invalid " << side << " operand for shift operator (nullptr type)"<<"in line :"<< line_num<<endl;
            exit(1);
        }
        if (tp->isvoid) {
            cout << "Error: Invalid " << side << " operand for shift operator (void type)" << " in line: " << line_num << endl;
            exit(1);
        }
        if (tp->isobj) {
            static const unordered_set<string> invalid_obj = {"enum", "struct", "class", "union"};
            if (invalid_obj.count(tp->obj_class)) {
                cout << "Error: Invalid " << side << " operand for shift operator ("
                     << tp->obj_class << " type)\n";
                exit(1);
            }
        }
        if (tp->isbasic && (tp->base == "float" || tp->base == "double")) {
            cout << "Error: Invalid " << side << " operand for shift operator ("
                 << tp->base << " type)\n";
            exit(1);
        }
        if (tp->func_ptr_lev > 0) {
            cout << "Error: Invalid " << side << " operand for shift operator (function pointer)" << " in line: " << line_num << endl;
            exit(1);
        }
        if (tp->array_dim > 0) {
            cout << "Error: Invalid " << side << " operand for shift operator (array type)" << " in line: " << line_num << endl;
            exit(1);
        }
        if (tp->isfunction) {
            cout << "Error: Invalid " << side << " operand for shift operator (function type)" << " in line: " << line_num << endl;
            exit(1);
        }
        if (tp->ptr_level > 0) {
            cout << "Error: Invalid " << side << " operand for shift operator (pointer type)" << " in line: " << line_num << endl;
            exit(1);
        }
    };
    check_operand(e1, "left");
    check_operand(e2, "right");
}
Type :: Type(){
    this-> isconst=false;
    this-> isvoid=false;
    this-> isvolatile=false;
    this-> isfunction=false;
    this-> isbasic=false;
    this-> isobj=false;
    this-> isstatic=false;
    this-> isauto=false;
    this-> isextern=false;
    this-> isregister=false;
    this-> isigned=false;
    this-> isunsigned=false;
    this-> isnull=false;
    this-> isenum=false;
    this-> func_ret_type = nullptr;
    this-> el=nullptr;
    this-> base = "";
    this-> objtype = "";
    this-> obj_class = "";
    this-> array_dim = 0;
    this-> ptr_level = 0;
    this-> func_ptr_lev = 0;
    this->code=vector<string>();
    this->place="";
}
Type* check_if_id_in_obj(Type* t,string id){
    stack<pair<string,Local_Symbol_Table*>> copy=current_class_struct_union_info;
    int ccl=current_level;
    Local_Symbol_Table* cct=current_table;
    while(ccl>=0){
    if(ccl>0){
    if(ccl>copy.size()){
        if(cct!=nullptr&&cct->class_struct_union_info.find(t->obj_class)!=nullptr){
            Local_Symbol_Table* x=cct->class_struct_union_info[t->obj_class];
            if(x->lst.find(id)!=nullptr){
                Symbol_Info* z=x->lst[id];
                Type* y=z->t;
                if(y->isauto){
                    cout << "cannot declare auto inside class" << endl;
                    exit(1);
                }
                if(!y->isobj&&y->objtype!=""){
                    cout << "cannot access a struct class or union declaration" << endl;
                    exit(1);
                }
                else{
                    return y;
                }
            }
            else{
                cout << "no such member in " << t->obj_class << endl;
                exit(1);
            }
        }
        else if(cct==nullptr){
            Global_Symbol_Table* ccg=gst;
            if(ccg->class_struct_union_info.find(t->obj_class)!=nullptr){
                Local_Symbol_Table* x=ccg->class_struct_union_info[t->obj_class];
                if(x->lst.find(id)!=nullptr){
                    Symbol_Info* z=x->lst[id];
                    Type* y=z->t;
                    if(y->isauto){
                        cout << "cannot declare auto inside class" << endl;
                        exit(1);
                    }
                    if(!y->isobj&&y->objtype!=""){
                        cout << "cannot access a struct class or union declaration" << endl;
                        exit(1);
                    }
                    else{
                        return y;
                    }
                }
                else{
                    cout << "no such member in " << t->obj_class << endl;
                    exit(1);
                }
            }
            else{
                cout << "class not found" << endl;
                exit(1);
            }
        }
        else{
            ccl--;
            cct=cct->parent;
        }
    }
    else{
        if(copy.top().first==t->obj_class){
            Local_Symbol_Table* x=copy.top().second;
            if(x->lst.find(id)!=nullptr){
                Symbol_Info* z=x->lst[id];
                Type* y=z->t;
                if(y->isauto){
                    cout << "cannot declare auto inside class" << endl;
                    exit(1);
                }
                if(!y->isobj&&y->objtype!=""){
                    cout << "cannot access a struct class or union declaration" << endl;
                    exit(1);
                }
                else{
                    return y;
                }
            }
            else{
                cout << "no such member in " << t->obj_class << endl;
                exit(1);
            }
        }
        else{
            if(cct!=nullptr){
                ccl--;
                cct=cct->parent;
            }
            copy.pop();
        }
    }
    }
    else{
        Global_Symbol_Table* ccg=gst;
            if(ccg->class_struct_union_info.find(t->obj_class)!=nullptr){
                Local_Symbol_Table* x=ccg->class_struct_union_info[t->obj_class];
                if(x->lst.find(id)!=nullptr){
                    Symbol_Info* z=x->lst[id];
                    Type* y=z->t;
                    if(y->isauto){
                        cout << "cannot declare auto inside class" << endl;
                        exit(1);
                    }
                    if(!y->isobj&&y->objtype!=""){
                        cout << "cannot access a struct class or union declaration" << endl;
                        exit(1);
                    }
                    else{
                        return y;
                    }
                }
                else{
                    cout << "no such member in " << t->obj_class << endl;
                    exit(1);
                }
            }
            else{
                cout << "class not found" << endl;
                exit(1);
            }
            ccl--;
    }
    }
    cout << "class not found " << t->obj_class  << endl;
    exit(1);
}

Argument_Expression_List :: Argument_Expression_List(){
    this->vec_exp={};
    this->prm_temps=vector<string>();
}



Type* check_for_assign(Type* t1, Type* t2,string op) {
    cout << t1->base << " " << t2->base << endl;
    cout<< t1->isbasic<<" " <<t2->isbasic<<endl;
    cout << "base checked" << endl;
    if(op=="="){
        bool isconst=false;
        if(t1->ptr_level>0){
            cout<<"inside pointer"<<endl;
            Tq ss=t1->ptrtql.back();
            isconst=ss.isconst;
            cout<<"completed inside pointer"<<endl;
        }
        else isconst=t1->isconst;
        if(t1->isfunction){
            cout << "functions cannot be assigned a value" << endl;
            exit(1);
        }
        else if(t1->isconst){
            cout << "cannot change value of a constant" << endl;
            exit(1);
        }
        else if(t1->isnull){
            cout << "cannot assign value to nullptr" << endl;
        }
        else if(t2->isvoid||t2->isvoid){
            cout << "cannot assign a void type to anything" << endl;
            exit(1);
        }
        else if(t1->isauto){
            return t2;
        }
        else if(t2->isauto){
            cout << "first assign value to auto" << endl;
        }
        else if(t1->isenum){
            if(!t2->isenum){
                cout << "enum can be assigned only enum value" << endl;
                exit(1);
            }
            else if(t1->obj_class!=t2->obj_class){
                cout << "enum can be assigned only enum value" << endl;
                exit(1);
            }
            else{
                return t2;
            }
        }
        else if(t1->func_ptr_lev>0||t2->func_ptr_lev>0||t2->isfunction){
            if((t1->func_ptr_lev==1&&t2->isfunction)||(t1->func_ptr_lev==t2->func_ptr_lev+1)){
                if(!is_equal(t1->func_ret_type,t2->func_ret_type)){
                    cout << "return type not same" << endl;
                    exit(1);
                }
                else{
                    if(t1->prms.size()==t2->prms.size()){
                        int n=t1->prms.size();
                        for(int i=0;i<n;i++){
                            check_for_assign(t1->prms[i],t2->prms[i],"=");
                        }
                        return t2;
                    }
                    else{
                        cout << "function pointer prms not matching" << endl;
                        exit(1);
                    }
                }
            }
            else {
                cout << "invalid assigment for function pointer" << endl;
            }
        }
        else if(t2->isfunction){
            cout << "invalid assignment for func" << endl;
            exit(1);
        }
        else if(t1->ptr_level>0&&t2->isnull){
            cout<<"another ppointer in check for assign"<<endl;
            return t2;
        }
        else if(t2->isenum){
            if(t1->isbasic&&t1->base!="CHAR"&&t1->base!="SHORT"&&t1->ptr_level==0&&t1->array_dim==0&&t1->func_ptr_lev==0){
                return t2;
            }
            else{
                cout << "enum cannot be asgined to this type" << endl;
                exit(1);
            }
        }
        else if(t1->array_dim>0||t2->array_dim>0){
            if(is_equal(t1,t2)){
                return t2;
            }
            else{
                cout << "invalid assignment with arrays" << endl;
            }
        }
        else if(t1->ptr_level>0||t2->ptr_level>0){
            if(t1->isbasic||t2->isbasic){
                if(is_equal(t1,t2)){
                    return t2;
                }
                else{
                    cout << "invalid assignment with ptrs" << endl;
                    exit(1);
                }
            }
            else{
                if(t1->ptr_level==1&&t2->ptr_level==1){
                    assert(t1->isobj);
                    assert(t2->isobj);
                    if(t1->objtype==t1->objtype){
                        if(t1->objtype=="class"){
                            if(t1->obj_class==t2->obj_class){
                                return t2;
                            }
                            else{
                                bool check=false;
                                Type* z2=get_type_id(t2->obj_class);
                                for(auto i:z2->base_classes){
                                    if(t1->obj_class==i->id){
                                        check=true;
                                        break;
                                    }
                                }
                                if(check){
                                    return t2;
                                }
                                else{
                                    cout << "different classes " << endl;
                                    exit(1);
                                }
                            }
                        }
                        else{
                            if(t1->obj_class==t2->obj_class){
                                return t2;
                            }
                            else{
                                cout << "different struct/union" << endl;
                                exit(1);
                            }
                        }
                    }
                    else{
                        cout << "not proper assignment between objects:different inter assignment between struct union class" << endl;
                        exit(1);
                    }
                }
                else{
                    if(is_equal(t1,t2)){
                        return t2;
                    }
                    else{
                        cout << "not proper assignment between objects pointers" << endl;
                        exit(1);
                    }
                }
            }
        }
        else{
            if(t1->isbasic||t2->isbasic){
                if(t1->isbasic&&t2->isbasic){
                    cout << t1->base << " " << t2->base << endl;
                    if(t1->base==t2->base){
                        return t2;
                    }
                    else if(t1->base=="LONG LONG"&&(t2->base=="INT"||t2->base=="SHORT"||t2->base=="LONG"||t2->base=="CHAR")){
                        return t2;
                    }
                    else if(t1->base=="LONG"&&(t2->base=="INT"||t2->base=="SHORT"||t2->base=="CHAR")){
                        return t2;
                    }
                    else if(t1->base=="FLOAT"&&(t2->base=="INT"||t2->base=="SHORT"||t2->base=="CHAR")){
                        return t2;
                    }
                    else if(t1->base=="DOUBLE"&&(t2->base=="INT"||t2->base=="SHORT"||t2->base=="LONG"||t2->base=="FLOAT"||t2->base=="CHAR")){
                        return t2;
                    }
                    else if(t1->base=="INT"&&(t2->base=="CHAR"||t2->base=="SHORT")){
                        return t2;
                    }
                    else{
                        cout << "basic types not compatible for assignment" << endl;
                        exit(1);
                    }
                }
                else{
                    cout << "basic types not compatible with obj types for assignment" << endl;
                    exit(1);
                }
            }
            else{
                assert(t1->isobj);
                assert(t2->isobj);
                if(t1->objtype==t1->objtype){
                    if(t1->objtype=="class"){
                        if(t1->obj_class==t2->obj_class){
                            return t2;
                        }
                        else{
                            Type* z2=get_type_id(t2->obj_class);
                            bool check=false;
                            for(auto i:z2->base_classes){
                                if(t1->obj_class==i->id){
                                    check=true;
                                    break;
                                }
                            }
                            if(check){
                                return t2;
                            }
                            else{
                                cout << "different classes " << endl;
                                exit(1);
                            }
                        }
                    }
                    else{
                        if(t1->obj_class==t2->obj_class){
                            return t2;
                        }
                        else{
                            cout << "different struct/union" << endl;
                            exit(1);
                        }
                    }
                }
                else{
                    cout << "not proper assignment between objects:different inter assignment between struct union class" << endl;
                    exit(1);
                }
            }
        }

    }
    else{
        check_for_assign(t1,check_for_arithmatic_op(t1,t2),"=");
        return t1;
    }
}

void check_typecast_compatibility(Type* t1,Type* t2){
    check_for_assign(t1,t2,"=");
}
bool is_equal(Type* t1,Type* t2){
    bool check=true;
    if(t1->prms.size()==t2->prms.size()){
        int n=t1->prms.size();
        for(int i=0;i<n;i++){
            if(!is_equal(t1->prms[i],t2->prms[i])){
                check=false;
                break;
            }
        }
    }
    return (
        check&&
        t1->isfunction==t2->isfunction &&
        t1->isbasic==t2->isbasic &&
        t1->isobj==t2->isobj &&
        t1->isauto==t2->isauto &&
        t1->isnull==t2->isnull &&
        t1->isenum==t2->isenum &&
        is_equal(t1->func_ret_type,t2->func_ret_type)&&
        t1->base==t2->base&&
        t1->objtype==t2->objtype&&
        t1->obj_class==t2->obj_class&&
        t1->array_dim==t2->array_dim&&
        t1->ptr_level==t2->ptr_level&&
        t1->func_ptr_lev==t2->func_ptr_lev
        
    );
}

/*
vector<pair<string,Symbol_Info>> get_params(Parameter_List* p){
    vector<pair<string,string>> ans;
    if(p==nullptr)return ans;
    for(auto i:p->pl){
        vector<string> prms;
        bool isfunction;
        string type=create_type(i->ds,i->dec,isfunction,prms);
        string name=get_name(i->dec);
        if
        Symbol_Info info;
        pair<string,string> x={type,name};
        ans.push_back(x);
    }
    return ans;
}
// Helper function to check if a type is a function pointer
bool is_function_pointer(const string& type) {
    return type.find("(*)") != string::npos;
}

// Helper function to check if a type is a class or struct
bool is_class_or_struct(const string& type) {
    return type.find("class") == 0 || type.find("struct") == 0;
}

// Helper function to check if a type is a base class of another type
/*Steps to Check Inheritance
Access the Global Symbol Table (gst):

The Global_Symbol_Table (gst) contains information about all classes, structs, and other entities defined in the program.
Each class in the gst has its inheritance information stored in the Inheritance_Specifier object.
Retrieve the Class Information:

For the param_type (expected type) and arg_type (actual type), check if they are class types.
Look up the class information in the gst using the class_struct_union_info map.
Check the Inheritance Relationship:

If param_type is a base class, traverse the inheritance hierarchy of arg_type to see if param_type is one of its base classes.
Use the Inheritance_Specifier and Base_Class_List objects to traverse the inheritance hierarchy.
Return the Result:

If param_type is found in the inheritance hierarchy of arg_type, the check passes.
Otherwise, report a type mismatch.
*/
Type* check_if_function(Type* t){
    if(t->isfunction){
        return t->func_ret_type;
    }
    else if(t->func_ptr_lev==0&&!t->isobj&&t->objtype==""&&!t->obj_class.empty()){
        Type* z=new Type();
        z->isobj=true;
        z->ptr_level++;
        z->objtype="class";
        z->obj_class=t->obj_class;
        return z;
    }
    else{
        cout << "only functions can be called" << endl;
        exit(1);
    }
    
}

string Abstract_Declarator:: check_abstract_declarator(){
    Direct_Abstract_Declarator* z=this->dad;
    if(z==nullptr){
        return "id";
    }
    else if(z->type=="func"){
        Direct_Abstract_Declarator* nxt=z->dad;
        if(nxt=nullptr){
            return "function";
        }
        else if(nxt->type=="abs_dec"){
            if(nxt->ad->dad==nullptr&&nxt->ad->p!=nullptr){
                return "function pointer";
            }
            else{
                cout << "error: " << "is not valid abs declarator" << endl;
                exit(1);
            }
        }
        else{
            cout << "error: " << "is not valid abs declarator" << endl;
             exit(1);
        }
    }
    else if(z->type=="abs_dec"){
        cout << "error: "  << "is not valid declarator" << endl;
        exit(1);
    }
    else if(z->type=="array"){
        Direct_Abstract_Declarator* x=z;
        while(x!=nullptr&&x->type=="array"){
            x=x->dad;
        }
        if(x==nullptr){
            return "array";
        }
        else{
            cout << "error: " << z->type << "is not valid declarator at line no" <<line_num << endl;
            exit(1);
        }
    }
}
Symbol_Info* get_symbol_info_id(string id){
    stack<pair<string,Local_Symbol_Table*>> copy=current_class_struct_union_info;
    cout << "copy made here" << endl;
    cout << "this is get symbol info id" << endl;
    cout << "x is there after reching get symbol info id" << endl;
    int ccl=current_level;
    cout << "current level: " << ccl << endl;
    Local_Symbol_Table* cct=current_table;
    while(ccl>=0){
        if(ccl>=1){
            if(ccl>copy.size()){
                cout << "if block of get type id" << endl;
                auto it = cct->lst.find(id);
                if(cct!=nullptr&&it!=cct->lst.end()){
                    Symbol_Info* z=it->second;
                    if(z != nullptr) { // Check 1: Symbol_Info exists
                        cout << "jjjj" << endl;
                        cout << z->name << endl;
                        cout << z->type << endl;
                        cout << "KKKK" << endl;
                        if(z->t != nullptr) { // Check 2: Type pointer valid
                            Type* y = z->t;
                            cout << y->base << endl;
                            cout << "got type from symtab" << endl;
                            
                            if(!y->isobj && y->objtype != "") {
                                // Your error handling
                            } else {
                                return z;
                            }
                        } else {
                            cout << "NULL TYPE POINTER" << endl;
                        }
                    }
                } else if(cct==nullptr){
                    Global_Symbol_Table* ccg=gst;
                    if(ccg->gst.find(id)!=ccg->gst.end()){
                        Symbol_Info* z=ccg->gst[id];
                        Type* y=z->t;
                        if(!y->isobj&&y->objtype!=""){
                            cout << "cannot access a struct class or union declaration" << endl;
                            exit(1);
                        } else {
                            return z;
                        }
                    }
                } else {
                    ccl--;
                    cct=cct->parent;
                }
            } else {
                cout << "else block " << endl;
                ccl--;
                cct=cct->parent;
                copy.pop();
            }
        } else {
            cout << "serching in global symtab" << endl;
            Global_Symbol_Table* ccg=gst;
            if(ccg->gst.find(id)!=ccg->gst.end()){
                Symbol_Info* z=ccg->gst[id];
                Type* y=z->t;
                if(!y->isobj&&y->objtype!=""){
                    cout << "cannot access a struct class or union declaration" << endl;
                    exit(1);
                } else {
                    return z;
                }
            }
            ccl--;
        }
    }
    if(current_params_list.find(id)!=current_params_list.end()){
        cout << "found id in parameter map" << endl;
        Type* y=current_params_list[id];
        Symbol_Info* si=new Symbol_Info(id,"","",0,"","",y);
        si->tempname=y->place;
        final_symtab[si->tempname]=si;
        return si;
    }
    //parameters not handled
    cout << "identifier not found " << id  << endl;
    exit(1);
}
Type* get_type_id(string id) {
    stack<pair<string,Local_Symbol_Table*>> copy=current_class_struct_union_info;
    cout << "copy made here" << endl;
    int ccl=current_level;
    cout << "current level " << ccl << endl;
    Local_Symbol_Table* cct=current_table;
    while(ccl>=0){
        if(ccl>=1){
            cout << "ccl" << endl;
            cout <<ccl << endl;
            if(ccl>copy.size()){
                cout << "if block of get type id" << endl;
                auto it = cct->lst.find(id);
                if(cct!=nullptr&&it!=cct->lst.end()){
                    Symbol_Info* z=it->second;
                    if(z != nullptr) { // Check 1: Symbol_Info exists
                        cout << "jjjj" << endl;
                        cout << z->name << endl;
                        cout << z->type << endl;
                        cout << "KKKK" << endl;
                        if(z->t != nullptr) { // Check 2: Type pointer valid
                            Type* y = z->t;
                            cout << y->base << endl;
                            cout << "got type from symtab" << endl;
                            
                            if(!y->isobj && y->objtype != "") {
                                // Your error handling
                            } else {
                                return y;
                            }
                        } else {
                            cout << "NULL TYPE POINTER" << endl;
                        }
                    }
                } else if(cct==nullptr){
                    cout <<"cct nullptr"<<endl;
                    Global_Symbol_Table* ccg=gst;
                    if(ccg->gst.find(id)!=ccg->gst.end()){
                        Symbol_Info* z=ccg->gst[id];
                        Type* y=z->t;
                        if(!y->isobj&&y->objtype!=""){
                            cout << "cannot access a struct class or union declaration" << endl;
                            exit(1);
                        } else {
                            return y;
                        }
                    }
                } else {
                    cout << "got to parent" <<endl;
                    ccl--;
                    cct=cct->parent;
                }
            } else {
                cout << "else block " << endl;
                ccl--;
                cct=cct->parent;
                copy.pop();
            }
        } else {
            Global_Symbol_Table* ccg=gst;
            cout << "is it serching in global symtab" << endl;
            if(ccg->gst.find(id)!=ccg->gst.end()){
                cout << "found id in global symtab " << endl;
                Symbol_Info* z=ccg->gst[id];
                Type* y=z->t;
                cout << z->name << endl;
                if(!y->isobj&&y->objtype!=""){
                    cout << "cannot access a struct class or union declaration" << endl;
                    exit(1);
                } else {
                    return y;
                }
            }
            cout << "came out of this global symtab block" << endl;
            ccl--;
        }
    }
    if(current_params_list.find(id)!=current_params_list.end()){
        cout << "found id in parameter map" << endl;
        Type* y=current_params_list[id];
        return y;
    }
    cout << "identifier not found " << id  << endl;
    exit(1);
}
Type::Type(const Type& other) {
    isconst = other.isconst;
    isvoid = other.isvoid;
    isvolatile = other.isvolatile;
    isfunction = other.isfunction;
    isbasic = other.isbasic;
    isobj = other.isobj;
    isstatic = other.isstatic;
    isauto = other.isauto;
    isextern = other.isextern;
    isregister = other.isregister;
    isigned = other.isigned;
    isunsigned = other.isunsigned;
    isnull = other.isnull;
    isenum = other.isenum;

    func_ret_type = other.func_ret_type ? new Type(*other.func_ret_type) : nullptr;

    prms.clear();
    for (Type* t : other.prms) {
        prms.push_back(t ? new Type(*t) : nullptr);
    }

    code = other.code;
    place = other.place;

    el = other.el; // shallow copy
    base = other.base;
    objtype = other.objtype;
    obj_class = other.obj_class;

    base_classes = other.base_classes; // shallow copy of vector of pointers

    array_dim = other.array_dim;
    ptr_level = other.ptr_level;
    func_ptr_lev = other.func_ptr_lev;
    ptrtql = other.ptrtql;
}

Type* check_if_array_or_pointer(Type* t){
    Type* T=new Type(*t);
    if(t->array_dim){
        T->array_dim--;
        return T;
    }
    else if(T->ptr_level){
        T->ptr_level--;
        T->ptrtql.pop_back();
        return T;
    }
    else{
        cout << "only pointer or array and be used with square braces" << endl;
        exit(1);
    }
}

vector<pair<string,Type*>> get_params(Parameter_List* p){
    vector<pair<string,Type*>> ans;
    if(p==nullptr)return ans;
    for(auto i:p->pl){
        vector<string> prms;
        bool isfunction;
        Type* t=new Type();
        string type=create_type(i->ds,i->dec,t);
        string name=get_name(i->dec);
        ans.push_back(make_pair(name,t));
    }

    
    return ans;
}
Type* check_for_arithmatic_op(Type* s1, Type* s2){
    //Type* t=new Type();
    cout << s1->base << " " << s2->base << endl;
    cout << s1->isbasic << " " << s2->isbasic << endl;
//     if(s1->isobj || s2->isobj){
//         if((s1->base=="INT" && s2->objtype=="enum") || (s1->objtype=="enum" && s2->base=="INT") || (s1->base=="INT" && s2->objtype=="enum")){
//             t->base="INT";
//         }
//         else{
//             cout << "error:  not valid for arithmatic operation" <<"in line :"<< line_num<<"pls pls check again"<< endl;
//             exit(1);
//         }
//     }
//     if(s1->isbasic || s2->isbasic==false){
//         cout << "error:  not valid for arithmatic operation" <<"in line :"<< line_num<<"pls pls check"<< endl;
//         exit(1);
//     }
//     if(s1->base=="CHAR" && s2->base=="CHAR"){
//         t->base="CHAR";
//     }
//     else if(s1->base=="SHORT" && s2->base=="SHORT" || (s1->base=="SHORT" && s2->base=="CHAR") || (s1->base=="CHAR" && s2->base=="SHORT")){
//         t->base="SHORT";
//     }
//     else if((s1->base=="INT" && s2->base=="INT") || (s1->base=="SHORT" && s2->base=="INT") || (s1->base=="INT" && s2->base=="SHORT") || (s1->base=="CHAR" && s2->base=="INT") || (s1->base=="INT" && s2->base=="CHAR")){
//         t->base="INT";
//     }
//     else if((s1->base=="FLOAT" || s2->base=="FLOAT") || 
//    (s1->base == "INT" && s2->base == "FLOAT") || (s1->base == "FLOAT" && s2->base == "INT") || 
//     (s1->base == "SHORT" && s2->base == "FLOAT") || (s1->base == "FLOAT" && s2->base == "SHORT") || 
//     (s1->base == "CHAR" && s2->base == "FLOAT") || (s1->base == "FLOAT" && s2->base == "CHAR") || 
//     (s1->base == "LONG" && s2->base == "FLOAT") || (s1->base == "FLOAT" && s2->base == "LONG") ||
//     (s1->base == "LONG LONG" && s2->base == "FLOAT") || (s1->base == "FLOAT" && s2->base == "LONG LONG")) {

//     t->base = "FLOAT";
//     }
//     else if ((s1->base == "DOUBLE" || s2->base == "DOUBLE") || 
//     (s1->base == "INT" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "INT") || 
//     (s1->base == "SHORT" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "SHORT") || 
//     (s1->base == "FLOAT" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "FLOAT") || 
//     (s1->base == "CHAR" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "CHAR") ||
//     (s1->base == "LONG" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "LONG") ||
//     (s1->base == "LONG LONG" && s2->base == "DOUBLE") || (s1->base == "DOUBLE" && s2->base == "LONG LONG")) {

//     t->base = "DOUBLE";
//     }
//     else if ((s1->base == "LONG" && s2->base == "LONG") &&
//     (s1->base == "LONG" && s2->base == "INT") || (s1->base == "INT" && s2->base == "LONG") || 
//     (s1->base == "LONG" && s2->base == "CHAR") || (s1->base == "CHAR" && s2->base == "LONG")  || 
//     (s1->base == "LONG" && s2->base == "SHORT") || (s1->base == "SHORT" && s2->base == "LONG")) {

//     t->base = "LONG";
//     }
//     else if ((s1->base == "LONG LONG" && s2->base == "LONG LONG") &&
//     (s1->base == "LONG LONG" && s2->base == "INT") || (s1->base == "INT" && s2->base == "LONG LONG") || 
//     (s1->base == "LONG LONG" && s2->base == "CHAR") || (s1->base == "CHAR" && s2->base == "LONG LONG")  || 
//     (s1->base == "LONG LONG" && s2->base == "SHORT") || (s1->base == "SHORT" && s2->base == "LONG LONG") ||
//     (s1->base == "LONG LONG" && s2->base == "LONG") || (s1->base == "LONG" && s2->base == "LONG LONG")) {

//     t->base = "LONG LONG";
//     }
    
//     else {
//     cout << "error:  not valid for arithmetic operation " <<"in line :"<< line_num<<"pls check"<< endl;
//     exit(1);
//     }
//     return t;
    Type* t=new Type();
    if(s1->ptr_level==0&&s2->ptr_level==0&&s1->array_dim==0&&s2->array_dim==0&&s1->func_ptr_lev==0&&s2->func_ptr_lev==0&&!s1->isfunction&&!s2->isfunction){
        cout << "dash dash" << endl;
        if(s1->isbasic&&s2->isbasic){
            t->isbasic=true;
            cout << "dash dash dash" << endl;
            if(s1->base=="DOUBLE"||s2->base=="DOUBLE"){
                t->base="DOUBLE";
            }
            else if(s1->base=="FLOAT"||s2->base=="FLOAT"){
                t->base="FLOAT";
            }
            else if(s1->base=="LONG LONG"||s2->base=="LONG LONG"){
                t->base="LONG LONG";
            }
            else if(s1->base=="LONG"||s2->base=="LONG"){
                t->base="LONG";
            }
            else if(s1->base=="INT"||s2->base=="INT"){
                t->base="INT";
            }
            else if(s1->base=="SHORT"||s2->base=="SHORT"){
                t->base="SHORT";
            }
            else if(s1->base=="CHAR"||s1->base=="CHAR"){
                t->base="CHAR";
            }
            else{
                cout << "should not be executed" << endl;
            }
        }
        else if(s1->isenum&&s2->isenum){
            t->isbasic=true;
            t->base="INT";
        }
        else if(s1->isenum&&s2->isbasic){
            t->isbasic=true;
            if(s2->base=="INT"||s2->base=="SHORT"||s2->base=="CHAR"){t->base=="INT";}
            else if(s2->base=="LONG"){t->base="LONG";}
            else if(s2->base=="LONG LONG"){t->base=="LONG LONG";}
            else if(s2->base=="FLOAT"){t->base=="FLOAT";}
            else if(s2->base=="DOUBLE"){t->base=="DOUBLE";}
            else {
                cout << "this is not possible" << endl;
            }
        }
        else if(s1->isbasic&&s2->isenum){
            t->isbasic=true;
            if(s1->base=="INT"||s1->base=="SHORT"||s1->base=="CHAR"){t->base=="INT";}
            else if(s1->base=="LONG"){t->base="LONG";}
            else if(s1->base=="LONG LONG"){t->base=="LONG LONG";}
            else if(s1->base=="FLOAT"){t->base=="FLOAT";}
            else if(s1->base=="DOUBLE"){t->base=="DOUBLE";}
            else {
                cout << "this is not possible" << endl;
            }
        }
        else{
            cout << "arithmatic operations not allowed between these types" << endl;
            exit(1);
        }
    }
    else{
        cout << "arithmatic operations not allowed between these types" << endl;
        exit(1);
    }
    cout << t->isbasic << endl;
    cout << "checking here in check_for_arithmatic_op" << endl;
    return t;

}
void check_if_obj(Type* s){
    if(s->objtype=="enum"){
        cout << "error: type is an enum, not an object" <<"in line :"<< line_num<< endl;
        exit(1);
    }
    if(s->isobj==false){
        cout << "error: " << " is not an object" <<"in line :"<< line_num<< endl;
        exit(1);
    }
}

void check_int_comp(Type* type){

    if(type->isbasic==false){
        cout << "error:  not valid type for comparison" <<"in line :"<< line_num<< endl;
        exit(1);
    }
 
}

Type* check_for_eq_op(Type* s1, Type* s2) {
    Type* t=new Type();
     vector<pair<string, string>> validPairs = {
        {"CHAR", "CHAR"}, {"INT", "INT"}, {"SHORT", "SHORT"}, {"LONG", "LONG"}, {"FLOAT", "FLOAT"}, {"DOUBLE", "DOUBLE"},
        {"INT", "CHAR"}, {"CHAR", "INT"}, {"INT", "SHORT"}, {"SHORT", "INT"}, {"LONG", "INT"}, {"INT", "LONG"},
        {"LONG", "SHORT"}, {"SHORT", "LONG"}, {"FLOAT", "INT"}, {"INT", "FLOAT"}, {"FLOAT", "SHORT"}, {"SHORT", "FLOAT"},
        {"FLOAT", "CHAR"}, {"CHAR", "FLOAT"}, {"FLOAT", "LONG"}, {"LONG", "FLOAT"}, {"DOUBLE", "INT"}, {"INT", "DOUBLE"},
        {"DOUBLE", "SHORT"}, {"SHORT", "DOUBLE"}, {"DOUBLE", "CHAR"}, {"CHAR", "DOUBLE"}, {"DOUBLE", "LONG"}, {"LONG", "DOUBLE"},
        {"LONG LONG", "LONG LONG"}, {"LONG LONG", "LONG"}, {"LONG", "LONG LONG"}, {"LONG LONG", "INT"}, {"INT", "LONG LONG"}
    };

    for (auto& pair : validPairs) {
        if ((pair.first == s1->base && pair.second == s2->base) ||
            (pair.first == s2->base && pair.second == s1->base)) {
            t->isbasic = true;
            t->base = "INT";
            return t;
        }
    }
    if (s1->isobj && s2->isobj) {
        if (s1->base == "INT" && s2->objtype == "enum") {
            t->base = "INT";
        } else if (s1->objtype == "enum" && s2->base== "INT") {
            t->base = "INT";
        } else if (s1->base == "CHAR" && s2->objtype == "enum") {   
            t->base = "INT";
        } else if (s1->objtype == "enum" && s2->base == "CHAR") {
            t->base = "INT";
        } else if (s1->base == "SHORT" && s2->objtype == "enum") {      
            t->base = "INT";
        } else if (s1->objtype == "enum" && s2->base == "SHORT") {
            t->base = "INT";
        } else {
            cout << "error:  not valid for comparison" << endl;
            exit(1);
        }
    } else if (s1->ptr_level == s2->ptr_level) {
        if (s1->base == s2->base) {
            t->base = "INT";
        } else {
            cout << "error: not valid for comparison" <<"in line :"<< line_num<< endl;
            exit(1);
        }
    } else if (s1->func_ptr_lev > 0) {
        if (s1->func_ptr_lev == s2->func_ptr_lev) {
            check_argument_with_params({s1->prms}, {s2->prms});
            check_argument_with_params(s1->prms, s2->prms);
            t->base = "INT";
        } else {
            cout << "error:  not valid for comparison" <<"in line :"<< line_num<< endl;
            exit(1);
        }
    } else if (s1->ptr_level > 0 && s2->isnull) {
        t->base = "INT";
    } else {
        cout << "error: not valid for comparison" <<"in line :"<< line_num<< endl;
        exit(1);
    }
    return t;
}
void check_if_obj_ptr(Type* s) {
    if(s->objtype=="enum"){
        cout << "error:  is an enum not object pointer" <<"in line :"<< line_num<< endl;
        exit(1);
    }
    if(s->isobj==false){
        cout << "error:  is not an object pointer" <<"in line :"<< line_num<< endl;
        exit(1);
    }
    if(s->ptr_level==0){
        cout << "error:  is not an  object pointer" <<"in line :"<< line_num<< endl;
        exit(1);
    }
}

string get_string_type(Type* t){
    if(t->isbasic){
        return t->base;
    }
    else if(t->isobj){
        return t->objtype+" "+t->obj_class;
    }
    else{
        cout << "these types are yet to be done" << endl;
        exit(1);
    }
}
Type* get_type_unary_expression(string t1, Type* t2) {
    Type* t = t2;

    if (t1 == "*") {
        if(t->ptr_level>0)t->ptr_level--;
        else{
            cout << "dereferencing can be done only on pointers" << endl;
            exit(1);
        }
    }
    else if(t1=="&"){
        t->ptr_level++;
    }
    else if(t1=="+"||t1=="-"||t1=="~"||t1=="!"){
        if(t->isbasic&&t->ptr_level==0&&t->func_ptr_lev==0&&!t->isfunction){
            return t;
        }
        else{
            cout << "only basic types are allowed for unary operator +,-,~,!" << endl;
            exit(1);
        }
    }
    return t;
}

void check_for_sizeof(Type* t) {
    if ((t->isauto && !t->isbasic) || (t->isauto && !t->isobj) || (t->isvoid)) {
        cout << "error:  not valid for sizeof" << endl;
        exit(1);
    }
    if ((t->isstatic && !t->isbasic) || (t->isstatic && !t->isobj)) {
        cout << "error:  not valid for sizeof" << endl;
        exit(1);
    }
    if ((t->isextern && !t->isbasic) || (t->isextern && !t->isobj)) {
        cout << "error:  not valid for sizeof" << endl;
        exit(1);
    }
    if ((t->isregister && !t->isbasic) || (t->isregister && !t->isobj)) {
        cout << "error: not valid for sizeof" << endl;
        exit(1);
    }
    if (t->isnull || t->isfunction) {
        cout << "error:  not valid for sizeof" << endl;
        exit(1);
    }
}

string Declarator :: check_declarator(){
    //return which type of declarator
    Direct_Declarator* z=this->dd;
    assert(dd!=nullptr);
    if(z->type=="function"){
        cout << "function block of check declarator" << endl;
        Direct_Declarator* nxt=z->dd;
        assert(nxt!=nullptr);
        if(nxt->type=="id"){
            cout << "correct" << endl;
            return "function";
        }
        else if(nxt->type=="declarator"){
            if(nxt->d->dd->type=="id"&&nxt->d->p!=nullptr){
                return "function pointer";
            }
            else{
                cout << "error: " << z->id << "is not valid declarator" <<"in line :"<< line_num<< endl;
                exit(1);
            }
        }
        else{
            cout << "error: " << z->id << "is not valid declarator" <<"in line :"<< line_num<< endl;
             exit(1);
        }
    }
    else if(z->type=="id"){
        return "id";
    }
    else if(z->type=="declarator"){
        cout << "error: " << z->id << "is not valid declarator" <<"in line :"<< line_num<< endl;
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
            cout << "error: " << z->id << "is not valid declarator" <<"in line :"<< line_num<< endl;
            exit(1);
        }
    }
}
void Declarator :: check_for_func(){
    string t=this->check_declarator();
    if(t!="function"){
        cout << "error : invalid function declarator " << this->id <<"in line :"<< line_num<< endl;
        exit(1); 
    }
}
Pointer::Pointer(Type_Qualifier_List* tql, Pointer* p) 
    : tql(tql), p(p) {
}
Type_Qualifier_List::Type_Qualifier_List(){
    //
}
void add_params_to_map(Parameter_List* pl) {
    vector<pair<string, Type* >> params = get_params(pl);
    
    for (const auto& param : params) {
        if (current_params_list.find(param.first) != current_params_list.end()) {
            string t=param.second->base;
            if(t==""){
                t=param.second->objtype;
            }
            std::cerr << "error: parameter " << t
                      << "' of type '" << param.first 
                      << "' conflicts with previous declaration of type '" 
                      <<param.first  <<"in line :"<< line_num;
            exit(1);
        }
        current_params_list[param.first] = param.second;
        current_param_vector.emplace_back(param);
        cout << "params pushed in map" << endl;
    }
}

string get_name(Declarator* d){
    return d->id;
}

vector<Type*> get_func_params(Declarator* d){
    if (!d->isfunction) {
        cerr << "error: declarator is not a function"<<"in line :"<< line_num<< endl;
        exit(1);
    }
    Parameter_List* tpl = d->dd->pl;
    return get_const_params(tpl);
}
vector<Type*> get_func_params(Abstract_Declarator* ad){
    if (!(ad->type=="func")) {
        cerr << "error: declarator is not a function"<<"in line :"<< line_num<< endl;
        exit(1);
    }
    Parameter_List* tpl = ad->dad->pl;
    return get_const_params(tpl);

}

vector<pair<string, pair<string,Type*>>> create_name_type_list(Declaration_Specifiers* ds, Init_Declarator_List* idl) {
    vector<pair<string, pair<string,Type*>>> result;
    
    if (!idl) {
        Type* t=new Type();
        string type = create_type(ds, nullptr, t);
        if(type == "class" || type == "struct" || type == "union" || type == "enum") {
            if(ds->ts[0]->string_type == "class") {
                string name = ds->ts[0]->class_type->class_name;
                result.push_back(make_pair(name, make_pair("class", t)));
            }
            else if(ds->ts[0]->string_type == "struct") {
                string name = ds->ts[0]->struct_union_type->name;
                result.push_back(make_pair(name, make_pair("struct", t)));
            }
            else if(ds->ts[0]->string_type == "union") {
                string name = ds->ts[0]->struct_union_type->name;
                result.push_back(make_pair(name, make_pair("union", t)));
            }
            else if(ds->ts[0]->string_type == "enum") {
                string name = ds->ts[0]->enum_type->id;
                result.push_back(make_pair(name, make_pair("enum", t)));
            }
        }
        else {
            return result;
        }
        cout<<"not of create_name_type_list"<<endl;
    }
    // Properly placed loop outside initial if-block
    if (idl) {  // Add null check for safety
        for (Declarator* d : idl->idl) {
            cout<<"true of create_name_type_list"<<endl;
            Type* t=new Type();
            string type = create_type(ds, d, t);
            cout << t->base << endl;
            cout << "create type in create name type list done" << endl;
            if(type == "class" || type == "struct" || type == "union" || type == "enum") {
                cout << "error: can't define objects like this for " << d->id << " in line :" << line_num << endl;
                exit(1);
            }
            
            string name = d->id;
            result.push_back(make_pair(name, make_pair(type, t)));
        }
    }
    
    return result;
}



Direct_Declarator* create_direct_declarator(const string& type,const string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl){
    Direct_Declarator* z=new Direct_Declarator(type,id,d,dd,ce,pl);
    cout << "created dir decl obj" << endl;
    cout << type << endl;
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
    cout << "created declarator object" <<endl;
    assert(dd!=nullptr);
    z->id=z->dd->id;
    cout << "********" << endl;
    string t=z->check_declarator();
    cout << "declarator type: " << t << endl;
    if(t=="function"){
        cout << "function declarator" << endl; 
        z->isfunction=true;
        z->prms=get_params(dd->pl);
        cout << "get params done successfully" << endl;
        for(auto i:z->prms){
            current_params_list[i.first]=i.second;
            current_param_vector.push_back(i);
            cout << "added prms to map" << endl;
        }
    }
    z->type=t;
    return z;
}


Direct_Declarator::Direct_Declarator(const string& type,const string& id, Declarator* d, Direct_Declarator* dd, Constant_Expression* ce, Parameter_List* pl)
    : type(type), id(id), d(d), dd(dd), ce(ce), pl(pl) {
}

Parameter_Declaration::Parameter_Declaration(Declaration_Specifiers* ds, Declarator* d)
    : ds(ds), dec(d) {  
}
void check_if_declared(Local_Symbol_Table* current_table,const string& var_name,const string& var_type){
    Local_Symbol_Table* x=current_table;
    bool check=false;
    while(x!=nullptr){
        auto y=(x->lst).find(var_name);
        if(y!=x->lst.end()){
            if((y->second)->type==var_type){
                check=true;
                break;
            }
        }
        else{
            x=x->parent;
        }
    }
    if(gst->gst.find(var_name)!=gst->gst.end()){
        auto y=gst->gst.find(var_name);
        if((y->second)->type==var_type){
            check=true;
        }
    }
    if(!check){
        cout << "error: " << var_type << " " << var_name << " not declared!" <<"in line :"<< line_num<< endl;
        exit(1);
    }
}
void add_to_gst(Declaration* symbol,Global_Symbol_Table* gst){
    for(auto i:symbol->name_type_list){
        Symbol_Info* x=new Symbol_Info(i.first,i.second.first,symbol->level_name,symbol->level,symbol->scope,"-",i.second.second);
        if(gst->gst.find(i.first)!=gst->gst.end()){
            cout << "error :" << "redeclaration of " << i.first <<"in line :"<< line_num<< endl;
            exit(1);
        }
        gst->gst[i.first]=x;
    }

}
void add_to_gst(Function_Definition* symbol,Global_Symbol_Table* gst){
    assert(symbol!=nullptr);
    assert(gst!=nullptr);
    Symbol_Info* x=new Symbol_Info(symbol->name,symbol->type,symbol->level_name,symbol->level,symbol->scope,"-",symbol->t);
    x->tempname=symbol->decl->tempname;
    final_symtab[x->tempname]=x;
    if(gst->gst.find(symbol->name)!=gst->gst.end()){
        cout << "error :" << "redeclaration of function " << symbol->name <<"in line :"<< line_num<< endl;
        exit(1);
    }
    gst->gst[symbol->name]=x;
}
Local_Symbol_Table* next_table(){
    bool checkgst=false;
    if(current_table==nullptr)checkgst=true;
    Local_Symbol_Table* new_table=new Local_Symbol_Table(checkgst);
    if(current_table!=nullptr)current_table->children.push_back(new_table);
    else {
        gst->children.push_back(new_table);
    }
    return new_table;
}
void add_to_local_table(Local_Symbol_Table* current_table,Struct_Declaration* sd){
    for(auto i:sd->name_type_list){
        Symbol_Info* x=new Symbol_Info(i.first,i.second.first,sd->level_name,sd->level,sd->scope,"-",i.second.second);

        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first <<"in line :"<< line_num<< endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
    }
}
void add_to_local_table(Enumerator_List* e,Type* t){
    string level_name=get_level_name();
    int level=current_level-lvl_name.size()+1;
    string scope;
    if(current_level==0)scope="global";
    else scope="local";
    cout<<"inside add_to_local_table el,t"<<endl;
    for(auto x:e->e){
        if(current_table!=nullptr){
            Symbol_Info* info=new Symbol_Info(x->id,"enum "+t->obj_class,level_name,level,scope,"-",t);
            if(current_table->lst.find(x->id)!=current_table->lst.end()){
                cout << "error :" << "redeclaration of " << x->id <<"in line :"<< line_num<< endl;
                exit(1);
            }
            current_table->lst[x->id]=info;
        }
        else{
            cout<<"enum " + t->obj_class<<endl;
            assert(x!=nullptr);
            cout << "x not null" << endl;
            cout << "x->id = " << x->id << endl;
            if (t != nullptr) {
                cout << "t->obj_class = " << t->obj_class << endl;
            } else {
                cout << "t is null!" << endl;
            }
            cout << "level_name = " << level_name << endl;
            cout << "level = " << level << endl;
            cout << "scope = " << scope << endl;

            Symbol_Info* info=new Symbol_Info(x->id, "enum " + t->obj_class,level_name,level,scope,"-",t);
            cout<<"obj successfully created of symbol info"<<endl;
            if(gst->gst.find(x->id)!=gst->gst.end()){
                cout << "error :" << "redeclaration of " << x->id <<"in line :"<< line_num<< endl;
                exit(1);
            }
            gst->gst[x->id]=info;
        }
        
    }
}
void add_to_local_table(Local_Symbol_Table* current_table,Declaration* d){
    for(auto i:d->name_type_list){
        if(d->init_dec_list!=nullptr){
            for(auto j:d->init_dec_list->idl){
                if(j->ini){
                    cout<<"check compatilblity started"<<endl;
                    check_compatibility(j->ini,i.second.second);
                    cout<<"check compatiblity done"<<endl;
                }
            }
        }
        cout << i.second.second->base << endl;
        cout << "got type from declaration" << endl;
        Symbol_Info* x=new Symbol_Info(i.first,i.second.first,d->level_name,current_level-lvl_name.size()+1,d->scope,"-",i.second.second);
        cout << x->t->base << endl;
        cout << "type correctly added to symbol info" << endl;
        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first <<"in line :"<< line_num<< endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
        cout << "current level : " << current_level << endl;
        cout << "symbol added : " << i.first << endl;
        cout << current_table->lst[i.first]->t->base << endl;
        cout << "type correctly added to current table" << endl;
        /*check if initializer is matching with type*/
    }
}
void add_to_local_table(Local_Symbol_Table* current_table,Specifier_Qualifier_List* ds,Declarator* d){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    Type* t=new Type();
    string type=create_type(ds,d,t);
    string name=get_name(d);
    string level_name=get_level_name();
    int level=current_level-lvl_name.size()+1;
    Symbol_Info* x=new Symbol_Info(name,type,level_name,level,"local",access,t);
    current_table->lst[name]=x;

}
Compound_Statement::Compound_Statement(Type* st, Declaration_List* dl)
    : st(st), dl(dl){ 
        cout << "compound statement constructor called" << endl;
}

Declaration_List :: Declaration_List(){
    this->dv={};
}

Function_Declaration::Function_Declaration(Declaration_Specifiers* ds, Declarator* d)
    : ds(ds), d(d) {
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
    vector<Type*> prms=cd->pvec;
    Type* t=new Type();
    t->prms=prms;
    t->obj_class=name;
    Symbol_Info* x=new Symbol_Info(name,type,level_name,level,"local",access,t);
    current_table->lst[name]=x;/*redefinition of same type of constructor not handled. also multiple constructors case not handled. can handle by adding params to name*/
}
void add_to_local_table(Local_Symbol_Table* current_table,Function_Definition* fd){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    Symbol_Info* x=new Symbol_Info(fd->name,fd->type,fd->level_name,fd->level,fd->scope,access,fd->t);
    if(current_table->lst.find(fd->name)!=current_table->lst.end()){
        cout << "error :" << "redeclaration of function " << fd->name <<"in line :"<< line_num<< endl;
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
Function_Definition:: Function_Definition(Declaration_Specifiers* ds,Declarator* dc,Compound_Statement* cs){
    this->dec_spec=ds;
    this->decl=dc;
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
    this->level_name = ""; 
    this->level = 0;     
    this->scope = ""; // assigning default scope
    this->dec_spec=ds;
    this->init_dec_list=idl;
    this->typedef_spec=ts;
}

Global_Symbol_Table::Global_Symbol_Table() {
    this->children = {};
}

Local_Symbol_Table::Local_Symbol_Table(bool ispargst) {
    this->children = {};
    this->ispargst = ispargst ;
    this->parent = current_table;
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

Function_Definition* create_func_def(Declaration_Specifiers* ds,Declarator* dc,Compound_Statement* cs){
    Function_Definition* fd=new Function_Definition(ds,dc,cs);
    Type* t=new Type();
    fd->type=create_type(ds,dc,t);
    fd->t=t;
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
    cout << "create name type list working fine" << endl;
    d->level_name=get_level_name();
    cout << "get level name done successfully" << endl;
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

Type_Specifier::Type_Specifier(string str, Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type) 
    {
    this->string_type=str;
    this->struct_union_type=struct_union_type;
    this->class_type=class_type;
    this->enum_type=enum_type;
    if(str==""){
        cout << "str is null" << endl;
        if(struct_union_type) {
            string sou = struct_union_type->str_or_union;
            string name = struct_union_type->name;
            Struct_Declaration_List* sdl = struct_union_type->strdec_list;
            if (!sou.empty()) {
                if (sdl) { 
                    if (name.empty()) {
                        this->string_type = sou + " anonymous";
                    } 
                    else {
                        this->string_type = sou;
                    }
                } 
                else {
                    if (!name.empty()) {
                        this->string_type = sou + " " + name;
                    }
                }
            }
        }
        else if (class_type) { 
            if (class_type->cb == nullptr) {
                this->string_type = "class " + class_type->class_name;
            }
            else {
                if (class_type->class_name.empty()) {
                    this->string_type = "class anonymous";
                } 
                else {
                    this->string_type = "class";
                }
            }
        }
        else if (enum_type) {
            if (enum_type->enuml == nullptr) {
                this->string_type = "enum " + enum_type->id;
            } else {
                if (enum_type->id.empty()) {
                    this->string_type = "enum anonymous"; 
                } else {
                    this->string_type = "enum";  
                }
            }
        }
        else{
            cout<<"Not struct_or_union,enum or class"<<"in line :"<< line_num<<endl;
            exit(1);
        }
        cout << this->string_type << endl;
        cout << "hello this is type specifier constructor" << endl;
    }
    
}


Enum_Specifier::Enum_Specifier(const std::string& id, Enumerator_List* enuml)
    : id(id), enuml(enuml) { 
}

Declarator::Declarator(Pointer* p, Direct_Declarator* dd)
    : p(p), dd(dd), type(""), id(""), prms(), isfunction(false) {
    this->type = this->check_declarator();  // Store the result of check_declarator()
    this->tempname="";
}

Enumerator_List::Enumerator_List()  {
    this->e=vector<Enumerator*>();
}

Initializer::Initializer(Type* type, string name, Initializer_List* ini_lst,string class_id, Argument_Expression_List* arg_exp_lst)
    : type(type),          
      name(name),         
      ini_lst(ini_lst),   
      class_id(class_id),  
      arg_exp_lst(arg_exp_lst) {  
}

Initializer_List::Initializer_List() {
}

Struct_Declaration::Struct_Declaration(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl) {
    this->sql = sql;
    this->sdl = sdl;
    int calculated_level = current_level -(lvl_name.size()) + 1;
    cout << "calculated levl in struct decl contr" << endl;
    this->level = calculated_level;
    this->name_type_list = create_struct_name_type_list(sql, sdl); // Now safe
    cout << "create_struct_name_type_list_done" << endl;
    this->scope = "local";
    this->level_name = get_level_name();       
}

Struct_Declarator_List::Struct_Declarator_List() {
   this->sd={};
}

Enumerator::Enumerator(string id, Type* ce){ 
    this->id=id;
    this->ce=ce;
}

Struct_Declarator::Struct_Declarator(Declarator* d){
    this->d=d;
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

Parameter_List::Parameter_List() : pl() {
}

Base_Class::Base_Class(const std::string& asp, const std::string& id)
    : asp(asp), id(id) {  
}

Specifier_Qualifier_List::Specifier_Qualifier_List() 
    : ts(), tq() {
    std::cout << "Constructor called. ts size: " << ts.size() 
              << ", address: " << this << std::endl;
}

Struct_Declaration*  create_struct_dec_obj(Specifier_Qualifier_List* sql,Struct_Declarator_List* sdl){
    cout<<"in 1st line of create_struct_dec_obj"<<endl;
    Struct_Declaration* sd=new Struct_Declaration(sql,sdl);
    cout << "constr done" << endl;
    sd->level_name=get_level_name();
    if(current_level==0)sd->scope="global";
    else sd->scope="local";
    return sd;
}
Declaration_Specifiers* create_decl_spec_object(){
    Declaration_Specifiers* ds=new Declaration_Specifiers();
    cout <<"successfully created dec spec obj" << endl;
    return ds;
}

Class_Member_Declaration::Class_Member_Declaration(Member_Declaration* md, Constructor_Declaration* cd)
    : md(md), cd(cd) { 
}

Member_Declaration::Member_Declaration(Specifier_Qualifier_List* ds,  Declarator* dec,Function_Definition* fd)
    : ds(ds) ,dec(dec), fd(fd) {  // Member initializer list for direct initialization
}

Class_Specifier::Class_Specifier(const std::string &class_name, Inheritance_Specifier* is, Class_Member_Declaration_List* cb)
    : class_name(class_name), 
      is(is),
      cb(cb) {
}

Type_Specifier* create_ts_obj(const std::string& str,Struct_or_Union_Specifier* struct_union_type,Class_Specifier* class_type,Enum_Specifier* enum_type){
    Type_Specifier* ts=new Type_Specifier(str,struct_union_type, class_type, enum_type);
    cout << "successfully created ts obj" << endl;
    return ts;
}
Struct_or_Union_Specifier* create_struct_union_spec_obj(const string& sou,const string& name,Struct_Declaration_List* sdl){
    Struct_or_Union_Specifier* sus =new Struct_or_Union_Specifier(sou,name,sdl);
    return sus;
}
Struct_Declarator* create_struct_declarator_obj(Declarator* d){
    Struct_Declarator* sd=new Struct_Declarator(d);
    return sd;
}

