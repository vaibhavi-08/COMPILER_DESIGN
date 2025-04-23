.intel_syntax noprefix
.text
.globl main
.B0:
main :
push rbp
mov rbp , rsp
mov eax , 4
jmp .B1
.B1:
cmp eax , 0
jmp .B2
.B2:
mov DWORD PTR [rbp-4] , eax
mov eax , 9
jmp .B3
.B3:
cmp eax , 0
jmp .B4
.B4:
mov DWORD PTR [rbp-8] , eax
mov ebx , DWORD PTR [rbp-4]
add ebx , DWORD PTR [rbp-8]
mov eax , ebx
jmp .B5
.B5:
cmp eax , 0
jmp .B6
.B6:
mov DWORD PTR [rbp-12] , eax
jmp .B7
.B7:
cmp DWORD PTR [rbp-12] , 0
je .end
jmp .B8
.B8:
mov eax , 8
jmp .B9
.B9:
cmp eax , 0
jmp .B10
.B10:
mov DWORD PTR [rbp-16] , eax
jmp .end
.end :
