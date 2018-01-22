
.global lower
lower:
    movb    (%rdi),%al
    movq    $32,%rdx
    xorq    %rcx,%rcx
    testb   %al,%al         # *s != '\0' 
    je      done
    cmpb    $'A',%al        # *s >= 'A' 
    jge     greater_than
lower_continued:
    addb    %cl,(%rdi)
    leaq    1(%rdi),%rdi    # ++s
    jmp     lower
greater_than:
    cmpb    $90,%al         # *s <= 'Z'
    cmovle  %rdx,%rcx       # *s += ' '    
    jmp     lower_continued
done:
    ret
