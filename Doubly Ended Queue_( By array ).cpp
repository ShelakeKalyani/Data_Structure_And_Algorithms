#include<stdio.h>
#define SIZE 10
//Function Declarations
void IsFull();
void IsEmpty();
void EnQueue_F();
void EnQueue_R();
void DeQueue_F();
void DeQueue_R();
void Display();
void Front();
void Rear();

int front = -1,rear = -1;
int Dqueue[SIZE];
int main()
{
	int choice = 0;
	while(1)
	{
		puts("**Menu For Doubly Ended Queue**");
		puts("1.Is Full");
		puts("2.Is Empty");
		puts("3.Enqueue from front");
		puts("4.Enqueue from rear");
		puts("5.Dequeue from front");
		puts("6.Dequeue from rear");
		puts("7.Display");
		puts("8.Front");
		puts("9.Rear");
		puts("10.Exit");
		
		printf("Enter your choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					IsFull();
					break;
			case 2:
					IsEmpty();
					break;
			case 3:
					EnQueue_F();
					break;
			case 4:
					EnQueue_R();
					break;
			case 5:
					DeQueue_F();
					break;
			case 6:
					DeQueue_R();
					break;
			case 7:
					Display();
					break;
			case 8:
					Front();
					break;
			case 9:
					Rear();
					break;
			case 10:
					return 0;
			default:
					printf("Invalid Choice.\n");			
		}
	}
	return 0;
}

void IsFull()
{
	if((front==0 && rear==SIZE-1) || (front==rear+1))
	{
		printf("Queue is Full.\n");
	}
	else
	{
		printf("Queue is not Full.\n");
	}
	return;
}

void IsEmpty()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty.\n");
	}
	else
	{
		printf("Queue is not Empty.\n");
	}
	return;
}

void EnQueue_F()
{
	int value = 0;
	
	if((front==0 && rear==SIZE-1) || (front==rear+1))
	{
		printf("Queue is Full, Can not Enqueue.\n");
		return;
	}
	
	printf("Enter value for insert = ");
	scanf("%d",&value);
	
	if(front==-1 && rear==-1)
	{
		front = rear = 0;
	}
	else if(front==0)
	{
		front = SIZE-1;
	}
	else
	{
		front--;
	}
	Dqueue[front] = value;
	printf("%d value inserted succesfully.\n",value);
	return;
}

void EnQueue_R()
{
	int value = 0;
	
	if((front==0 && rear==SIZE-1) || (front==rear+1))
	{
		printf("Queue is Full, Can not Enqueue.\n");
		return;
	}
	
	printf("Enter value for insert = ");
	scanf("%d",&value);
	
	if(front==-1 && rear==-1)
	{
		front = rear = 0;
	}
	else if(rear==SIZE-1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	Dqueue[rear] = value;
	printf("%d value inserted succesfully.\n",value);
	return;
}

void DeQueue_F()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty, can not deqeue\n");
		return;
	}
	
	if(front==rear)
	{
		printf("%d element deleted from queue.\n",Dqueue[front]);
		front = rear = -1;
	}
	else if(front==SIZE-1)
	{
		printf("%d element deleted from queue.\n",Dqueue[front]);
		front = 0;
	}
	else
	{
		printf("%d element deleted from queue.\n",Dqueue[front]);
		front++;
	}
	return;
}

void DeQueue_R()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty, can not deqeue\n");
		return;
	}
	
	if(front==rear)
	{
		printf("%d element deleted from queue.\n",Dqueue[rear]);
		front = rear = -1;
	}
	else if(rear==0)
	{
		printf("%d element deleted from queue.\n",Dqueue[rear]);
		rear = SIZE-1;
	}
	else
	{
		printf("%d element deleted from queue.\n",Dqueue[rear]);
		rear--;
	}
	return;
}

void Display()
{
	int temp = front;
	
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty.\n");
	}
	else
	{
		while(temp!=rear)
		{
			printf("%d\n",Dqueue[temp]);
			temp = (temp+1)%SIZE;
		}
		printf("%d\n",Dqueue[temp]);
	}
	return;
}

void Front()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty.\n");
	}
	else 
	{
		printf("Front = %d.\n",Dqueue[front]);
	}
	return;
}

void Rear()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty.\n");
	}
	else 
	{
		printf("Front = %d.\n",Dqueue[rear]);
	}
	return;
}
