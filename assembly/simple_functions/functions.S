
# Set all the values in an array to 0
    .global zero_array
    .text
zero_array:
    xorq    %rdx, %rdx
.L1:
    cmpq    %rsi, %rdx
    jge .L2
    movl    $0, (%rdi, %rdx, 4)
    inc     %rdx
    jmp     .L1
.L2:
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


/*
    Copy the contents of an array. 
    Takes pointer to int array, unsigned long length of the array
    Returns a pointer to the array
*/
    .global copy
    .text
copy:
	pushq	%rbp
	mov 	%rsp, %rbp
	sub 	$16, %rsp
    mov     %rdi, -8(%rbp)          # Save pointer to src array
    mov     %rsi, -16(%rbp)         # Save len of array
    mov     %rsi, %rdi              # Move length into rdi
    sal     $2, %rdi                # Multiply by 4 to get number of bytes
    call    malloc                  # Call malloc and allocate new array
    mov     -8(%rbp), %rdi          # Move pointer to src array back to rdi
    mov     -16(%rbp), %rsi         # Move array len back to rsi
    xorq    %rbx, %rbx              # i=0
.copy_loop:
    cmpq    %rsi, %rbx              # Compare i:len
    jge     .copy_end
    movl    (%rdi, %rbx, 4), %r9d   # temp=src[i]
    movl    %r9d, (%rax, %rbx, 4)   # dest[i]=temp
    inc     %rbx                    # ++i
    jmp     .copy_loop
.copy_end:
    xorq    %rdi, %rdi
    xorq    %rsi, %rsi
    addq    $16, %rsp
    popq    %rbp
    ret



