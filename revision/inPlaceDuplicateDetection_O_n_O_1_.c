/*Write an algorithm that returns any duplicate in an array of integers. The algorithm must run in O(n) time and O(1) space. (hint: the integers in the array are not greater than the size of the array).
*/
#include<stdio.h>
int array[6] = {4,2,3,1,4,2};
int abs(int a)
{
if (a<0)
return a*-1;
else
return a;
}
void checkForDuplicate()
{
for(int i = 0 ; i<6;i++)
{
   if(array[abs(array[i])]<0)
   {
   printf("%d is duplicate\n", abs(array[i]));
   }
   array[abs(array[i])] *= -1; 
}
}
int main()
{
checkForDuplicate();
return 0;
}
