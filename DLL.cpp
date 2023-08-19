#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

struct student
{
	 struct student* prev;
	 int data;
	 struct student* next;
};
typedef struct student NODE;
typedef struct student* PNODE;
typedef struct student** PPNODE;
typedef int BOOL;

//function declarations
BOOL InsertFirst(PPNODE,int);
BOOL InsertLast(PPNODE,int);
BOOL Display(PPNODE);
BOOL Count_Node(PPNODE);
BOOL Search(PPNODE,int);
BOOL DeleteFirst(PPNODE);
BOOL DeleteLast(PPNODE);
BOOL InsertBetween(PPNODE,int,int);
BOOL DeleteBetween(PPNODE,int);

int main()
{
	PNODE head = NULL;
	
	int cnt = 0;
	int ret = 0;
	int value = 0,choice = 0,pos = 0;
	
	while(1)
	{
	puts("\n*****Menu Started*****");
	puts("1.Display");
	puts("2.Count Node");
	puts("3.Insert First");
	puts("4.Insert Last");
	puts("5.Insert Between");
	puts("6.Delete first");
	puts("7.Delete Last");
	puts("8.Delete Between");
	puts("9.Delete All");
	puts("10.Delete Mid");
	puts("11.Search");
	puts("100.Exit");
	puts("*****Menu End*****");
	printf("Enter your choice = ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			    Display(&head);
			    break;
		case 2:
			    cnt = Count_Node(&head);
			    printf("Total nodes = %d\n",cnt);
			    break;
		case 3:
			    printf("Enter value to insert = ");
			    scanf("%d",&value);
			    InsertFirst(&head,value);
			    break;
		case 4: 
		        printf("Enter value to insert = ");
			    scanf("%d",&value);
			    InsertLast(&head,value);
			    break;
		case 5: 
				printf("Enter position to insert value = ");
				scanf("%d",&pos);
				printf("Enter value to insert = ");
				scanf("%d",&value);
			    InsertBetween(&head,pos,value);
			    break;
		case 6: 
			    DeleteFirst(&head);
			    break;
		case 7: 
			    DeleteLast(&head);
			    break; 
		case 8: 
				printf("Enter position to delete = ");
				scanf("%d",&pos);
			    DeleteBetween(&head,pos);
			    break;
		case 9: 
			    //DeleteAll();
			    break; 
		case 10: 
			    //DeleteMid();
			    break;
		case 11: 
				printf("Enter value to search = ");
  			    scanf("%d",&value);
			    ret = Search(&head,value);
			    if(ret==1)
			    {
			    	printf("%d value is found.\n",value);
				}
				else
				{
					printf("%d value is not found.\n",value);
				}
			    break;
		case 100:
			    return 0;
		default : 
		           printf("Sorry....invalid choice\n");
	}
  }	
	return 0;
}

int InsertFirst(PPNODE hptr,int value)
{
	PNODE NewNode = NULL;
	NewNode = (PNODE)malloc(sizeof(NODE));
	
	if(NewNode==NULL)
	{
		printf("Memory allocation failed.\n");
		return FALSE;
	}
	NewNode->data = value;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	
	if(*hptr==NULL)
	{
		*hptr = NewNode;
	}
	else
	{
		NewNode->next = *hptr;
		(*hptr)->prev = NewNode;
		*hptr = NewNode;
	}
	return TRUE;
}

BOOL Display(PPNODE hptr)
{
	PNODE temp = *hptr;
	
	if(temp==NULL)
	{
		printf("List is empty.\n");
		return FALSE;
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
	return TRUE;
}

BOOL InsertLast(PPNODE hptr,int value)
{
	PNODE NewNode = NULL;
	PNODE temp = *hptr;
	
	NewNode = (PNODE)malloc(sizeof(NODE));
	
	if(NewNode==NULL)
	{
		printf("Memory allocation failed.\n");
		return FALSE;
	}
	NewNode->data = value;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	
	if(*hptr==NULL)
	{
		*hptr = NewNode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
		NewNode->prev = temp;
	}
	return TRUE;
}

BOOL Count_Node(PPNODE hptr)
{
	PNODE temp = *hptr;
	int cnt = 0;
	
	if(temp==NULL)
	{
		return cnt;
	}
	else
	{
		while(temp->next!=NULL)
		{
			cnt++;
			temp = temp->next;
		}
		cnt++;
	}
	return cnt;
}

int Search(PPNODE hptr,int value)
{
	PNODE temp = *hptr;
	int flag = 0;
	
	if(*hptr==NULL)
	{
		return -1;
	}
	else
    {
    	while(temp->next!=NULL)
    	{
    		if(temp->data==value)
    		{
    			flag = 1;
    			break;
			}
			temp = temp->next;
		}
		if(temp->data==value)
		{
			flag = 1;
		}
	}
	return flag;
}

BOOL DeleteFirst(PPNODE hptr)
{
	PNODE temp = *hptr;
	
	if(*hptr==NULL)
	{
		printf("Sorry..! List is empty. you can't delete any node.\n");
		return FALSE;
	}
	else
	{
		*hptr = temp->next;
		free(temp);
	}
	printf("Node deleted successfully.\n");
	return TRUE;
}

BOOL DeleteLast(PPNODE hptr)
{
	PNODE temp = *hptr;
	
	if(*hptr==NULL)
	{
		printf("Sorry..! List is empty. you can't delete any node.\n");
		return FALSE;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		*hptr = NULL;
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
	printf("Node deleted successfully.\n");
	return TRUE;
}

BOOL InsertBetween(PPNODE hptr,int pos,int value)
{
	PNODE temp = *hptr;
	PNODE NewNode = NULL;
	
	NewNode = (PNODE)malloc(sizeof(NODE));
	
	if(NewNode==NULL)
	{
		printf("Insufficient memory.\n");
		return FALSE;
	}
	
	NewNode->prev = NULL;
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(pos<1 || pos>Count_Node(hptr)+1)
	{
		printf("Invalid position.\n");
		return FALSE;
	}
	
	if(pos==1)
	{
			if(*hptr==NULL)
		{
			*hptr = NewNode;
		}
			else
		{
			NewNode->next = *hptr;
			(*hptr)->prev = NewNode;
			*hptr = NewNode;
		}
	}
	else if(pos==Count_Node(hptr)+1)
	{
			if(*hptr==NULL)
		{
			*hptr = NewNode;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
			NewNode->prev = temp;
		}
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		NewNode->prev = temp;                   
		NewNode->next = temp->next;		        
		temp->next->prev = NewNode;				
		temp->next = NewNode;                    
	}
	return TRUE;
}

BOOL DeleteBetween(PPNODE hptr,int pos)
{
	PNODE temp = *hptr;
	PNODE temp1 = NULL;
	
	if(pos<1 || pos>Count_Node(hptr)+1)
	{
		printf("Invalid position.\n");
		return FALSE;
	}
	
	if(pos==1)
	{
			if(*hptr==NULL)
		{
			printf("Sorry..! List is empty. you can't delete any node.\n");
			return FALSE;
		}
			else
		{
			*hptr = temp->next;
			free(temp);
		}
		printf("Node deleted successfully.\n");
	}
	else if(pos==Count_Node(hptr))
	{
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		printf("Node deleted successfully.\n");
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
	return TRUE;
}

