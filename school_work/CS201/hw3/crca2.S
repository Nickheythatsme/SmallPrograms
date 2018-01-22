#Nicholas Grout
#Assignment 3
#Fast CRC, using conditional move

    .data
crcTable:
	.byte	200
POLYNOMIAL:
    .long   0xD5

#Start of CRC init
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
    mov     %rdx, %rax       #store unshifted remainder to compare later
    and     $0x80, %rax      #(remainder & 0x80) to compare later
    sal     $1,%rdx          #remainder << 1 (this happens in both cases)
    mov     %rdx,%rcx        #store shifted remainder
    xor     POLYNOMIAL,%rcx  #temp remainder ^ POLYNOMIAL
    cmp     $0, %rax
    cmovne  %rcx, %rdx       #remainder ^ POLYNOMIAL

    sub     $1, %bl         #--bit
    cmp     $0, %bl
    jg      bit_loop        #while bit > 0, do bit loop

#end of bit loop
    leaq    crcTable, %rcx
    movb    %dl, (%rcx,%rsi,1)      #crcTable[dividend] = remainder
    add     $1, %rsi                #++dividend
    cmp     $256, %rsi
    jl      dividend_loop           #while dividend < 256, do dividend loop
    leaq    crcTable, %rax
    ret                             #else return

#Start of CRC fast
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
