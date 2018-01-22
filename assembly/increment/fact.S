
.global fact
fact:
    cmp     $1,%rdi
    je      eq_one
    pushq   %rbx
    subq    $16,%rsp
    movq    %rdi,%rbx
    subq    $1,%rdi
    call    fact
    imul    %rbx,%rax
    addq    $16,%rsp
    popq    %rbx
    ret

eq_one:
    mov     $1,%rax
    ret
