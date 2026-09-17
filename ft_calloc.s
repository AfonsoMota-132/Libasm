
extern malloc

section .text
	global ft_calloc

ft_calloc:
	push rdi
	mov rax, rdi
	mul rsi
	jc .error

	mov [rsp], rax
	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz .error

	mov rsi, [rsp]
	mov rdi, rax
	call ft_bzero
	mov rax, rdi
	pop rdi
	ret 
.error:
	pop rdi
	xor	rax, rax
	ret


ft_bzero:
    xor rax, rax

.loop:
    cmp rax, rsi
    jae .done
    mov byte [rdi + rax], 0
    inc rax
    jmp .loop

.done:
    ret
