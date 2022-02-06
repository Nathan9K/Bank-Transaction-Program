
// rec02

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// declare int pointer and allocate memory
	int *int_ptr;
	int_ptr = (int *) malloc(2*sizeof(int));
	
	// exit program if memory allocation fails
	if (int_ptr == NULL)
	{
		printf("Failed to allocate memory, exiting ...\n");
		exit(1);
	}

	// prompt user to enter in two integer values
	printf("Enter first integer: ");
	scanf("%d", &int_ptr[0]);
	printf("Enter second integer: ");
	scanf("%d", &int_ptr[1]);

	// display original values before performing operations
	printf("\nOriginal values\n");
	printf("First integer: %d\n", int_ptr[0]);
	printf("Second integer: %d\n", int_ptr[1]);

	// perform XOR operations to swap values of user entered integers
	int_ptr[0] = int_ptr[0] ^ int_ptr[1];
	int_ptr[1] = int_ptr[0] ^ int_ptr[1];
	int_ptr[0] = int_ptr[0] ^ int_ptr[1];

	// display swapped values
	printf("\nSwapped values\n");
	printf("First integer: %d\n", int_ptr[0]);
	printf("Second integer: %d\n", int_ptr[1]);

	// release allocated memory
	free(int_ptr);
	
	return 0;
}