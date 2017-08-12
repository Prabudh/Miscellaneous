#include<stdio.h>
struct dynamicStack {
int array[10];
};

struct stacksPointer {
  int index;
  struct dynamicStack *node;
  struct stacksPointer* link;
};
void append(struct stacksPointer)
{
  
}
main()
{
int elements,i;
printf("Enter number of elements to be added\n");
scanf("%d", &elements);

while(i<elements)
 {
    append()
 }
}
