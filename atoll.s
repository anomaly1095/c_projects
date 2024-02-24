	.file	"atoll.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$2, -20(%rbp)
	je	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_size
	movb	%al, -1(%rbp)
	movsbl	-1(%rbp), %edx
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_atoll
	movq	%rax, -16(%rbp)
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.globl	_size
	.type	_size, @function
_size:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movb	$0, -1(%rbp)
	jmp	.L5
.L6:
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L5:
	movsbq	-1(%rbp), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
	movzbl	-1(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_size, .-_size
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	_atoll
	.type	_atoll, @function
_atoll:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movl	%esi, %eax
	movb	%al, -60(%rbp)
	movb	$1, -1(%rbp)
	movq	-32(%rbp), %rax
	movb	$0, (%rax)
	movq	$0, -16(%rbp)
	movb	$0, -17(%rbp)
	jmp	.L9
.L13:
	movsbq	-17(%rbp), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	_checkdigits
	movb	%al, -33(%rbp)
	cmpb	$1, -33(%rbp)
	jne	.L10
	movl	$1, %edi
	call	exit@PLT
.L10:
	cmpq	$0, -16(%rbp)
	je	.L16
	movsbl	-33(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movsbl	-1(%rbp), %edx
	movsbl	-33(%rbp), %eax
	imull	%edx, %eax
	cltq
	addq	%rax, -16(%rbp)
	movzbl	-1(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movb	%al, -1(%rbp)
	jmp	.L12
.L16:
	nop
.L12:
	movzbl	-17(%rbp), %eax
	addl	$1, %eax
	movb	%al, -17(%rbp)
.L9:
	movzbl	-17(%rbp), %eax
	cmpb	-60(%rbp), %al
	jl	.L13
	movq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$1, %al
	jne	.L14
	movq	-16(%rbp), %rax
	negq	%rax
	jmp	.L15
.L14:
	movq	-16(%rbp), %rax
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_atoll, .-_atoll
	.globl	_checkdigits
	.type	_checkdigits, @function
_checkdigits:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movq	%rsi, -32(%rbp)
	movb	%al, -20(%rbp)
	movl	$0, -8(%rbp)
	movl	$48, -4(%rbp)
	jmp	.L18
.L21:
	movsbl	-20(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jne	.L19
	movl	-8(%rbp), %eax
	jmp	.L20
.L19:
	addl	$1, -4(%rbp)
.L18:
	cmpl	$56, -4(%rbp)
	jle	.L21
	cmpb	$45, -20(%rbp)
	jne	.L22
	movq	-32(%rbp), %rax
	movb	$1, (%rax)
	movl	$0, %eax
	jmp	.L20
.L22:
	movl	$1, %eax
.L20:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_checkdigits, .-_checkdigits
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
