
.global lower
lower:
    cmpb    $0,(%rdi)       # *s != '\0' 
    je      done
    cmpb    $'A',(%rdi)     # *s >= 'A' 
    jge     greater_than
lower_continued:
    leaq    1(%rdi),%rdi    # ++s
    jmp     lower
greater_than:
    cmpb    $90,(%rdi)      # *s <= 'Z'
    jg      lower_continued
    addq    $32,(%rdi)      # *s += ' '     
    jmp     lower_continued
done:
    ret
