#include <stdio.h>
struct node
{
  int data;
  struct node *link;
};

main()
{
struct node *p;
p=NULL;
printf("\n elements in linked list=%d",count(p));
append(&p,1);
append(&p,2);
append(&p,17);
}

append(struct node **q, int a)
{
  struct node *temp, r;
  if (*q==NULL) {
    /* First element*/
    temp = malloc(sizeof (struct node));
    if (temp!=NULL) {
      temp->data = a
      temp->link = NULL;
      *q = temp;
    }
  } else  {
    while (temp->link !=NULL)
        temp = temp->link;
    temp->link = &r;
    r.data = a; 
    r.link = NULL;
  }
} 

addatbeg (struct node **q, int a)
{
 struct node *temp;
 temp = malloc(sizeof (struct node));
 temp->link = *q;
 temp->data = a;
 *q = temp;
}


addafter (struct node **q, int loc, int num)
{
  struct node *temp,r,*x;
  for (i=0;i<loc;i++)
  {
    temp = temp->link;
    if (temp->link == NULL) {
     printf ("End of list reached before loc");
     return
    }     
  }
  r.data = num;
  r.link = temp->link;
  temp->link = &r;


}



