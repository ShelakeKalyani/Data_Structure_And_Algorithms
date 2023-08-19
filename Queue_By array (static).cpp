#include<stdio.h>
#define SIZE 5
int queue[SIZE] = {0};
int front = -1;
int rear = -1;

void IsEmpty();
void IsFull();
void Enqueue();
void Dequeue();
void Display();
void Peek();
void Rear();

int main()
{
	int choice = 0;
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
					IsEmpty();
					break;
			case 2:
					IsFull();
					break;
			case 3:
					Enqueue();
					break;
			case 4:
					Dequeue();
					break;
			case 5:
					Display();
					break;
			case 6:
					Peek();
			 		break;
			case 7:
					Rear();
					break;
			case 10:
					return 0;
			default:
					printf("Invalid choice..\n");
					
		}
	}
	return 0;
}

void IsEmpty()
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

void IsFull()
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

void Enqueue()
{
	int value = 0;
	int temp = rear;
	
	if(rear==SIZE-1)
	{
		printf("Queue is full...can not insert.\n");
		return;
	}
	printf("Enter value to insert = ");
	scanf("%d",&value);
	
	if(front==-1)
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

void Dequeue()
{
	int value = 0;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty...can not delete.\n");
		return;
	}
	if(front==rear)
	{
		value = queue[front];
		front = -1;
		rear = -1;
	}
	else
	{
		value = queue[front];
		front++;
	}
	printf("%d value deleted from queue.\n",value);
	return;
}

void Peek()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty..\n");
	}
	else
	{
		printf("Peek(front) element is = %d\n",queue[front]);
	}
	return;
}

void Rear()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty..\n");
	}
	else 
	{
		printf("Rear is = %d\n",queue[rear]);
	}	
	return;
}

void Display()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty..\n");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
	return;
}
