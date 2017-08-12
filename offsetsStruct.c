#include<stdio.h>
struct a
{
   struct b
   {
     int i;
     float f;
     char ch;
   }x;

   struct c
   {
     int j;
     float g;
     char ch;
   }y;
};

main()
{
  int *p;
  struct a z;
   
  clrscr();
  fun (&z.y);
  printf("\n %d %f %c", z.x.i, z.x.f, z.x.ch);
  getch();
}



fun (struct c *p)
{
  int offset;
  struct b *address;
  offset = (char*)&((struct c *)(&((struct a*) 0)->y)->j) - (char*)((struct a*) 0);
  address = (struct b*)((char*) & (p->j)-offset);
  address->i = 400;
  address->f = 3.14;
  address->ch = 'c';
}
