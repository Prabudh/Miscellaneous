#include<stdio.h>
#include<stdlib.h>
 
typedef struct node {
   struct node * next;
   struct node *prev;
   int pageNumber;
}node;

typedef struct Queue {
   struct node * front;
   struct node * rear;
   int maxNumberOfElements ;
   int currentNoElements;   
} Queue;

typedef struct hashNode {
   struct node** q_array;
   int key;
}hashNode;

hashNode * createHash(int size)
{
  hashNode* hash = (hashNode*) malloc(sizeof (hashNode));
  hash->q_array = (node **) malloc(size*sizeof(node*));

  for(int i = 0; i<size;i++)
      hash->q_array[i] = NULL;
  return hash;
}

struct Queue * createQueue( int data)
{
struct Queue *temp;
temp = (Queue*)malloc(sizeof(struct Queue));
temp->front = NULL;
temp->rear = NULL;
temp->maxNumberOfElements = data;
temp->currentNoElements = 0;
return temp;
}
/*
struct node * checkIfPagePresent(int i, hashNode **hash)
{
   if(hash->q_array[i] == NULL)
     return NULL;
   else
     return hash->q_array[i];
  
}
*/
void dequeue(Queue *q)
{
   node* qNode = q->rear;
   if(q->rear!=q->front)
   {
      q->rear = q->rear->prev;   
      q->rear->next = NULL;
      free(qNode);
   }
   else
   {
      q->rear = q->front = NULL;
      free(qNode);
   }
}
void enqueue(Queue * q, hashNode * h, int pageNumber)
{
node *temp = (node *) malloc(sizeof(node));
temp->prev = NULL;
temp->next = NULL;
temp->pageNumber = pageNumber;
if(q->currentNoElements == 0)
{
    printf("I cam here\n");
    q->front = q->rear = temp;
    h->q_array[pageNumber] = q->front;
    printf("I cam here\n");
}
else if(q->currentNoElements <= q->maxNumberOfElements)
{
  printf("We came here\n");
  q->front->prev = temp;
  temp->next = q->front;
  temp->prev = NULL;
  q->front = temp;
  h->q_array[pageNumber] = q->front;
}
  else
  {
    h->q_array[q->rear->pageNumber] = NULL;
    dequeue(q);
    //enqueue(q,h,pageNumber);
    q->front->prev = temp;
    temp->next = q->front;
    temp->prev = NULL;
    q->front = temp;
    h->q_array[pageNumber] = q->front;
  }
  q->currentNoElements ++;
}
void referPage(Queue *q , int pageNumber, struct hashNode* h)
{
   struct node *temp = NULL;
   temp = h->q_array[pageNumber];
   if(h->q_array[pageNumber] != NULL && temp != q->front)
   {
      //move to the front of the queue
      temp->prev->next = temp->next;
      if(temp->next!=NULL)
      {//element is not the last element
          temp->next->prev = temp->prev;
      }
      else if(q->front != q->rear)
      {
        if(q->front != q->rear)
        {
            //last node
            q->rear = temp->prev;
        }     
       }
      //
      q->front->prev = temp;
      temp->next = q->front;
      q->front = temp;
      q->front->prev = NULL;
      return;
   }
   else if (h->q_array[pageNumber] == NULL) {
     // Add new element in hash and queue
     enqueue(q,h,pageNumber);
   }
}
int main() 
{
struct hashNode *Hash = createHash(10);
struct Queue *q = createQueue(4);
referPage(q,1,Hash);

referPage(q,4,Hash);
referPage(q,3,Hash);
referPage(q,2,Hash);
referPage(q,1,Hash);
referPage(q,5,Hash);
referPage(q,6,Hash);
referPage(q,4,Hash);
    printf ("%d ", q->front->pageNumber);
    printf ("%d ", q->front->next->pageNumber);
    printf ("%d ", q->front->next->next->pageNumber);
    printf ("%d ", q->front->next->next->next->pageNumber);
} 
