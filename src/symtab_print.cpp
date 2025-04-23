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

// Helper function to create a formatted table separator line
string create_separator(int width) {
    return string(width, '-');
}

// Print a local symbol table in table format
void print_local_symbol_table(Local_Symbol_Table* lst, int indent_level) {
    if (!lst) {
        print_indent(indent_level);
        cout << "Empty symbol table" << endl;
        return;
    }
    
    // Define column widths
    const int NAME_WIDTH = 20;
    const int TYPE_WIDTH = 15;
    const int LEVEL_WIDTH = 10;
    const int DETAILS_WIDTH = 55;  // Wider now that we removed SCOPE
    
    // Print header
    print_indent(indent_level);
    cout << left << setw(NAME_WIDTH) << "NAME" 
         << setw(TYPE_WIDTH) << "TYPE" 
         << setw(LEVEL_WIDTH) << "LEVEL" 
         << "DETAILS" << endl;
    
    // Print separator
    print_indent(indent_level);
    cout << create_separator(NAME_WIDTH + TYPE_WIDTH + LEVEL_WIDTH + DETAILS_WIDTH) << endl;
    
    // Print all symbols in this table
    for (const auto& entry : lst->lst) {
        Symbol_Info* si = entry.second;
        
        print_indent(indent_level);
        cout << left << setw(NAME_WIDTH) << entry.first 
             << setw(TYPE_WIDTH) << (si->type.empty() ? "No type" : si->type)
             << setw(LEVEL_WIDTH) << si->level;
        
        // Print type details with proper wrapping
        if (si->t) {
            string type_details = type_to_string(si->t);
            cout << (type_details.length() > DETAILS_WIDTH ? 
                     type_details.substr(0, DETAILS_WIDTH-3) + "..." : 
                     type_details);
        }
        cout << endl;
    }
    
    // Print any class/struct/union definitions in this table
    for (const auto& entry : lst->class_struct_union_info) {
        cout << endl;
        print_indent(indent_level);
        cout << "Definition of " << entry.first << ":" << endl;
        print_indent(indent_level);
        cout << create_separator(NAME_WIDTH + TYPE_WIDTH + LEVEL_WIDTH + DETAILS_WIDTH) << endl;
        print_local_symbol_table(entry.second, indent_level + 1);
    }
}

// Helper function to recursively print local symbol tables
void print_local_symbol_tables(Local_Symbol_Table* table, int depth) {
    if (!table) return;
    
    // Define column widths
    const int NAME_WIDTH = 20;
    const int TYPE_WIDTH = 15;
    const int LEVEL_WIDTH = 10;
    const int DETAILS_WIDTH = 55;  // Wider now that we removed SCOPE
    const int TOTAL_WIDTH = NAME_WIDTH + TYPE_WIDTH + LEVEL_WIDTH + DETAILS_WIDTH;
    
    // Print header for this local table
    cout << string(depth * 2, ' ') << "Local Symbol Table " 
         << (table->ispargst ? "(Parameter Table)" : "") << ":" << endl;
    
    // Print separator
    cout << string(depth * 2, ' ') << create_separator(TOTAL_WIDTH) << endl;
    
    // Print header row
    cout << string(depth * 2, ' ') 
         << left << setw(NAME_WIDTH) << "NAME" 
         << setw(TYPE_WIDTH) << "TYPE" 
         << setw(LEVEL_WIDTH) << "LEVEL" 
         << "DETAILS" << endl;
    
    cout << string(depth * 2, ' ') << create_separator(TOTAL_WIDTH) << endl;
    
    // Print all symbols in this table
    for (const auto& entry : table->lst) {
        Symbol_Info* si = entry.second;
        
        cout << string(depth * 2, ' ') 
             << left << setw(NAME_WIDTH) << entry.first 
             << setw(TYPE_WIDTH) << (si->type.empty() ? "No type" : si->type)
             << setw(LEVEL_WIDTH) << si->level;
        
        // Print type details with proper wrapping
        if (si->t) {
            string type_details = type_to_string(si->t);
            cout << (type_details.length() > DETAILS_WIDTH ? 
                     type_details.substr(0, DETAILS_WIDTH-3) + "..." : 
                     type_details);
        }
        cout << endl;
    }
    
    // Print separator after symbols
    cout << string(depth * 2, ' ') << create_separator(TOTAL_WIDTH) << endl;
    
    // Print any class/struct/union definitions in this table
    for (const auto& entry : table->class_struct_union_info) {
        cout << endl;
        cout << string(depth * 2, ' ') << "Definition of " << entry.first << ":" << endl;
        print_local_symbol_table(entry.second, depth + 1);
    }
    
    // Recursively print child tables
    cout << endl;
    if (!table->children.empty()) {
        cout << string(depth * 2, ' ') << "Child Scopes:" << endl;
        for (auto child : table->children) {
            print_local_symbol_tables(child, depth + 1);
        }
    }
}

// Function to print the entire global symbol table with formatting
void print_global_symbol_table() {
    if (!gst) {
        cout << "Global symbol table is not initialized" << endl;
        return;
    }
    
    cout << "\n=== GLOBAL SYMBOL TABLE ===" << endl << endl;
    
    // Define column widths
    const int NAME_WIDTH = 25;
    const int TYPE_WIDTH = 20;
    const int DETAILS_WIDTH = 55;  // Wider now that we removed SCOPE
    
    // Print global symbols header
    cout << "Global Symbols:" << endl;
    cout << left << setw(NAME_WIDTH) << "NAME" 
         << setw(TYPE_WIDTH) << "TYPE" 
         << "DETAILS" << endl;
    cout << create_separator(NAME_WIDTH + TYPE_WIDTH + DETAILS_WIDTH) << endl;
    
    // Print all global symbols
    for (const auto& entry : gst->gst) {
        cout << left << setw(NAME_WIDTH) << entry.first
             << setw(TYPE_WIDTH) << (entry.second->type.empty() ? "No type" : entry.second->type);
        
        // Print type details with proper wrapping
        if (entry.second->t) {
            string type_details = type_to_string(entry.second->t);
            cout << (type_details.length() > DETAILS_WIDTH ? 
                     type_details.substr(0, DETAILS_WIDTH-3) + "..." : 
                     type_details);
        }
        cout << endl;
    }
    cout << create_separator(NAME_WIDTH + TYPE_WIDTH + DETAILS_WIDTH) << endl;
    
    // Print class/struct/union information
    cout << "\nClass/Struct/Union Definitions:" << endl;
    for (const auto& entry : gst->class_struct_union_info) {
        cout << "\nDefinition of " << entry.first << ":" << endl;
        cout << create_separator(NAME_WIDTH + TYPE_WIDTH + DETAILS_WIDTH) << endl;
        print_local_symbol_table(entry.second, 0);
    }
    
    // Print all local scopes from the global scope
    cout << "\nLocal Scopes:" << endl;
    for (auto child : gst->children) {
        print_local_symbol_tables(child, 1);
    }
}

// Function to print current scope information in a tabular format
void print_current_scope_info() {
    cout << "\n=== CURRENT SCOPE INFORMATION ===" << endl;
    cout << "Current level: " << current_level << endl << endl;
    
    // Format level name stack
    cout << "Level name stack (from top):" << endl;
    cout << create_separator(50) << endl;
    
    stack<string> temp = lvl_name;
    vector<string> names;
    
    while (!temp.empty()) {
        names.push_back(temp.top());
        temp.pop();
    }
    
    for (size_t i = 0; i < names.size(); i++) {
        cout << setw(3) << (names.size() - i) << " | " << names[i] << endl;
    }
    
    cout << create_separator(50) << endl;
    cout << "Current table: " << (current_table ? "exists" : "nullptr") << endl << endl;
    
    // Format access specifier stack
    cout << "Access specifier stack (from top):" << endl;
    cout << create_separator(30) << endl;
    
    temp = access_spec_stk;
    names.clear();
    
    while (!temp.empty()) {
        names.push_back(temp.top());
        temp.pop();
    }
    
    for (size_t i = 0; i < names.size(); i++) {
        cout << setw(3) << (names.size() - i) << " | " << names[i] << endl;
    }
    
    cout << create_separator(30) << endl << endl;
    
    // Format current parameters list
    cout << "Current parameters list:" << endl;
    if (current_params_list.empty()) {
        cout << "  (empty)" << endl << endl;
    } else {
        const int NAME_WIDTH = 20;
        const int TYPE_WIDTH = 50;
        
        cout << create_separator(NAME_WIDTH + TYPE_WIDTH) << endl;
        cout << left << setw(NAME_WIDTH) << "PARAMETER" << "TYPE" << endl;
        cout << create_separator(NAME_WIDTH + TYPE_WIDTH) << endl;
        
        for (const auto& param : current_params_list) {
            cout << left << setw(NAME_WIDTH) << param.first;
            cout << type_to_string(param.second) << endl;
        }
        cout << create_separator(NAME_WIDTH + TYPE_WIDTH) << endl << endl;
    }
    
    // Format current class/struct/union stack
    cout << "Current class/struct/union stack (from top):" << endl;
    if (current_class_struct_union_info.empty()) {
        cout << "  (empty)" << endl;
    } else {
        const int LEVEL_WIDTH = 5;
        const int NAME_WIDTH = 25;
        const int TABLE_WIDTH = 15;
        
        cout << create_separator(LEVEL_WIDTH + NAME_WIDTH + TABLE_WIDTH) << endl;
        cout << left << setw(LEVEL_WIDTH) << "LEVEL" 
             << setw(NAME_WIDTH) << "NAME" 
             << "TABLE STATUS" << endl;
        cout << create_separator(LEVEL_WIDTH + NAME_WIDTH + TABLE_WIDTH) << endl;
        
        stack<pair<string, Local_Symbol_Table*>> temp_stack = current_class_struct_union_info;
        vector<pair<string, Local_Symbol_Table*>> entries;
        
        while (!temp_stack.empty()) {
            entries.push_back(temp_stack.top());
            temp_stack.pop();
        }
        
        for (size_t i = 0; i < entries.size(); i++) {
            auto entry = entries[i];
            cout << left << setw(LEVEL_WIDTH) << (entries.size() - i) 
                 << setw(NAME_WIDTH) << entry.first
                 << (entry.second ? "Has symbol table" : "No symbol table yet") << endl;
        }
        cout << create_separator(LEVEL_WIDTH + NAME_WIDTH + TABLE_WIDTH) << endl;
    }
}

// Function to print the labels in the program with nicer formatting
void print_labels() {
    cout << "\n=== LABEL SET ===" << endl;
    
    if (labelset.empty()) {
        cout << "  (no labels defined)" << endl;
        return;
    }
    
    const int LABEL_WIDTH = 25;
    const int COUNTER_WIDTH = 5;
    int counter = 1;
    
    cout << create_separator(COUNTER_WIDTH + LABEL_WIDTH) << endl;
    cout << left << setw(COUNTER_WIDTH) << "#" << "LABEL" << endl;
    cout << create_separator(COUNTER_WIDTH + LABEL_WIDTH) << endl;
    
    for (const auto& label : labelset) {
        cout << left << setw(COUNTER_WIDTH) << counter++ << label << endl;
    }
    
    cout << create_separator(COUNTER_WIDTH + LABEL_WIDTH) << endl;
}

// Main function to print all symbol table information
void print_full_symbol_table() {
    try {
        // Open an output file for writing
        ofstream outfile("symbol_table_dump.txt");
        if (!outfile.is_open()) {
            cerr << "Error: Could not open output file for writing" << endl;
            return;
        }
        
        // Store the original cout buffer to restore it later
        streambuf* cout_buffer = cout.rdbuf();
        
        // Redirect cout to the output file
        cout.rdbuf(outfile.rdbuf());
        
        // Set left alignment for all output
        cout << left;
        
        // Now all cout operations will go to the file
        cout << "\n===============================================\n";
        cout << "             SYMBOL TABLE DUMP                 \n";
        cout << "===============================================\n";
        
        if (gst) print_global_symbol_table();
        //print_current_scope_info();
        print_labels();
        cout << "\n===============================================\n";
        
        // Restore cout to its original output (terminal)
        cout.rdbuf(cout_buffer);
        
        // Close the file
        outfile.close();
        
        // Inform the user that the dump was written to a file
        cout << "Symbol table dump written to symbol_table_dump.txt" << endl;
    } catch (exception& e) {
        // Restore cout buffer in case of exception
        cout.rdbuf(cout.rdbuf());
        cerr << "Error while generating symbol table dump: " << e.what() << endl;
    }
}