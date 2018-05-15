
.global test
test:
    movq    $10, %rax
    movq    $20, %rdi
    addq    %rdi, %rax
    ret
