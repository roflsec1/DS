#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Queue {
	struct Node *front, *rear;
};

struct Node* newNode(int k)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); //create decoy
	temp->data = k;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue() //create a new, empty queue and return it
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void enQueue(struct Queue* q, int k)
{
	struct QNode* temp = newNode(k); //create new node
	if(q->rear == NULL) //if this is the first node in the queue
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp; //otherwise do this
	q->rear = temp;
}

void deQueue(struct Queue* q)
{
	if(q->front == NULL) //if only 1 in queue
		return;

	struct Node* temp = q->front; //store it in a variable so that it can be removed from memory.
	q->front = q->front->next; //move ahead

	if(q->front == NULL) //if only 1 left after moving ahead
		q->rear = NULL;

	free(temp); //remove the node that was left behind
}

void main()
{
	struct Queue *q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	deQueue(q);

	if(q->front == NULL && q->rear == NULL)
		printf("\t\tQUEUE IS EMPTY.\n");

	else
	{
		printf("Queue Front : %d\n", q->front->data);
		printf("Queue Rear : %d\n", q->rear->data);
	}
}
