.intel_syntax noprefix
.text
.globl main
.B0:
mov ebx , DWORD PTR [ebp-4]
add ebx , DWORD PTR [ebp-8]
mov eax , ebx
jmp .end
.end :
mov eax , 0
leave
ret
.B1:
mov eax , 5
mov eax , 7
mov DWORD PTR [ebp-4] , eax
jmp .end
.end :
mov eax , 0
leave
ret
