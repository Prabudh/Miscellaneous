#include<stdio.h>
typedef struct linkedList {
int data;
struct linkedList * next;
} lL;

void push(lL **head, int data)
{
lL *temp = (lL*)malloc(sizeof(lL));
temp->data = data;
temp->next = NULL;
if(*head == NULL)
{
*head = temp;
}
else
{
temp->next = *head;
*head = temp;
}
}

int pop(lL **head)
{
if(*head == NULL)
    return NULL;
else
{
lL *temp = *head;
int data = temp->data;
*head = temp->next;
free(temp);
return data;
}
}

int peek(lL *head)
{
if(head==NULL)
return NULL;

return head->data; 
}

sortList(int data,lL **head)
{
    if(*head==NULL || (data<peek(*head)))
        push(head,data);
    else
    {
       int temp = pop(head);
       sortList(data,head);
       push(head,data);
    }
}


sortStack(lL **head)
{
if(*head!=NULL)
{
     int temp = pop(head);
     sortStack(head);
     sortList(temp,head);
}
}

int main()
{
//create Stack
lL *head = NULL;
push(&head,7);
push(&head, 6);
push(&head, 5);
push(&head, -1);
sortStack(&head);
int dat;
while(peek(head)!=NULL)
{
   printf("%d, ",pop(&head));
}
printf("\n");
}
