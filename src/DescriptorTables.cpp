#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Register Descriptor Table - Maps each register to the temporaries it contains
class RegisterDescriptorTable {
    private:
        // Maps each register to a set of temporaries it currently holds
        map<string, vector<string>> registerToTemps;
        // List of available registers
        vector<string> availableRegisters;
    
    public:
        RegisterDescriptorTable() {
            // Initialize available x86-64 registers
            availableRegisters = {"rax", "rbx", "rcx", "rdx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"};
            
            // Initialize empty descriptor for each register
            for (const auto& reg : availableRegisters) {
                registerToTemps[reg] = {};
            }
        }
    
        // Add a temporary to a register's descriptor
        void addTemp(const string& reg, const string& temp) {
            registerToTemps[reg].push_back(temp);
        }
    
        // Remove a temporary from all registers
        void removeTemp(const string& temp) {
            for (auto& [reg, temps] : registerToTemps) {
                auto it = find(temps.begin(), temps.end(), temp);
                if (it != temps.end()) {
                    temps.erase(it);
                }
            }
        }
    
        // Check if a temporary is in a register
        bool isInRegister(const string& temp) const {
            for (const auto& [reg, temps] : registerToTemps) {
                if (find(temps.begin(), temps.end(), temp) != temps.end()) {
                    return true;
                }
            }
            return false;
        }
    
        // Get the register holding a temporary (empty string if not found)
        string getRegisterForTemp(const string& temp) const {
            for (const auto& [reg, temps] : registerToTemps) {
                if (find(temps.begin(), temps.end(), temp) != temps.end()) {
                    return reg;
                }
            }
            return "";
        }
    
        // Get all temporaries in a register
        const vector<string>& getTempsInRegister(const string& reg) const {
            return registerToTemps.at(reg);
        }
    
        // Get all available registers (those with no temporaries)
        vector<string> getEmptyRegisters() const {
            vector<string> emptyRegs;
            for (const auto& [reg, temps] : registerToTemps) {
                if (temps.empty()) {
                    emptyRegs.push_back(reg);
                }
            }
            return emptyRegs;
        }
    
        // Clear all temporaries from a register
        void clearRegister(const string& reg) {
            registerToTemps[reg].clear();
        }
    };
    
    // Address Descriptor Table - Maps each temporary to its storage locations
    class AddressDescriptorTable {
    private:
        // Maps each temporary to its possible locations (memory, register)
        map<string, struct {
            bool inMemory;              // Is the temporary in memory?
            string registerLocation;    // Which register contains the temporary (if any)
        }> tempToLocations;
    
    public:
        // Add or update a temporary's location information
        void setLocation(const string& temp, bool inMem, const string& reg = "") {
            tempToLocations[temp].inMemory = inMem;
            if (!reg.empty()) {
                tempToLocations[temp].registerLocation = reg;
            }
        }
    
        // Set the register location of a temporary
        void setRegisterLocation(const string& temp, const string& reg) {
            tempToLocations[temp].registerLocation = reg;
        }
    
        // Mark a temporary as being in memory
        void setInMemory(const string& temp, bool status = true) {
            tempToLocations[temp].inMemory = status;
        }
    
        // Check if a temporary is in memory
        bool isInMemory(const string& temp) const {
            auto it = tempToLocations.find(temp);
            if (it != tempToLocations.end()) {
                return it->second.inMemory;
            }
            return false;
        }
    
        // Get the register location of a temporary (empty string if not in a register)
        string getRegisterLocation(const string& temp) const {
            auto it = tempToLocations.find(temp);
            if (it != tempToLocations.end()) {
                return it->second.registerLocation;
            }
            return "";
        }
    
        // Clear the register location of a temporary
        void clearRegisterLocation(const string& temp) {
            auto it = tempToLocations.find(temp);
            if (it != tempToLocations.end()) {
                it->second.registerLocation = "";
            }
        }
    };    

// Enum for operand location
enum class OperandLocation {
    REGISTER,
    MEMORY,
    IMMEDIATE
};

// Struct to represent instruction information
struct InstructionInfo {
    string opcode;
    string description;
};

// Class to store x86-64 instruction information and provide lookup functionality
class X86InstructionSet {
private:
    // Map of instruction templates based on operation and operand locations
    map<string, map<vector<OperandLocation>, InstructionInfo>> instructionMap;

public:
    X86InstructionSet() {
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
    
    // Get the opcode for a given operation and operand locations
    string getOpcode(const string& operation, const vector<OperandLocation>& operandLocations) {
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
    
    // Get the instruction info for a given operation and operand locations
    InstructionInfo getInstructionInfo(const string& operation, const vector<OperandLocation>& operandLocations) {
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
};

// Example usage function
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

// Function to get a register for a temporary in the context of an instruction
string getRegister(const string& instruction, const vector<string>& temporaries, 
    RegisterDescriptorTable& regDesc, AddressDescriptorTable& addrDesc) {

    // Parse the instruction to identify the operation and operands
    string operation, result, operand1, operand2;

    // Extract the operation and operands from the instruction
    // Format examples: "14: t8=t6%t7", "19: t11=t2++", "20: t2=t11"
    size_t colonPos = instruction.find(':');
    if (colonPos != string::npos) {
    string instrBody = instruction.substr(colonPos + 1);

    // Handle assignment operations (t2=t11)
    size_t equalPos = instrBody.find('=');
    if (equalPos != string::npos) {
    result = instrBody.substr(0, equalPos);
    // Remove whitespace
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());

    string rightSide = instrBody.substr(equalPos + 1);

    // Check for post-increment/decrement (t11=t2++)
    if (rightSide.find("++") != string::npos) {
    operand1 = rightSide.substr(0, rightSide.find("++"));
    operation = "++";
    } else if (rightSide.find("--") != string::npos) {
    operand1 = rightSide.substr(0, rightSide.find("--"));
    operation = "--";
    } else {
    // Check for binary operations (t8=t6%t7)
    for (char op : {'+', '-', '*', '/', '%', '&', '|', '^'}) {
        size_t opPos = rightSide.find(op);
        if (opPos != string::npos) {
            operand1 = rightSide.substr(0, opPos);
            operand2 = rightSide.substr(opPos + 1);
            operation = string(1, op);
            break;
        }
    }
    
    // If no binary operation was found, it's a simple assignment
    if (operation.empty()) {
        operand1 = rightSide;
        operation = "=";
    }
    }

    // Remove whitespace from the operands
    operand1.erase(remove_if(operand1.begin(), operand1.end(), ::isspace), operand1.end());
    operand2.erase(remove_if(operand2.begin(), operand2.end(), ::isspace), operand2.end());
    }
    }

    // Focus on the first temporary in the list passed to the function
    if (temporaries.empty()) {
    return "";
    }

    string temp = temporaries[0];

    // Check if the temporary already has a register assigned
    string reg = addrDesc.getRegisterLocation(temp);
    if (!reg.empty()) {
    return reg;
    }

    // If not, we need to allocate a register

    // First, try to find an empty register
    vector<string> emptyRegisters = regDesc.getEmptyRegisters();
    if (!emptyRegisters.empty()) {
    reg = emptyRegisters[0];
    } else {
    // No empty registers, we need to spill one
    // For simplicity, use rax if no other priority
    reg = "rax";

    // Spill the register's current contents to memory
    vector<string> tempsInReg = regDesc.getTempsInRegister(reg);
    for (const auto& t : tempsInReg) {
    addrDesc.setInMemory(t, true);
    addrDesc.clearRegisterLocation(t);
    }
    regDesc.clearRegister(reg);
    }

    // Allocate the register to the temporary
    regDesc.addTemp(reg, temp);
    addrDesc.setRegisterLocation(temp, reg);

    return reg;
}

// Example main to demonstrate usage
int main() {
    // Example: t1 = t2 * t3 (both in registers)
    cout << "Example 1: t1 = t2 * t3 (both operands in registers)" << endl;
    selectInstruction("*", {OperandLocation::REGISTER, OperandLocation::REGISTER});
    
    // Example: t1 = t2 * 5 (immediate)
    cout << "\nExample 2: t1 = t2 * 5 (second operand is immediate)" << endl;
    selectInstruction("*", {OperandLocation::REGISTER, OperandLocation::IMMEDIATE});
    
    // Example: t1 = t2 + mem[t3] (memory operand)
    cout << "\nExample 3: t1 = t2 + mem[t3] (second operand in memory)" << endl;
    selectInstruction("+", {OperandLocation::REGISTER, OperandLocation::MEMORY});
    
    return 0;
}