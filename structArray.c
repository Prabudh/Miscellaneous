#include<stdio.h>
#define MAXAUT 10
#define MAXTIT 10
#define MAXBOOKS 2
struct book 
{
char Author[MAXAUT];
char Title[MAXTIT];
long value;
};
struct place
{
struct book specialBook;
char city[MAXAUT];
int zipCode;
};

main()
{
 struct book library[MAXBOOKS];
 struct place jpnagar = {
  {"PRABUDH","home",100},"bangalore",94087
 };	
 int index;
 printf("%s, %d",jpnagar.specialBook.Author,jpnagar.zipCode); 



 struct book *lib;
 	
 for (index = 0; index < MAXBOOKS; index++) {
  lib = &library[index];
  printf("\nEnter the Author name\n");
  gets(lib->Author);
  printf("\nEnter the Title name\n");
  gets(lib->Title);
  printf("\nEnter the Price of the book\n");
  scanf("%ld",&lib->value);
  printf("\n\"%s\" title, \"%s\" Author,\(%ld\) Price\n",lib->Author,lib->Title,lib->value);
 }
}
