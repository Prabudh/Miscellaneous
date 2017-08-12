/*
An interesting question asked in Google’s phone interview : suppose a row of parking lot with n spots, one of them is empty and n-1 spots are occupied with cars. Only one operation is allowed: move one car from its position to the empty spot. Given a initial order of cars and a final order, output steps needed to convert initial order to final oder with that operation.

Follow up: Minimize steps needed.

ex:

{1 2 3 -1 4 5}
move car 1 to empty spot(denoted as -1) will make it {-1,2,3,1,4,5}
push 1 to the output list because you move car 1 to the empty spot

suppose you have a initial order {1 2 3 -1 4 5} and a final order {5,1,-1,3,2,4}, you need to transfer {1 2 3 -1 4 5} to {5,1,-1,3,2,4}, push each car moved into a output list.
*/

#include<stdio.h>
array_i[6] = {1,2,3,-1,4,5};
array_f[6] = {5,1,-1,3,2,4};
int findIndex(int num)
{
int i;
for (i=0;i<6;i++)
{
if(num == array_i[i])
{
printf("index=%d\n",i);
return i;
}
}
}
display()
{
for(int i=0;i<6;i++)
    printf("%d, ",array_i[i]);

printf("\n");
}
int main()
{
int temp;
for(int j=0;j<6;j++)
{
    if(array_i[j]!=array_f[j])
    {//move the empty spot in the right position
            temp = array_i[j];
            array_i[findIndex(-1)] = temp;
            array_i[j] =-1;
            //printf("%d ",temp); 
            // index
            if(array_i[j]!=array_f[j])
            {
            array_i[findIndex(array_f[j])] = -1;
            array_i[j] = array_f[j];
            printf("%d \n",array_f[j]);
            }
  display();    
}
}
/*
for(int i=0;i<6;i++)
    printf(array_i[i]);
*/
return 0;
}
