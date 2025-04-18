#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <unordered_map>
#include <regex>

using namespace std;

// Structure to represent a Three Address Code instruction
struct ThreeAddressCode {
    int lineNumber;
    string instruction;
};

// Structure to represent a basic block
struct BasicBlock {
    int id;
    int startLine;
    int endLine;
    vector<ThreeAddressCode> instructions;
    vector<int> successors;
};

struct RegisterDescriptor {
    string name;        // Register name (eax, ebx, etc.)
    bool isFree;        // Whether register is free
    vector<string> variables;  // Variables currently held in this register
};

// Address Descriptor: Keeps track of the location of each variable
struct AddressDescriptor {
    string name;        // Variable name
    bool inMemory;      // Whether variable is in memory
    string registerName; // Register holding the variable (if any)
    int memoryOffset;   // Memory offset for the variable
};

// Function to identify if an instruction is a jump/branch instruction
bool isJumpInstruction(const string& instruction) {
    return (instruction.find("goto") != string::npos || 
            instruction.find("if") != string::npos);
}

// Function to extract target line of a goto instruction
int extractGotoTarget(const string& instruction) {
    regex gotoPattern("goto (\\d+)");
    smatch match;
    if (regex_search(instruction, match, gotoPattern) && match.size() > 1) {
        return stoi(match[1]);
    }
    return -1;
}

// Function to extract target line of an if condition
int extractIfTarget(const string& instruction) {
    regex ifPattern("if .+ goto (\\d+)");
    smatch match;
    if (regex_search(instruction, match, ifPattern) && match.size() > 1) {
        return stoi(match[1]);
    }
    return -1;
}

// Function to read 3AC code from file or string
// Updated function to read 3AC code from file or string
vector<ThreeAddressCode> read3ACCode(const string& input, bool isFile = false) {
    vector<ThreeAddressCode> code;
    istringstream iss;
    ifstream file;
    
    if (isFile) {
        file.open(input);
        if (!file.is_open()) {
            cerr << "Error opening file: " << input << endl;
            return code;
        }
    } else {
        iss.str(input);
    }
    
    istream& stream = isFile ? static_cast<istream&>(file) : static_cast<istream&>(iss);
    string line;
    
    // Read 3AC instructions directly, without looking for a header
    regex linePattern("\\s*(\\d+):\\s*(.+)");
    smatch match;
    
    while (getline(stream, line)) {
        if (regex_search(line, match, linePattern) && match.size() > 2) {
            ThreeAddressCode tac;
            tac.lineNumber = stoi(match[1]);
            tac.instruction = match[2];
            code.push_back(tac);
        }
    }
    
    if (isFile) {
        file.close();
    }
    
    return code;
}

// Function to identify leaders in the 3AC code
set<int> identifyLeaders(const vector<ThreeAddressCode>& code) {
    set<int> leaders;
    
    // Rule 1: First statement is a leader
    if (!code.empty()) {
        leaders.insert(0);
    }
    
    for (size_t i = 0; i < code.size(); i++) {
        const ThreeAddressCode& tac = code[i];
        
        // Rule 2: Extract goto targets and mark them as leaders
        if (tac.instruction.find("goto") != string::npos) {
            int target = -1;
            
            // Check if it's a conditional jump (if)
            if (tac.instruction.find("if") != string::npos) {
                target = extractIfTarget(tac.instruction);
            } else {
                target = extractGotoTarget(tac.instruction);
            }
            
            if (target != -1) {
                // Find the index corresponding to the target line number
                for (size_t j = 0; j < code.size(); j++) {
                    if (code[j].lineNumber == target) {
                        leaders.insert(j);
                        break;
                    }
                }
            }
            
            // Rule 3: Statement following a jump is a leader
            if (i + 1 < code.size()) {
                leaders.insert(i + 1);
            }
        }
    }
    
    return leaders;
}

// Function to create basic blocks from leaders
vector<BasicBlock> createBasicBlocks(const vector<ThreeAddressCode>& code, const set<int>& leaders) {
    vector<BasicBlock> blocks;
    vector<int> leadersList(leaders.begin(), leaders.end());
    sort(leadersList.begin(), leadersList.end());
    
    for (size_t i = 0; i < leadersList.size(); i++) {
        BasicBlock block;
        block.id = i;
        int startIdx = leadersList[i];
        block.startLine = code[startIdx].lineNumber;
        
        // Determine end index of this block
        int endIdx;
        if (i < leadersList.size() - 1) {
            endIdx = leadersList[i + 1] - 1;
        } else {
            endIdx = code.size() - 1;
        }
        
        block.endLine = code[endIdx].lineNumber;
        
        // Add instructions to the block
        for (int j = startIdx; j <= endIdx; j++) {
            block.instructions.push_back(code[j]);
        }
        
        blocks.push_back(block);
    }
    
    return blocks;
}

// Function to determine control flow between basic blocks
void determineControlFlow(vector<BasicBlock>& blocks, const vector<ThreeAddressCode>& code) {
    map<int, int> lineToBlockMap;
    
    // Create mapping from line numbers to block IDs
    for (const BasicBlock& block : blocks) {
        for (const ThreeAddressCode& tac : block.instructions) {
            lineToBlockMap[tac.lineNumber] = block.id;
        }
    }
    
    // Determine successors for each block
    for (BasicBlock& block : blocks) {
        const ThreeAddressCode& lastInstr = block.instructions.back();
        
        // If last instruction is a conditional jump
        if (lastInstr.instruction.find("if") != string::npos) {
            int target = extractIfTarget(lastInstr.instruction);
            
            // Add target block as successor
            for (const BasicBlock& targetBlock : blocks) {
                if (targetBlock.startLine == target) {
                    block.successors.push_back(targetBlock.id);
                    break;
                }
            }
            
            // Add fallthrough block as successor if it exists
            int currentBlockIdx = block.id;
            if (currentBlockIdx + 1 < (int)blocks.size()) {
                block.successors.push_back(currentBlockIdx + 1);
            }
        }
        // If last instruction is an unconditional jump
        else if (lastInstr.instruction.find("goto") != string::npos) {
            int target = extractGotoTarget(lastInstr.instruction);
            
            // Add target block as successor
            for (const BasicBlock& targetBlock : blocks) {
                if (targetBlock.startLine == target) {
                    block.successors.push_back(targetBlock.id);
                    break;
                }
            }
        }
        // If last instruction is not a jump, fall through to next block
        else {
            int currentBlockIdx = block.id;
            if (currentBlockIdx + 1 < (int)blocks.size()) {
                block.successors.push_back(currentBlockIdx + 1);
            }
        }
    }
}

// Function to print basic blocks and their control flow
void printBasicBlocks(const vector<BasicBlock>& blocks) {
    cout << "======== BASIC BLOCKS ========" << endl;
    
    for (const BasicBlock& block : blocks) {
        cout << "Block B" << block.id << " (Lines " << block.startLine << "-" << block.endLine << "):" << endl;
        
        for (const ThreeAddressCode& tac : block.instructions) {
            cout << "  " << tac.lineNumber << ": " << tac.instruction << endl;
        }
        
        cout << "Successors: ";
        if (block.successors.empty()) {
            cout << "None (Exit Block)";
        } else {
            for (size_t i = 0; i < block.successors.size(); i++) {
                cout << "B" << block.successors[i];
                if (i < block.successors.size() - 1) {
                    cout << ", ";
                }
            }
        }
        cout << endl << endl;
    }
}

// Function to initialize register descriptor
unordered_map<string, RegisterDescriptor> initRegisterDescriptor() {
    unordered_map<string, RegisterDescriptor> regDesc;
    
    // General purpose registers in x86
    vector<string> regNames = {"eax", "ebx", "ecx", "edx", "esi", "edi"};
    
    for (const string& name : regNames) {
        RegisterDescriptor reg;
        reg.name = name;
        reg.isFree = true;
        regDesc[name] = reg;
    }
    
    return regDesc;
}

// Main function to generate code from 3AC
void generateCode(const string& input, bool isFile = false) {
    // Read 3AC code
    vector<ThreeAddressCode> code = read3ACCode(input, isFile);
    
    if (code.empty()) {
        cerr << "No valid 3AC code found!" << endl;
        return;
    }
    
    // Identify leaders
    set<int> leaders = identifyLeaders(code);
    
    // Create basic blocks
    vector<BasicBlock> blocks = createBasicBlocks(code, leaders);
    
    // Determine control flow
    determineControlFlow(blocks, code);
    
    // Print basic blocks
    printBasicBlocks(blocks);
    
    // Code generation would continue here...
    // For example, you might generate assembly code for each basic block
}

// Function to initialize address descriptor from the 3AC code
unordered_map<string, AddressDescriptor> initAddressDescriptor(const vector<ThreeAddressCode>& code) {
    unordered_map<string, AddressDescriptor> addrDesc;
    set<string> variables;
    
    // Extract all variable names from the 3AC code
    for (const ThreeAddressCode& tac : code) {
        string instr = tac.instruction;
        
        // Skip labels and control statements
        if (instr.find(":") != string::npos) continue;
        if (instr.find("goto") != string::npos && instr.find("if") == string::npos) continue;
        
        // Extract all temp variables (t1, t2, etc.) using regex
        regex varPattern("t[0-9]+");
        sregex_iterator it(instr.begin(), instr.end(), varPattern);
        sregex_iterator end;
        
        while (it != end) {
            string var = it->str();
            variables.insert(var);
            ++it;
        }
    }
    
    // Initialize address descriptor for each variable
    int offset = 0;
    for (const string& var : variables) {
        AddressDescriptor addr;
        addr.name = var;
        addr.inMemory = true;       // Start with all variables in memory
        addr.registerName = "";     // No register initially
        addr.memoryOffset = offset; // Assign a memory offset
        addrDesc[var] = addr;
        offset += 4;  // Assuming 4-byte variables (integers)
    }
    
    return addrDesc;
}

// Function to print register and address descriptor tables to a file
void printDescriptorTables(const unordered_map<string, RegisterDescriptor>& regDesc, 
    const unordered_map<string, AddressDescriptor>& addrDesc,
    const string& outputFile) {
ofstream outFile(outputFile);
if (!outFile.is_open()) {
cerr << "Error: Unable to open output file: " << outputFile << endl;
return;
}

// Print Register Descriptor Table
outFile << "====================== REGISTER DESCRIPTOR TABLE ======================\n";
outFile << "Register\tFree?\tVariables\n";
outFile << "----------------------------------------------------------------\n";

for (const auto& entry : regDesc) {
const RegisterDescriptor& reg = entry.second;
outFile << reg.name << "\t\t" << (reg.isFree ? "Yes" : "No") << "\t";

if (!reg.variables.empty()) {
for (size_t i = 0; i < reg.variables.size(); i++) {
outFile << reg.variables[i];
if (i < reg.variables.size() - 1) {
outFile << ", ";
}
}
} else {
outFile << "None";
}
outFile << "\n";
}

// Print Address Descriptor Table
outFile << "\n====================== ADDRESS DESCRIPTOR TABLE ======================\n";
outFile << "Variable\tIn Memory?\tRegister\tMemory Offset\n";
outFile << "----------------------------------------------------------------\n";

for (const auto& entry : addrDesc) {
const AddressDescriptor& addr = entry.second;
outFile << addr.name << "\t\t" << (addr.inMemory ? "Yes" : "No") << "\t\t";

if (!addr.registerName.empty()) {
outFile << addr.registerName;
} else {
outFile << "None";
}

outFile << "\t\t" << addr.memoryOffset << "\n";
}

outFile.close();
cout << "Descriptor tables written to " << outputFile << endl;
}


// Add this function to your main to generate and print the tables
void generateDescriptorTables(const vector<ThreeAddressCode>& code, const string& outputFile) {
    // Initialize register and address descriptors
    unordered_map<string, RegisterDescriptor> regDesc = initRegisterDescriptor();
    unordered_map<string, AddressDescriptor> addrDesc = initAddressDescriptor(code);
    
    // Print descriptor tables
    printDescriptorTables(regDesc, addrDesc, outputFile);
}

// Update main function to include descriptor table generation
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [output_file]" << endl;
        return 1;
    }
    
    string inputFile = argv[1];
    string outputFile = (argc > 2) ? argv[2] : "descriptor_tables.txt";
    
    // Read 3AC code
    vector<ThreeAddressCode> code = read3ACCode(inputFile, true);
    
    if (code.empty()) {
        cerr << "No valid 3AC code found!" << endl;
        return 1;
    }
    
    // Identify leaders
    set<int> leaders = identifyLeaders(code);
    
    // Create basic blocks
    vector<BasicBlock> blocks = createBasicBlocks(code, leaders);
    
    // Determine control flow
    determineControlFlow(blocks, code);
    
    // Print basic blocks
    printBasicBlocks(blocks);
    
    // Generate and print descriptor tables
    generateDescriptorTables(code, outputFile);
    
    return 0;
}