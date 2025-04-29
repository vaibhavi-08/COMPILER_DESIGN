.file	"do_while.c"
.intel_syntax noprefix
.text
.globl main
.type	main, @function
.B0:
fld DWORD PTR .LC0
fstp DWORD PTR [ebp-8]
mov eax, DWORD PTR [ebp-8]
mov eax , eax
mov QWORD PTR [ebp-8] , eax
fld DWORD PTR .LC1
fstp DWORD PTR [ebp-8]
mov eax, DWORD PTR [ebp-8]
mov eax , eax
mov QWORD PTR [ebp-16] , eax
jmp .end
.end :
mov eax , 0
leave
ret
.size	main, .-main
.section	.rodata
.align 8
.LC1:
	.long	-1717986918
	.long	1075550617
.LC0:
	.long	-1717986918
	.long	1075812761
.section	.note.GNU-stack,"",@progbits
