#include <stdio.h>
#include <stdlib.h>

/* Convert fahrenheit to celsius */

float fahr2cel(float fahrenheit)
{
    return 5.0/9.0 * (fahrenheit - 32);
}

int main(int argc, char** argv)
{
	if(argc < 2)
		printf("Usage: this program expects at least 1 parameter; it will convert each decimal parameter from Fahrenheit to Celsius\n");
	else
	{
		printf(" F* | C* \n");
		for (unsigned i = 1; i < argc; ++i)
		{
			float fahrenheit = strtof(argv[i], NULL);
			printf("%3.1f | %3.1f\n", fahrenheit, fahr2cel(fahrenheit));
		}
	}

	return 0;
}
