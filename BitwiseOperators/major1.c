
#include "major1.h"

// for obtaining the integer operand
long long int getOperand()
{
	long long int number;
	
	printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
	scanf("%lld", &number);
				
	while (number < 1 || number > 4294967295)
	{
		printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
		if (scanf("%lld", &number)) 		
		{
			continue;
		}		
		// prevent infinite loop if characters are entered
		else 								
		{
			printf("Bad input - EXITING\n"); 
			exit(1);
		}
	}	
	
	return number;
}

// for obtaining the second integer operand used for the rotate-right function
int getSecondOperand()
{
	int number;
	
	printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
	scanf("%d", &number);
				
	while (number < 0 || number > 31)
	{
		printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
		if (scanf("%d", &number)) 		
		{
			continue;
		}		
		// prevent infinite loop if characters are entered
		else 								
		{
			printf("Bad input - EXITING\n"); 
			exit(1);
		}
	}	
	
	return number;	
}

int main()
{
	bool option = 0;		// condition for while loop
	int userChoice;			// will store user input 
	long long int operand;	// will store integer from operand function
	int secondOperand;		// will store integer from second operand function
	
	while (option == 0)
	{
		// menu options 
		printf("Enter the menu option for the operation to perform:\n");
		printf("(1) Count Leading Zeroes\n");
		printf("(2) Endian Swap\n");
		printf("(3) Rotate-right\n");
		printf("(4) Parity\n");
		printf("(5) EXIT\n--> ");
		
		// if userChoice is an integer follow if statement
		if (scanf("%d", &userChoice))
		{
			switch (userChoice)
			{
				case 1:
					operand = getOperand();
					clz(operand);
					break;
					
				case 2:
					operand = getOperand();
					/*** call endian swap function ***/
					break;
					
				case 3:
					operand = getOperand();
					secondOperand = getSecondOperand();
					/*** call rotate-right function ***/
					break;
					
				case 4:
					operand = getOperand();
					/*** call parity function ***/
					break;
					
				case 5:
					printf("Program terminating. Goodbye...\n");
					option = 1;
					break;
					
				default:
					// if user enters integer outside of the 1 - 5 range
					printf("Error: Invalid option. Please try again.\n");
					break;
					
			}
		}
		// prevents an infinite loop if user enters characters 
		else
		{
			printf("Bad input - EXITING\n");
			exit(1);
		}
	}
	
	return 0;
}
