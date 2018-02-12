
.global fibonacci
fibonacci:
    cmp     $2, %rdi
    mov     %rdi, %rax
    jl      endfi

    dec     %rdi
    push    %rdi
    call    fibonacci
    pop     %rdi
    dec     %rdi
    push    %rax
    call    fibonacci
    pop     %r8
    add     %r8, %rax

endfi:
    ret
