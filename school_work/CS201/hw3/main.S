.data
message:
    .fill 200

.text
.global test
test:
    leaq    message, %rdx
    mov     $0, %rsi
    movb    $65, (%rdx, %rsi, 1)
    movq    (%rdx, %rsi, 1), %rax      # rax = message[0]
    ret

