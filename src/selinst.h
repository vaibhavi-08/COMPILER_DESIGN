// X86InstructionSet.h
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

// Enum for operand location
enum class OperandLocation {
    REGISTER,
    MEMORY,
    IMMEDIATE
};

// Struct to represent instruction information
struct InstructionInfo {
    std::string opcode;
    std::string description;
};

// Class to store x86-64 instruction information and provide lookup functionality
class X86InstructionSet {
private:
    // Map of instruction templates based on operation and operand locations
    std::map<std::string, std::map<std::vector<OperandLocation>, InstructionInfo>> instructionMap;

public:
    // Constructor initializes the instruction map
    X86InstructionSet();
    
    // Get the opcode for a given operation and operand locations
    std::string getOpcode(const std::string& operation, const std::vector<OperandLocation>& operandLocations);
    
    // Get the instruction info for a given operation and operand locations
    InstructionInfo getInstructionInfo(const std::string& operation, const std::vector<OperandLocation>& operandLocations);
};

// Helper function to select an instruction
std::string selectInstruction(const std::string& operation, const std::vector<OperandLocation>& operandLocations);
