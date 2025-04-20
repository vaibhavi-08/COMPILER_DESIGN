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
    void addVariable(const std::string& variable) {
        addressDescriptor[variable] = {false, "", {}};
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
    // Modified selectRegister method with the requested changes
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
                    // Update address descriptor for all variables in this register
                    for (const auto& var : registerDescriptor[reg]) {
                        addressDescriptor[var].registers.erase(reg);
                    }
                    
                    // Empty the register descriptor
                    registerDescriptor[reg].clear();
                    
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
            addVariable(variable);
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
    // Complete list of x86-64 registers in Intel syntax
    std::vector<std::string> regs = {
        // General purpose registers (64-bit)
        // "rax", "rbx", "rcx", "rdx", "rsi", "rdi", "rbp", "rsp",
        // "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
        
        // General purpose registers (32-bit)
        "eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp",
        "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d",
        
        // General purpose registers (16-bit)
        // "ax", "bx", "cx", "dx", "si", "di", "bp", "sp",
        // "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w",
        
        // General purpose registers (8-bit)
        // "al", "bl", "cl", "dl", "sil", "dil", "bpl", "spl",
        // "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b",
        
        // Legacy 8-bit registers
        //"ah", "bh", "ch", "dh",
        
        // Segment registers
        //"cs", "ds", "ss", "es", "fs", "gs",
        
        // SIMD registers
        // SSE/AVX 128-bit registers
        // "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
        // "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15",
        // "xmm16", "xmm17", "xmm18", "xmm19", "xmm20", "xmm21", "xmm22", "xmm23",
        // "xmm24", "xmm25", "xmm26", "xmm27", "xmm28", "xmm29", "xmm30", "xmm31",
        
        // AVX 256-bit registers
        // "ymm0", "ymm1", "ymm2", "ymm3", "ymm4", "ymm5", "ymm6", "ymm7",
        // "ymm8", "ymm9", "ymm10", "ymm11", "ymm12", "ymm13", "ymm14", "ymm15",
        // "ymm16", "ymm17", "ymm18", "ymm19", "ymm20", "ymm21", "ymm22", "ymm23",
        // "ymm24", "ymm25", "ymm26", "ymm27", "ymm28", "ymm29", "ymm30", "ymm31",
        
        // AVX-512 512-bit registers (if needed)
        // "zmm0", "zmm1", "zmm2", "zmm3", "zmm4", "zmm5", "zmm6", "zmm7",
        // "zmm8", "zmm9", "zmm10", "zmm11", "zmm12", "zmm13", "zmm14", "zmm15",
        // "zmm16", "zmm17", "zmm18", "zmm19", "zmm20", "zmm21", "zmm22", "zmm23",
        // "zmm24", "zmm25", "zmm26", "zmm27", "zmm28", "zmm29", "zmm30", "zmm31",
        
        // Special registers
        // "rip",  // Instruction pointer
        // "rflags" // Flags register
    };
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