#include <bits/stdc++.h>
#include <classes_NT.h>
#include "symtab_print.h"
using namespace std;

// Helper function to print indentation
void print_indent(int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
}

// Helper function to print a Type in a readable format
string type_to_string(Type* t) {
    if (!t) return "nullptr";
    
    stringstream ss;
    
    // Base type information
    if (t->isbasic) {
        if (t->isunsigned) ss << "unsigned ";
        else if (t->isigned) ss << "signed ";
        ss << t->base;
    }
    else if (t->isvoid) {
        ss << "void";
    }
    else if (t->isnull) {
        ss << "nullptr";
    }
    else if (t->isenum) {
        ss << "enum " << t->obj_class;
    }
    else if (t->isobj) {
        ss << t->objtype << " " << t->obj_class;
    }
    
    // Qualifier information
    if (t->isconst) ss << " const";
    if (t->isvolatile) ss << " volatile";
    
    // Storage class
    if (t->isstatic) ss << " static";
    if (t->isauto) ss << " auto";
    if (t->isextern) ss << " extern";
    if (t->isregister) ss << " register";
    
    // Pointer levels
    for (int i = 0; i < t->ptr_level; i++) {
        ss << "*";
        if (i < t->ptrtql.size()) {
            if (t->ptrtql[i].isconst) ss << " const";
            if (t->ptrtql[i].isvol) ss << " volatile";
        }
    }
    
    // Array dimensions
    if (t->array_dim > 0) {
        ss << "[";
        for (int i = 1; i < t->array_dim; i++) {
            ss << "][";
        }
        ss << "]";
    }
    
    // Function information
    if (t->isfunction) {
        ss << " function(";
        
        for (size_t i = 0; i < t->prms.size(); i++) {
            if (i > 0) ss << ", ";
            ss << type_to_string(t->prms[i]);
        }
        
        ss << ")";
        if (t->func_ret_type) {
            ss << " returning " << type_to_string(t->func_ret_type);
        }
    }
    
    // Function pointer information
    if (t->func_ptr_lev > 0) {
        ss << " function pointer level " << t->func_ptr_lev;
    }
    
    return ss.str();
}

// Print a local symbol table
void print_local_symbol_table(Local_Symbol_Table* lst, int indent_level ) {
    if (!lst) {
        print_indent(indent_level);
        cout << "Empty symbol table" << endl;
        return;
    }
    
    // Print all symbols in this table
    for (const auto& entry : lst->lst) {
        print_indent(indent_level);
        Symbol_Info* si = entry.second;
        
        cout << entry.first << " : " 
             << (si->type.empty() ? "No type" : si->type) 
             << " (level: " << si->level << ", scope: " << si->scope << ")";
        
        if (si->t) {
            cout << " - " << type_to_string(si->t);
        }
        cout << endl;
    }
    
    // Print any class/struct/union definitions in this table
    for (const auto& entry : lst->class_struct_union_info) {
        print_indent(indent_level);
        cout << "Definition of " << entry.first << ":" << endl;
        print_local_symbol_table(entry.second, indent_level + 1);
    }
}

// Print the entire global symbol table
void print_global_symbol_table() {
    if (!gst) {
        cout << "Global symbol table is not initialized" << endl;
        return;
    }
    
    cout << "=== GLOBAL SYMBOL TABLE ===" << endl;
    
    // Print global symbols
    cout << "Global Symbols:" << endl;
    for (const auto& entry : gst->gst) {
        cout << "  " << entry.first << " : "
             << (entry.second->type.empty() ? "No type" : entry.second->type)
             << " (scope: " << entry.second->scope << ")";
        
        if (entry.second->t) {
            cout << " - " << type_to_string(entry.second->t);
        }
        cout << endl;
    }
    
    // Print class/struct/union information
    cout << "\nClass/Struct/Union Definitions:" << endl;
    for (const auto& entry : gst->class_struct_union_info) {
        cout << "  Definition of " << entry.first << ":" << endl;
        print_local_symbol_table(entry.second, 2);
    }
}

// Function to print current scope information
void print_current_scope_info() {
    cout << "=== CURRENT SCOPE INFORMATION ===" << endl;
    cout << "Current level: " << current_level << endl;
    
    cout << "Level name stack (from top): ";
    stack<string> temp = lvl_name;
    vector<string> names;
    
    while (!temp.empty()) {
        names.push_back(temp.top());
        temp.pop();
    }
    
    for (auto it = names.rbegin(); it != names.rend(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl;
    
    cout << "Current table: " << (current_table ? "exists" : "nullptr") << endl;
    
    // Print access specifier stack
    cout << "Access specifier stack (from top): ";
    temp = access_spec_stk;
    names.clear();
    
    while (!temp.empty()) {
        names.push_back(temp.top());
        temp.pop();
    }
    
    for (auto it = names.rbegin(); it != names.rend(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl;
    
    // Print current parameters list
    cout << "\nCurrent parameters list:" << endl;
    for (const auto& param : current_params_list) {
        cout << "  " << param.first << " : " << type_to_string(param.second) << endl;
    }
    
    // Print current class/struct/union stack
    cout << "\nCurrent class/struct/union stack (from top):" << endl;
    stack<pair<string, Local_Symbol_Table*>> temp_stack = current_class_struct_union_info;
    while (!temp_stack.empty()) {
        auto entry = temp_stack.top();
        cout << "  " << entry.first << " : " 
             << (entry.second ? "has symbol table" : "no symbol table yet") << endl;
        temp_stack.pop();
    }
}

// Function to print the labels in the program
void print_labels() {
    cout << "=== LABEL SET ===" << endl;
    for (const auto& label : labelset) {
        cout << "  " << label << endl;
    }
}

// Main function to print all symbol table information
void print_full_symbol_table() {
    cout << "\n===============================================\n";
    cout << "             SYMBOL TABLE DUMP                 \n";
    cout << "===============================================\n\n";
    
    print_global_symbol_table();
    cout << "\n";
    print_current_scope_info();
    cout << "\n";
    print_labels();
    cout << "\n===============================================\n";
}