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
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ThreeAddressCode {
private:
    int lineNumber;
    string instruction;
    unordered_map<string, bool> nextUseMap; // Next use information for variables

public:
    ThreeAddressCode(int line = 0, const string& instr = "");
    
    int getLineNumber() const;
    string getInstruction() const;
    bool isConditional() const;
    bool isGoto() const;
    int getGotoTarget() const;
    string getInstructionWithoutGoto() const;
    
    // Next use related functions
    void setNextUse(const string& var, bool isUsed);
    bool hasNextUse(const string& var) const;
    const unordered_map<string, bool>& getNextUseMap() const;
    
    // Variable tracking functions
    vector<string> getUsedVariables() const;
    vector<string> getDefinedVariables() const;
};

// Class for Basic Block
class BasicBlock {
public:
    int id;
    int startLine;
    int endLine;
    vector<ThreeAddressCode> instructions;
    vector<BasicBlock*> successors;
    bool visited; // For graph traversal

public:
    BasicBlock(int blockId=0);
    
    void setId(int blockId);
    int getId() const;
    
    void setStartLine(int line);
    int getStartLine() const;
    
    void setEndLine(int line);
    int getEndLine() const;
    
    void addInstruction(const ThreeAddressCode& tac);
    
    const vector<ThreeAddressCode>& getInstructions() const;
    vector<ThreeAddressCode>& getInstructions();
    
    vector<BasicBlock*>& getSuccessors();
    const vector<BasicBlock*>& getSuccessors() const;
    
    void addSuccessor(BasicBlock* block);
    
    bool isEmpty() const;
    bool onlyContainsGoto() const;
    const ThreeAddressCode& getLastInstruction() const;
};

// Function declarations
vector<vector<ThreeAddressCode>> read3ACCode(const string& input, bool isFile = false);
set<int> identifyLeaders(const vector<ThreeAddressCode>& code);
vector<BasicBlock*> createBasicBlocks(const vector<ThreeAddressCode>& code, const set<int>& leaders,int& blockId);
void determineControlFlow(vector<BasicBlock*>& blocks, const vector<ThreeAddressCode>& code);
vector<BasicBlock*> filterGotoOnlyBlocks(vector<BasicBlock*>& blocks);
void printBasicBlocks(const vector<BasicBlock*>& blocks,ofstream& outFile);
void cleanupBlocks(vector<BasicBlock*>& blocks);
BasicBlock* findMainBlock(const vector<BasicBlock*>& blocks);
vector<BasicBlock*> generateCode(const string& input, bool isFile = false);

// New functions for next-use analysis
void computeNextUseInfo(vector<BasicBlock*>& blocks, BasicBlock* mainBlock);
void computeNextUseForBlock(BasicBlock* block, unordered_map<string, bool>& activeVars);
void printNextUseInfo(const vector<BasicBlock*>& blocks);
void dfsTraversal(BasicBlock* block, vector<BasicBlock*>& processOrder);

#endif // THREE_ADDRESS_UTILS_H