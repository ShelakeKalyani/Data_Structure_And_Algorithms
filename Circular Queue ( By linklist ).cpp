#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue* next;
};

//function declarations
void Enqueue(struct queue**,struct queue**,int);
void Display(struct queue**);
void Dequeue(struct queue**,struct queue**);
void Front(struct queue**);
void Rear(struct queue**);
void IsEmpty(struct queue**,struct queue**);

int main()
{
	struct queue* front = NULL;
	struct queue* rear = NULL;
	int choice,value;
	
	while(1)
	{
		puts("\n*****QUEUE MENU*****");
		puts("1.Enqueue");
		puts("2.Dequeue");
		puts("3.Display");
		puts("4.Front(peek)");
		puts("5.Rear");
		puts("6.is Empty");
		puts("10.Exit");
		
		printf("Enter choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					printf("Enter value to be insert = ");
				    scanf("%d",&value);
				    Enqueue(&rear,&front,value);
					break;
			case 2:
					Dequeue(&front,&rear);
					break;
			case 3:
					Display(&front);
					break;
			case 4:
					Front(&front);
					break;
			case 5:
					Rear(&rear);
					break;
			case 6:
					IsEmpty(&front,&rear);
					break;
			case 10:
					return 0;
			default:
					printf("Invalid choice..\n");
		}
	}
	return 0;
}

void Enqueue(struct queue** Rptr,struct queue** Fptr,int value)
{
	struct queue* NewNode = NULL;
	struct queue* temp = *Fptr;
	
	NewNode = (struct queue*)malloc(sizeof(struct queue));
	
	if(NewNode==NULL)
	{
		printf("Memory not allocated.\n");
		return;
	}
	
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(*Rptr==NULL && *Fptr==NULL)                       // here *hptr and head are same
	{
		*Rptr         = NewNode;
		*Fptr         = NewNode;
		NewNode->next = NewNode;            // here *hptr and NewNode are same
	}
	else
	{
		while(temp->next!=*Fptr)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
		*Rptr = NewNode; 
		NewNode->next = *Fptr;
	}
	return;
}

void Display(struct queue** Fptr)
{
	struct queue* temp = *Fptr;
	
	if(*Fptr==NULL)
	{
		printf("List is empty.\n");
	}
	else 
	{
	while(temp->next!=*Fptr)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
       printf("%d->",temp->data);
   }
   return;
}

void Dequeue(struct queue** Fptr,struct queue** Rptr)
{
	struct queue* temp = *Fptr;
	struct queue* temp1 = *Fptr;
	
	if(*Fptr==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if(temp->next==*Fptr)
	{
		free(temp);
		*Fptr = NULL;
		*Rptr = NULL;
	}
	else
	{
		while(temp->next!=*Fptr)
		{
			temp = temp->next;
		}
		*Fptr = temp1->next;
		free(temp1);
		temp->next = *Fptr;
	}
	printf("Element dequed succesfully.\n");
	return;
}

void Front(struct queue** Fptr)
{
	struct queue* temp = *Fptr;
	
	printf("Front (Peek) = %d\n",temp->data);
	return;
}

void Rear(struct queue** Rptr)
{
	struct queue* temp = *Rptr;
	
	printf("Rear = %d\n",temp->data);
	return;
}

void IsEmpty(struct queue** Fptr,struct queue** Rptr)
{
	if(*Fptr==NULL && *Rptr==NULL)
	{
		printf("Queue is Empty.\n");
	}
	else
	{
		printf("Queue is not Empty.\n");
	}
}
