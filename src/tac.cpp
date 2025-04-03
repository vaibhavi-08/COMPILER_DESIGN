#include<tac.h>
using namespace std;
unordered_map<string,Symbol_Info*> final_symtab;
int tempcount=0;
vector<string> global_code;
string get_code4(string op1,string op2,string oprnd,string result){
    string s;
    s=result;
    s+="=";
    s+=op1;
    s+=oprnd;
    s+=op2;
    return s;
}
string get_new_temp(){
    tempcount++;
    return "t"+to_string(tempcount);
}
