// X86InstructionSet.cpp
#include "X86InstructionSet.h"

using namespace std;

X86InstructionSet::X86InstructionSet() {
    // Initialize instruction map with operations and operand locations
    
    // Addition instructions
    instructionMap["+"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"add", "Add register to register"};
    instructionMap["+"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"add", "Add memory to register"};
    instructionMap["+"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"add", "Add immediate to register"};
    instructionMap["+"][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"add", "Add register to memory"};
    instructionMap["+"][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"add", "Add immediate to memory"};

    // Subtraction instructions
    instructionMap["-"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"sub", "Subtract register from register"};
    instructionMap["-"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"sub", "Subtract memory from register"};
    instructionMap["-"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"sub", "Subtract immediate from register"};
    instructionMap["-"][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"sub", "Subtract register from memory"};
    instructionMap["-"][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"sub", "Subtract immediate from memory"};

    // Multiplication instructions
    instructionMap["*"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"imul", "Multiply register by register"};
    instructionMap["*"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"imul", "Multiply register by memory"};
    instructionMap["*"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"imul", "Multiply register by immediate"};
    
    // Division instructions (note: x86 division is special and uses specific registers)
    instructionMap["/"][{OperandLocation::REGISTER}] = {"idiv", "Divide RAX by register"};
    instructionMap["/"][{OperandLocation::MEMORY}] = {"idiv", "Divide RAX by memory"};
    
    // Modulo (uses same instruction as division but result is in RDX)
    instructionMap["%"][{OperandLocation::REGISTER}] = {"idiv", "Divide RAX by register, remainder in RDX"};
    instructionMap["%"][{OperandLocation::MEMORY}] = {"idiv", "Divide RAX by memory, remainder in RDX"};
    
    // Move instructions
    instructionMap["="][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"mov", "Move register to register"};
    instructionMap["="][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"mov", "Move memory to register"};
    instructionMap["="][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"mov", "Move immediate to register"};
    instructionMap["="][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"mov", "Move register to memory"};
    instructionMap["="][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"mov", "Move immediate to memory"};
    
    // Comparison instructions
    instructionMap["=="][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"cmp", "Compare register with register"};
    instructionMap["=="][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"cmp", "Compare register with memory"};
    instructionMap["=="][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"cmp", "Compare register with immediate"};
    instructionMap["=="][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"cmp", "Compare memory with register"};
    instructionMap["=="][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"cmp", "Compare memory with immediate"};
    
    // Inequality operators use the same base instruction (cmp)
    instructionMap["!="] = instructionMap["=="];
    instructionMap["<"] = instructionMap["=="];
    instructionMap["<="] = instructionMap["=="];
    instructionMap[">"] = instructionMap["=="];
    instructionMap[">="] = instructionMap["=="];
    
    // Logical operations
    instructionMap["&&"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"and", "Logical AND register with register"};
    instructionMap["&&"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"and", "Logical AND register with memory"};
    instructionMap["&&"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"and", "Logical AND register with immediate"};
    
    instructionMap["||"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"or", "Logical OR register with register"};
    instructionMap["||"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"or", "Logical OR register with memory"};
    instructionMap["||"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"or", "Logical OR register with immediate"};
    
    // Bitwise operations
    instructionMap["&"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"and", "Bitwise AND register with register"};
    instructionMap["&"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"and", "Bitwise AND register with memory"};
    instructionMap["&"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"and", "Bitwise AND register with immediate"};
    
    instructionMap["|"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"or", "Bitwise OR register with register"};
    instructionMap["|"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"or", "Bitwise OR register with memory"};
    instructionMap["|"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"or", "Bitwise OR register with immediate"};
    
    instructionMap["^"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"xor", "Bitwise XOR register with register"};
    instructionMap["^"][{OperandLocation::REGISTER, OperandLocation::MEMORY}] = {"xor", "Bitwise XOR register with memory"};
    instructionMap["^"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"xor", "Bitwise XOR register with immediate"};
    
    // Not operations
    instructionMap["!"][{OperandLocation::REGISTER}] = {"not", "Bitwise NOT register"};
    instructionMap["!"][{OperandLocation::MEMORY}] = {"not", "Bitwise NOT memory"};
    
    // Shift operations
    instructionMap["<<"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"shl", "Shift left register by register (CL)"};
    instructionMap["<<"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"shl", "Shift left register by immediate"};
    instructionMap["<<"][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"shl", "Shift left memory by register (CL)"};
    instructionMap["<<"][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"shl", "Shift left memory by immediate"};
    
    instructionMap[">>"][{OperandLocation::REGISTER, OperandLocation::REGISTER}] = {"shr", "Shift right register by register (CL)"};
    instructionMap[">>"][{OperandLocation::REGISTER, OperandLocation::IMMEDIATE}] = {"shr", "Shift right register by immediate"};
    instructionMap[">>"][{OperandLocation::MEMORY, OperandLocation::REGISTER}] = {"shr", "Shift right memory by register (CL)"};
    instructionMap[">>"][{OperandLocation::MEMORY, OperandLocation::IMMEDIATE}] = {"shr", "Shift right memory by immediate"};
    
    // Jump instructions
    instructionMap["jmp"][{}] = {"jmp", "Unconditional jump"};
    instructionMap["je"][{}] = {"je", "Jump if equal"};
    instructionMap["jne"][{}] = {"jne", "Jump if not equal"};
    instructionMap["jl"][{}] = {"jl", "Jump if less"};
    instructionMap["jle"][{}] = {"jle", "Jump if less or equal"};
    instructionMap["jg"][{}] = {"jg", "Jump if greater"};
    instructionMap["jge"][{}] = {"jge", "Jump if greater or equal"};
}

string X86InstructionSet::getOpcode(const string& operation, const vector<OperandLocation>& operandLocations) {
    // Check if operation exists in our map
    if (instructionMap.find(operation) == instructionMap.end()) {
        return ""; // Operation not found
    }
    
    // Check if operand location combination exists for this operation
    if (instructionMap[operation].find(operandLocations) == instructionMap[operation].end()) {
        return ""; // Operand location combination not found
    }
    
    // Return the opcode
    return instructionMap[operation][operandLocations].opcode;
}

InstructionInfo X86InstructionSet::getInstructionInfo(const string& operation, const vector<OperandLocation>& operandLocations) {
    // Check if operation exists in our map
    if (instructionMap.find(operation) == instructionMap.end()) {
        return {"", "Operation not supported"}; // Operation not found
    }
    
    // Check if operand location combination exists for this operation
    if (instructionMap[operation].find(operandLocations) == instructionMap[operation].end()) {
        return {"", "Operand location combination not supported"}; // Operand location combination not found
    }
    
    // Return the instruction info
    return instructionMap[operation][operandLocations];
}

// Helper function implementation
void selectInstruction(const string& operation, const vector<OperandLocation>& operandLocations) {
    static X86InstructionSet instructionSet;
    
    string opcode = instructionSet.getOpcode(operation, operandLocations);
    if (opcode.empty()) {
        cout << "No matching instruction found for operation: " << operation << endl;
    } else {
        cout << "Selected opcode: " << opcode << endl;
        cout << "Description: " << instructionSet.getInstructionInfo(operation, operandLocations).description << endl;
    }
}