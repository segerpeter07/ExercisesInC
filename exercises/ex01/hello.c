#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Y value: %d\n", y);
    return 0;
}


/* 
Experiment 1: I think the lines that coresponds to this are:
                .cfi_def_cfa_register %rbp
                subq	$16, %rsp
                movl	$0, -4(%rbp)
                movl	$5, -8(%rbp)
	            leaq	L_.str(%rip), %rdi

Experiment 2:  With optimization, all these lines just became:
                .cfi_def_cfa_register %rbp
	            leaq	L_str(%rip), %rdi

Experiment 3: When I print X, this line gets added:
                movl	$5, %esi

Experiment 4: When this addition is added, a new variable doesn't get made, but
            a variable is just made with it's updated value.

*/
