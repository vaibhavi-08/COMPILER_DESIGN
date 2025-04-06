#include<tac.h>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,Symbol_Info*> final_symtab;
int tempcount=0;
vector<string> global_code;
vector<int> break_label;
vector<int> continue_label;
vector<int> goto_label;
vector<int> switch_true;
vector<int> switch_false;
vector<int> switch_label;
vector<string> labelgoto;
map<string,int> labelmap;

bool identifier_found(vector<string>list, string id){
    for(auto i:list){
        if(i==id){
            return true;
        }
    }
    return false;
   
}
string get_code4(string op1,string op2,string oprnd,string result){
    string s;
    s=result;
    s+="=";
    s+=op1;
    s+=oprnd;
    s+=op2;
    return s;
}
string get_if_true_code(string condition){
    string s="";
    s+="if ";
    s+=condition;
    s+=" goto ";
    return s;

}
void fill_expr(int n, string op){
    global_code[n]+=op;
}
void fill_eqeq_exp1(int index, string s){
         size_t pos = global_code[index].find("if");
        if (pos != string::npos) {
            global_code[index].insert(pos + 2, " ");
            global_code[index].insert(pos + 3, s);
            
        }


}
void fill_eqeq_exp2(vector<int>list, string s){
    for(int index: list){
        size_t pos = global_code[index].find("==");
        if (pos != string::npos) {
            global_code[index].insert(pos + 2, " ");
            global_code[index].insert(pos + 3, s);

        }

    }

}

string get_code_array(string a1,string a2,string res){
    string s="";
    s+=res;
    s+="=";
    s+=a1;
    s+='[';
    s+=a2;
    s+=']';
    return s;
}

string get_code_func(string res,string a1){
    string s="";
    s+=res;
    s+="=";
    s+="call ";
    s+=a1;
    return s;
}
string get_param_code(string p){
    string s="";
    s+="param ";
    s+=p;
    return s;
}
string get_if_false_code(){
    string s="";
    s+="goto ";
    return s;
}
string get_while_code(int temp){
    string s="";
    s+="goto ";
    s+=to_string(temp);
    return s;
}
void merge_code(vector<string>& res,vector<string>& e1,vector<string>& e2){
    for(auto i:e1){
        res.push_back(i);
    }
    for(auto i:e2){
        res.push_back(i);
    }
}
void merge_code1(vector<string>& res,vector<string>& e1){
    for(auto i:e1){
        res.push_back(i);
    }
}
string get_new_temp(){
    tempcount++;
    return "t"+to_string(tempcount);
}

void backpatch(vector<int>& list,int label){
    cout << "backpatching started" << endl;
    cout << "label:" << label << endl;
    for(int i=0; i<list.size();i++){
        //cout << "line no:" << i << endl;
        cout << list[i] << endl;
        cout << global_code[list[i]] << endl;
        int n=global_code[list[i]].size();
        if(global_code[list[i]][n-1]==' '){
            global_code[list[i]]+=to_string(label);
        }
        cout << global_code[list[i]] << endl;

    }
}
void backpatch1(int i,int label){

  global_code[i]+=to_string(label);
}
string gen_return(string temp){
    string s="return ";
    s+=temp;
    return s;
}
string get_label(string temp){
    string s=temp;
    s+=" : ";
    return s;
}
string get_label_param(string nn){
    string s="arg ";
    s+=nn;
    return s;
}
vector<int> merge(vector<int>& l1,vector<int>& l2){
    set<int> res;
    for(auto i:l1){
        res.insert(i);
    }
    for(auto i:l2){
        res.insert(i);
    }
    vector<int> res1;
    for(auto i:res){
        res1.push_back(i);
    }
    return res1;
}
FCRB::FCRB(){
    this->pos=0;
    this->nextlist=vector<int>();
}