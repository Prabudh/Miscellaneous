#include<stdio.h>
#include<stdlib.h>
typedef struct node {
  struct node* link;
  int data; 
} node;
void delete(struct node **head, int data);
void displayList(struct node* temp);
void append(struct node **head, int data);
void populateArrayPointer(struct node* arr, struct node *head);
void appendList(struct node **list, struct node *temp);
void copyList(struct node **list, struct node *temp);
void mergeList(struct node* even, struct node *odd, struct node** merge);
void main()
{
  struct node *head= NULL;
  struct node  **lL;
  lL = &head;
  append(&head, 2);
  append(&head, 3);
  append(&head, 11);
  append(&head, 15);
  append(&head, 17);
  append(&head, 1);
  append(&head, 22);
  append(&head, 5);
  append(&head, 55);
  delete(&head, 55);

  //create array of pointers
  //struct node **array = (struct node *)malloc(8*sizeof(struct node *));
  //struct node* array[8];

  struct node *oddList=NULL;
  struct node *evenList=NULL;
  int evenOrOdd = 0;
  struct node *temp= head;
  while(temp!=NULL)
  {
  if(evenOrOdd%2 == 0)
    copyList(&evenList,temp);
  else
    appendList(&oddList,temp);
  temp = temp->link;
  evenOrOdd++;
  } 
  displayList(evenList);
  displayList(oddList); 
  //reverse(&oddList);
  evenOrOdd = 0;
  struct node *mergedList;
  mergeList(evenList, oddList, &mergedList);
  
  //Append even and odd list.

  //populateArrayPointer(array, head);
  //reverseOddElementsInArray(array);
  //rearrangeList(head, array);

  displayList(head);
  displayList(mergedList);
  return; 
}

void mergeList(struct node* even, struct node *odd, struct node** merge)
{
    int eOro = 0;
    while(even!=NULL || odd != NULL)
    {
        if(eOro%2==1)
        {
            copyList(merge, odd);    
            odd=odd->link;
        }
        else 
        { 
            copyList(merge, even);
            even=even->link;
        }
        eOro++;
    }
}

void copyList(struct node **list, struct node *temp)
{
   if(temp == NULL)
      return;
   if(*list == NULL)
   {
     *list = (struct node *)(malloc(sizeof(struct node)));
     (*list)->data = temp->data;
     (*list)->link = NULL;
     return;
   } 
   struct node *t, *tempList = *list;
   t = (struct node *) (malloc(sizeof(struct node)));
   t->data = temp->data;
   t->link = NULL;
   while(tempList->link!=NULL)
   {
      tempList = tempList->link;       
   }
   tempList->link = t;
   return;
}

void appendList(struct node **list, struct node *temp)
{
   if(temp==NULL)
      return;
   struct node *t;
   t = (struct node *) (malloc(sizeof(struct node)));
   t->data = temp->data;
   t->link = *list;
   *list = t;
   return;
}

void displayList(struct node* temp)
{
  while(temp!=NULL)
    {
      printf("%d " ,temp->data);
      temp=temp->link;
    }
printf("\n");
return;
}
void populateArrayPointer(struct node* arr, struct node *head)
{
  struct node *temp;
  temp = head;
  int i = 0;
  while(temp->link != NULL)
    {
      arr[i] = *temp;
      i++;
    }
}


reverseOddElementsInArray(struct node *arr)
{
  struct node *temp;
  int i, j;
  for(i=0, j=7 ;i<j ;i++) 
    {
      if(i%2 == 0)
	continue;
      else {
	temp = &arr[i];
	arr[i] = arr[j];
	arr[j] = *temp;
      }
      j--;
    }
}

rearrangeList(struct node *head, struct node *arr)
{
  struct node *temp = head;
  int i;
  for(i=1;i<8;i++) 
    {
      temp->link = &arr[i];
      temp= temp->link;
    }
}
void append(struct node **head, int data)
{
  struct node *temp, *x;
  temp = *head;
  //if list is empty
  if(*head==NULL)
    {
      temp = (struct node *)(malloc(sizeof(struct node))); 
      temp->data = data;
      temp->link = NULL;
      *head = temp;
      return;
    }
  while(temp->link != NULL)
  {
      temp= temp->link;
  }
  x = (struct node*)(malloc(sizeof(struct node)));
  x->data = data;
  x->link = NULL;
  temp->link = x;
return;
}

void delete(struct node **head, int data)
{
  struct node *old;
  struct node *temp;
  temp = *head;
  old = *head;
  //head has to be deleted
  if(temp->data == data)
    {
      *head = temp->link;
      free(temp);
      return;
    }
  else {
    temp= temp->link;
  }
  while(temp!= NULL)
    {
      if(temp->data == data)
	{
	  old->link = temp->link;
	  free(temp);
          return;
	}
      else {
	old = temp;
	temp= temp->link;
      }
    }
return;
}
