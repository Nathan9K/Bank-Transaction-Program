#include <stdio.h>

void clz(long long int operand)
{
	int leadingZeroes = 0;
	
	// referenced from recitation assignment to find binary number equivalent 
	/*
	printf("32-bit Binary Number:\n");
	for (int i = 31; i >= 0; i--)
	{
		int temp = operand >> i;
		
		if (temp & 1 == 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
	*/
	
	
	for (int i = 31; i >= 0; i--)
	{
		int temp = operand >> i;
		
		if (temp & 1 == 1)
		{
			break;
		}
		else
		{
			leadingZeroes += 1;
		}
	}
	printf("The number of leading zeroes in %lld is %d\n", operand, leadingZeroes);
	
}
