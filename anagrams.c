#include<stdio.h>
char *s1 = "gabcdef";
char *s2 = "abcdefg";
int array_1[255] = {0};
int array_2[255] = {0};
void main()
{
int i;
for(i=0; i<strlen(s1); i++)
  array_1[s1[i]]++;
for(i= 0; i<strlen(s2); i++)
  array_2[s2[i]]++;

for(i=0;i<255;i++)
{
  if(array_1[i]!=array_2[i])
  { 
      printf("Not an anagram\n");
      return;
  }
}
printf("Two strings are anagrams\n");
}

