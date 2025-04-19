#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class RegisterAllocator {
private:
    // Register Descriptor Table: maps register -> set of variables it contains
    std::unordered_map<std::string, std::unordered_set<std::string>> registerDescriptor;
    
    // Address Descriptor Table: maps variable -> locations (registers and/or memory)
    struct LocationInfo {
        bool inMemory;                       // Is variable in memory?
        std::string memoryLocation;          // If in memory, where?
        std::unordered_set<std::string> registers; // Set of registers containing this variable
    };
    std::unordered_map<std::string, LocationInfo> addressDescriptor;
    
    // List of available registers
    std::vector<std::string> registers;
    
    // Next Use information for variables (simplified)
    std::unordered_map<std::string, bool> nextUse;

public:
    // Structure to return register allocation result
    struct RegAllocResult {
        std::string location;  // Register or memory location
        bool isRegister;       // Whether location is a register
        bool needsSpill;       // Whether register needs to be spilled
    };
    
    RegisterAllocator(const std::vector<std::string>& availableRegisters) : registers(availableRegisters) {
        // Initialize register descriptor table
        for (const auto& reg : registers) {
            registerDescriptor[reg] = std::unordered_set<std::string>();
        }
    }
    
    // Initialize variable in the system
    void addVariable(const std::string& variable, const std::string& memLocation) {
        addressDescriptor[variable] = {true, memLocation, {}};
    }
    
    // Update next use information
    void updateNextUse(const std::unordered_map<std::string, bool>& useInfo) {
        nextUse = useInfo;
    }
    
    // Function to load variable into a register
    std::string loadToRegister(const std::string& variable, const std::string& reg) {
        // Update address descriptor
        addressDescriptor[variable].registers.insert(reg);
        
        // Update register descriptor
        registerDescriptor[reg].insert(variable);
        
        return reg;
    }
    
    // Get free register or select one for spilling
    std::string selectRegister(const std::unordered_set<std::string>& avoid) {
        // First, try to find an empty register
        for (const auto& reg : registers) {
            if (registerDescriptor[reg].empty() && avoid.find(reg) == avoid.end()) {
                return reg;
            }
        }
        
        // No empty register, find register with variable not used later
        for (const auto& reg : registers) {
            if (avoid.find(reg) == avoid.end()) {
                bool canUse = true;
                for (const auto& var : registerDescriptor[reg]) {
                    if (nextUse.find(var) != nextUse.end() && nextUse[var]) {
                        canUse = false;
                        break;
                    }
                }
                if (canUse) {
                    return reg;
                }
            }
        }
        
        // Otherwise, select first non-avoided register
        for (const auto& reg : registers) {
            if (avoid.find(reg) == avoid.end()) {
                return reg;
            }
        }
        
        // If all registers are in avoid list, return the first one (not ideal but fallback)
        return registers[0];
    }
    
    // Get register or memory for a variable based on preference
    RegAllocResult getLocationForVar(
        const std::string& variable, 
        bool preferRegister,
        const std::unordered_set<std::string>& avoidRegs
    ) {
        // If variable doesn't exist, add it with a default memory location
        if (addressDescriptor.find(variable) == addressDescriptor.end()) {
            addVariable(variable, "stack_" + variable);
        }
        
        const auto& locations = addressDescriptor[variable];
        
        // If we prefer memory and variable is in memory, return memory location
        if (!preferRegister && locations.inMemory) {
            return {locations.memoryLocation, false, false};
        }
        
        // If variable is already in a register not in the avoid list, use that
        for (const auto& reg : locations.registers) {
            if (avoidRegs.find(reg) == avoidRegs.end()) {
                return {reg, true, false};
            }
        }
        
        // If we prefer register or variable is not in memory, allocate a register
        if (preferRegister || !locations.inMemory) {
            std::string selectedReg = selectRegister(avoidRegs);
            bool needsSpill = !registerDescriptor[selectedReg].empty();
            
            return {selectedReg, true, needsSpill};
        }
        
        // Default: return memory location
        return {locations.memoryLocation, false, false};
    }
    
    // Main function to get registers/memory for instruction operands
    std::unordered_map<std::string, RegAllocResult> getRegisters(
        const std::vector<std::pair<std::string, bool>>& operands,
        const std::unordered_map<std::string, bool>& nextUseInfo
    ) {
        // Update next use information
        updateNextUse(nextUseInfo);
        
        std::unordered_map<std::string, RegAllocResult> result;
        std::unordered_set<std::string> allocatedRegs;
        
        // Process each operand
        for (const auto& [var, needsReg] : operands) {
            // Get location for this variable
            RegAllocResult location = getLocationForVar(var, needsReg, allocatedRegs);
            
            result[var] = location;
            
            // Add to allocated registers if it's a register
            if (location.isRegister) {
                allocatedRegs.insert(location.location);
            }
        }
        
        return result;
    }
    
    // Helper function to print the current state
    void printState() {
        std::cout << "Register Descriptor Table:\n";
        for (const auto& [reg, vars] : registerDescriptor) {
            std::cout << reg << ": ";
            for (const auto& var : vars) {
                std::cout << var << " ";
            }
            std::cout << "\n";
        }
        
        std::cout << "\nAddress Descriptor Table:\n";
        for (const auto& [var, info] : addressDescriptor) {
            std::cout << var << ": ";
            if (info.inMemory) {
                std::cout << "Memory(" << info.memoryLocation << ") ";
            }
            std::cout << "Registers(";
            for (const auto& reg : info.registers) {
                std::cout << reg << " ";
            }
            std::cout << ")\n";
        }
        std::cout << std::endl;
    }
    
    // Spill a register (will be implemented by caller)
    // Just marking it here for completeness
    void spillRegister(const std::string& reg) {
        // This should be implemented by the caller as mentioned in requirements
        std::cout << "Need to spill register: " << reg << std::endl;
    }
};

// Example usage
int main() {
    // Initialize with available registers
    std::vector<std::string> regs = {"R0", "R1", "R2", "R3"};
    RegisterAllocator allocator(regs);
    
    // Add some variables
    allocator.addVariable("x", "stack_x");
    allocator.addVariable("y", "stack_y");
    allocator.addVariable("z", "stack_z");
    
    // Print initial state
    allocator.printState();
    
    // Example: Process instruction x = y + z
    std::vector<std::pair<std::string, bool>> operands = {
        {"y", true},  // Need register for y
        {"z", true},  // Need register for z
        {"x", true}   // Need register for x
    };
    
    // Set next use information (true if variable will be used later)
    std::unordered_map<std::string, bool> nextUse = {
        {"x", false},
        {"y", true},
        {"z", false}
    };
    
    // Get registers for these operands
    auto result = allocator.getRegisters(operands, nextUse);
    
    // Print results
    std::cout << "Allocation for x = y + z:\n";
    for (const auto& [var, res] : result) {
        std::cout << var << ": " << (res.isRegister ? "Register " : "Memory ") 
                  << res.location;
        if (res.needsSpill) {
            std::cout << " (needs spill)";
        }
        std::cout << std::endl;
    }
    
    return 0;
}