#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack* next;
};
typedef struct stack STACK;
typedef struct stack* PSTACK;
typedef struct stack** PPSTACK;

int isEmpty(PSTACK top);
void Push(PPSTACK,int);
void Display(PPSTACK);
void Pop(PPSTACK);
void Peek(PPSTACK);

int main()
{
	PSTACK top = NULL;
	
	int choice,ret,value;
	
	while(1)
	{
		puts("\n*****STACK MENU******");
		puts("1.isEmpty");
		puts("2.Push");
		puts("3.Pop");
		puts("4.Peek");
		puts("5.Display");
		puts("10.Exit");
		
		printf("Enter your choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					ret = isEmpty(top);
					if(ret==1)
					{
						printf("Stack is empty.\n");
					}
					else
					{
						printf("Stack is not empty.\n");
					}
					break;
			case 2:
					printf("Enter value to insert = ");
			    	scanf("%d",&value);
			    	Push(&top,value);
					break;
			case 3:
					Pop(&top);
					break;
			case 4:
					Peek(&top);
					break;
			case 5:
					Display(&top);
					break;
			case 10:
					return 0;
			default:
					printf("Invalid choice..");		
		}
	}
	return 0;
}

int isEmpty(PSTACK top)
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void Push(PPSTACK top,int value)
{
	PSTACK temp = *top;
	PSTACK ptr = NULL;
	
	ptr = (PSTACK)malloc(sizeof(STACK));
	
	if(ptr==NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(*top==NULL)
	{
		*top = ptr;
		ptr->next = NULL;
		//top++;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
			//top++;
		}
		temp->next = ptr;
	}
//	printf("Top = %d\n",top);
	return;
}

void Display(PPSTACK top)
{
	PSTACK temp = *top;
	
	//printf("Top = %d\n",top);
	//printf("Top = %d\n",top);
	if(*top==NULL)
	{
		printf("Stack is empty..!!\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("%d->",temp->data);
	}
	return;
}

void Pop(PPSTACK top)
{
	PSTACK temp = *top;
	
	if(*top==NULL)
	{
		printf("Stack is empty..You can not pop.\n");
	}
	else if(temp->next==NULL)
	{
		free(temp);
		*top = NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
	return;
}

void Peek(PPSTACK top)
{
	PSTACK temp = *top;
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	printf("Peek = %d\n",temp->data);
	
	return;
}

