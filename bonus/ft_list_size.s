
section	.text
	global	ft_list_size

ft_list_size
	mov	rsi, rdi
	xor	rax, rax
_loop:
	test rdi, rdi
	jz	_end
	inc rax
	mov	rdi, [rdi + 8]
	jmp	_loop

_end:
	ret
