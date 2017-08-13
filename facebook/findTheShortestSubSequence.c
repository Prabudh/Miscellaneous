#include<stdio.h>
#include<string.h>
int main()
{
    char input[100];
    char pat[10];
    printf("Enter the input string\n");
    scanf("%s",input);
    printf("Enter the pattern String\n");
    scanf("%s",pat);
    char subSeq[10];
    int startIndex;
    int range = findTheShortSubSeq(input, pat, &subSeq, &startIndex);
    printf("\nThe shortest SubString Length =%d\n", range);
    for(int i=0;i<=range;i++)
    {
        printf("%c", input[startIndex+i]);
    }
printf("\n");
}

int findTheShortSubSeq(char * input, char * pat, char** subSeq, int *index)
{
int lenInput = strlen(input);
int lenPat = strlen(pat);
int count_Pat=0;
int count_j=0;
int count_k=0;
int i,j,k,l;
//Create histogram
int array_pat[26] = {0};
int constArrayPat[26] = {0};
for(i=0;i<lenPat;i++)
{
  array_pat[pat[i]-'a']++;
  constArrayPat[pat[i]-'a']++;
  count_Pat++;
}
int minLen = 100000;
for(i=0;i<lenInput;i++)
{
    for(l=0;l<26;l++)
    {
       array_pat[l]=constArrayPat[l];
    }
    count_j =0;
    for(j=i;j<lenInput;j++)
    {
        if(array_pat[input[j]-'a']!=0 && count_j<count_Pat)
        {
             array_pat[input[j]-'a']--;
             count_j++;
        }
        
        if(count_j==count_Pat)
        {
              if(minLen>j-i)
              {
                  minLen = j-i;
                  *subSeq = input+i;
                  *index = i;
              }
              for(l=0;l<26;l++)
              {
                  array_pat[l] = constArrayPat[l];
              }
              count_k = 0;
              for(k=j;k>i;k--)
              {
                    if(array_pat[input[k]-'a']!=0 && count_k<count_Pat)
                    {
                         array_pat[input[k]-'a']--;
                         count_k++; 
                    }  
                    if(count_k==count_Pat)
                    {
                         if(minLen>j-k)
                         {
                              minLen = j-k;
                              i= k;
                              *subSeq = input+k;
                              *index = k;
                         }
                         break;
                    }
              }
        break;
        }
    }
}
return minLen;
}

