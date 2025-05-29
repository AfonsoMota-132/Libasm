
section	.text
	global	ft_strcpy

ft_strcpy:
	xor rax, rax
	mov	rax, -1
_loop:
	inc rax
	mov	cl, [rsi + rax]
	mov [rdi + rax], cl
	cmp cl, 0
	jne _loop
	mov	rax, rdi
	ret

