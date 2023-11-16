#include <main.h>
#include <stdio.h>

int main(void)
{
    int number = 42;

    printf("The big print gives and the small print takes away\n");

    printf("%+d\n", number);  /* Plus sign: always show sign */
    printf("% d\n", number);  /* Space: insert space before positive numbers */
    printf("%#o\n", number);  /* Hash: octal with prefix */

    return (0);
}

