#include <cfg.h>
#include <algorithm>
#include <queue>

// ThreeAddressCode class implementation
ThreeAddressCode::ThreeAddressCode(int line, const string& instr) : lineNumber(line), instruction(instr) {}

int ThreeAddressCode::getLineNumber() const { 
    return lineNumber; 
}

string ThreeAddressCode::getInstruction() const { 
    return instruction; 
}

bool ThreeAddressCode::isConditional() const {
    return instruction.find("if") != string::npos;
}

bool ThreeAddressCode::isGoto() const {
    return instruction.find("goto") != string::npos && !isConditional();
}

int ThreeAddressCode::getGotoTarget() const {
    regex gotoPattern("goto (\\d+)");
    smatch match;
    if (regex_search(instruction, match, gotoPattern) && match.size() > 1) {
        return stoi(match[1]);
    }
    return -1;
}

string ThreeAddressCode::getInstructionWithoutGoto() const {
    if (isConditional()) {
        size_t gotoPos = instruction.find("goto");
        if (gotoPos != string::npos) {
            return instruction.substr(0, gotoPos);
        }
    }
    return instruction;
}

void ThreeAddressCode::setNextUse(const string& var, bool isUsed) {
    nextUseMap[var] = isUsed;
}

bool ThreeAddressCode::hasNextUse(const string& var) const {
    auto it = nextUseMap.find(var);
    return (it != nextUseMap.end()) ? it->second : false;
}

const unordered_map<string, bool>& ThreeAddressCode::getNextUseMap() const {
    return nextUseMap;
}

// Extract used variables from the instruction
vector<string> ThreeAddressCode::getUsedVariables() const {
    vector<string> usedVars;
    
    // Helper function to check if a string is a temporary variable (t1, t2, etc. or "main")
    auto isTempVar = [](const string& var) -> bool {
        if (var == "main") return true;
        
        if (var.size() < 2 || var[0] != 't') return false;
        
        // Check if the rest is a number
        for (size_t i = 1; i < var.size(); i++) {
            if (!isdigit(var[i])) return false;
        }
        
        return true;
    };
    
    // Split the instruction by spaces
    istringstream iss(instruction);
    string token;
    vector<string> tokens;
    
    while (iss >> token) {
        // Remove any punctuation at the end (like commas or parentheses)
        while (!token.empty() && !isalnum(token.back()) && token.back() != '_') {
            token.pop_back();
        }
        tokens.push_back(token);
    }
    
    // For conditional statements
    if (isConditional()) {
        // Skip the "if" token and process the remaining tokens
        for (size_t i = 1; i < tokens.size(); i++) {
            // Skip goto and line number in "goto N"
            if (tokens[i] == "goto") {
                i++; // Skip the next token (line number)
                continue;
            }
            
            if (isTempVar(tokens[i])) {
                usedVars.push_back(tokens[i]);
            }
        }
    } 
    // For regular assignments
    else {
        // Find the position of '=' token
        auto equalsPos = find(tokens.begin(), tokens.end(), "=");
        
        if (equalsPos != tokens.end()) {
            // Process tokens after the '=' sign
            for (auto it = equalsPos + 1; it != tokens.end(); ++it) {
                if (isTempVar(*it)) {
                    usedVars.push_back(*it);
                }
            }
        }
    }
    
    return usedVars;
}
// Extract defined variables from the instruction
vector<string> ThreeAddressCode::getDefinedVariables() const {
    vector<string> definedVars;
    
    // Skip if it's a conditional or goto
    if (isConditional() || isGoto()) {
        return definedVars;
    }
    
    // Helper function to check if a string is a temporary variable (t1, t2, etc. or "main")
    auto isTempVar = [](const string& var) -> bool {
        if (var == "main") return true;
        
        if (var.size() < 2 || var[0] != 't') return false;
        
        // Check if the rest is a number
        for (size_t i = 1; i < var.size(); i++) {
            if (!isdigit(var[i])) return false;
        }
        
        return true;
    };
    
    // Split the instruction by spaces
    istringstream iss(instruction);
    string token;
    vector<string> tokens;
    
    while (iss >> token) {
        tokens.push_back(token);
    }
    
    // Find the position of '=' token
    auto equalsIt = find(tokens.begin(), tokens.end(), "=");
    
    if (equalsIt != tokens.end() && equalsIt != tokens.begin()) {
        // The token immediately before '=' is the defined variable
        string potentialVar = *(equalsIt - 1);
        
        // Remove any punctuation
        while (!potentialVar.empty() && !isalnum(potentialVar.back()) && potentialVar.back() != '_') {
            potentialVar.pop_back();
        }
        
        // Check if it's a temporary variable
        if (isTempVar(potentialVar)) {
            definedVars.push_back(potentialVar);
        }
    }
    
    return definedVars;
}

// BasicBlock class implementation
BasicBlock::BasicBlock(int blockId) : id(blockId), startLine(0), endLine(0), visited(false) {}

void BasicBlock::setId(int blockId) { id = blockId; }
int BasicBlock::getId() const { return id; }

void BasicBlock::setStartLine(int line) { startLine = line; }
int BasicBlock::getStartLine() const { return startLine; }

void BasicBlock::setEndLine(int line) { endLine = line; }
int BasicBlock::getEndLine() const { return endLine; }

void BasicBlock::addInstruction(const ThreeAddressCode& tac) {
    instructions.push_back(tac);
}

const vector<ThreeAddressCode>& BasicBlock::getInstructions() const {
    return instructions;
}

vector<ThreeAddressCode>& BasicBlock::getInstructions() {
    return instructions;
}

vector<BasicBlock*>& BasicBlock::getSuccessors() {
    return successors;
}

const vector<BasicBlock*>& BasicBlock::getSuccessors() const {
    return successors;
}

void BasicBlock::addSuccessor(BasicBlock* block) {
    // Avoid adding duplicate successors
    for (BasicBlock* succ : successors) {
        if (succ == block) return;
    }
    successors.push_back(block);
}

bool BasicBlock::isEmpty() const {
    return instructions.empty();
}

bool BasicBlock::onlyContainsGoto() const {
    for (const ThreeAddressCode& tac : instructions) {
        if (!tac.isGoto()) {
            return false;
        }
    }
    return !instructions.empty();
}

const ThreeAddressCode& BasicBlock::getLastInstruction() const {
    if (instructions.empty()) {
        static ThreeAddressCode emptyTac;
        return emptyTac;
    }
    return instructions.back();
}

// Function to read 3AC code from file or string
vector<ThreeAddressCode> read3ACCode(const string& input, bool isFile) {
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

// Function to find the basic block that contains the main function
BasicBlock* findMainBlock(const vector<BasicBlock*>& blocks) {
    // Pattern to look for in the 3AC code that indicates the start of main
    regex mainPattern("\\bmain\\b");
    
    for (BasicBlock* block : blocks) {
        const vector<ThreeAddressCode>& instructions = block->getInstructions();
        
        for (const ThreeAddressCode& tac : instructions) {
            const string& instruction = tac.getInstruction();
            
            // Check if the instruction contains "main"
            if (regex_search(instruction, mainPattern)) {
                return block;
            }
        }
    }
    
    return blocks.empty() ? nullptr : blocks[0];
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

// Function to print basic blocks and their control flow, now including next use info
void printBasicBlocks(const vector<BasicBlock*>& blocks) {
    // Create output file
    ofstream outFile("basic_blocks_info.txt");
    
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file for writing" << endl;
        return;
    }
    
    outFile << "======== BASIC BLOCKS WITH NEXT USE INFO ========" << endl;
    
    for (const BasicBlock* block : blocks) {
        // Skip printing the EOC block itself, but still reference it in successors
        if (block->getStartLine() == -1 && block->getEndLine() == -1) {
            continue;
        }
        
        outFile << "Block B" << block->getId() << " (Lines " << block->getStartLine() << "-" << block->getEndLine() << "):" << endl;
        
        for (const ThreeAddressCode& tac : block->getInstructions()) {
            // Skip printing pure goto statements
                
            outFile << "  " << tac.getLineNumber() << ": " << tac.getInstruction();
            
            // Print next use information
            const auto& nextUseMap = tac.getNextUseMap();
            if (!nextUseMap.empty()) {
                outFile << " [Next Use: ";
                bool first = true;
                for (const auto& pair : nextUseMap) {
                    if (!first) outFile << ", ";
                    outFile << pair.first << ":" << (pair.second ? "true" : "false");
                    first = false;
                }
                outFile << "]";
            }
            outFile << endl;
            
        }
        
        outFile << "Successors: ";
        if (block->getSuccessors().empty()) {
            outFile << "None (Exit Block)";
        } else {
            for (size_t i = 0; i < block->getSuccessors().size(); i++) {
                if (block->getSuccessors()[i]->getStartLine() == -1) {
                    outFile << "EOC";  // End of Code marker
                } else {
                    outFile << "B" << block->getSuccessors()[i]->getId();
                }
                if (i < block->getSuccessors().size() - 1) {
                    outFile << ", ";
                }
            }
        }
        outFile << endl << endl;
    }
    
    outFile.close();
    cout << "Basic blocks information written to basic_blocks_info.txt" << endl;
}

// Clean up allocated memory
void cleanupBlocks(vector<BasicBlock*>& blocks) {
    for (BasicBlock* block : blocks) {
        delete block;
    }
    blocks.clear();
}

// DFS traversal to get blocks in reverse topological order
void dfsTraversal(BasicBlock* block, vector<BasicBlock*>& processOrder) {
    if (!block || block->visited) {
        return;
    }
    
    block->visited = true;
    
    // Visit all successors first
    for (BasicBlock* succ : block->getSuccessors()) {
        dfsTraversal(succ, processOrder);
    }
    
    // After visiting all successors, add this block to process order
    processOrder.push_back(block);
}

// Compute next use information for the entire CFG starting from main block
void computeNextUseInfo(vector<BasicBlock*>& blocks, BasicBlock* mainBlock) {
    if (!mainBlock) {
        cerr << "Main block not found for next-use analysis!" << endl;
        return;
    }
    
    // Reset visited flags
    for (BasicBlock* block : blocks) {
        block->visited = false;
    }
    
    // Get blocks in reverse topological order
    vector<BasicBlock*> processOrder;
    dfsTraversal(mainBlock, processOrder);
    
    // At this point, processOrder contains blocks in reverse topological order
    // (from exit blocks towards entry blocks)
    
    // Process each block
    for (BasicBlock* block : processOrder) {
        // Skip EOC block
        if (block->getStartLine() == -1 && block->getEndLine() == -1) {
            continue;
        }
        
        // Initially, no variables have next use in this block
        unordered_map<string, bool> activeVars;
        
        // Process successors' used variables first
        for (BasicBlock* succ : block->getSuccessors()) {
            // If successor has instructions, check variables used in its first instruction
            if (!succ->getInstructions().empty()) {
                const ThreeAddressCode& firstInstr = succ->getInstructions().front();
                for (const string& var : firstInstr.getUsedVariables()) {
                    activeVars[var] = true;  // This variable is "live" at the end of current block
                }
            }
        }
        
        // Now process this block's instructions in reverse order
        computeNextUseForBlock(block, activeVars);
    }
}

// Compute next use information for a single block
void computeNextUseForBlock(BasicBlock* block, unordered_map<string, bool>& activeVars) {
    // Work backwards through the instructions
    vector<ThreeAddressCode>& instructions = block->getInstructions();
    
    for (auto it = instructions.rbegin(); it != instructions.rend(); ++it) {
        ThreeAddressCode& tac = *it;
        
        // Get variables used in this instruction
        vector<string> usedVars = tac.getUsedVariables();
        
        // Mark each used variable as having a next use here
        for (const string& var : usedVars) {
            tac.setNextUse(var, true);
            activeVars[var] = true;  // This variable is now "live"
        }
        
        // Get variables defined in this instruction
        vector<string> definedVars = tac.getDefinedVariables();
        
        // For each defined variable, check if it has a next use
        for (const string& var : definedVars) {
            auto it = activeVars.find(var);
            bool hasNextUse = (it != activeVars.end()) && it->second;
            tac.setNextUse(var, hasNextUse);
            
            // If this is a definition without next use, mark it as "dead" after this point
            if (!hasNextUse) {
                activeVars.erase(var);
            }
        }
        
        // For all other active variables, mark their next use as true
        for (const auto& pair : activeVars) {
            if (pair.second) {
                tac.setNextUse(pair.first, true);
            }
        }
    }
}

// Main function to generate code from 3AC
BasicBlock* generateCode(const string& input, bool isFile) {
    // Read 3AC code
    vector<ThreeAddressCode> code = read3ACCode(input, isFile);
    
    if (code.empty()) {
        cerr << "No valid 3AC code found!" << endl;
        return nullptr;
    }
    
    // Identify leaders
    set<int> leaders = identifyLeaders(code);
    
    // Create basic blocks
    vector<BasicBlock*> blocks = createBasicBlocks(code, leaders);
    
    // Determine control flow
    determineControlFlow(blocks, code);
    
    // Filter out blocks that only contain goto statements
    vector<BasicBlock*> filteredBlocks = filterGotoOnlyBlocks(blocks);
    
    // Find the main block
    BasicBlock* mainBlock = findMainBlock(filteredBlocks);
    
    if (mainBlock) {
        cout << "======== MAIN FUNCTION BLOCK ========" << endl;
        cout << "Found main function in Block B" << mainBlock->getId() << endl;
        cout << "Main block lines: " << mainBlock->getStartLine() << "-" << mainBlock->getEndLine() << endl << endl;
        
        // Compute next use information
        computeNextUseInfo(filteredBlocks, mainBlock);
    } else {
        cout << "No main function found in the code!" << endl;
    }
    for(BasicBlock* i:filteredBlocks){
        i->visited=false;
    }
    // Print basic blocks with next use info
    printBasicBlocks(filteredBlocks);
    
    return mainBlock;
}