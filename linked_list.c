#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void append(struct Node*, int);
//void delete_node(struct Node*, int);
void display(struct Node*);
void insertAtBeginning(struct Node*, int);
void insertAfter(struct Node*, int, int);

void main()
{
	struct Node *node, *linked_list;
	linked_list = NULL;
	for(int i=0;i<5;i++)
	{
		/*It's gonna be over-written after each iteration, gotta store it
		somewhere*/
		node = (struct Node*)malloc(sizeof(struct Node));
		node->data = i;
		if(linked_list == NULL) //If this is the first iteration. Next node will point to this.
			node->next = NULL;
		else
			node->next = linked_list;
		linked_list = node; //remember how an array was a pointer except in arrays the data was continuous in memory?
	}

	display(linked_list);
	insertAfter(linked_list, 0, 6);
	insertAtBeginning(linked_list, 10);
	append(linked_list, 11);
	//delete_node(linked_list, 2);
}

void display(struct Node *ll)
{
	printf("\n==============================\n");
	while(ll != NULL)
	{
		printf("ll->data = %d\n", ll->data);
		ll = ll->next;
	}
}

void insertAfter(struct Node *ll, int index, int data)
{
	int count = 0;
	struct Node *ptr, *newnode;
	ptr = ll;
	while(ptr != NULL)
	{
		if(count == index)
		{
			newnode = (struct Node*)malloc(sizeof(struct Node));
			newnode->data = data;
			newnode->next = ptr->next;
			ptr->next = newnode;
			break;
		}
		ptr = ptr->next;
		count++;
	}
	display(ll);
}

void insertAtBeginning(struct Node* ll, int data)
{
	struct Node *ptr, *node;
	ptr = ll;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	while(ptr != NULL)
	{
		if(ptr->next == NULL)
		{
			ptr->next = node;
			node->next = NULL;
			ptr = node;
			break;
		}
		else
			ptr = ptr->next;
	}
	display(ll);
}

void append(struct Node* ll, int data)
{
	struct Node *node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = ll;
	ll = node;
	display(ll);
}

/* Can't think, I'm exhausted
void delete_node(struct Node *ll, int index)
{
	struct Node *ptr, *temp;
	for(int i=0;i<=index;i++)
	{
		if(i == index)
		{
			temp = (struct Node*)malloc(sizeof(struct Node));

			break;
		}
		ptr = ptr->next;
	}
	display(ll);
}
*/
