/*

ntk0025 - Nathan Kevil
rec01 - ASCII Bits and Bytes

*/

#include <stdio.h>

int main()
{
	unsigned char userInput;	// store user input
	
	// prompt user to enter in an ascii character
	printf("Enter an ASCII character: "); 
	scanf("%c", &userInput);
	
	// print corresponding values in decimal and hex
	printf("The ASCII value of %c is: \n", userInput); 
	printf("  dec -- %d\n", userInput);
	printf("  hex -- %x\n", userInput);
	
	// algorithm for printing the binary equivalent of user input
	printf("  bin -- ");
	for (int i = 7; i >= 0; --i) // ascii contains 8 binary digits, decrement from 7 to 0
	{
		int temp = userInput >> i; // everytime the loop restarts shift right by 1 bit
		
		// if 1*1=1, print 1
		if (temp & 1 == 1) 
		{
			printf("1");
		}
		else // otherwise print 0
		{
			printf("0");
		}
	}
	printf("\n"); 
	
	return 0;
}
