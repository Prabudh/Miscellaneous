#include<stdio.h>
int main() {
int num;
scanf("%d",&num);
for(int i= 0; i<16; i++)
printf("%d",(num<<i & 1<<15)? 1: 0);
return 0;
}
