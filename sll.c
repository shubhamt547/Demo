#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node n1;

n1 *addbegin(n1 **,int data);
n1 *addend(n1 **,int data);
n1 *addposition(n1 **,int ,int );
void print(n1 *);

struct node 
{
int data;
struct node *next;

};

n1 *reversal(n1 **head_ref)
{
n1 *first,*rest;
 if (*head_ref == NULL) 
       return 0;    
  
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;   
    rest  = first->next; 
  
    /* List has only one node */
    if (rest == NULL) 
       return;    
  
    /* reverse the rest list and put the first element at the end */
    reversal(&rest); 
    first->next->next  = first;   
      
    /* tricky step -- see the diagram */
    first->next  = NULL;           
  
    /* fix the head pointer */
    *head_ref = rest;  
}

int main()
{
n1 *head=NULL;
int choice;
int data=0,pos=0;
while(1)
{

printf("1.add-begin 2.print 3.Exit 4.add-end 5.add-at-position 6.reverse\n");
printf("Enter ur choice:\n");
scanf("%d",&choice);

switch(choice)
{

case 1 : printf("Enter data:");
	 scanf("%d",&data);
	 addbegin(&head,data);
	 break;
case 2 : print(head);
	 break;
case 3 : printf("Exiting...\n");
	 return 0;
case 4 : printf("Enter data:");
	 scanf("%d",&data);
	 addend(&head,data);
	 break;
case 5 : printf("Enter data:");
         scanf("%d",&data);
	 printf("Enter Position:");
	 scanf("%d",&pos);
         addposition(&head,data,pos);
         break;	
case 6 : reversal(&head);
	break;
}

}
}

n1 *addposition(n1 **node ,int data,int pos)
{
pos=pos-1;
n1 *nu=(n1 *)malloc(sizeof(n1));
nu->next=NULL;
nu->data=data;
n1 *ref=*node;
while(pos-1)
{
ref=ref->next;
pos--;
}
nu->next=ref->next;
ref->next=nu;

}



n1 *addend(n1 **node,int data)
{
n1 *nu=(n1 *)malloc(sizeof(n1));
n1 *ref;
ref=*node;
if(nu==NULL)
{
printf("memory allocation failed.\n");
}
nu->data=data;
nu->next=NULL;

if(*node==NULL)
{
nu->next=*node;
*node=nu;
}
while(ref->next !=NULL)
{
ref=ref->next;
}
ref->next=nu;
}

n1 *addbegin(n1 **node,int data)
{
n1 *new=(n1 *)malloc(sizeof(n1));
if(new==NULL)
{
printf("Memory allocation failed\n");
}

new->data=data;
new->next=*node;
*node = new;
}

void print(n1 *ptr)
{
	while(ptr!=NULL)
	{
	printf("data=%d\n",ptr->data);
	ptr=ptr->next;

	}
}



