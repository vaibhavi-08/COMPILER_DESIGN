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
mov eax , 4
mov eax , 1
mov ebx , 2
mov ecx , 3
mov edx , 4
mov esi , 5
mov DWORD PTR [ebp-16] , eax
mov DWORD PTR [ebp-12] , ebx
mov DWORD PTR [ebp-8] , ecx
mov DWORD PTR [ebp-4] , edx
mov DWORD PTR [ebp+0] , esi
mov eax , 1
mov eax , DWORD PTR [ebp-12]
mov eax , eax
mov eax , 2
mov edx , eax
imul edx , ebx
mov ecx , edx
mov DWORD PTR [ebp-20] , ecx
mov eax , 0
mov eax , DWORD PTR [ebp-16]
mov eax , eax
mov eax , 3
mov DWORD PTR [ebp-16] , eax
jmp .end1
.end1 :
mov eax , 0
leave
ret
