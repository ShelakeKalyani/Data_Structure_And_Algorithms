#include<stdio.h>
#define SIZE 5

void IsEmpty(int,int);
void IsFull(int,int);
void Enqueue(int,int);

int main()
{
	int choice = 0;
	int front = -1;
	int rear = -1;
	
	while(1)
	{
		puts("\n***MENU START***");
		puts("1.Is Empty");
		puts("2.Is full");
		puts("3.Enqueue");
		puts("4.Dequeue");
		puts("5.Display");
		puts("6.Peek(front)");
		puts("7.Rear");
		puts("10.Exit");
		
		printf("Enter choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					IsEmpty(front,rear);
					break;
			case 2:
					IsFull(front,rear);
					break;
			case 3:
					Enqueue(front,rear);
					break;
			case 4:
				//	Dequeue();
					break;
			case 5:
				//	Display();
					break;
			case 6:
				//	Peek();
			 		break;
			case 7:
				//	Rear();
					break;
			case 10:
					return 0;
			default:
					printf("Invalid choice..\n");
					
		}
	}
	return 0;
}

void IsEmpty(int front,int rear)
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty.\n");
	}
	else
	{
		printf("Queue is not empty.\n");
	}
	return;
}

void IsFull(int front,int rear)
{
	if(rear==SIZE-1)
	{
		printf("Queue is full.\n");
	}
	else
	{
		printf("Queue is not full.\n");
	}
	return;
}

void Enqueue(int front,int rear)
{
	int value = 0;
	
	printf("Enter value to insert = ");
	scanf("%d",&value);
	
	if(rear==SIZE-1)
	{
		printf("Queue is full...can not insert.\n");
	}
	else if(front==-1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear++;
	}
	queue[rear] = value;
	return;
}
