#include "myprintf.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 42;
	float floatNum = 3.14;

	myprintf("Basic integer: %d\n", num);
	myprintf("Integer with + flag: %+d\n", num);
	myprintf("Integer with space flag: % d\n", num);

	myprintf("Basic float: %f\n", floatNum);
	myprintf("Float with + flag: %+f\n", floatNum);

	return (0);
}

