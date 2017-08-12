#include<stdio.h>
struct queue {
 int data;
 struct queue * link;
};
struct queue *head_q1 = NULL;
struct queue *tail_q1 = NULL;
struct queue *head_q2 = NULL;
struct queue *tail_q2 = NULL;

void enqueue(struct queue **head, struct queue **tail, int data)
{
struct queue *temp = (struct queue *)(malloc (sizeof(struct queue)));
temp->data = data;
temp->link = NULL;
if(*tail!= NULL)
{
    (*tail)->link = temp;
    *tail = temp;
}
if(*head == NULL && *tail == NULL)
{
    *head = temp;
    *tail = temp;
}

}

int dequeue(struct queue **head , struct queue **tail)
{
int data;
struct queue *temp;
if(*head == NULL)
{
   return NULL;
}
data = (*head)->data;
temp = *head;
if(*head == *tail)
{
   *head = NULL;
   *tail = NULL;
}
else {
   *head = (*head)->link;
}
free(temp);
return data;
}

int isEmpty(struct queue *head)
{
if(head==NULL)
return 1;
else
return 0;
}

void push (int data) {
     if(head_q1 == NULL && head_q2 == NULL)
     { 
         enqueue(&head_q1,&tail_q1, data);    
     }
     else if(head_q1==NULL)
     {
       enqueue(&head_q2, &tail_q2,data);
     }
     else
     {
       enqueue(&head_q1,&tail_q1, data);
     }
}
int pop() {
    int data = NULL;
    if(!isEmpty(head_q1))
    {
        while(head_q1!=NULL)
        {
          data = dequeue(&head_q1,&tail_q1);
          if(head_q1!=NULL)
              enqueue(&head_q2, &tail_q2, data);
        }
    }
    else if(!isEmpty(head_q2))
    {
       while(head_q2 != NULL)
       {  
          data = dequeue(&head_q2,&tail_q2);
          if(head_q2!=NULL)
              enqueue(&head_q1, &tail_q1, data);
       }
    }
    return data;
}

void main()
{
push(10);
push(20);
push(30);
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
push(100);
push(200);
push(300);
printf("%d ",pop());
printf("%d ",pop());
push(1000);
push(2000);
push(3000);
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
}
