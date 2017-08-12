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
void detectIfCircular(struct linkedList *sum)
{
struct linkedList *slow, *fast;
slow = sum;
fast = sum;
while(fast!=NULL && slow!=NULL)
{
   if(fast==slow)
   { 
      printf("loop was detected at %d", fast->x);
      return;
   }
   if(fast->link!=NULL)
     fast= fast->link;
   slow = slow->link;
   fast = fast->link;
}
}

void elementFromTheEnd(struct linkedList* s, int pos);
void main()
{
struct linkedList *stack1 = NULL;

struct linkedList *stack2 = NULL;
struct linkedList *sum=NULL, *temp;
append(&stack1, 9);
append(&stack1, 7);
append(&stack1, 6);
append(&stack1, 5);
append(&stack2, 9);
append(&stack2, 7);
append(&stack2, 6);
append(&stack2, 5);
append(&stack2, 4);
add(&sum,stack1,stack2);

printf("Sum =");
temp = sum;
while(sum->link!=NULL)
{
printf("%d ",sum->x);
temp= sum;
sum = sum->link;
}
sum->link = temp; 
//makeItCircular();
detectIfCircular(sum);
}

void addAtEnd(struct linkedList **sum, int num)
{
struct linkedList *temp=NULL;
struct linkedList  *var= NULL;
temp = (struct linkedList *)(malloc(sizeof(struct linkedList)));
temp->x = num;
temp->link = NULL;
if(*sum == NULL)
   *sum = temp;
else {
var = *sum;
while(var->link!=NULL)
{
    var= var->link;
}
var->link = temp;
} 
}

add(struct linkeList **sum, struct linkedList *arg1, struct linkedList *arg2)
{
int carry =0;
while(arg1!=NULL && arg2!=NULL)
{
    addAtEnd(sum, ((arg1->x+ arg2->x+ carry)%10));
    if((arg1->x+arg2->x) >= 10)
        carry = 1;
    else
        carry = 0;
    arg1= arg1->link;
    arg2 =arg2->link;
}
//copy rest of the elements
while(arg1!=NULL)
{
    addAtEnd(sum,((arg1->x+carry)%10));
    if((arg1->x+carry) >= 10)
       carry = 1;
    else
       carry = 0;
    arg1 = arg1->link;
}

while(arg2!=NULL)
{
    addAtEnd(sum,((arg2->x+carry)%10));
    if((arg2->x+carry) >= 10)
       carry = 1;
    else
       carry = 0;
    arg2 = arg2->link;
}

if (carry == 1)
{
    addAtEnd(sum, 1);
}

}
