section .text

; return the length of a char based on the first byte
; returns 0 if the current byte is part of a multi-byte char (not the first byte)

global char_len
char_len:
    and     rsi, 0xf0
    cmp     rsi, 0
    je      char_len_1
    jne     char_len_2
char_len_1:
    mov    rax, 1
    jmp    fin
    ret
char_len_2:
    mov    rax, 2
    jmp    fin
fin:
    ret
