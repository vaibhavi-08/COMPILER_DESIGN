#ifndef TAC_H
#define TAC_H
#include <bits/stdc++.h>
#include <classes_NT.h>
using namespace std;
extern unordered_map<string,Symbol_Info*> final_symtab;
extern int tempcount;
extern vector<string> global_code;
void backpatch(vector<int>& list,int label);
string get_if_true_code(string condition);
string get_if_false_code();
vector<int> merge(vector<int>& l1,vector<int>& l2);
void merge_code1(vector<string>& res,vector<string>& e1);
void merge_code(vector<string>& res,vector<string>& e1,vector<string>& e2);
string get_new_temp();
string get_code4(string op1,string op2,string oprnd,string result);
#endif