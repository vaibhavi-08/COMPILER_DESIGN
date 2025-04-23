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
cmp eax , 0
jmp .B2
.B2:
mov DWORD PTR [rbp-4] , eax
jmp .B3
.B3:
cmp DWORD PTR [rbp-4] , 0
jmp .B4
.B4:
mov eax , 10
jmp .B5
.B5:
cmp eax , 0
jmp .B6
.B6:
cmp eax , DWORD PTR [rbp-4]
sete al
movzx eax , al
cmp eax , 0
je .B10
jmp .B7
.B7:
mov eax , 11
jmp .B8
.B8:
cmp eax , 0
jmp .B9
.B9:
mov DWORD PTR [rbp-4] , eax
jmp .B10
.B10:
mov eax , 11
jmp .B11
.B11:
cmp eax , 0
jmp .B12
.B12:
cmp eax , DWORD PTR [rbp-4]
sete al
movzx eax , al
cmp eax , 0
je .B16
jmp .B13
.B13:
mov eax , 12
jmp .B14
.B14:
cmp eax , 0
jmp .B15
.B15:
mov DWORD PTR [rbp-4] , eax
jmp .B16
.B16:
mov eax , 0
jmp .B17
.B17:
cmp eax , 0
jmp .B18
.B18:
mov DWORD PTR [rbp-4] , eax
jmp .end
.end :
