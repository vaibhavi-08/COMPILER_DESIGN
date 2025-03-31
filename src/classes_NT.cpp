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
set<string> labelset;
stack<pair<string,Local_Symbol_Table*>> current_class_struct_union_info;
void add_to_local_class_struct_union_info(){
    if(!current_class_struct_union_info.empty()){
        auto z=current_class_struct_union_info.top();
        if(current_table=nullptr){
            gst->class_struct_union_info[z.first]=z.second;
        }
        else{
            current_table->class_struct_union_info[z.first]=z.second;
        }
        current_class_struct_union_info.pop();
    }
    else{
        cout << "error class not entered in stack" << endl;
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
string create_type(Declaration_Specifiers* ds,Declarator* d,bool& check_f,vector<string>& fp){
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
        if((z[0]->string_type=="UNSIGNED") && (z[1]->string_type=="LONG") && (z[2]->string_type=="LONG")){
            return type + "UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="CHAR"){
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="SHORT"){
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="INT"){
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type=="UNSIGNED"&& z[1]->string_type=="LONG"){
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type=="SIGNED"&& z[1]->string_type=="CHAR"){
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="SHORT"){
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="INT"){
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="LONG"){
            type+=" SIGNED LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        if(z[0]->string_type=="class"||"struct"||"enum"||"union"){
            if(ds->scs.empty()&&ds->tq.empty()&&d==nullptr){
                return z->string_type;
            }
            else{
                cout << "error incorrect declaration ^struct^union^enum^class" << endl;
            }
        }
        else{
            type+=z->string_type;
        }
    }
    else if(z.size()>3) {
        cout << "incorrect type specs in type of " << d->id << endl;
        exit(1);
    }
    if(d!=nullptr){
        Pointer* y=d->p;
        while(y!=nullptr){
            type+='*';
            y=y->p;
        }
        string dtype=d->check_declarator();
        if(dtype=="array"){
            Direct_Declarator* a=d->dd;
            while(a->type=="array"){
                type+='$';
                a=a->dd;
            }
        }
        else (dtype=="function"){
            isfunction=true;
            prms=get_func_prms(d);
        }
        else if(dtype=="function pointer"){
            prms=get_func_prms(d);
            Declarator* a=d->dd->d;
            while(a->p!=nullptr){
                type+='#';
                a=a->p;
            }
        }
    }
    check_f=isfunction;
    fp=prms;
    return type;
     
}
Type_Name::Type_Name(Specifier_Qualifier_List* sql, Abstract_Declarator* ad)
    : sql(sql), ad(ad) {
}
Abstract_Declarator :: Abstract_Declarator(Pointer* p,Direct_Abstract_Declarator* dad) 
{   
    this->p=p;
    this->dad=dad;
    this->type="";
}
Direct_Abstract_Declarator::Direct_Abstract_Declarator(string type, Abstract_Declarator* ad, Direct_Abstract_Declarator* dad, Constant_Expression* con_exp,Parameter_List* pl)
: type(type), ad(ad), dad(dad), con_exp(con_exp),pl(pl)  {

}

string create_type(Specifier_Qualifier_List* ds,Declarator* d,bool& check_f,vector<string>& fp){
    string type="";
    bool isfunction=false;
    vector<string> prms;
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
    vector<Type_Specifier*> z=ds->ts;
    reverse(z.begin(),z.end());
    if(z.size()==3){
        if((z[0]->string_type=="UNSIGNED") && (z[1]->string_type=="LONG") && (z[2]->string_type=="LONG")){
            return type + "UNSIGNED LONG LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==2){
        if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="CHAR"){
            type += " UNSIGNED CHAR";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="SHORT"){
            type +=" UNSIGNED SHORT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="INT"){
            type+=" UNSIGNED INT";
        }
        else if(z[0]->string_type=="UNSIGNED"&&z[1]->string_type=="LONG"){
            type+=" UNSIGNED LONG";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="CHAR"){
            type+=" SIGNED CHAR";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="SHORT"){
            type+=" SIGNED SHORT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="INT"){
            type+=" SIGNED INT";
        }
        else if(z[0]->string_type=="SIGNED"&&z[1]->string_type=="LONG"){
            type+=" SIGNED LONG";
        }
        else{
            cout << "incorrect type specs in type of " << d->id << endl;
            exit(1);
        }
    }
    else if(z.size()==1){
        if(z->string_type=="class"||"struct"||"enum"||"union"){
            if(ds->scs.empty()&&ds->tq.empty()&&d==nullptr){
                return z->string_type;
            }
            else{
                cout << "error incorrect declaration ^struct^union^enum^class" << endl;
            }
        }
        else{
            type+=z->string_type;
        }
    }
    else if(z.size()>3) {
        cout << "incorrect type specs in type of " << d->id << endl;
        exit(1);
    }
    if(d!=nullptr){
        Pointer* y=d->p;
        while(y!=nullptr){
            type+='*';
            y=y->p;
        }
        string dtype=d->check_declarator();
        if(dtype=="array"){
            Direct_Declarator* a=d->dd;
            while(a->type=="array"){
                type+='$';
                a=a->dd;
            }
        }
        else (dtype=="function"){
            isfunction=true;
            prms=get_func_prms(d);
        }
        else if(dtype=="function pointer"){
            prms=get_func_prms(d);
            Declarator* a=d->dd->d;
            while(a->p!=nullptr){
                type+='#';
                a=a->p;
            }
        }
    }
    check_f=isfunction;
    fp=prms;
    return type;
}
string get_type_exp(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]=='-'){
            return "FLOAT";
        }
    }
    return "INT";


}

void create_struct_name_type_list(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl,vector<pair<string,string>>& yy,bool& check_f,vector<string>& fp){
    vector<pair<string,string>> ans;
    if(sdl==nullptr){
        string type=check_type(sql,nullptr);
        if(type=="class"||type=="struct"||type=="union"||type=="enum"){
            if(sql->ts[0]->string_type=="class"){
                
                    string name=sql->ts[0]->class_type->class_name;
                    result.push_back(make_pair(name,"class"));
                
            }
            else if(sql->ts[0]->string_type=="struct"){
                
                    string name=sql->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,"struct"));
            
                
            }
            else if(sql->ts[0]->string_type=="union"){
               
                    string name=sql->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,"union"));
                
            }
            else if(sql->ts[0]->string_type=="enum"){
                
                    string name=sql->ts[0]->enum_type->id;
                    result.push_back(make_pair(name,"enum"));
            }
            else {
                cout << "error &&&" << endl;
            }
            else yy=ans;
    }
    }
    for(auto i:sdl->sd){
        string type=create_type(sql,i->d,check_f,fp);
        string name=get_name(i->d);
        ans.push_back(make_pair(name,type));
    }
    yy=ans;
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
Expression::Expression(const std::string& type,const std::string& name)
    : type(type) , name(name) {  

}
void check_argument_with_params(Argument_Expression_List* arg_el,vector<string>pl){

}

Argument_Expression_List :: Argument_Expression_List(){
    this->vec_exp={};
}

vector<string> check_if_function(string name){
    Local_Symbol_Table* temp = current_table;
    while (temp != nullptr) {
        auto it = temp->lst.find(name);
        if (it != temp->lst.end()) {
            if(!it->second->isfunction){
                cout << "error: " << it->first << " should be a function" << endl;
                exit(1);
            }
            else{
                return it->second->function_parameters;
            }
        }
        temp = temp->get_parent(); 
    }
    if(gst && gst->gst.count(id)) {
        if(!gst->gst[id]->isfunction){
            cout << "error: " << it->first << " should be a function" << endl;
            exit(1);
        }
        else{
            return gst->gst[id]->function_parameters;
        }
    }
    cerr << "Error: Identifier '" << id << "' not found in any symbol table" << endl;
    exit(1);
}

pair<string,string> get_type_id(string id) {
    Local_Symbol_Table* temp = current_table;
    while (temp != nullptr) {
        auto it = temp->lst.find(id);
        if (it != temp->lst.end()) {
            return {it->second->type,it->second->name};
        }
        temp = temp->get_parent(); 
    }
    if(gst && gst->gst.count(id)) {
        return {gst->gst[id]->type,gst->gst[id]->name};
    }
    cerr << "Error: Identifier '" << id << "' not found in any symbol table" << endl;
    exit(1);
}
string check_if_array_or_pointer(Expression* e){
    string x=e->type;
    int len=x.length();
    char ch=x[len-1];
    if(ch=='$'){
        x.pop_back();
    }
    else if(ch=='*'){
        x.pop_back();
    }
    else{
        cout<<"Declaration "<<e->name<<" is incorrect! It should be pointer or array."<<endl;
    }
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

bool is_base_class(const string& base, const string& derived) {
    // Check if both base and derived are valid class types in the global symbol table
    if (gst->class_struct_union_info.find(derived) == gst->class_struct_union_info.end()) {
        cerr << "Error: Derived class '" << derived << "' not found in symbol table." << endl;
        return false;
    }

    if (gst->class_struct_union_info.find(base) == gst->class_struct_union_info.end()) {
        cerr << "Error: Base class '" << base << "' not found in symbol table." << endl;
        return false;
    }

    // Get the Local_Symbol_Table for the derived class
    Local_Symbol_Table* derived_table = gst->class_struct_union_info[derived];
    if (!derived_table) {
        cerr << "Error: Derived class '" << derived << "' has no associated symbol table." << endl;
        return false;
    }

    // Check if the derived class has an inheritance specifier
    if (derived_table->inheritance_specifier == nullptr) {
        return false; // No inheritance, so base is not a parent of derived
    }

    // Traverse the inheritance hierarchy
    Inheritance_Specifier* inheritance = derived_table->inheritance_specifier;
    for (Base_Class* base_class : inheritance->bcl->bc) {
        if (base_class->id == base) {
            return true; // Found the base class in the inheritance hierarchy
        }

        // Recursively check the base class's inheritance hierarchy
        if (is_base_class(base, base_class->id)) {
            return true;
        }
    }

    return false; // Base class not found in the inheritance hierarchy
}

// Helper function to normalize type strings
string normalize_type(const string& type) {
    static unordered_map<string, string> type_equivalents = {
        {"long", "long int"},
        {"unsigned", "unsigned int"},
        {"signed", "int"},
        {"short", "short int"},
        {"long long", "long long int"}
    };

    // Check if the type exists in the map and return its normalized form
    if (type_equivalents.find(type) != type_equivalents.end()) {
        return type_equivalents[type];
    }

    // If no normalization is needed, return the original type
    return type;
}

// Function to check if arguments match the expected parameters
void check_argument_with_params(vector<string> params, vector<string> args) {
    // Step 1: Check if the number of parameters matches the number of arguments
    if (params.size() != args.size()) {
        cerr << "Error: Number of arguments (" << args.size() 
             << ") does not match the number of parameters (" << params.size() << ")." << endl;
        exit(1);
    }

    // Step 2: Iterate over parameters and arguments
    for (size_t i = 0; i < params.size(); ++i) {
        string param_type = normalize_type(params[i]); // Normalize parameter type
        string arg_type = normalize_type(args[i]);     // Normalize argument type

        // Step 3: Handle primitive types (direct match after normalization)
        if (param_type == arg_type) {
            continue;
        } 
        // Step 4: Handle function pointers
        else if (is_function_pointer(param_type)) {
            // Check if the argument is a valid function pointer
            if (!is_function_pointer(arg_type)) {
                cerr << "Error: Argument " << i + 1 << " is not a valid function pointer. Expected: " 
                     << param_type << ", Got: " << arg_type << endl;
                exit(1);
            }
        } 
        // Step 5: Handle class or struct types
        else if (is_class_or_struct(param_type)) {
            // Check if the argument matches the expected class or struct type
            if (param_type != arg_type) {
                // Check for inheritance (polymorphism)
                if (!is_base_class(param_type, arg_type)) {
                    cerr << "Error: Argument " << i + 1 << " does not match the expected class/struct type. Expected: " 
                         << param_type << ", Got: " << arg_type << endl;
                    exit(1);
                }
            }
        } 
        // Step 6: Handle references and pointers
        else if (param_type.back() == '&' || param_type.back() == '*') {
            // Check if the argument matches the reference or pointer type
            if (arg_type.back() != param_type.back()) {
                cerr << "Error: Argument " << i + 1 << " does not match the expected reference/pointer type. Expected: " 
                     << param_type << ", Got: " << arg_type << endl;
                exit(1);
            }
        } 
        // Step 7: Handle const and volatile qualifiers
        else if (param_type.find("const") != string::npos || param_type.find("volatile") != string::npos) {
            // Check if the argument respects const/volatile qualifiers
            if (arg_type != param_type && arg_type.find("const") == string::npos) {
                cerr << "Error: Argument " << i + 1 << " does not respect const/volatile qualifiers. Expected: " 
                     << param_type << ", Got: " << arg_type << endl;
                exit(1);
            }
        } 
        // Step 8: Handle templates
        else if (param_type.find('<') != string::npos && param_type.find('>') != string::npos) {
            // Check if the argument matches the template type
            if (param_type != arg_type) {
                cerr << "Error: Argument " << i + 1 << " does not match the expected template type. Expected: " 
                     << param_type << ", Got: " << arg_type << endl;
                exit(1);
            }
        } 
        // Step 9: Handle variadic functions
        else if (param_type == "...") {
            // Variadic functions accept any type for the remaining arguments
            break;
        } 
        // Step 10: Handle unknown or mismatched types
        else {
            cerr << "Error: Argument " << i + 1 << " type mismatch. Expected: " 
                 << param_type << ", Got: " << arg_type << endl;
            exit(1);
        }
    }

    //enum ka bhi check alag se karna padega?

    // Step 11: If all checks pass
    cout << "All arguments match their respective parameters." << endl;
}





void check_int_comp(string type){
    bool flag=false;
    for(int i=0; i<type.length(); i++){
        if(type[i]=='INT' || type[i]=='CHAR' || type[i]=='SHORT' || type[i]=='LONG'){
          flag=true;
        }
        if(type[i]=='$' || type[i]=='#'){
        cout << "error: " << type << " is not valid type for comparison" << endl;
        exit(1);
        }
    }
    if(!flag){
        cout << "error: " << type << " is not valid type for comparison" << endl;
        exit(1);
    }

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
Pointer::Pointer(Type_Qualifier_List* tql, Pointer* p) 
    : tql(tql), p(p) {
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
    if (!idl) {
         if (!idl){
        string type=check_type(ds,nullptr);
        if(type=="class"||type=="struct"||type=="union"||type=="enum"){
            if(ds->ts[0]->string_type=="class"){
                
                    string name=ds->ts[0]->class_type->class_name;
                    result.push_back(make_pair(name,"class"));
                
            }
            else if(ds->ts[0]->string_type=="struct"){
                
                    string name=ds->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,"struct"));
            
                
            }
            else if(ds->ts[0]->string_type=="union"){
               
                    string name=ds->ts[0]->struct_union_type->name;
                    result.push_back(make_pair(name,"union"));
                
            }
            else if(ds->ts[0]->string_type=="enum"){
                
                    string name=ds->ts[0]->enum_type->id;
                    result.push_back(make_pair(name,"enum"));
            }
            else {
                cout << "error &&&" << endl;
            }
            else return result;

        }
    }

    }
    for (Declarator* d : idl->idl) {
        string type = create_type(ds, d);
        if(type=="class"||type=="struct"||type=="union"||type=="enum"){
            cout << "error: can't define objects like this for " << d->id << endl;
            exit(1);
        }
        string name = d->id;
        result.emplace_back(name, type);
    }
    return result;
}


Direct_Declarator* create_direct_declarator(const string& type,const string& id,Declarator* d,Direct_Declarator* dd,Constant_Expression* ce,Parameter_List* pl){
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

Direct_Declarator::Direct_Declarator(string& type, string& id, Declarator* d, Direct_Declarator* dd, Constant_Expression* ce, Parameter_List* pl)
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
    for(auto i:d->name_type_list){
        Enumerator_List* z=nullptr;
        bool isenum=false;
        if(i.second=="enum"){
            isenum=true;
            z=d->dec_spec->ts.front()->enum_type->enuml;
        }
        Symbol_Info info={i.first,i.second,d->level_name,d->level,d->scope,"-",false,{},isenum,z};
        Symbol_Info* x=&info;
        if(current_table->lst.find(i.first)!=current_table->lst.end()){
            cout << "error :" << "redeclaration of " << i.first << endl;
            exit(1);
        }
        current_table->lst[i.first]=x;
        /*check if initializer is matching with type*/
    }
}
void add_to_local_table(Local_Symbol_Table* current_table,Specifier_Qualifier_List* ds,Declarator* d){
    string access="PRIVATE";
    if(!access_spec_stk.empty()){
        access=access_spec_stk.top();
    }
    string type=check_type(ds,d);
    string name=get_name(d);
    Enumerator_List* z=nullptr;
    bool isenum=false;
    if(type=="enum"){
        isenum=true;
        z=ds->ts.front()->enum_type->enuml;
    }
    string level_name=get_level_name();
    int level=current_level-lvl_name.size()+1;
    Symbol_Info info={name,type,level_name,level,"local",access,false,{},isenum,z};
    Symbol_Info* x=&info;
    current_table->lst[name]=x;

}
Compound_Statement::Compound_Statement(Node* st, Declaration_List* dl)
    : st(st), dl(dl),have_ret(0) { 
}

Declaration_List :: Declaration_List(){
    this->dv={};
}
Struct_Declarator_List::Struct_Declarator_List() : sd() {
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
}

Local_Symbol_Table::Local_Symbol_Table(bool ispargst,Local_Symbol_Table* parent) {
    this->children = {};
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

Declarator::Declarator(Pointer* p, Direct_Declarator* dd)
    : p(p), dd(dd), type(""), id(""), prms(), isfunction(false) {
        this->check_declarator();
}

Enumerator_List::Enumerator_List() : e() {
}

Initializer::Initializer(string type, string name, Initializer_List* ini_lst, string class_id, Argument_Expression_List* arg_exp_lst)
    : type(type),          
      name(name),         
      ini_lst(ini_lst),   
      class_id(class_id),  
      arg_exp_lst(arg_exp_lst) {  
}

Struct_Declaration::Struct_Declaration(Specifier_Qualifier_List* sql, Struct_Declarator_List* sdl) {
    this->sql = sql;                   
    this->sdl = sdl;                  
    this->name_type_list = create_struct_name_type_list(sql,sdl,this->isfunction,this->prms);         
    this->scope = "local";                  
    this->level = current_level-lvl_name.size()+1;                  
    this->level_name = get_level_name();         
}

Struct_Declarator_List::Struct_Declarator_List() {
   this->sd={};
}

Enumerator::Enumerator(const std::string& id, Constant_Expression* ce)
    : id(id), ce(ce) { 
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

Class_Member_Declaration::Class_Member_Declaration(Member_Declaration* md, Constructor_Declaration* cd)
    : md(md), cd(cd) { 
}

Member_Declaration::Member_Declaration(Declaration* d, Function_Definition* fd)
    : d(d), fd(fd) {  // Member initializer list for direct initialization
}

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
Struct_Declarator* create_struct_declarator_obj(Declarator* d){
    Struct_Declarator* sd=new Struct_Declarator(d);
    return sd;
}

