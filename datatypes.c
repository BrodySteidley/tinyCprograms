#include <stdio.h>
#include <limits.h>
#include <float.h>

/* print the size and range of primitive datatypes, as defined in limits.h */

int main(void)
{
    printf("DATATYPE SIZES ON YOUR SYSTEM\n");

    /* char */
    printf("Number of bits in char: %d\n", CHAR_BIT);
    printf("Minimum signed char: %d\n", SCHAR_MIN);
    printf("Maximum signed char: %d\n", SCHAR_MAX);
    printf("Minimum unsigned char: %d\n", 0);
    printf("Maximum unsigned char: %d\n\n", UCHAR_MAX);
    
    /* short */
    printf("Number of bits in short int: %lu\n", CHAR_BIT * sizeof(short int));
    printf("Minimum signed short int: %d\n", SHRT_MIN);
    printf("Maximum signed short int: %d\n", SHRT_MAX);
    printf("Minimum unsigned short int: %d\n", 0);
    printf("Maximum unsigned short int: %d\n\n", USHRT_MAX);
    
    /* int */
    printf("Number of bits in int: %lu\n", CHAR_BIT * sizeof(int));
    printf("Minimum signed int: %i\n", INT_MIN);
    printf("Maximum signed int: %i\n", INT_MAX);
    printf("Minimum unsigned int: %d\n", 0);
    printf("Maximum unsigned int: %u\n\n", UINT_MAX);
    
    /* long int */
    printf("Number of bits in long int: %lu\n", CHAR_BIT * sizeof(long int));
    printf("Minimum signed long int: %ld\n", LONG_MIN);
    printf("Maximum signed long int: %ld\n", LONG_MAX);
    printf("Minimum unsigned long int: %d\n", 0);
    printf("Maximum unsigned long int: %lu\n\n", ULONG_MAX);

    /* long long int */
    printf("Number of bits in long long int: %lu\n", CHAR_BIT * sizeof(long long int));
    printf("Minimum signed long long int: %lld\n", LLONG_MIN);
    printf("Maximum signed long long int: %lld\n", LLONG_MAX);
    printf("Minimum unsigned long long int: %d\n", 0);
    printf("Maximum unsigned long long int: %llu\n\n", ULLONG_MAX);

    /* float */
    printf("Number of bits in float: %lu\n", CHAR_BIT * sizeof(float));
    printf("Minimum float: %e\n", FLT_MIN);
    printf("Maximum float: %e\n\n", FLT_MAX);

    /* double */
    printf("Number of bits in double: %lu\n", CHAR_BIT * sizeof(double));
    printf("Minimum double: %.20e\n", DBL_MIN);
    printf("Maximum double: %.20e\n\n", DBL_MAX);

    /* long double */
    printf("Number of bits in long double: %lu\n", CHAR_BIT * sizeof(long double));
    printf("Minimum long double: %.20Le\n", LDBL_MIN);
    printf("Maximum long double: %.20Le\n", LDBL_MAX);

    return 0;
}
