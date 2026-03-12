#include <stdio.h>

/* hex to dec converter, without using library functions  */

int intpow(int base, int power)
{
    int result = base;

    if (power == 0)
	return 1;

    for (int i = 1; i < power; ++i)
	result *= base;

    return result;
}

int hexCharValue(int value)
{   // converts a-f or A-F to 11-16
    if (value >= 'a' && value <= 'f')
	value -= ('a' - 10);

    else if (value >= 'A' && value <= 'f')
	value -= ('A' - 10);

    else if (value >= '0' && value <= '9')
	value -= '0';

    return value;
}

int hexToInt(char input[])
{
    int result, beginning, end;
    result = beginning = end = 0;

    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X'))
	beginning = 2; // input can start with 0x or 0X

    for (; input[end + 1] != '\0'; ++end)
	; // locate the last valid character of the string

    for (int i = end; i >= beginning; --i)
	result += hexCharValue(input[i]) * intpow(16, end - i);

    return result;
}

int main(int argc, char *argv[])
{

    printf("Hex to decimal converter!!!\n");
    if (argc == 1)
    {
	printf("Accepts arguments as hex numbers\n");
	return 1;
    }

    
    for (int i = 1; i < argc; ++i)
	printf("%s: %d\n", argv[i], hexToInt(argv[i]));

    return 0;
}
