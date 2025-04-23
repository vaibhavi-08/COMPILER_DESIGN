.intel_syntax noprefix
.text
.globl main
.LC0:
        .string "hello world" 
main:
push rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 4
        mov     eax, DWORD PTR [rbp-4]
        add     eax, 10
        mov     DWORD PTR [rbp-8], eax
        cmp     DWORD PTR [rbp-8], 0
        je      .L2
        mov     edi, OFFSET FLAT:.LC0
        call    printf
.L2:
        mov     eax, 0
        leave
        ret         
//gcc -m64 -no-pie -o try try.s