#ifndef SYMTAB_PRINT_H
#define SYMTAB_PRINT_H

#include <classes_NT.h>

// Helper function to print indentation
void print_indent(int level);

// Helper function to print a Type in a readable format
std::string type_to_string(Type* t);

// Print a local symbol table
void print_local_symbol_table(Local_Symbol_Table* lst, int indent_level = 0);

// Print the entire global symbol table
void print_global_symbol_table();

// Function to print current scope information
void print_current_scope_info();

// Function to print the labels in the program
void print_labels();

// Main function to print all symbol table information
void print_full_symbol_table();

#endif // SYMTAB_PRINT_H