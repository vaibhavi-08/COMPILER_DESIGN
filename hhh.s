	.file	"funcCall.c"
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
	sub	esp, 16
	push	7
	push	5
	call	sum
	add	esp, 8
	mov	DWORD PTR [ebp-4], eax
	mov	eax, 0
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
