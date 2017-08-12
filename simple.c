/*simple.c*/
#include <stdio.h>
main()
{
  float num,n,n2,n3=0x70,age=0;
  printf("%f",n3);
  char beep;
  beep = '/007';
  num = 0;
  
  n=5;
  n2=n*n;
  n3=n2*n2/n*0.346;
  printf("n = %1.4f, n2 = %1.3f, n3= %1.2f",n,n2,n3);
  printf("My name is a simple.c");
  printf("My favorite number is .\n");

  printf("%f I like to play football", num);
  printf("Enter Age");
  scanf("%f",&age);	
  printf("abcd, age =%f",age);
  butler();
}
#define weight 34
butler() 
{
        char name[40];
	printf("\nhelloworld\n %c", '\007');
	//#int a,b;
	unsigned int a;
        short b;
        unsigned long c;
        a = 64535;
	a = a+1;
        b = a+3; 
	c = 4294967295/weight;
	char grade = 65; 
        printf("\n%d,%d,%d,%c\n",a,b,c,grade);
        printf("What is your Name");
        scanf("%s",name);
	printf("\n My name is %s and my strn len = %d\n",name,strlen(name));
	
}
