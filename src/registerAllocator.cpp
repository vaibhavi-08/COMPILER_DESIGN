// RegisterAllocator.cpp
#include <registerAllocator.h>
#include <tac.h>

RegisterAllocator::RegisterAllocator(const std::vector<std::string>& availableRegisters) : registers(availableRegisters) {
    // Initialize register descriptor table
    crbp=0;
    for (const auto& reg : registers) {
        registerDescriptor[reg] = std::unordered_set<std::string>();
    }
}

void RegisterAllocator::addVariable(const std::string& variable) {
    if(addressDescriptor.find(variable)==addressDescriptor.end()){
        if(temp_and_type.find(variable)!=temp_and_type.end()&&temp_and_type[variable]->isreal_var){
            if(temp_and_type[variable]->size==4){
                crbp+=4;
                cout << "adding this variable " << variable << "with size 4" << endl;
                addressDescriptor[variable] = {true, "DWORD PTR [rbp-"+to_string(crbp)+"]", {}};
            }
            else if(temp_and_type[variable]->size==8){
                crbp+=8;
                addressDescriptor[variable] = {true, "QWORD PTR [rbp-"+to_string(crbp)+"]", {}};
            }
            else if(temp_and_type[variable]->size==1){
                crbp+=1;
                addressDescriptor[variable] = {true, "BYTE PTR [rbp-"+to_string(crbp)+"]", {}};
            }
            else{
                crbp+=2;
                addressDescriptor[variable] = {true, "WORD PTR [rbp-"+to_string(crbp)+"]", {}};
            }
        }
        else addressDescriptor[variable]={false,"",{}};
            
    }
        
}

void RegisterAllocator::updateNextUse(const std::unordered_map<std::string, bool>& useInfo) {
    nextUse = useInfo;
}

std::string RegisterAllocator::loadToRegister(const std::string& variable, const std::string& reg) {
    // Update address descriptor
    addressDescriptor[variable].registers.insert(reg);
    
    // Update register descriptor
    registerDescriptor[reg].insert(variable);
    
    return reg;
}

std::string RegisterAllocator::selectRegister(const std::unordered_set<std::string>& avoid) {
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

RegAllocResult RegisterAllocator::getLocationForVar(
    const std::string& variable, 
    bool preferRegister,
    const std::unordered_set<std::string>& avoidRegs
) {
    // If variable doesn't exist, add it with a default memory location
    if (addressDescriptor.find(variable) == addressDescriptor.end()) {
        cout << "got here for " << variable << endl;
        addVariable(variable);
    }
    cout << " added " << variable << endl;
    const auto& locations = addressDescriptor[variable];
    cout << "accessed " << variable << endl;
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
        cout << "select register done" << endl;
        bool needsSpill = !registerDescriptor[selectedReg].empty();
        
        return {selectedReg, true, needsSpill};
    }
    
    // Default: return memory location
    return {locations.memoryLocation, false, false};
}

std::unordered_map<std::string, RegAllocResult> RegisterAllocator::getRegisters(
    const std::vector<std::pair<std::string, bool>>& operands,
    const std::unordered_map<std::string, bool>& nextUseInfo
) {
    // Update next use information
    updateNextUse(nextUseInfo);
    cout << "next use info updated" << endl;
    std::unordered_map<std::string, RegAllocResult> result;
    std::unordered_set<std::string> allocatedRegs;
    cout << "next use :" << endl;
    for(auto i : nextUse){
        cout << i.first << " " << i.second << endl;
    }
    // Process each operand
    for (const auto& [var, needsReg] : operands) {
        // Get location for this variable
        cout <<  var << " >> " << needsReg << endl;
        RegAllocResult location = getLocationForVar(var, needsReg, allocatedRegs);
        cout << "get location done" << endl;
        result[var] = location;
        
        // Add to allocated registers if it's a register
        if (location.isRegister) {
            allocatedRegs.insert(location.location);
        }
    }
    
    return result;
}

void RegisterAllocator::printState() {
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

void RegisterAllocator::spillRegister(const std::string& reg) {
    // This should be implemented by the caller as mentioned in requirements
    std::cout << "Need to spill register: " << reg << std::endl;
}