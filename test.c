#include <stdio.h>
#include <string.h>

void strrev(char *s) {
  int tmp, i, j;
  for (j = strlen(s) - 1; j >=0; j--) {
    
    printf("%c",s[j]);
   
  }
printf("\n");
}

int main() {
  char buffer[10];
  scanf("%s", buffer);
  strrev(buffer);
  return 0;
}
