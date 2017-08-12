#include<stdio.h>
struct linkedList {
  struct linkedList* link;
  int x;
};
void append(struct linkedList **head, int z)
{
   struct linkedList *temp;
   temp = (struct linkedList *)malloc(sizeof(struct linkedList));
   temp->x = z;
   temp->link = *head;
   *head = temp;
}


void elementFromTheEnd(struct linkedList* s, int pos);
void main()
{
struct linkedList *stack = NULL;
append(&stack, 1);
append(&stack, 2);
append(&stack, 3);
append(&stack, 4);
append(&stack, 5);
append(&stack, 6);
append(&stack, 7);
append(&stack, 8);
append(&stack, 9);
append(&stack, 10);

elementFromTheEnd(stack,3);
elementFromTheEnd(stack,5);
}


int len(struct linkedList *s);
void elementFromTheEnd(struct linkedList* s, int pos)
{
int length;
length = len(s);
int count = length -pos +1;
int i =0;
while(s!=NULL)
{
i++;
if(i==count)
{
  printf("Elemnt = %d", s->x);
}
s= s->link;

}

}

int len(struct linkedList *s)
{
int count= 0;
while(s!=NULL)
{
count++;
s= s->link;
}
return count;
}
