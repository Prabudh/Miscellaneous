//#include<stdio.h>
/*int 
main( int argc, char const ** argv ) { 
for( int i = 0; i < argc; ++i ) { 
printf("%s\n", argv[i] ); 
} 
} 
*/
#include <stdio.h> 

/* Describe the code below 
*/
struct s { 
double f; 
int i; 
char c[3]; 
void *p; 
int x[0]; 
}; 

int main( int argc, char ** argv ) { 

struct s temp; 

printf("The size of the struct is %d \n", sizeof(temp)); 

printf("The size of the double is %d \n", sizeof(temp.f)); 

printf("The size of a character array is %d \n", sizeof(temp.c)); 

printf("The size of a void pointer is %d \n", sizeof(temp.p)); 

printf("The size of a integer array is %d \n", sizeof(temp.x)); 

printf("The size of a integer is %d \n", sizeof(temp.i)); 

return 0; 

} 
/*

#include <stdlib.h> 
#include <stdio.h> 

class C { 
public: 
void func() { 
printf("func called\n"); 
} 
virtual void virtualFunc() { 
printf("virtual func called\n"); 
} 
}; 

int main (int argc, char ** argv) { 
C * obj = NULL; 
/* What does the following print? 
obj->func(); 
/* What does the following print?  
obj->virtualFunc(); 
/* What's the difference? 
} 
*/
