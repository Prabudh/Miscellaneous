#include<stdio.h>

void permute(int* mat,int index, int len, int *count);
int main()
{
int mat[8] = {0,1,2,3,4,5,6,7};
int count =0;
int length = 8;
permute(mat,0,length,&count);
printf("\n%d\n",count);
}

void permute(int* mat,int index, int len, int *count)
{
if(index==len)
{
if(checkThePositions(mat,len))
{ 
   *count=*count + 1;
   for(int i=0;i<len;i++) printf("%d, ",mat[i]);

printf("\n");
}
return;
}
for(int i = index; i<len;i++)
{
    swap(mat,i,index);
    permute(mat,index+1,len,count);
    swap(mat,i,index);
}

}
swap(int *mat, int i, int j)
{
int temp = mat[i];
mat[i]= mat[j];
mat[j]= temp;
}

checkThePositions(int *mat, int len)
{
for(int i = 0 ; i<len;i++)
{  for(int j =i+1; j<len; j++)
   {
       if((i-j == mat[i]-mat[j]) || (j-i == mat[i]-mat[j]))
         return 0;
   }
}
return 1;
}
