#include<bits/stdc++.h>
#include <basic_block+cfg.h>
#include <registerAllocator.h>
using namespace std;
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


int main(int argc, char* argv[]) {
    BasicBlock* mainblock;
    string inputFile = argv[1];
    mainblock=generateCode(inputFile, true);
    
    if(mainblock)cout << "mainblock id: " << mainblock->id << endl;
    RegisterAllocator allocator(x86_regs);
    
    return 0;
}