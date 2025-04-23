.intel_syntax noprefix
.text
.globl main
.B0:
main :
push rbp
mov rbp , rsp
mov eax , 10
jmp .B1
.B1:
mov DWORD PTR [rbp-4] , eax
mov eax , 110
jmp .B2
.B2:
mov DWORD PTR [rbp-8] , eax
mov eax, DWORD PTR [rbp-8]
cdq
idiv DWORD PTR [rbp-4]
mov eax, edx
jmp .B3
.B3:
mov DWORD PTR [rbp-12] , eax
jmp .end
.end :
