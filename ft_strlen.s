
section	.text
	global	ft_strlen

ft_strlen:
	xor rax, rax
	mov	rax, -1
_loop:
	inc rax
	cmp BYTE [rdi + rax], 0
	jne _loop
	ret
