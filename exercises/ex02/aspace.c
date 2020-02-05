/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_local() {
    int loc = 4;
    printf("The location of the local is %p\n", &loc);
}


int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *x = malloc(sizeof(int));

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("x points to %p\n", x);

    print_local();

    void *n1 = malloc(15);
    void *n2 = malloc(15);
    printf ("The address of the two numbers are %p and %p\n", n1, n2);
    printf ("They are %ld bits away\n", (n2-n1));

    return 0;
}
