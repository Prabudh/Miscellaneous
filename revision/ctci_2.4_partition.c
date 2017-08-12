#include<stdio.h>
typedef struct llNode {
  struct llNode *next;
  int data;
}llNode;

void append(llNode **root, int data)
{
    llNode *temp = (llNode *)malloc(sizeof(llNode));
    temp->data = data;
    temp->next = NULL;
    if(*root == NULL)
    {
        *root =temp;
    }
    else
    {
        temp->next = *root;
        *root = temp;
    }
}

void createLinkedList(llNode **head)
{
   append(head, 1);
   append(head , 2);
   append(head, 3);
   append(head, 4);
   append(head , 5);
   append(head, 6); 
   append(head, 7);
   append(head , 9);
   append(head, 8);
}

void partition(llNode **head, int pivot)
{
   llNode *temp = *head;
   llNode *part1 = NULL;
   llNode *part2 = NULL;
   llNode *pivot = NULL;
   while(temp != NULL)
   {
       if(temp->data > pivot)
       {
          //Add at the end
          append(&part2,temp->data);
          
       }
       else if(temp->data<pivot)
       {
           //Add at the beginning
           append(&part1,temp->data);
       }
       else
       {
          append(&pivot,temp->data);
       }
   }
   
}
void display(llNode *root)
{
   while(root!=NULL)
   {
       printf("%d, ",root->data);
       root=root->next;
   }
  
}

int main()
{
llNode* root=NULL;
createLinkedList(&root);
partition(&root, 5);
}

