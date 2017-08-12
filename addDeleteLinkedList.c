#<include stdio.h>
struct node 
{
int data;
struct node *link;
};
add(struct node **q,int num)
{
struct node *temp,*r;
temp = *q;
if (temp == NULL) 
{ 
  /*The list is empty*/
  r = malloc(sizeof(struct node));   
  r->data = num;  
  if(*q == NULL || (*q)->data > num)
  {
    *q = r;
    r->link = temp;
  } 
}
else {
  while(temp != NULL)
  {
     if (temp->data <= num && (temp->link->data > num || temp->link == NULL))
     {
        temp -> link = r;
        r->link = temp->link->link;
         
     }
     else 
     {
       temp = temp->link;  
     } 
  }
}



}

display(struct node *temp)
{
   int c, length;
   c = 0;
   while(temp->link!=NULL)
   {
      printf("%d, %d",c,temp->data);
      c++;
      temp = temp->link;
   }
} 

reverse(struct node **x)
{
  struct node *r, *s, *q;
  q = *x;
  r = NULL;
  while(q->link !=NULL)
  {
     s = r;
     r = q;
     q = q->link;
     r->link = s;
  }
  *x =r;
}

main()
{
  struct node *p;
  p = NULL;
  
  add(&p,5);
  add(&p,1);
  add(&p,4);
  add(&p,6);
  

display(p);
}






