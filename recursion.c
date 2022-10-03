/*Apparently recursion is an application of stack*/

#include<stdlib.h>
#include<stdio.h>

int factorial(int fa, int n)
{
	if(n<=1)
		printf("\nFactorial = %d\n", fa);
	else
	{
		fa = fa * n;
		factorial(fa, --n);
	}
}

void main()
{
	int number;
	int product = 1;
	printf("Enter a number:\n");
	scanf("%d", &number);
	factorial(product, number);
}
