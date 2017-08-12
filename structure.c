#include<stdio.h>
#define MAXAUT 10
#define MAXTIT 10
struct book 
{
char Author[MAXAUT];
char Title[MAXTIT];
long value;
};


main()
{
 struct book library;
 printf("\nEnter the Author name\n");
 gets(library.Author);
 printf("\nEnter the Title name\n");
 gets(library.Title);
 printf("\nEnter the Price of the book\n");
 scanf("%ld",&library.value);
 printf("\n\"%s\" title, \"%s\" Author,\(%ld\) Price\n",library.Author,library.Title,library.value);

}
