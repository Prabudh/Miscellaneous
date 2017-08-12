#include<stdio.h>
/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j Write a method to set all bits between i and j in N equal to M (e g , M becomes a substring of N located at i and starting at j)
SOLUTION
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6 Output: N = 10001010100
*/

int main()
{
short  N,M,i,j;
printf("Enter the value of N\n");
scanf("%d",&N);
printf("Enter the value of M\n");
scanf("%d",&M);
printf("Enter the value of i\n");
scanf("%d",&i);
printf("Enter the value of j\n");
scanf("%d",&j);
int mask;
mask = ~0;


printf("%d\n",mask);
mask = mask<<(32-j);

printf("%d\n",mask);
mask = mask>>(32-j);

printf("%d\n",mask);
mask = mask >> i;

printf("%d\n",mask);
mask = mask<<i;

printf("%d\n",mask);

mask = ~0^mask;
printf("%d\n",mask);
N= N&mask;
N= N|(M<<i);
printf("\n%d",N);
}
