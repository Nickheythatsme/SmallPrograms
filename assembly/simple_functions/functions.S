
# Reverse an array. 
# Takes int* array, unsigned long length
# Returns nothing
    .global reverse
    .text
reverse:
    xorq    %rdx, %rdx              # Set i=0
    mov     %rsi, %r8               # Len-1 (+i)
    sub     $1, %r8
    sar     $1, %rsi                # Divide len by 2
loop:
    cmpq    %rsi, %rdx              # Compare i:len
    jge     end                     # Goto end if we're finished
    movl    (%rdi, %rdx, 4), %ecx   # temp1=array[i]
    movl    (%rdi, %r8, 4), %eax    # store temp2=array[len-1-i]
    movl    %ecx, (%rdi, %r8, 4)    # store array[len-1-i]=temp
    movl    %eax, (%rdi, %rdx, 4)    # store array[i]=temp2
    inc     %rdx
    dec     %r8
    jmp     loop
end:
    ret
