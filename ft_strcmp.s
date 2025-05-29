
section	.text
	global	ft_strcmp

ft_strcmp:
	xor	rax, rax
_loop:
	mov	cl, byte [rdi + rax]
	mov dl, byte [rsi + rax]
	cmp cl, dl
	jne _ret
	test cl, cl
	je _equ
	inc	rax
	jmp _loop

_ret:
	movzx	eax, dl
	movzx	ecx, cl
	sub		eax, ecx
	ret

_equ:
	xor	rax, rax
	ret

