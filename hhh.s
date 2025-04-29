<<<<<<< HEAD
	.file	"do_while.c"
=======
	.file	"funcCall.c"
>>>>>>> 5367b2d891ce1cf6d891443a57c77a89788db560
	.intel_syntax noprefix
	.text
	.globl	sum
	.type	sum, @function
sum:
	push	ebp
	mov	ebp, esp
	mov	edx, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, edx
	pop	ebp
	ret
	.size	sum, .-sum
	.globl	main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
<<<<<<< HEAD
	and	esp, -8
	sub	esp, 16
	fld	QWORD PTR .LC0
	fstp	QWORD PTR [esp+8]
=======
	sub	esp, 32
	mov	DWORD PTR [ebp-20], 1
	mov	DWORD PTR [ebp-16], 2
	mov	DWORD PTR [ebp-12], 3
	mov	DWORD PTR [ebp-8], 4
	mov	eax, DWORD PTR [ebp-16]
	add	eax, eax
	mov	DWORD PTR [ebp-4], eax
	mov	DWORD PTR [ebp-20], 3
>>>>>>> 5367b2d891ce1cf6d891443a57c77a89788db560
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
