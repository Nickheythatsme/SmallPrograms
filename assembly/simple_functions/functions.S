# Set all the values in an array to 0
    .global zero_array
    .text
zero_array:
    xorq    %rdx, %rdx
.L1:
    cmpq    %rsi, %rdx
    jge end
    movl    $0, (%rdi, %rdx, 4)
    inc     %rdx
    jmp     .L1
.l2:
    ret


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
    movl    %eax, (%rdi, %rdx, 4)   # store array[i]=temp2
    inc     %rdx
    dec     %r8
    jmp     loop
end:
    ret


    .global copy
    .text
copy:
    sar     $2, %rsi                 # Multiply len by 4 to get number of bytes
    mov     %rdi, %rcx
    mov     %rsi, %rdi
    call    malloc
    mov     %rax, %rdi
    sal     $2, %rsi
    call    zero_array
    ret

