#include<stdio.h>
 void swap(char *s, char*y)
 {
     char temp = *s;
     *s=*y;
     *y=temp;
     printf("");
 }
 int hash[100000] ={0};
 int permute(char* str,int index,int len)
 {
 int sum=1;     
 if(index==len)
    return 1;
 int j;
 for(j=0; j<index;j++)
 {
     printf("\nstr[j] = %c",str[j]);
     sum = sum*(str[j]-'0');
     printf("sum=%d\n",sum);
     if (hash[sum]==0)
         hash[sum] =1;
     else 
     {
         printf("\nhash[sum] already exists %d,%d",sum,hash[sum]);
         return 0;
     }
 }
 int i;
 for(i=index;i<len;i++)
 {
     swap(str+i,str+index);
     if(0==permute(str,index+1,len))
        return 0;
     swap(str+i,str+index);
 }
 return 1;
 }


int colorful(int A) {
    int i;
    int array[10] = {1,1,0,0,0,0,0,0,0,0};
    int hash[10000] = {0};
    char x[10];
    i=A;
    int lenInt =0;
    while(i>0)
    {
       i=i/10;
       lenInt++;
    }
    int temp = A,j;
    int val;
    for(j=lenInt;j>0;j--)
    {
        val = temp%10;
        temp = temp/10;
        x[j-1] = val+'0';
    }
    printf("len=%d\n",lenInt);
    printf("");  
    int wholeProduct = 1;
    int level = 0;
    for(level=0;level<lenInt;level++)
    {
    for(j=0; j+level<lenInt;j++)
    {
        wholeProduct =1;
        for(i=j;i<=j+level;i++)
        {
            wholeProduct= wholeProduct*(x[i]-'0');   
        }
        if(hash[wholeProduct]==1 && wholeProduct!=1)
        {
          printf("%d\n",wholeProduct);
          return 0;
        }
        else
           hash[wholeProduct] = 1;
    }
    }
    
    return 1;
}
/*
int colorful(int A) {
    char x[10]={0};
    int i;
    i=A;
    int lenInt =0;
    while(i>0)
    {
       i=i/10;
       lenInt++;
    }
    printf("lenInt=%d\n",lenInt);
    int temp = A,j;
    int val;
    for(j=lenInt;j>0;j--)
    {
        val = temp%10;
        temp = temp/10;
        x[j-1]=val+'0';
        //printf("\n%c, %d\n",x[j-1],j-1);
    }
    printf("\nx=%s\n",x);
    if(permute(x,0,lenInt))
        return 1;
    else
        return 0;
    
}
*/
int main()
{
if(colorful(99))
printf("99 is colorful");
else
printf("99 is not");
}
