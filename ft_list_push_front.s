
section	.text
	global	ft_list_push_front

_ft_list_push_front:
    push    rdi
    push    rsi
    sub     rsp, 8				; align the stack (now 16-byte aligned)
    mov     rdi, 16				; rule of thumb if nbrofpush % 2 = 1, its aligned
    call    _malloc				; if nbrofpush % 2 = 0 it needs alignment by doing
								; sub rsp, 8
    add     rsp, 8             ; remove alignment padding
    pop     rsi
    pop     rdi
    test    rax, rax
    jz      return
    mov     [rax], rsi         ; new->data = data
    mov     rcx, [rdi]         ; rcx = *begin
    mov     [rax + 8], rcx     ; new->next = *begin
    mov     [rdi], rax         ; *begin = new
return:
    ret
