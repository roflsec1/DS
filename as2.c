#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void print_commmon(int array[10]) //doing these operation on linked lists causes a segmentation fault
{
	printf("Common Elements:\n");
	for(int i=0;i<10;i++)
	{
		if(array[i] == array[i+1])
			printf("%d ", array[i]);
	}
	printf("\n");
}

void ignore_duplicate(int array[10]) //so I have used arrays to prevent crashing
{
	printf("Unique Elements:\n");
	for(int i=0;i<10;i++)
	{
		if(array[i] == array[i+1])
			continue;
		else
			printf("%d ", array[i]);
	}
	printf("\n");
}

void selection_sort(int array[10])
{
	int i, j, min_idx, temp, xp, yp;
	for (i = 0; i < 10; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < 10; j++)
          if (array[j] < array[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        temp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = temp;
    }
}


void main()
{
	//Given Scenario, there are two links containing the following data:
	//Structure 1
	struct Node *linked_list1, *head1, *prev1;
	head1 = NULL;

	int array1[] = {3, 7, 10, 15, 16};

	for(int i=0;i<5;i++)
	{
		linked_list1 = (struct Node*)malloc(sizeof(struct Node));
		linked_list1->data = array1[i];
		linked_list1->next = NULL;

		if(head1 == NULL)
			head1 = linked_list1;
		else
			prev1->next = linked_list1;

		prev1 = linked_list1;
	}

	//Structure 2
	struct Node *linked_list2, *head2, *prev2;
	head2 = NULL;

	int array2[] = {16, 2, 9, 13, 10};

	for(int i=0;i<5;i++)
	{
		linked_list2 = (struct Node*)malloc(sizeof(struct Node));
		linked_list2->data = array2[i];
		linked_list2->next = NULL;

		if(head2 == NULL)
			head2 = linked_list2;
		else
			prev2->next = linked_list2;

		prev2 = linked_list2;
	}

	//I have recreated the scenario necessary to carry out the required actions above.^^

	//SOLUTION STARTS HERE------------------------------------------>
	//append both linked lists to a third linked list
	struct Node *linked_list3, *head3, *prev3;
	head3 = NULL;

	for(int i=0;i<5;i++)
	{
		linked_list3 = (struct Node*)malloc(sizeof(struct Node));
		linked_list3->data = head1->data;
		linked_list3->next = NULL;

		if(head3 == NULL)
			head3 = linked_list3;

		else
			prev3->next = linked_list3;

		prev3 = linked_list3;
		head1 = head1->next;
	}

	for(int i=0;i<5;i++)
	{
		linked_list3 = (struct Node*)malloc(sizeof(struct Node));
		linked_list3->data = head2->data;
		linked_list3->next = NULL;

		if(head3 == NULL)
			head3 = linked_list3;
		else
			prev3->next = linked_list3;

		prev3 = linked_list3;
		head2 = head2->next;
	}

	//print data in linked_list3 and store them in an array
	int array[10];
	for(int i=0;i<10;i++)
	{
		if(head3 == NULL)
			printf("NULL\n");
		else
		{
			printf("linked_list3->data = %d\n", head3->data);
			array[i] = head3->data;
			head3 = head3->next;
		}
	}
	//sorting
	selection_sort(array);
	//find duplicate elements and choose not to print them
	ignore_duplicate(array);
	//
	print_commmon(array);
	/*Print all the elements in linked_list3
	for(int i=0;i<10;i++)
	{
		printf("%d\n", array[i]);
	}
	*/
}
