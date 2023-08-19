#include<stdio.h>
#define SIZE 10
int stack[SIZE] = {0};
int top = -1;
int temp = top;
//function prototype
void Push();
void Pop();
void isFull();
void isEmpty();
void Peek();
void Pop_index();
void Display_H();
void Display_V();
int Count();
void Search();

int main()
{
	int choice;
	int cnt = 0;
	
	while(1)
	{
		puts("\n*****START MENU*****");
		puts("1. Push");
		puts("2. Pop");
		puts("3. is Full");
		puts("4. is Empty");
		puts("5. Peek");
		puts("6. Display");
		puts("7. Count");
		puts("8. Search");
		puts("10. Exit");
		puts("*****MENU END*****");
		
		printf("Enter choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
					Push();
					break;
			case 2:
				    printf("\n **Menu for Display**\n");
			       	puts("1.Pop only peek element");
			        puts("2.Pop elements upto particular index\n");
			     
			     	printf("Enter your choice = ");
			     	scanf("%d",&choice);
			     	
			     	switch(choice)
			     	{
			     		case 1: 
			     				Pop();
			     				break;
			     		case 2: 
			     				Pop_index();
			     				break;
			     		default:
			     			    printf("Invalid choice..\n");
					 }
				    break;
			case 3:
				    isFull();
				    break;
			case 4:
				    isEmpty();
				    break;
			case 5: 
					Peek();
					break;
			case 6:
				    printf("\n **Menu for Display**\n");
			       	puts("1.Display Horizontally");
			        puts("2.Display Vertically\n");
			     
			     	printf("Enter your choice = ");
			     	scanf("%d",&choice);
			     	
			     	switch(choice)
			     	{
			     		case 1: 
			     				Display_H();
			     				break;
			     		case 2: 
			     				Display_V();
			     				break;
			     		default:
			     			    printf("Invalid choice..\n");
					 }
				    break;
			case 7:
				    cnt = Count();
				    printf("Total elements in stack = %d\n",cnt);
				    break;
			case 8:
				   Search();
				   break;
			case 10:
				   return 0;
			default:
				   printf("Invalid choice..\n");
			}
				   
		}
		return 0;
}

void isEmpty()
{
	if(top==-1)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("Stack is not empty.\n");
	}
	return;
}

void isFull()
{
	if(top==SIZE-1)
	{
		printf("Stack is full.\n");
	}
	else
	{
		printf("Stack is not full.\n");
	}
	return;
}

void Push()
{
	int value;
	
	printf("Enter value = ");
	scanf("%d",&value);
	
	if(top==SIZE-1)
	{
		printf("Stack is full..can not push.\n");
	}
	else
	{
		top++;
		temp = top;
		stack[top] = value;
	}
	return;
}

void Pop()
{
	int value;
	
	if(top==-1)
	{
		printf("Stack is empty..can not pop.\n");
	}
	else
	{
		 	top--;	
	}
	temp = top;
	printf("pop peek element successfully...\n");
	return;
}

void Pop_index()
{
	int value,index;
	
	printf("Enter index to pop elements upto this index = ");
	scanf("%d",&index);
	
	if(index<0 || index>top)
	{
		printf("Invalid index..\n");
		return;
	}
	
	if(top==-1)
	{
		printf("Stack is empty..can not pop.\n");
	}
	else
	{
		for(int i=index;i<=temp;i++)
		{
		 	top--;	
		}
	}
	temp = top;
	printf("pop elements successfully...\n");
	return;
}

void Peek()
{
	if(top==-1)
	{
		printf("Stack is empty..!!\n");
	}
	else
	{
	//	printf("Top by temp = %d\n",temp);
	//	printf("Top by top = %d\n",top);
		printf("Peek = %d\n",stack[top]);
	}
	return;
}

void Display_H()
{
	if(top==-1)
	{
		printf("Stack is empty..!!\n");
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			printf("%d ",stack[i]);
		}
	}
	return;
}

void Display_V()
{
	if(top==-1)
	{
		printf("Stack is empty..!!\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
	return;
}

int Count()
{
	int cnt = 0;
	
	if(top==-1)
	{
		return cnt;
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			cnt++;
		}
		return cnt;
	}
}

void Search()
{
	int value = 0;
	int flag = 0;
	
	printf("Enter value to search = ");
	scanf("%d",&value);
	
	for(int i=0;i<=top;i++)
	{
		if(value==stack[i])
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		printf("Value found.\n");
	}
	else
	{
		printf("Value not found.\n");
	}
	return;
}
