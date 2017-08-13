#include <stdio.h>
#include <string.h>
int atoi(char *s)
{
    int i =0,sm=0;
    for(i=0;i<strlen(s);i++)
    sm =sm*10+(s[i]-'0');
    return sm;
}
int main(int argc,char** argv) {
	if (argc<2)
	  return 0;
	int diff;
	int min = ~0;
        
	 //min = min << 1;
	 min = min >> 1;
	 printf("%d",min);
	//code
	for(int i=1;i<(argc-1);i++)
	{  
	   diff =atoi(argv[i])-atoi(argv[i+1]);
	   if(diff<0)
	     diff = atoi(argv[i+1]) - atoi(argv[i]);
	   if(diff < min)
	      min =diff;
	}
	return min;
}
