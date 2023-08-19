#include<stdio.h>
#include<stdlib.h>
//Node creation
struct node
{
	int data;
	struct node* next;
};

// function declarations

void InsertFirst(struct node**,int);
void Display(struct node**);
int Count_Node(struct node** hptr);  // for insert = 1 pointer
void InsertLast(struct node**,int);    //  for insert = 2 pointer
void DeleteFirst(struct node**);
void DeleteLast(struct node**);
void Search(struct node**,int);
void InsertBetween(struct node**,int);
void DeleteBetween(struct node**);

//main function

int main()
{
	struct node* head = NULL;  //head pointer creation
	
	int cnt = 0;
	int value = 0,choice = 0;
	
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
			    printf("Enter value to be insert = ");
				scanf("%d",&value);
			    InsertFirst(&head,value);
			    break;
		case 4: 
				printf("Enter value to be insert = ");
				scanf("%d",&value);
			    InsertLast(&head,value);
			    break;
		case 5: 
		        printf("Enter value to be insert = ");
				scanf("%d",&value);
			    InsertBetween(&head,value);
			    break;
		case 6: 
			    DeleteFirst(&head);
			    break;
		case 7: 
			   DeleteLast(&head);
			    break; 
		case 8: 
			    DeleteBetween(&head);
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
			    Search(&head,value);
			    break;
		case 100:
			    return 0;
		default : 
		           printf("Sorry....invalid choice\n");
	}
  }	
	return 0;
}

// Function Definitions
void InsertFirst(struct node** hptr,int value)
{
	struct node* NewNode = NULL;
	struct node* temp = *hptr;
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	if(NewNode==NULL)
	{
		printf("Memory not allocated.\n");
		return;
	}
	
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(*hptr==NULL)                       // here *hptr and head are same
	{
		*hptr         = NewNode;
		NewNode->next = *hptr;            // here *hptr and NewNode are same
	}
	else
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		NewNode->next = *hptr;
		*hptr 		  = NewNode;
		temp->next 	  = *hptr;
		
	}
	return;
}
void Display(struct node** hptr)
{
	struct node* temp = *hptr;
	int cnt = 0;
	
	if(*hptr==NULL)
	{
		printf("List is empty.\n");
	}
	else 
	{
	while(temp->next!=*hptr)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
       printf("%d->",temp->data);
   }
   return;
}

int Count_Node(struct node** hptr)
{
	struct node* temp = *hptr;
	int cnt = 0;
	
	if(*hptr==NULL)
	{
		return cnt;
	}
	else
	{
		while(temp->next!=*hptr)
		{
			cnt++;
			temp = temp->next;
		}
		cnt++;
	}
	return cnt;
}

void InsertLast(struct node** hptr,int value)
{
	struct node* NewNode = NULL;
	struct node* temp = *hptr;
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	if(NewNode==NULL)
	{
		printf("Memory not allocated.\n");
		return;
	}
	
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(*hptr==NULL)                       // here *hptr and head are same
	{
		*hptr         = NewNode;
		NewNode->next = NewNode;            // here *hptr and NewNode are same
	}
	else
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
		NewNode->next = *hptr;
	}
	return;
	
}

void DeleteFirst(struct node** hptr)
{
	struct node* temp = *hptr;
	struct node* temp1 = *hptr;
	
	if(*hptr==NULL)
	{
		printf("List is empty.\n");
	}
	else if(temp->next==*hptr)
	{
		free(temp);
		*hptr = NULL;
	}
	else
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		*hptr = temp1->next;
		free(temp1);
		temp->next = *hptr;
	}
	return;
}

void DeleteLast(struct node** hptr)
{
	struct node* temp = *hptr;
	if(*hptr==NULL)
	{
		printf("List is empty.\n");
	}
	else if(temp->next==*hptr)
	{
		free(temp);
		*hptr = NULL;
	}
	else
	{
		while(temp->next->next!=*hptr)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = *hptr;
	}
	return;
}

void Search(struct node** hptr,int value)
{
   struct node* temp = *hptr;
   int flag = 0;
   
   if(*hptr==NULL)
   {
   	printf("Sorry...List is empty.\n");
   }	
   else
   {
   while(temp->next!=*hptr)
   {
   	if(value==temp->data)
   	{
   		flag = 1;
   		break;
	}
   	temp = temp->next;
   }
}
   if(value==temp->data)
   	{
   		flag = 1;
	}
   if(flag==0)
   {
   	printf("Value not found.\n");
   }
   else
   {
   	printf("Value found.\n");
   }
   
   return;
}

void InsertBetween(struct node** hptr,int value)
{
	struct node* NewNode = NULL;
	struct node* temp = *hptr;
	int pos = 0;
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	if(NewNode==NULL)
	{
		printf("Memory not allocated.\n");
		return;
	}
	printf("Enter position = ");
	scanf("%d",&pos);
	
	if(pos<1 || pos>Count_Node(hptr)+1)
	{
		printf("Invalid position.\n");
		return;
	}
	
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(pos==1)
{
		if(*hptr==NULL)                       // here *hptr and head are same
	{
		*hptr         = NewNode;
		NewNode->next = *hptr;            // here *hptr and NewNode are same
	}
	else
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		NewNode->next = *hptr;
		*hptr 		  = NewNode;
		temp->next 	  = *hptr;
		
	}
}
	else if(pos==Count_Node(hptr)+1)
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
		NewNode->next = *hptr;
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		NewNode->next = temp->next;
		temp->next = NewNode;
	} 
	return;
}

void DeleteBetween(struct node** hptr)
{
	struct node* temp = *hptr;
	struct node* temp1 = *hptr;
	int pos = 0;
	
	printf("Enter position = ");
	scanf("%d",&pos);
	
	if(pos==1)
{
		if(*hptr==NULL)
	{
		printf("List is empty.\n");
	}
	else if(temp->next==*hptr)
	{
		free(temp);
		*hptr = NULL;
	}
	else
	{
		while(temp->next!=*hptr)
		{
			temp = temp->next;
		}
		*hptr = temp1->next;
		free(temp1);
		temp->next = *hptr;
	}
}
    else if(pos==Count_Node(hptr))
{
		while(temp->next->next!=*hptr)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = *hptr;
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
   return;
}


