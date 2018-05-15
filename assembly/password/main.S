    .text
    .global get_password
    .type get_password, @function
get_password:
    pushq   %rbp
    movq    (%rsi), %rdi
    call    puts
    ret
    

    .text
    .global main
    .type main, @function
main:
    call    get_password
    movq    $0, %rax
    ret
