.intel_syntax noprefix
.text
.globl main
.B0:
t1:
push ebp
mov ebp , esp
mov ebx , DWORD PTR [ebp+8]
add ebx , DWORD PTR [ebp+12]
mov eax , ebx
mov eax , eax
jmp .end0
.end0 :
pop ebp
ret
.B1:
main:
push ebp
mov ebp , esp
mov eax , 5
mov eax , 7
push eax
push eax
call t1
mov eax , eax
mov DWORD PTR [ebp-4] , eax
jmp .end1
.end1 :
mov eax , 0
leave
ret
