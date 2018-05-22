section .text

; return the length of a char based on the first byte
; returns 0 if the current byte is part of a multi-byte char (not the first byte)

section .data
    temp1 db 0

section .text

global char_len
char_len:
    xor     rax, rax
    nop
    mov     cx, di
    cmp     cl, 0           ; test cl:0
    jge     char_len_fin    ; if cl >= 0
char_len_loop:
    shl     cl,1
    cmp     cl,0            ; test cl:0
    jge     char_len_fin
    inc     rax
    jmp     char_len_loop
char_len_fin:
    inc     rax
    ret     