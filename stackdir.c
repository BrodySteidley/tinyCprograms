
#include <stdio.h>

/* This program checks the direction of the stack by comparing two pointers.
 * On most architectures the stack will grow downward */

int main(void)
{
	int i;
	int j;

	if (&j - &i < 0)
		printf("Your stack grows down.\n");
	else if (&j - &i > 0)
		printf("Your stack grows up.\n");
	else 
		printf("Something is seriously wrong with your computer.\n");

	return 0;
}

