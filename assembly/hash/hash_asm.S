

.global hash
hash:
    xorq    %r8, %r8    # index
    mov     %rsi, %r9   # index - 4
    subq    $4, %r9
    xorq    %rax, %rax  # Return hash value
    xorq    %r10, %r10  # tmp value
loop_one:
    cmpq    %r8, %r9
    jl      loop_two
    ret
loop_two:
    mov     $0, %rax
    ret
