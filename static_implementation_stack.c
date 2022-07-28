#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5

struct stack
{
	int top;
	int arr[MAXSIZE];
};

void push(struct stack *stack_p)
{
	int element;
	if(stack_p->top == MAXSIZE-1)
	{
		printf("\n\tSTACK IS FULL.\n");
	}
	else
	{
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		stack_p->arr[++stack_p->top] = element;
	}
}

void pop(struct stack *stack_p)
{
	int element;
	if(stack_p->top == -1)
		printf("\n\tSTACK IS EMPTY.\n");
	else
	{
		element = stack_p->arr[stack_p->top--];
		printf("\n\t%d DELETED.\n", element);
	}
}

void travis(struct stack *stack_p)
{
	if(stack_p->top == -1)
		printf("\n\tSTACK IS EMPTY.\n");
	else
	{
		for(int i=0;i<stack_p->top+1;i++)
			printf("stack_p->arr[%d]: %d\n", i, stack_p->arr[i]);
	}
}

void printStackTop(struct stack *stack_p)
{
	if(stack_p->top == -1)
		printf("\n\tSTACK IS EMPTY.\n");
	else
		printf("\n%d\n", stack_p->arr[stack_p->top]);
}

void main()
{
	bool x = true;
	struct stack *stack_p = (struct stack*)malloc(sizeof(struct stack));
	stack_p->top = -1;
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("\nEnter stack_p->arr[%d]: ", i);
		scanf("%d", &stack_p->arr[i]);
		stack_p->top++;
	}
	while(x)
	{
		int c;
		printf("\n1.\tPUSH");
		printf("\n2.\tPOP");
		printf("\n3.\tTRAVERSE");
		printf("\n4.\tPEEK");
		printf("\n5.\tEXIT");
		printf("\n>>> ");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
				push(stack_p);
				break;
			case 2:
				pop(stack_p);
				break;
			case 3:
				travis(stack_p);
				break;
			case 4:
				printStackTop(stack_p);
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("\n\tTOUCH SOME GRASS.\n");
				break;
		}
	}
}
