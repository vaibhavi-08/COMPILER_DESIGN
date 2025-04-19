#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Class for Register Descriptor Table (RDT)
class RegisterDescriptorTable {
private:
    // Maps register name to the set of variables/temporaries it contains
    map<string, set<string>> registerMap;
    
    // Lists of available registers by category
    vector<string> gprRegisters;      // General-Purpose Registers
    vector<string> sprRegisters;      // Special-Purpose Registers
    vector<string> fpuRegisters;      // x87 FPU Registers
    vector<string> mmxRegisters;      // MMX Registers
    vector<string> xmmRegisters;      // XMM Registers (SSE)
    vector<string> ymmRegisters;      // YMM Registers (AVX)
    vector<string> zmmRegisters;      // ZMM Registers (AVX-512)

    // Initialize all register categories with their respective registers in constructor

public:
    // Constructor to initialize all registers
    RegisterDescriptorTable() {
        // Initialize General-Purpose Registers (GPR)
        gprRegisters = {
            "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP",  // Original 8
            "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"      // Extended 8
        };
        
        // Initialize Special-Purpose Registers (SPR)
        sprRegisters = {
            "RIP", "RFLAGS", "CS", "DS", "ES", "FS", "GS", "SS"
        };
        
        // Initialize x87 FPU Registers
        fpuRegisters = {
            "ST0", "ST1", "ST2", "ST3", "ST4", "ST5", "ST6", "ST7"
        };
        
        // Initialize MMX Registers
        mmxRegisters = {
            "MM0", "MM1", "MM2", "MM3", "MM4", "MM5", "MM6", "MM7"
        };
        
        // Initialize XMM Registers (SSE)
        xmmRegisters.clear();
        for (int i = 0; i <= 31; i++) {
            xmmRegisters.push_back("XMM" + to_string(i));
        }
        
        // Initialize YMM Registers (AVX)
        ymmRegisters.clear();
        for (int i = 0; i <= 31; i++) {
            ymmRegisters.push_back("YMM" + to_string(i));
        }
        
        // Initialize ZMM Registers (AVX-512)
        zmmRegisters.clear();
        for (int i = 0; i <= 31; i++) {
            zmmRegisters.push_back("ZMM" + to_string(i));
        }
        
        // Initialize all registers as empty (not holding any variable)
        // Add GPRs to registerMap
        for (const string& reg : gprRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add SPRs to registerMap
        for (const string& reg : sprRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add FPU registers to registerMap
        for (const string& reg : fpuRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add MMX registers to registerMap
        for (const string& reg : mmxRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add XMM registers to registerMap
        for (const string& reg : xmmRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add YMM registers to registerMap
        for (const string& reg : ymmRegisters) {
            registerMap[reg] = set<string>();
        }
        
        // Add ZMM registers to registerMap
        for (const string& reg : zmmRegisters) {
            registerMap[reg] = set<string>();
        }
    }
    
    // Get all available GPR registers
    const vector<string>& getGPRRegisters() const {
        return gprRegisters;
    }
    
    // Get all available SPR registers
    const vector<string>& getSPRRegisters() const {
        return sprRegisters;
    }
    
    // Get all available FPU registers
    const vector<string>& getFPURegisters() const {
        return fpuRegisters;
    }
    
    // Get all available MMX registers
    const vector<string>& getMMXRegisters() const {
        return mmxRegisters;
    }
    
    // Get all available XMM registers
    const vector<string>& getXMMRegisters() const {
        return xmmRegisters;
    }
    
    // Get all available YMM registers
    const vector<string>& getYMMRegisters() const {
        return ymmRegisters;
    }
    
    // Get all available ZMM registers
    const vector<string>& getZMMRegisters() const {
        return zmmRegisters;
    }
    
    // Add a variable/temporary to a register
    void addVariableToRegister(const string& reg, const string& var) {
        if (registerMap.find(reg) != registerMap.end()) {
            registerMap[reg].insert(var);
        } else {
            cout << "Warning: Register " << reg << " not found in RDT." << endl;
        }
    }
    
    // Remove a variable/temporary from a register
    void removeVariableFromRegister(const string& reg, const string& var) {
        if (registerMap.find(reg) != registerMap.end()) {
            registerMap[reg].erase(var);
        }
    }
    
    // Remove a variable/temporary from all registers
    void removeVariableFromAllRegisters(const string& var) {
        for (auto& entry : registerMap) {
            entry.second.erase(var);
        }
    }
    
    // Check if a register contains a specific variable/temporary
    bool registerContainsVariable(const string& reg, const string& var) const {
        auto it = registerMap.find(reg);
        if (it != registerMap.end()) {
            return it->second.find(var) != it->second.end();
        }
        return false;
    }
    
    // Get all variables/temporaries in a register
    set<string> getVariablesInRegister(const string& reg) const {
        auto it = registerMap.find(reg);
        if (it != registerMap.end()) {
            return it->second;
        }
        return set<string>();
    }
    
    // Get a free register from a specific category
    string getFreeRegisterFromCategory(const vector<string>& regCategory) const {
        for (const string& reg : regCategory) {
            if (registerMap.at(reg).empty()) {
                return reg;
            }
        }
        return ""; // No free register available
    }
    
    // Get a free GPR register
    string getFreeGPR() const {
        return getFreeRegisterFromCategory(gprRegisters);
    }
    
    // Get a free XMM register
    string getFreeXMM() const {
        return getFreeRegisterFromCategory(xmmRegisters);
    }
    
    // Get register containing a specific variable (returns empty string if not found)
    string getRegisterForVariable(const string& var) const {
        for (const auto& entry : registerMap) {
            if (entry.second.find(var) != entry.second.end()) {
                return entry.first;
            }
        }
        return ""; // Variable not in any register
    }
    
    // Print the Register Descriptor Table for a specific category of registers
    void printRegisterCategory(const string& categoryName, const vector<string>& registers) const {
        cout << "--- " << categoryName << " ---" << endl;
        cout << "Register | Variables/Temporaries" << endl;
        cout << "--------------------------------------" << endl;
        
        for (const string& reg : registers) {
            cout << reg << "\t| ";
            const set<string>& vars = registerMap.at(reg);
            if (vars.empty()) {
                cout << "(empty)";
            } else {
                bool first = true;
                for (const string& var : vars) {
                    if (!first) cout << ", ";
                    cout << var;
                    first = false;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Print the entire Register Descriptor Table
    void printTable() const {
        cout << "======== REGISTER DESCRIPTOR TABLE ========" << endl;
        
        // Print General-Purpose Registers
        printRegisterCategory("General-Purpose Registers", gprRegisters);
        
        // Print Special-Purpose Registers
        printRegisterCategory("Special-Purpose Registers", sprRegisters);
        
        // Print FPU Registers
        printRegisterCategory("x87 FPU Registers", fpuRegisters);
        
        // Print MMX Registers
        printRegisterCategory("MMX Registers", mmxRegisters);
        
        // Print XMM Registers
        printRegisterCategory("XMM Registers (SSE)", xmmRegisters);
        
        // Skip YMM and ZMM registers by default as they're quite numerous
        cout << "(YMM and ZMM registers omitted for brevity)" << endl << endl;
    }
};

// Class for Address Descriptor Table (ADT)
class AddressDescriptorTable {
private:
    // For each variable/temporary, stores:
    // - Set of registers it resides in
    // - Boolean indicating if it's also in memory
    struct LocationInfo {
        set<string> registers;
        bool inMemory;
        
        LocationInfo() : inMemory(true) {} // By default, assume variables start in memory
    };
    
    map<string, LocationInfo> variableMap;

public:
    // Add a variable to the table (initially in memory)
    void addVariable(const string& var) {
        if (variableMap.find(var) == variableMap.end()) {
            variableMap[var] = LocationInfo();
        }
    }
    
    // Add a variable to a register
    void addVariableToRegister(const string& var, const string& reg) {
        addVariable(var); // Ensure variable exists in table
        variableMap[var].registers.insert(reg);
    }
    
    // Remove a variable from a register
    void removeVariableFromRegister(const string& var, const string& reg) {
        if (variableMap.find(var) != variableMap.end()) {
            variableMap[var].registers.erase(reg);
        }
    }
    
    // Set whether a variable is in memory
    void setVariableInMemory(const string& var, bool inMem) {
        addVariable(var); // Ensure variable exists in table
        variableMap[var].inMemory = inMem;
    }
    
    // Check if a variable is in a specific register
    bool isVariableInRegister(const string& var, const string& reg) const {
        auto it = variableMap.find(var);
        if (it != variableMap.end()) {
            return it->second.registers.find(reg) != it->second.registers.end();
        }
        return false;
    }
    
    // Check if a variable is in memory
    bool isVariableInMemory(const string& var) const {
        auto it = variableMap.find(var);
        if (it != variableMap.end()) {
            return it->second.inMemory;
        }
        return false;
    }
    
    // Get all registers containing a variable
    set<string> getRegistersForVariable(const string& var) const {
        auto it = variableMap.find(var);
        if (it != variableMap.end()) {
            return it->second.registers;
        }
        return set<string>();
    }
    
    // Print the Address Descriptor Table
    void printTable() const {
        cout << "======== ADDRESS DESCRIPTOR TABLE ========" << endl;
        cout << "Variable | Location (Registers/Memory)" << endl;
        cout << "--------------------------------------" << endl;
        
        for (const auto& entry : variableMap) {
            cout << entry.first << "\t| ";
            
            // Print registers
            if (entry.second.registers.empty()) {
                cout << "(no registers)";
            } else {
                cout << "Registers: ";
                bool first = true;
                for (const string& reg : entry.second.registers) {
                    if (!first) cout << ", ";
                    cout << reg;
                    first = false;
                }
            }
            
            // Print memory status
            cout << ", Memory: " << (entry.second.inMemory ? "Yes" : "No");
            cout << endl;
        }
        cout << endl;
    }
};

// Function to demonstrate the use of both tables
void demonstrateTables() {
    // Create tables
    RegisterDescriptorTable rdt;
    AddressDescriptorTable adt;
    
    // Add some variables and register assignments
    adt.addVariable("t1");
    adt.addVariable("t2");
    adt.addVariable("t3");
    adt.addVariable("a");
    adt.addVariable("b");
    
    // Assign some variables to registers
    adt.addVariableToRegister("t1", "RAX");
    adt.addVariableToRegister("t2", "RBX");
    adt.addVariableToRegister("a", "RCX");
    adt.addVariableToRegister("a", "RDX"); // a is in two registers
    
    // Update RDT to match
    rdt.addVariableToRegister("RAX", "t1");
    rdt.addVariableToRegister("RBX", "t2");
    rdt.addVariableToRegister("RCX", "a");
    rdt.addVariableToRegister("RDX", "a");
    
    // Mark t3 as not in memory (only in register)
    adt.addVariableToRegister("t3", "RSI");
    adt.setVariableInMemory("t3", false);
    rdt.addVariableToRegister("RSI", "t3");
    
    // Add a floating point variable to an XMM register
    adt.addVariable("f1");
    adt.addVariableToRegister("f1", "XMM0");
    rdt.addVariableToRegister("XMM0", "f1");
    
    // Print tables
    rdt.printTable();
    adt.printTable();
}

// Main function to test the tables
int main() {
    demonstrateTables();
    return 0;
}