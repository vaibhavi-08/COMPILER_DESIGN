	.file	"verybasic.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 5
	mov	DWORD PTR [ebp-8], 6
	mov	DWORD PTR [ebp-12], 3
	mov	eax, DWORD PTR [ebp-4]
	imul	eax, DWORD PTR [ebp-8]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-4]
	cdq
	idiv	DWORD PTR [ebp-8]
	mov	DWORD PTR [ebp-12], eax
	mov	edx, DWORD PTR [ebp-4]
	mov	eax, DWORD PTR [ebp-8]
	add	eax, edx
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-4]
	sub	eax, DWORD PTR [ebp-8]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, 0
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
