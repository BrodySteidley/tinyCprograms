#include <stdio.h>
#include <stdlib.h>

/* recursive fibonacci 
 * on my computer, the calculation begins to noticably slow at around n=40 */
long long unsigned fib(unsigned n)
{
	if (n == 0 || n == 1)
		return 1;

	return fib(n - 2) + fib(n - 1);
}

/* iterative fibonacci
 * after n=93 there will be integer overflow on an 8 byte cpu */
long long unsigned fib_iter(unsigned n)
{
	long long unsigned a = 0;
	long long unsigned b = 1;
	long long unsigned temp;

	for (unsigned i = 0; i < n; ++i)
	{
		temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}


int main(int argc, char **argv) 
{
	long int count = 0;

	long long unsigned (*fib_fun)(unsigned) = fib;

	if (argc >= 3 && argv[1][0] == '-' && argv[1][1] == 'i' && argv[1][2] == '\0')
	{
		fib_fun = fib_iter;
		count = atoi(argv[2]);
	}
	else if (argc >= 2)
		count = atoi(argv[1]);

	if (count <= 0)
	{
		printf("Usage:\nThe program expects the first parameter to be a number greater than zero:\n"
			"\tthe number of fibonacci numbers to generate recursively.\n"
			"Use -i before the count to use iteration instead of recursion. i.e. fib -i 93\n");
		return 1;
	}

	printf("First %ld fibonacci numbers:\n", count);
	for (unsigned i = 0; i < count; ++i)
		printf("%llu\n", fib_fun(i));

	return 0;
}

