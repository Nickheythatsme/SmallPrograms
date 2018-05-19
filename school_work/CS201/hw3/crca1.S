#Nicholas Grout
#Assignment 3
#Regular crcInit() and crcFast() rather than the conditional jumping one

    .data
crcTable:
    .fill   200
POLYNOMIAL:
    .long   0xD5

    .text
    .globl crcInit
crcInit:
    xorq    %rbx, %rbx  #bl  == char bit
    xorq    %rdx, %rdx  #dl  == char remainder 
    xorq    %rsi, %rsi  #rsi == int dividend

dividend_loop:
    movb    %sil, %dl   #remainder = dividend
    movb    $8, %bl     #Set bit to 8

bit_loop:
    movb    %dl, %al    #store remainder
    andb    $0x80, %al  #remainder & 0x80
    cmp     $0, %al
    jne     bit_loop_if
    jmp     bit_loop_else

bit_loop_if:
    salb    $1,%dl          #remainder << 1
    xorb    POLYNOMIAL,%dl  #remainder ^ POLYNOMIAL
    jmp     bit_loop_finally

bit_loop_else:
    salb    $1, %dl
    jmp     bit_loop_finally

bit_loop_finally:
    sub     $1, %bl     #--bit
    cmp     $0, %bl
    jg      bit_loop    #while bit > 0, do bit loop

#end of bit loop
    leaq    crcTable, %rcx
    movb    %dl, (%rcx,%rsi,1)      #crcTable[dividend] = remainder
    add     $1, %rsi                #++dividend
    cmp     $256, %rsi
    jl      dividend_loop           #while dividend < 256, do dividend loop
# TODO testing
    mov     %rcx, %rax
# TODO end testing
    ret                             #else return


    .text
    .globl crcFast
crcFast:
    xorq    %rdx, %rdx          # long byte = 0 (index variable)
    xorq    %rcx, %rcx          # (cl) char remainder = 0;
    xorq    %r8, %r8            # (r8b) unsigned char data = 0;

crcFastLoop:
    movb    (%rdi,%rdx,1), %r8b #data = message[byte]
    xorb    %cl, %r8b           #data = data ^ remainder
    leaq    crcTable, %r9
    movb    (%r9,%r8,1), %cl    #remainder = crcTable[data];
    addq    $1, %rdx            #++byte
    cmp     %rsi,%rdx           #byte < nBytes
    jl      crcFastLoop         #Continue for loop
    mov     %rcx, %rax
    ret


.text
.global
crcInit:
    ret 
