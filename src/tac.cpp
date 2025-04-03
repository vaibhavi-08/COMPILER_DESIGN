#include<tac.h>
using namespace std;
unordered_map<string,Symbol_Info*> final_symtab;
int tempcount=0;
vector<string> global_code;
string get_code4(string op1,string op2,string oprnd,string result){
    string s=result;
    s+="=";
    s+=op1;
    s+=oprnd;
    s+=op2;
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
