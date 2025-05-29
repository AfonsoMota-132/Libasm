
section	.text
	global	ft_read

ft_read:
	mov rax, 0
	syscall
	jc error_exit
	ret

error_exit:
	mov rax, -1
	ret
