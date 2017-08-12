/*
Assume you have a method isSubstring which checks if one word is a substring of another Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat”)
*/
#include<stdio.h>

     static int isRotation(char str1 [], char str2[] )
    {
        return isSubstring(append(str2,str2),str1);
    }
    // COMPLEXITY  O ( n + m )
     static char[] append(char str1[], char str2[]){
    char result[] = new char[strlen(str1) + strlen(str2)];
        int index = 0;
        int len1 = strlen(str1); 
        while(index < strlen(str1))
            result[index] = str1[index++];
        index = 0;
        while(index < strlen(str2))
            result[len1 + index] = str2[index++];
        
        return result;
    }
    // COMPLEXITY O ( N^2 )
     static int isSubstring(char str1[], char str2[]){
        int counter = 0;
        for(int i = 0; i < strlen(str2); i++){
            int start = i;
            while(counter < strlen(str2) && start < strlen(str1) && str1[start++] == str2[counter++]){
                if(counter == strlen(str2))return 1;
            }
            counter = 0;
        }
        return 0;
    }
void main()
{
if(isRotation("waterbottle","bottlewater"))
{
    printf("Yes\n");
}
else
printf("No\n");
}
