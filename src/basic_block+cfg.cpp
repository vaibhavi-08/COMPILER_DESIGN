#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <regex>

using namespace std;

// Class for Three Address Code instruction
class ThreeAddressCode {
private:
    int lineNumber;
    string instruction;

public:
    ThreeAddressCode(int line = 0, const string& instr = "") : lineNumber(line), instruction(instr) {}

    int getLineNumber() const { return lineNumber; }
    string getInstruction() const { return instruction; }
    
    bool isConditional() const {
        return instruction.find("if") != string::npos;
    }
    
    bool isGoto() const {
        return instruction.find("goto") != string::npos && !isConditional();
    }
    
    int getGotoTarget() const {
        regex gotoPattern("goto (\\d+)");
        smatch match;
        if (regex_search(instruction, match, gotoPattern) && match.size() > 1) {
            return stoi(match[1]);
        }
        return -1;
    }
    
    // Get instruction without the goto part
    string getInstructionWithoutGoto() const {
        if (isConditional()) {
            size_t gotoPos = instruction.find("goto");
            if (gotoPos != string::npos) {
                return instruction.substr(0, gotoPos);
            }
        }
        return instruction;
    }
};

// Class for Basic Block
class BasicBlock {
private:
    int id;
    int startLine;
    int endLine;
    vector<ThreeAddressCode> instructions;
    vector<BasicBlock*> successors;

public:
    BasicBlock(int blockId = 0) : id(blockId), startLine(0), endLine(0) {}
    
    void setId(int blockId) { id = blockId; }
    int getId() const { return id; }
    
    void setStartLine(int line) { startLine = line; }
    int getStartLine() const { return startLine; }
    
    void setEndLine(int line) { endLine = line; }
    int getEndLine() const { return endLine; }
    
    void addInstruction(const ThreeAddressCode& tac) {
        instructions.push_back(tac);
    }
    
    const vector<ThreeAddressCode>& getInstructions() const {
        return instructions;
    }
    
    vector<BasicBlock*>& getSuccessors() {
        return successors;
    }
    
    const vector<BasicBlock*>& getSuccessors() const {
        return successors;
    }
    
    void addSuccessor(BasicBlock* block) {
        // Avoid adding duplicate successors
        for (BasicBlock* succ : successors) {
            if (succ == block) return;
        }
        successors.push_back(block);
    }
    
    // Check if the block has meaningful instructions
    bool isEmpty() const {
        return instructions.empty();
    }
    
    // Check if block only contains goto statements
    bool onlyContainsGoto() const {
        for (const ThreeAddressCode& tac : instructions) {
            if (!tac.isGoto()) {
                return false;
            }
        }
        return !instructions.empty();
    }
    
    // Get the last instruction of the block
    const ThreeAddressCode& getLastInstruction() const {
        if (instructions.empty()) {
            static ThreeAddressCode emptyTac;
            return emptyTac;
        }
        return instructions.back();
    }
};

// Function to read 3AC code from file or string
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
    
    // Read 3AC instructions directly
    regex linePattern("\\s*(\\d+):\\s*(.+)");
    smatch match;
    
    while (getline(stream, line)) {
        if (regex_search(line, match, linePattern) && match.size() > 2) {
            ThreeAddressCode tac(stoi(match[1]), match[2]);
            code.push_back(tac);
        }
    }
    
    if (isFile) {
        file.close();
    }
    
    return code;
}

// Function to identify leaders in the 3AC code based on specific conditions
set<int> identifyLeaders(const vector<ThreeAddressCode>& code) {
    set<int> leaders;
    map<int, int> lineToIndex; // Map from line number to index in code vector
    
    // Create mapping from line numbers to indices
    for (size_t i = 0; i < code.size(); i++) {
        lineToIndex[code[i].getLineNumber()] = i;
    }
    
    // Condition 1: First line can be a leader
    if (!code.empty()) {
        leaders.insert(0);
    }
    
    for (size_t i = 0; i < code.size(); i++) {
        const ThreeAddressCode& tac = code[i];
        
        // Condition 2: Any conditional statement is a leader
        if (tac.isConditional()) {
            leaders.insert(i);
        }
        
        // Condition 3: Any target of a goto is a leader
        if (tac.isConditional() || tac.isGoto()) {
            int targetLine = tac.getGotoTarget();
            if (targetLine != -1 && lineToIndex.find(targetLine) != lineToIndex.end()) {
                leaders.insert(lineToIndex[targetLine]);
            }
        }
    }
    
    return leaders;
}




// Function to create basic blocks from leaders
vector<BasicBlock*> createBasicBlocks(const vector<ThreeAddressCode>& code, const set<int>& leaders) {
    vector<BasicBlock*> blocks;
    vector<int> leadersList(leaders.begin(), leaders.end());
    sort(leadersList.begin(), leadersList.end());
    
    int blockId = 0;
    for (size_t i = 0; i < leadersList.size(); i++) {
        BasicBlock* block = new BasicBlock(blockId++);
        int startIdx = leadersList[i];
        block->setStartLine(code[startIdx].getLineNumber());
        
        // Determine end index of this block (exclusive)
        int endIdx;
        if (i < leadersList.size() - 1) {
            endIdx = leadersList[i + 1] - 1;
        } else {
            endIdx = code.size() - 1;
        }
        
        block->setEndLine(code[endIdx].getLineNumber());
        
        // Add instructions to the block
        for (int j = startIdx; j <= endIdx; j++) {
            block->addInstruction(code[j]);
        }
        
        blocks.push_back(block);
    }
    
    return blocks;
}

// Function to determine control flow between basic blocks
void determineControlFlow(vector<BasicBlock*>& blocks, const vector<ThreeAddressCode>& code) {
    map<int, BasicBlock*> lineToBlockMap;
    
    // Create mapping from line numbers to block pointers
    for (BasicBlock* block : blocks) {
        for (const ThreeAddressCode& tac : block->getInstructions()) {
            lineToBlockMap[tac.getLineNumber()] = block;
        }
    }
    
    // Create a special "End of Code" block
    BasicBlock* eocBlock = new BasicBlock(blocks.size());
    eocBlock->setStartLine(-1);  // Special marker for EOC
    eocBlock->setEndLine(-1);    // Special marker for EOC
    blocks.push_back(eocBlock);  // Add to blocks list
    
    // Determine successors for each block
    for (BasicBlock* block : blocks) {
        if (block == eocBlock) continue;  // Skip processing for EOC block
        
        const vector<ThreeAddressCode>& instructions = block->getInstructions();
        
        // Find conditional and goto statements in the block
        for (size_t i = 0; i < instructions.size(); i++) {
            const ThreeAddressCode& instr = instructions[i];
            
            // For conditional statements, add the target block as successor
            if (instr.isConditional()) {
                int targetLine = instr.getGotoTarget();
                if (targetLine != -1) {
                    auto it = lineToBlockMap.find(targetLine);
                    if (it != lineToBlockMap.end()) {
                        block->addSuccessor(it->second);
                    } else {
                        // Target line doesn't exist in code, point to EOC
                        block->addSuccessor(eocBlock);
                    }
                }
                
                // If this conditional is followed by a goto, also add that target
                if (i + 1 < instructions.size() && instructions[i + 1].isGoto()) {
                    int elseTargetLine = instructions[i + 1].getGotoTarget();
                    if (elseTargetLine != -1) {
                        auto it = lineToBlockMap.find(elseTargetLine);
                        if (it != lineToBlockMap.end()) {
                            block->addSuccessor(it->second);
                        } else {
                            // Target line doesn't exist in code, point to EOC
                            block->addSuccessor(eocBlock);
                        }
                    }
                }
            }
            // For unconditional goto (not following a conditional), add the target
            else if (instr.isGoto() && (i == 0 || !instructions[i - 1].isConditional())) {
                int targetLine = instr.getGotoTarget();
                if (targetLine != -1) {
                    auto it = lineToBlockMap.find(targetLine);
                    if (it != lineToBlockMap.end()) {
                        block->addSuccessor(it->second);
                    } else {
                        // Target line doesn't exist in code, point to EOC
                        block->addSuccessor(eocBlock);
                    }
                }
            }
        }
        
        // If block doesn't end with a jump/conditional, fall through to next block
        const ThreeAddressCode& lastInstr = block->getLastInstruction();
        if (!lastInstr.isConditional() && !lastInstr.isGoto()) {
            int currentBlockIdx = -1;
            for (size_t i = 0; i < blocks.size() - 1; i++) {  // -1 to skip EOC block
                if (blocks[i] == block) {
                    currentBlockIdx = i;
                    break;
                }
            }
            
            if (currentBlockIdx != -1 && currentBlockIdx + 1 < (int)blocks.size() - 1) {
                block->addSuccessor(blocks[currentBlockIdx + 1]);
            } else {
                // If this is the last normal block, point to EOC
                block->addSuccessor(eocBlock);
            }
        }
    }
}

// Function to filter blocks that only contain goto statements
vector<BasicBlock*> filterGotoOnlyBlocks(vector<BasicBlock*>& blocks) {
    vector<BasicBlock*> filteredBlocks;
    map<int, int> oldToNewIdMap;
    
    int newId = 0;
    for (size_t i = 0; i < blocks.size(); i++) {
        BasicBlock* block = blocks[i];
        if (!block->onlyContainsGoto()) {
            oldToNewIdMap[block->getId()] = newId;
            block->setId(newId++);
            filteredBlocks.push_back(block);
        } else {
            // For blocks that only contain goto, we need to redirect successors
            for (BasicBlock* otherBlock : blocks) {
                vector<BasicBlock*>& successors = otherBlock->getSuccessors();
                for (size_t j = 0; j < successors.size(); j++) {
                    if (successors[j] == block && !block->getSuccessors().empty()) {
                        // Replace with the target of the goto block
                        successors[j] = block->getSuccessors()[0];
                    }
                }
            }
            delete block;
        }
    }
    
    return filteredBlocks;
}

// Function to print basic blocks and their control flow
void printBasicBlocks(const vector<BasicBlock*>& blocks) {
    cout << "======== BASIC BLOCKS ========" << endl;
    
    for (const BasicBlock* block : blocks) {
        // Skip printing the EOC block itself, but still reference it in successors
        if (block->getStartLine() == -1 && block->getEndLine() == -1) {
            continue;
        }
        
        cout << "Block B" << block->getId() << " (Lines " << block->getStartLine() << "-" << block->getEndLine() << "):" << endl;
        
        for (const ThreeAddressCode& tac : block->getInstructions()) {
            // Skip printing pure goto statements
            if (!tac.isGoto()) {
                if (tac.isConditional()) {
                    // For conditional statements, only print the condition part
                    cout << "  " << tac.getLineNumber() << ": " << tac.getInstructionWithoutGoto() << endl;
                } else {
                    cout << "  " << tac.getLineNumber() << ": " << tac.getInstruction() << endl;
                }
            }
        }
        
        cout << "Successors: ";
        if (block->getSuccessors().empty()) {
            cout << "None (Exit Block)";
        } else {
            for (size_t i = 0; i < block->getSuccessors().size(); i++) {
                if (block->getSuccessors()[i]->getStartLine() == -1) {
                    cout << "EOC";  // End of Code marker
                } else {
                    cout << "B" << block->getSuccessors()[i]->getId();
                }
                if (i < block->getSuccessors().size() - 1) {
                    cout << ", ";
                }
            }
        }
        cout << endl << endl;
    }
}

// Clean up allocated memory
void cleanupBlocks(vector<BasicBlock*>& blocks) {
    for (BasicBlock* block : blocks) {
        delete block;
    }
    blocks.clear();
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
    vector<BasicBlock*> blocks = createBasicBlocks(code, leaders);
    
    // Determine control flow
    determineControlFlow(blocks, code);
    
    // Filter out blocks that only contain goto statements
    vector<BasicBlock*> filteredBlocks = filterGotoOnlyBlocks(blocks);
    
    // Print basic blocks
    printBasicBlocks(filteredBlocks);
    
    // Clean up allocated memory
    cleanupBlocks(filteredBlocks);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // For testing with hardcoded input
        string tacCode = R"(0: t1 : 
   1: arg t2
   2: arg t3
   3: t4=t2+t3
   4: if t4 goto 6
   5: goto 6
   6: t5=t4
   7: t6=t2+t3
   8: if t6 goto 10
   9: goto 10
  10: return t6
  11: t7 : 
  12: t8=9
  13: if t8 goto 15
  14: goto 15
  15: t9=t8
  16: t10=10
  17: if t10 goto 19
  18: goto 19
  19: t11=t10
  20: t12=7
  21: if t12 goto 23
  22: goto 23
  23: t13=t12
  24: t14=2
  25: t15=t13%t14
  26: t16=0
  27: t17=t15==t16
  28: if t17 goto 30
  29: goto 34
  30: t18=t9++
  31: t9=t18
  32: if t9 goto 34
  33: goto 34
  34: t19=t11++
  35: t11=t19
  36: if t11 goto 38
  37: goto 38)";
        
        generateCode(tacCode, false);
    } else {
        string inputFile = argv[1];
        generateCode(inputFile, true);
    }
    
    return 0;
}