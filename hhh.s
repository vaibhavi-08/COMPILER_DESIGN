	.file	"do_while.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
	and	esp, -8
	sub	esp, 16
	fld	QWORD PTR .LC0
	fstp	QWORD PTR [esp+8]
	mov	eax, 0
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	-1717986918
	.long	1075812761
	.section	.note.GNU-stack,"",@progbits
