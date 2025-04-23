#ifndef TAC_H
#define TAC_H
#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
extern unordered_map<string,Symbol_Info*> final_symtab;
extern unordered_map<string,Type*> temp_and_type;
extern int tempcount;
extern vector<string> global_code;
extern vector<int> break_label;
extern vector<int> continue_label;
extern vector<int> goto_label;
extern vector<int> switch_true;
extern vector<int> switch_false;
extern vector<int> switch_label;
bool identifier_found(vector<string>list, string id);
extern vector<string> labelgoto;
extern map<string,int> labelmap;
void fill_expr(int n, string op);
void fill_eqeq_exp1(int index, string s);
void fill_eqeq_exp2(vector<int>list, string s);
class FCRB;
string get_while_code(int temp);
string gen_return(string temp);
string get_param_code(string p);
void backpatch(vector<int>& list,int label);
string get_if_true_code(string condition);
void backpatch1(int i,int label);
string get_if_false_code();
vector<int> merge(vector<int>& l1,vector<int>& l2);
void merge_code1(vector<string>& res,vector<string>& e1);
void merge_code(vector<string>& res,vector<string>& e1,vector<string>& e2);
string get_new_temp();
string get_code4(string op1,string op2,string oprnd,string result);
string get_code_func(string res,string a1);
string get_code_array(string a1,string a2,string res);
string get_label(string temp);
string get_label_param(string nn);
class FCRB{
    public:
    int pos;
    vector<int> nextlist;
    FCRB();
};

#endif