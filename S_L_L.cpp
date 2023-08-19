#include <stdio.h>
#include <stdlib.h>
void Display();
void InsertFirst();
void InsertLast();
int Count_Node();
void InsertBetween();
void DeleteFirst();
void DeleteLast();
void DeleteBetween();
void DeleteMid();
void DeleteAll();
void Search();
void Sort();

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
typedef struct node* PNODE;

PNODE head = NULL;             // head pointer

int main() 
{
	int choice;
	int cnt = 0;
	int no = 0;
	while(1)
	{
	puts("\n*****Link List Start*****");
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
	puts("12.Sort");
	puts("100.Exit");
	puts("*****Link List End*****");
	
	printf("Enter your choice = ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			    Display();
			    break;
		case 2:
			    cnt = Count_Node();
			    printf("Total nodes = %d\n",cnt);
			    break;
		case 3:
			    InsertFirst();
			    break;
		case 4: 
				InsertLast();
			    break;
		case 5: 
			    InsertBetween();
			    break;
		case 6: 
			    DeleteFirst();
			    break;
		case 7: 
			    DeleteLast();
			    break; 
		case 8: 
			    DeleteBetween();
			    break;
		case 9: 
			    DeleteAll();
			    break; 
		case 10: 
			   // DeleteMid();
			    break;
		case 11: 
			    Search();
			    break;
		case 12: 
			    Sort();
			    break;
		case 100:
			    return 0;
		default : 
		           printf("Sorry....invalid choice\n");
	}
 }
	return 0;
}

void Display()
{
	PNODE temp = head;
	
	if(head == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("%d\n",head);
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
	}
	return ;
} 
void InsertFirst()   
{
    PNODE ptr  = NULL;
    PNODE temp = head;
    int value = 0;
    char str[50] = {'\0'};
    
    ptr = (PNODE)malloc(sizeof(NODE));
    
    if(ptr==NULL)
	{
		printf("Insufficient Memory.\n");
	}
    
    printf("Enter value = ");
    scanf("%d",&value);
    
    ptr->data = value;
    ptr->next = NULL;
    
    if(head==NULL)
    {
    	head = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
    return ;
}

void InsertLast()   
{
    PNODE ptr  = NULL;
    PNODE temp = head;
    int value = 0;
    
    ptr = (PNODE)malloc(sizeof(NODE));
    
    if(ptr==NULL)
	{
		printf("Insufficient Memory.\n");
	}
	
    printf("Enter value = ");
    scanf("%d",&value);
    
    ptr->data = value;
    ptr->next = NULL;
    
    if(head==NULL)
    {
    	head = ptr;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
	return;
}

int Count_Node()
{
	int cnt = 0;
	PNODE temp = head;
	
	if(head==NULL)
	{
		return cnt;
	}
	else
	{
		while(temp!=NULL)
		{
			cnt++;
			temp = temp->next;
		}
			return cnt;
	}
}

void InsertBetween()
{
	PNODE ptr = NULL;
	PNODE temp = head;
	int value = 0;
	int pos = 0;
	
	ptr = (PNODE)malloc(sizeof(NODE));
	if(ptr==NULL)
	{
		printf("Insufficient Memory.\n");
		return ;
	}
	printf("Enter position = ");
	scanf("%d",&pos);
	
	if(pos<1 || pos > Count_Node()+1)
	{
		printf("Invalid position.\n");
		return;
	}
	printf("Enter value = ");
	scanf("%d",&value);
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(pos==1)
   {
		 if(head==NULL)
         {
    	    head = ptr;
	     }
	     else
	    {
			ptr->next = head;
			head = ptr;
		}
	//	InsertFirst();
   }
	else if(pos==Count_Node()+1)
	{
			while(temp->next!=NULL)
			{
			   temp = temp->next;
			}
				temp->next = ptr;
			//	InsertLast();
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		ptr->next = temp->next;
		temp->next = ptr;
	} 
	return;
}

void DeleteFirst()
{
	PNODE temp = head;
	
	if(head==NULL)
	{
		printf("List is EMPTY..! you can not delete.\n");
		return;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		head = NULL;
	}
	else
	{
		head = temp->next;
		free(temp);
	}
	printf("Node deleted succesfully.\n");
	return ;
}

void DeleteLast()
{
    PNODE temp = head;
	
	if(head==NULL)
	{
		printf("List is EMPTY..! you can not delete.\n");
		return;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		head = NULL;
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
	printf("Node deleted succesfully.\n");
	return;
} 

void DeleteBetween()
{
	PNODE temp = head;
	PNODE temp1 = NULL;
	int pos = 0;
	
	printf("Enter position = ");
	scanf("%d",&pos);
	
	if(pos<1 || pos>Count_Node())
	{
		printf("Invalid position.\n");
		return;
	}
	
	if(pos==1)
	{
		if(head==NULL)
		{
			printf("List is empty!!You can not delete.\n");
			return;
		}
		else if(temp->next==NULL)
		{
			free(temp);
			head = NULL;
		}
		else
		{
			head = temp->next;
			free(temp);
		}
	}
	else if(pos==Count_Node())
	{
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
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
	printf("Node deleted Succesfully.\n");
	return;
}

void DeleteAll()
{
	/*while(head!=NULL)
	{
		DeleteFirst();
	}  */
	
	 PNODE temp = head;
	if(head==NULL)
	{
		printf("List is empty.\n");
	}
	else if(head->next==NULL)
	{
		free(temp);
		head = NULL;
	}
	else
	{
		while(head!=NULL)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	} 
	printf("All node deleted.\n");
	return;
}

void Search()
{
   PNODE temp = head;
   int value = 0;
   int flag = 0;
   
   if(head==NULL)
   {
   	printf("Sorry...List is empty.\n");
   	return;
   }
   printf("Enter value to search = ");
   scanf("%d",&value);	
   
   while(temp!=NULL)
   {
   	if(value==temp->data)
   	{
   		flag = 1;
   		break;
	}
   	temp = temp->next;
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

/*void DeleteMid()
{
	int mid = Count_Node()/2;
	printf("mid = %d.\n",mid);
	
	while(temp!=)
}*/

void Sort()
{
	 PNODE temp = head;
	 PNODE temp2 = head;
	 PNODE temp3 = head;
	 PNODE min = head;
	 int temp1 = 0;
	 
    if(min==NULL)
   {
   	printf("Sorry...List is empty.\n");
   }
   else
   {
   	//while(temp3!=NULL)
   //	{
   		while(temp->next!=NULL)
   		{
   			if(min->data>temp->data)
   			{
   				temp1 = min->data;
   				min->data = temp->data;
   				temp->data = temp1;
			}
   			temp = temp->next;
		}
	//	temp3 = temp3->next;
 //	}
	
 }
   
}
