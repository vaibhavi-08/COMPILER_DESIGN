#include<bits/stdc++.h>
#include <cfg.h>
#include <registerAllocator.h>
#include <selinst.h>
#include<tac.h>
#include <classes_NT.h>
#include <tac.h>
#include "symtab_print.h"
using namespace std;
extern char yytext[];
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
// Define the global variables here
bool iserror = false;
vector<pair<string, int>> error;
unordered_map<string, string> symtab;
vector<string> program;
vector<string> x86_regs = {
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
void parseCondition(const string& line,string &op1,string&op2,string& opr) {
    //string op1 = "", op2 = "", opr = "";
    
    // Remove "if " prefix and split before "goto"
    size_t ifPos = line.find("if ");
    size_t gotoPos = line.find("goto");

    if (ifPos == string::npos || gotoPos == string::npos) {
        cout << "Invalid format" << endl;
        return;
    }

    string condition = line.substr(ifPos + 3, gotoPos - (ifPos + 3));
    istringstream iss(condition);
    string token1, token2, token3;

    iss >> token1;
    if (iss >> token2) {
        // There is a second token, so it's a comparison
        iss >> token3;
        op1 = token1;
        opr = token2;
        op2 = token3;
    } else {
        // Only one token after "if"
        op1 = token1;
    }

    //cout << "op1 = \"" << op1 << "\", op2 = \"" << op2 << "\", opr = \"" << opr << "\"" << endl;
}
bool isLabelStatement(const string& line) {
    size_t len = line.length();
    //cout << len << endl;
    // Minimum format should be like "a :" => length >= 3
    if (len < 4) return false;

    // Must end with " :" (space then colon)
    if (line[len - 3] == ' ' && line[len - 2] == ':') {
        return true;
    }

    return false;
}

// Extract the label from a valid label statement
string getLabel(const string& line) {
    // Just return everything except the last 2 characters (" :")
    return line.substr(0, line.length() - 2);
}
vector<string> splitBySpace(const string& line) {
    stringstream ss(line);
    string word;
    vector<string> tokens;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

// Check if it's a "t1 = t2" type of statement
bool isSimpleAssignment(const string& line) {
    vector<string> tokens = splitBySpace(line);
    return (tokens.size() == 3 && tokens[1] == "=");
}

// Extract op1 and op2 from a valid assignment
void getOperandsAssignment(const string& line, string& op1, string& op2) {
    vector<string> tokens = splitBySpace(line);
    op1 = tokens[0];
    op2 = tokens[2];
}
void getOperandsCAssign(const std::string& instruction, std::string& operand1, 
                      std::string& operand2, std::string& op, std::string& operand3) {
    
    std::istringstream iss(instruction);
    
    // Parse tokens directly without validation
    // Format: operand1 = operand2 op operand3
    iss >> operand1;        // First operand
    std::string equals;
    iss >> equals;          // Skip the '=' sign
    iss >> operand2;        // Second operand
    iss >> op;              // The operator
    iss >> operand3;        // Third operand
}
bool isAssignWithOp(const std::string& instruction) {
    // Check if string is empty
    if (instruction.empty()) {
        return false;
    }
    
    std::istringstream iss(instruction);
    std::string firstOp, assignOp, secondOp, thirdOp;
    std::string op;
    
    // Expected format: firstOp assignOp secondOp op thirdOp
    // Example: "t10 = t8 & t9"
    
    // Try to extract the expected parts
    if (!(iss >> firstOp >> assignOp >> secondOp)) {
        return false; // Not enough tokens
    }
    
    // Check if the second token is an assignment operator
    if (assignOp != "=") {
        return false;
    }
    
    // Try to get the operator and third operand
    if (!(iss >> op >> thirdOp)) {
        return false; // Missing operator or third operand
    }
    
    // Make sure there's nothing extra
    std::string extra;
    if (iss >> extra) {
        return false; // Extra tokens found
    }
    
    return true;
}
vector<string> asmcode;
void dfs(BasicBlock* curb, RegisterAllocator& allocator) {
    curb->visited = true;
    cout << " dfs runned" << endl;
    
    if(curb->getStartLine() == -1) {
        string s = ".end :";
        asmcode.push_back(s);
        return;
    }
    
    string stl = ".B" + to_string(curb->id) + ":";
    asmcode.push_back(stl);
    
    // just an if statement
    if(curb->instructions.size() == 2 && curb->instructions[0].isConditional() && curb->instructions[1].isGoto()) {
        //get the condition
        string op1 = ""; //first operand
        string op2 = ""; //second operand
        string opr = ""; //operator
        parseCondition(curb->instructions[0].getInstruction(), op1, op2, opr);
        
        if(temp_and_type[op1]->isreal_var) {
            allocator.addVariable(op1);
        }
        
        if(!op2.empty() && temp_and_type[op2]->isreal_var) {
            allocator.addVariable(op2);
        }
        
        if(op2.empty() && opr.empty()) { //if ti goto x case
            vector<pair<string, bool>> tr;
            tr.emplace_back(op1, !temp_and_type[op1]->isreal_var);
            auto z = allocator.getRegisters(tr, curb->instructions[0].getNextUseMap());
            
            if(!z[op1].needsSpill) {
                asmcode.push_back("cmp " + z[op1].location + " , 0");
                
                if(curb->successors.size() == 1) {
                    string jmpl;
                    if(curb->successors[0]->getStartLine() != -1) 
                        jmpl = ".B" + to_string(curb->successors[0]->getId());
                    else 
                        jmpl = ".end";
                    asmcode.push_back("jmp " + jmpl);
                }
                else if(curb->successors.size() == 2) {
                    string jumpl;
                    if(curb->successors[0]->getStartLine() != -1) 
                        jumpl = ".B" + to_string(curb->successors[0]->getId());
                    else 
                        jumpl = ".end";
                    
                    string jel;
                    if(curb->successors[1]->getStartLine() != -1) 
                        jel = ".B" + to_string(curb->successors[1]->getId());
                    else 
                        jel = ".end";
                    
                    asmcode.push_back("je " + jel);
                    asmcode.push_back("jmp " + jumpl);
                }
                else {
                    cout << "no more than 2 successors possible for B" << curb->getId() << endl;
                    exit(1);
                }
            }
            else {
                cout << "error " << op1 << " should not need spill" << endl;
                exit(1);
            }
        }
        else {
            vector<pair<string, bool>> tr;
            tr.emplace_back(op1, !temp_and_type[op1]->isreal_var);
            tr.emplace_back(op2, !temp_and_type[op2]->isreal_var);
            auto z = allocator.getRegisters(tr, curb->instructions[0].getNextUseMap());
            
            string op1l = z[op1].location;
            if(!z[op1].isRegister && !z[op2].isRegister) {
                vector<pair<string, bool>> ntr;
                ntr.emplace_back(op1, true);
                //handle spilling
                auto nz = allocator.getRegisters(ntr, curb->instructions[0].getNextUseMap());
                asmcode.push_back("mov " + nz[op1].location + " , " + z[op1].location);
                op1l = nz[op1].location;
            }
            
            asmcode.push_back("cmp " + op1l + " , " + z[op2].location);
            asmcode.push_back("sete al");
            
            vector<pair<string, bool>> ctr;
            ctr.emplace_back("xx", true);
            //handle spilling
            auto cz = allocator.getRegisters(ctr, curb->instructions[0].getNextUseMap());
            asmcode.push_back("movzx " + cz["xx"].location + " , al");
            asmcode.push_back("cmp " + cz["xx"].location + " , 0");
            
            if(curb->successors.size() == 1) {
                string jmpl;
                if(curb->successors[0]->getStartLine() != -1) 
                    jmpl = ".B" + to_string(curb->successors[0]->getId());
                else 
                    jmpl = ".end";
                asmcode.push_back("jmp " + jmpl);
            }
            else if(curb->successors.size() == 2) {
                string jumpl;
                if(curb->successors[0]->getStartLine() != -1) 
                    jumpl = ".B" + to_string(curb->successors[0]->getId());
                else 
                    jumpl = ".end";
                
                string jel;
                if(curb->successors[1]->getStartLine() != -1) 
                    jel = ".B" + to_string(curb->successors[1]->getId());
                else 
                    jel = ".end";
                
                asmcode.push_back("je " + jel);
                asmcode.push_back("jmp " + jumpl);
            }
            else {
                cout << "no more than 2 successors possible for B" << curb->getId() << endl;
                exit(1);
            }
        }
    }
    //for spilling you need to study the space allocation thing for functions
    else {
        for(ThreeAddressCode tac : curb->instructions) {
            string instr = tac.getInstruction();
            cout << instr << endl;
            
            //check if label
            if(isLabelStatement(instr)) {
                string label = getLabel(instr);
                asmcode.push_back(label + ":");
                asmcode.push_back("push rbp");
                asmcode.push_back("mov rbp , rsp");
            }
            //if it is an assignment statement simple
            else if(isSimpleAssignment(instr)) {
                string op1 = "", op2 = "";
                getOperandsAssignment(instr, op1, op2);
                
                if(temp_and_type[op1]->isreal_var) {
                    allocator.addVariable(op1);
                }
                
                vector<pair<string, bool>> tr;
                tr.emplace_back(op1, !temp_and_type[op1]->isreal_var);
                
                if(!op2.empty() && op2[0] == 't') {
                    tr.emplace_back(op2, !temp_and_type[op2]->isreal_var);
                    if(temp_and_type[op2]->isreal_var) {
                        allocator.addVariable(op2);
                    }
                }
                
                auto z = allocator.getRegisters(tr, tac.getNextUseMap());
                string op1l = z[op1].location;
                
                if(!z[op1].isRegister && !z[op2].isRegister) {
                    vector<pair<string, bool>> ntr;
                    ntr.emplace_back(op1, true);
                    //handle spilling
                    auto nz = allocator.getRegisters(ntr, curb->instructions[0].getNextUseMap());
                    asmcode.push_back("mov " + nz[op1].location + " , " + z[op1].location);
                    op1l = nz[op1].location;
                }
                
                //handle spilling if register
                if(!op2.empty() && op2[0] == 't')
                    asmcode.push_back("mov " + op1l + " , " + z[op2].location);
                else
                    asmcode.push_back("mov " + op1l + " , " + op2);
            }
            // if it is a= b op c type
            else if(isAssignWithOp(instr)) {
                string op1 = "", op2 = "", result = "", opr = "";
                //call that function
                getOperandsCAssign(instr, result, op1, opr, op2);
                cout << result << " " << op1 << " " << opr << " " << op2 << endl;
                
                if(temp_and_type[op1]->isreal_var) {
                    allocator.addVariable(op1);
                }
                if(temp_and_type[op2]->isreal_var) {
                    allocator.addVariable(op2);
                }
                if(temp_and_type[result]->isreal_var) {
                    allocator.addVariable(result);
                }
                
                cout << "add variables done " << endl;
                
                vector<pair<string, bool>> tr;
                tr.emplace_back(op1, !temp_and_type[op1]->isreal_var);
                tr.emplace_back(op2, !temp_and_type[op2]->isreal_var);
                tr.emplace_back(result, !temp_and_type[result]->isreal_var);
                tr.emplace_back("xx", true);
                
                cout << "pushed vars" << endl;
                auto z = allocator.getRegisters(tr, tac.getNextUseMap());
                cout << "got z" << endl;
                
                //handle spilling above
                asmcode.push_back("mov " + z["xx"].location + " , " + z[op1].location);
                
                if(opr != "/" && opr != "%") {
                    cout << " reached correct if" << endl;
                    string opcode;
                    if(z[op2].isRegister)
                        opcode = selectInstruction(opr, {OperandLocation::REGISTER, OperandLocation::REGISTER});
                    else
                        opcode = selectInstruction(opr, {OperandLocation::REGISTER, OperandLocation::MEMORY});
                    
                    asmcode.push_back(opcode + " " + z["xx"].location + " , " + z[op2].location);
                    cout << "finally pushed the code" << endl;
                }
                else {
                    //to be handled
                    cout << "to be handled" << endl;
                }
                
                asmcode.push_back("mov " + z[result].location + " , " + z["xx"].location);
            }
            // if unary expression (++ or --)
            else if (instr.find("++") != string::npos || instr.find("--") != string::npos) {
                // Extract the variable being incremented/decremented
                string var = instr.substr(0, instr.find(" "));
                string op = (instr.find("++") != string::npos) ? "++" : "--";
                
                // Add variable if it's a real variable
                if (temp_and_type[var]->isreal_var) {
                    allocator.addVariable(var);
                }
                
                // Prepare operands for register allocation
                vector<pair<string, bool>> tr;
                tr.emplace_back(var, !temp_and_type[var]->isreal_var);
                
                // Get register/memory locations
                auto z = allocator.getRegisters(tr, tac.getNextUseMap());
                
                // Select instruction based on operand location
                string opcode;
                if (z[var].isRegister) {
                    opcode = selectInstruction(op, {OperandLocation::REGISTER});
                } else {
                    opcode = selectInstruction(op, {OperandLocation::MEMORY});
                }
                
                // Generate assembly code for increment/decrement
                asmcode.push_back(opcode + " " + z[var].location + " , 1");
            }
            // Other unary expressions
            else {
                cout << "to be handled##" << endl;
            }
        }
        
        if(curb->successors.size() == 1) {
            cout << "curb->successors" << endl;
            string jmpl;
            if(curb->successors[0]->getStartLine() != -1)
                jmpl = ".B" + to_string(curb->successors[0]->getId());
            else
                jmpl = ".end";
            asmcode.push_back("jmp " + jmpl);
        }
        else {
            cout << "no more than 1 succ" << endl;
            exit(1);
        }
    }
    
    for(auto i : curb->successors) {
        if(!i->visited) {
            cout << "here we are" << endl;
            dfs(i, allocator);
        }
    }
}
int main(int argc, char* argv[]) {
    string outputFileName="lexer_output";
    FILE *fh;
	FILE *fo;

	if ((fh = fopen(argv[1], "r"))){
		yyin = fh;
	}
	else{
		std::cout << "Input file does not exist!" << endl;
		exit(1);
	}
	ofstream outputFile(outputFileName);
	
	Node* root= new Node();
	gst=new Global_Symbol_Table();
	current_params_list.clear();
	while(!current_param_vector.empty()){
		current_param_vector.pop_back();
	}
	labelset.clear();
	while (!lvl_name.empty()){
    lvl_name.pop();
	}
	current_table=nullptr;
	func_ret_type=nullptr;
	current_func_name="";
	current_func_si=nullptr;
	current_level=0;
    int abc=yyparse();
	if (!error.empty()) {
        outputFile << "Errors Found:\n";
        for (const auto &err : error) {
             if(err.first!="unterminated comment")outputFile << "invalid character : " << err.first << " at line no. " << err.second << endl;
            else outputFile  << err.first << " at line no. " << err.second << endl;
        }
		/*cout << "error in lexical phase" << endl;
		exit(1);*/
    } 
	else {
		
        outputFile << "Original Symbol Table:\n";
        outputFile << "-------------------------------------------------------------------------------\n";
        outputFile << "| Lexeme                                | Token                                 |\n";
        outputFile << "-------------------------------------------------------------------------------\n";

        for (const auto &entry : symtab) {
            std::stringstream tokenStream(entry.first);
            std::string line;
            bool firstLine = true;
            while (std::getline(tokenStream, line, '\n')) {
                if (firstLine) {
                    outputFile << "| " << setw(36) << left << line
                               << " | " << setw(36) << left << entry.second << " |\n";
                    firstLine = false;
                } else {
                    outputFile << "| " << setw(36) << left << line
                               << " | " << setw(36) << left << "" << " |\n";
                }
            }
        }
        outputFile << "-------------------------------------------------------------------------------\n";
        outputFile << '\n';
		outputFile << "seperated tokens: "<< endl;
		for(auto i:program)outputFile << i << endl;
		outputFile << endl;

		
	
    cout << "Lexical analysis completed. Check '" << outputFileName << "' for results." << endl;
	
    }
	outputFile.close();
    if(abc){
        cout << "parsing failed!" << endl;
    }
    else{
        cout << "parsing successful" << endl;
    }
    print_full_symbol_table();
    string tacOutputFile = "output_tac.txt";
    string final_symtabFile="final_symtab.txt";
    ofstream tacFile(tacOutputFile);
	ofstream fsFile(final_symtabFile);
    
    if (!tacFile.is_open()) {
        cerr << "Error: Could not open file " << tacOutputFile << " for writing." << endl;
    } else {
        fsFile << "====================== FINAL SYMBOL TABLE ======================\n\n";
        for(auto i:final_symtab){
            fsFile << "Temp: " << i.first << "\n";
            fsFile << "  Name: " << i.second->name << "\n";
            fsFile << "  Type: " << i.second->type << "\n";
            fsFile << "  Scope: " << i.second->level_name << "\n";
            fsFile << "  Level: " << i.second->level << "\n\n";
        }
        fsFile << "====================== FINAL TEMP SYMBOL TABLE ======================\n\n";
        for (auto i : temp_and_type) {
		fsFile << "Temp: " << i.first << "\n";

		Type* t = i.second;
		t->size=getBasicTypeSize(t);
		if (!t) {
			fsFile << "  Type: nullptr\n";
			continue;
		}

		fsFile << "  Type Info:\n";
		fsFile << "    is real var? " << t->isreal_var << "\n"; 
		fsFile << "    size: " << t->size << "\n";
		fsFile << "    base: " << t->base << "\n";
		fsFile << "    ptr_level: " << t->ptr_level << "\n";
		fsFile << "    array_dim: " << t->array_dim << "\n";
		fsFile << "    isbasic: " << t->isbasic << "\n";
		fsFile << "    isobj: " << t->isobj << "\n";
		fsFile << "    isfunction: " << t->isfunction << "\n";
		fsFile << "    isconst: " << t->isconst << "\n";
		fsFile << "    isvolatile: " << t->isvolatile << "\n";
		fsFile << "    isstatic: " << t->isstatic << "\n";
		fsFile << "    isauto: " << t->isauto << "\n";
		fsFile << "    isextern: " << t->isextern << "\n";
		fsFile << "    isregister: " << t->isregister << "\n";
		fsFile << "    isigned: " << t->isigned << "\n";
		fsFile << "    isunsigned: " << t->isunsigned << "\n";
		fsFile << "    isnull: " << t->isnull << "\n";
		fsFile << "    isenum: " << t->isenum << "\n";
		fsFile << "    isvarargs: " << t->isvarargs << "\n";
		fsFile << "    func_ptr_lev: " << t->func_ptr_lev << "\n";
		
		// Optional: print func_ret_type if available
		if (t->isfunction && t->func_ret_type) {
			fsFile << "    func_ret_type.base: " << t->func_ret_type->base << "\n";
		}

	}

        /*tacFile << "====================== THREE ADDRESS CODE ======================\n\n";*/
        for(int i=0; i<global_code.size(); i++){
            tacFile << setw(4) << right << i << ": " << global_code[i] << "\n";
        }
        tacFile.close();
        cout << "Three address code written to '" << tacOutputFile << "'" << endl;
    }

	




    //codegen
    BasicBlock* mainblock;
    string inputFile = "output_tac.txt";
    mainblock=generateCode(inputFile, true);
    
    if(mainblock)cout << "mainblock id: " << mainblock->id << endl;
    RegisterAllocator allocator(x86_regs);
    string outFile = "out.s";  // Output file name is hardcoded

    ofstream fout(outFile);
    if (!fout.is_open()) {
        cerr << "Failed to open output file: " << outFile << endl;
        return 1;
    }

    // Write the assembly preamble
    fout << ".intel_syntax noprefix\n";
    fout << ".text\n";
    fout << ".globl main\n";

    dfs(mainblock, allocator);  // This fills asmcode

    // Write generated assembly to output file
    for (const string& line : asmcode) {
        fout << line << '\n';
    }

    fout.close();
    //first three lines
    //dfs for basic block
    //in each
    //generate label with name of block 
    //if it is label instruction (eg: t1:, main:) simply print it as it is as that is a function name. also  generate this two instr, push rbp and mov rbp,rsp.
    //if it is assignment statement get rhs and lhs. select instruction based on imm, mem or reg by looking at temp and type
    // if it is a (t13 = t4 op t5) kind of instruction first evaluate rhs and then mov the result to lhs see for all operands
    //if it is a unary operator (++ or --) 
    // if it is a if statement then cmp,jump if zero and and an unconditional jump
    // if it is unconditional statement then just a jmp statement

    return 0;
}