#ifndef THREE_ADDRESS_UTILS_H
#define THREE_ADDRESS_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <regex>

using namespace std;

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
public:
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


// Function declarations
vector<ThreeAddressCode> read3ACCode(const string& input, bool isFile = false);
set<int> identifyLeaders(const vector<ThreeAddressCode>& code);
vector<BasicBlock*> createBasicBlocks(const vector<ThreeAddressCode>& code, const set<int>& leaders);
void determineControlFlow(vector<BasicBlock*>& blocks, const vector<ThreeAddressCode>& code);
vector<BasicBlock*> filterGotoOnlyBlocks(vector<BasicBlock*>& blocks);
void printBasicBlocks(const vector<BasicBlock*>& blocks);
void cleanupBlocks(vector<BasicBlock*>& blocks);
BasicBlock* findMainBlock(const vector<BasicBlock*>& blocks);
BasicBlock* generateCode(const string& input, bool isFile = false);

#endif // THREE_ADDRESS_UTILS_H
