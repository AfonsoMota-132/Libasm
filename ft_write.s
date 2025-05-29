
section	.text
	global	ft_write

ft_write:
	mov rax, 1
	syscall
	jc error_exit
	ret

error_exit:
	mov rax, -1
	ret
