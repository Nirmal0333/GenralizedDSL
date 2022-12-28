#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head, int no)
{
	//Allocate memory for node(Dynamically)
	//Initialise that node
	
	//check whether LL is empty or not
	//If LL is empty then new node is the first node so update its address in first pointer through head
	
	//If LL is not empty then
	//travel till last node of LL
	//store address of new node in the next pointer of the last node
	
	PNODE newn  = NULL;
	
	newn  = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*head == NULL) // if LL is empty
	{
		*head = newn;
	}
	else		//if LL contains atleast one node
	{
		newn -> next = *head;
		*head = newn;
	}
}
void InsertLast(PPNODE head, int no)
{
	//Allocate memory for node(Dynamically)
	//Initialise that node
	
	//check whether LL is empty or not
	//If LL is empty then new node is the first node so update its address in first pointer through head
	
	//If LL is not empty then
	//travel till last node of LL
	//store address of new node in the next pointer of the last node
	
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	newn  = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*head == NULL) // if LL is empty
	{
		*head = newn;
	}
	else		//if LL contains atleast one node
	{
		//travel till last node
		//store address of new node in the next pointer of the last node
		temp = *head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void Display(PNODE head)
{
	printf("Elements from linked list are :\n");
	
	while(head != NULL)
	{
		printf("| %d | -> ", head->data);
		head = head -> next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	while(head != NULL)
	{
		iCnt++;
		head = head -> next;
	}
	return iCnt;
}

void DeleteFirst(PPNODE head)
{
	//If LL is empty then return
	//If LL contains atleast one node then
	//store the address of second node in the first pointer through head-
	//And delete the first node
	PNODE temp = NULL;
	
	if(*head==NULL)		//LL is empty
	{
		return;
	}
	else			// LL contains atleast one node
	{
		temp  = *head;
		*head = temp->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	//If LL is empty then return
	//If LL contains one node then delete that node and return
	//If LL contains more than one node then travel till second last node and delete last node
	
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
	}
	else if((*head) -> next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = *head;
		while(temp->next->next != NULL)
		{
			temp = temp -> next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

void InsertAtPos(PPNODE head, int no, int pos)
{
	//consider no of node are 4
	
	//If position is invalid then return directly (< 1 or  > 5)
	//If position is 1 then call insertfirst
	//If position is N+1 then call insertlast (position is 5)
	
	int size = 0, iCnt = 0;
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	size = Count(*head);
	
	if((pos <1) || (pos >(size+1)))
	{
		printf("Position is invalid\n");
		return;
	}
	
	 if(pos == 1)
	 {
		 InsertFirst(head, no);
	 }
	 else if(pos == (size+1))
	 {
		 InsertLast(head, no);
	 }
	 else
	 {
		PNODE newn = NULL;
		newn = (PNODE)malloc(sizeof(NODE));
		//newn = (struct node *)malloc(12);
		
		newn->data = no;
		newn->next = NULL;
		
		temp = *head;
		
		for(iCnt =1; iCnt < pos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		newn -> next = temp ->next;
		temp -> next = newn;
	 }
}

void DeleteAtPos(PPNODE head, int pos)
{
	//consider no of node are 4
	
	//If position is invalid then return directly (< 1 or  > 4)
	//If position is 1 then call deletefirst
	//If position is N then call deletelast (position is 5)
	
	int size = 0, iCnt = 0;
	PNODE temp = NULL;
	PNODE tempdelete = NULL;
	
	size = Count(*head);
	
	if((pos <1) || (pos >(size)))
	{
		printf("Position is invalid\n");
		return;
	}
	
	 if(pos == 1)
	 {
		 DeleteFirst(head);
	 }
	 else if(pos == (size))
	 {
		 DeleteLast(head);
	 }
	 else
	 {
		temp = *head;
		
		for(iCnt =1; iCnt < pos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		tempdelete = temp->next;
		temp->next = temp->next->next;
		free(tempdelete);
	 }
}

int Maximum(PNODE head)
{
	int Max = 0;
	
	while(head != NULL)
	{
		if(Max < head -> data)
		{
			Max = head -> data;
			head = head -> next;
		}
	}
	return Max;
}

/*int Minimum(PNODE head)
{
	int Min = 0;
	
	while(head != NULL)
	{
		if(Min > head -> data)
		{
			Min = head -> data;
			head = head -> next;
		}
	}
	return Min;
}
*/

void Additon(PNODE head)
{
	int Add = 0;
	
	if(head == NULL)
	{
		return;
	}
	if(head -> data == NULL)
	{
		Add = Add + head -> data;
		head  =  head -> next;
	}
	printf("Additonof all nodes are :%d\n");
}

int Middle(PNODE head)
{
	PNODE slow = head;
	PNODE fast = head;
	
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow -> data;
}

int main()
{
	int iRet = 0;
	PNODE first = NULL;
	
	InsertFirst(&first,101);			//Call by address
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	InsertAtPos(&first,75,3);
	
	DeleteAtPos(&first,3);
	
	Display(first);		//Call by value
	
	iRet = Count(first);
	printf("Number of nodes are : %d\n", iRet);
	
	InsertFirst(&first, 1);
	Display(first);		//Call by value
	
	iRet = Count(first);
	printf("Number of nodes are : %d\n", iRet);
	
	InsertLast(&first, 111);
	InsertLast(&first, 121);
	
	Display(first);		//Call by value
	
	iRet = Count(first);
	printf("Number of nodes are : %d\n", iRet);
	
	DeleteFirst(&first);
	DeleteFirst(&first);
	
	Display(first);		//Call by value
	
	iRet = Count(first);
	printf("Number of nodes are : %d\n", iRet);
	
	DeleteLast(&first);
	
	Display(first);		//Call by value
	
	iRet = Count(first);
	printf("Number of nodes are : %d\n", iRet);
	
	iRet = Maximum(first);
	printf("Maximum no of nodes are : %d\n", iRet);
	
	//iRet = Minimum(first);
	//printf("Minimum no of nodes are : %d\n", iRet);
	
	Additon(first);
	
	iRet = Middle(first);
	printf("Middle no of node are : %d\n", iRet);
	return 0;
}
