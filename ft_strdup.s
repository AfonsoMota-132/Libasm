
section	.text
	global	ft_strdup
	extern ft_strlen
	extern malloc
	extern ft_strcpy

ft_strdup:
	push	rdi
	call	ft_strlen wrt ..plt
	add		rax, 1
	mov		rdi, rax
	call	malloc wrt ..plt
	test	rax, rax
	jz		_error
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	ret

_error:
	pop rdi
	xor	rax, rax
	ret
