

test_v:
    mov     $1, %rax
    ret

.global stack
stack:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp
	movq	%rdi, -8(%rbp)
    retq
