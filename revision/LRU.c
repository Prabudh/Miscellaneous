typedef struct QNode
{
int pageNumber;
struct QNode *next,*prev; 
} QNode;

struct HashNode {
int capacity;//hash array size
QNode **pointerQueueNode;
}
struct Queue {
QNode *front, *rear;
int MaxPageNumbers;
int currentCount;
}
QNode* createQNode(int pageNum) {
   Qnode* node = (QNode*) malloc(sizeof(QNode));
   node->next =NULL;
   node->prev= NULL;
   node->pageNumber = pageNum;
}
Queue* createQ(int size)
{
Queue *root;
root->MaxPageNumbers = size;
root->currentCount = 0;
return root;
}
/*
struct HashNode Hash[10];
*/

enQueue(hash,queue,pageNumber)
{
QNode* temp = hash->array[pageNumber];
if(temp)
{
if(queue->front != temp)
{
   temp->prev->next=temp->next;
   if(temp->next)
   {
       temp->next->prev = temp->prev;
   }
   else
   {
     queue->rear = temp->prev;
   }
   temp->next = queue->front;
   queue->front->prev = temp;
   
}
}
else
{
//add the page in front of queue and store the entry in the hash
}
}

