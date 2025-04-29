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
	sub	esp, 32
	mov	DWORD PTR [ebp-20], 1
	mov	DWORD PTR [ebp-16], 2
	mov	DWORD PTR [ebp-12], 3
	mov	DWORD PTR [ebp-8], 4
	mov	eax, DWORD PTR [ebp-16]
	add	eax, eax
	mov	DWORD PTR [ebp-4], eax
	mov	DWORD PTR [ebp-20], 3
	mov	eax, 0
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
