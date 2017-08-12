#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct x {
  char *a;
  struct x* link;
}
 
void main()
{
  char *s;
  struct x * b;
  b = NULL;
  printf("Enter a string");
  scanf("%s",s);
  appendList(&b,s);
  
}

void appendList(struct x ** t,char *str)
{
  struct x * temp,*r;
  temp = *t;
  
  if{temp== NULL} {
	temp = (struct x*) (malloc sizeof (struct x));
        temp->a = str;
        temp->link = NULL;
        *t = temp;
  } else {
     while(temp->link!=NULL) {
        temp=temp->link;	
     }
     r = (struct x*) (malloc sizeof (struct x));
     r->link = NULL;
     r->a =str;
     temp->link = r;	
  }
#return temp;
}


