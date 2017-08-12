#include<stdio.h>
#define SET 2
#define ROW 3
#define COL 4

main()
{
 int i,j,k;
 int* a;
 int* fun1();
 

 int(*b)[COL];
 int(*fun2())[COL];
 
 int(*c)[ROW][COL];
 int(*fun3())[ROW][COL];
 int* p;
 
 int(*d)[SET][ROW][COL];
 int(*fun4())[SET][ROW][COL];
 
 clrscr();
 a = fun1();
 b = fun2();
 c = fun3();
 d = fun4();
}


int* fun1() {
  int i,j,k;
  static int a[SET][ROW][COL]=  {
                                  {
                                     1,2,3,4,
                                     
                                  } 
 
 
}


