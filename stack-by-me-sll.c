#include<stdio.h>
#include<stdlib.h>
#include <limits.h> 

struct stacknode
{
    int data;
    struct stacknode *next;
};
typedef struct stacknode sn;

int isEmpty(sn *root) 
{ 
return !root;
} 

sn push(sn **node,int data)
{
  sn *new = (sn *)malloc(sizeof(sn));
    new->next = NULL;
    new->data = data;
    new->next= *node;
    *node=new;
}
int pop(sn **head)
{
    if(isEmpty(*head))
          return INT_MIN;
    sn *temp = *head;
    int popped=temp->data;
    free(temp);
    *head=(*head)->next;
    return popped;

}

int main()
{
sn *head =NULL;
int ch,data=0;

while(1)
{   
    printf("\n1. push-stack 2. pop 3.exit\n");

    printf("Enter ur choice:");
    scanf("%d",&ch);

switch(ch)
{
 
case 1 : printf("\nEnter data:");
         scanf("%d",&data);
         push(&head,data);
         break;

case 2 : printf("pop = %d",pop(&head));
         break;
case 3 : printf("\nExiting...\n");
         return 0;
}

}
}
