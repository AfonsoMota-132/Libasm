
section	.text
	global	ft_strdup
	extern ft_strlen
	extern malloc
	extern ft_strcpy

ft_strdup:
	call	ft_strlen
	add		rax, 1
	push	rdi
	mov		rdi, rax
	call	malloc
	test	rax, rax
	jz		_error
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	ret

_error:
	xor	rax, rax
	ret
