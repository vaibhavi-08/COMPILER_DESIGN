// RegisterAllocator.h
#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
struct RegAllocResult {
    std::string location;  // Register or memory location
    bool isRegister;       // Whether location is a register
    bool needsSpill;       // Whether register needs to be spilled
};
class RegisterAllocator {
public:
    // Register Descriptor Table: maps register -> set of variables it contains
    std::unordered_map<std::string, std::unordered_set<std::string>> registerDescriptor;
    
    // Address Descriptor Table: maps variable -> locations (registers and/or memory)
    struct LocationInfo {
        bool inMemory;                       // Is variable in memory?
        std::string memoryLocation;          // If in memory, where?
        std::unordered_set<std::string> registers; // Set of registers containing this variable
    };
    int crbp;
    std::unordered_map<std::string, LocationInfo> addressDescriptor;
    
    // List of available registers
    std::vector<std::string> registers;
    
    // Next Use information for variables (simplified)
    std::unordered_map<std::string, bool> nextUse;

public:
    
    // Constructor
    RegisterAllocator(const std::vector<std::string>& availableRegisters);
    
    // Initialize variable in the system
    void addVariable(const std::string& variable);
    
    // Update next use information
    void updateNextUse(const std::unordered_map<std::string, bool>& useInfo);
    
    // Function to load variable into a register
    std::string loadToRegister(const std::string& variable, const std::string& reg);
    
    // Get free register or select one for spilling
    std::string selectRegister(const std::unordered_set<std::string>& avoid);
    
    // Get register or memory for a variable based on preference
    RegAllocResult getLocationForVar(
        const std::string& variable, 
        bool preferRegister,
        const std::unordered_set<std::string>& avoidRegs
    );
    
    // Main function to get registers/memory for instruction operands
    std::unordered_map<std::string, RegAllocResult> getRegisters(
        const std::vector<std::pair<std::string, bool>>& operands,
        const std::unordered_map<std::string, bool>& nextUseInfo,
        std:: unordered_set<std:: string> nototuse
    );
    
    // Helper function to print the current state
    void printState();
    
    // Spill a register (will be implemented by caller)
    void spillRegister(const std::string& reg);
};