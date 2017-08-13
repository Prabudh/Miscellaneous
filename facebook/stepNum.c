/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
#include<stdio.h>
#include<stdlib.h>
int* stepnum(int A, int B, int *len1) {
    int i,temp1,temp2=-1;
    *len1=0;
    int j,tempI;
    int* newRes,*temp,*res;
    int pass;
    for(i=A;i<B;i++)
    {
        temp2 = -1;
        tempI=i;
        pass =1;
        printf("\n");
        while(i>0)
        {
           printf("%d,pass=%d,temp1=%d,temp2=%d",i,pass,temp1,temp2);
           temp1=i%10;
           if(temp2!=-1)
           {
               if(temp1-temp2 == 1 || temp2-temp1 == 1)
               {
                   
               }
               else
              {
                 pass=0;
             }
          }
           else
           {
             temp2=temp1; 
           }

           i=i/10;
        }
        if(pass!=0)
        {
        //printf("%d\n",tempI);
        *len1= *len1+1;
        newRes = (int*)malloc((*len1)*sizeof(int));
        newRes[(*len1)-1] = tempI;
        if((*len1)>1)
        {
            temp = res;
            for(j=0;j<((*len1)-1);j++)
            {
                newRes[j] = res[j];
            }
            res= newRes;
            free(temp);
        }
        else
        {
            res = newRes;
        }
        }
      i=tempI;
    }
  /*  int *res = (int*)malloc(*len1 * sizeof(int));
    int index=0;
    for(i=A;i<B;i++)
    {
        while(i>0)
        {
           temp1=i%10;
           i=i/10;
           if(temp2!=-1)
           {
               if(temp1-temp2 == 1 || temp2-temp1 == 1)
               {
                   
               }
               else
               break;
           }
           else
           {
             temp2=temp1; 
           }
        }
        res[index] = i;
        index++;
    }*/
    return res;
}
int main()
{
int len=0;
    int * array = stepnum(10,20,&len);
for(int i=0;i<len;i++)
printf("\n%d,",array);

    return 0;

}

