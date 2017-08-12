#include<stdio.h>
#include<stdlib.h>
struct node {
int val;
struct node * next;
};
struct node* createList(int nodes);
struct node* freeList(struct node* list , int nodes);
void readList(struct node* lL, int nodes)
{
int i =0;
while(lL[nodes-1-i].next!=NULL)
{
printf("%d ",lL->val);
//lL=lL->next;
i++;
}
printf("\n");
for(i=0;i<nodes;i++)
{
printf("%d ",lL[i].val);
}
}
int main(int argc,char** argv)
{
if(argc!=2) {
printf("usage fib num --you gave %d args\n", argc-1);
exit(0);
}

int nodes = atoi(argv[1]);

if(nodes<1)
{
printf("num must be a positive number\n");
} 

struct node* list = createList(nodes);
readList(&list[nodes-1], nodes);
freeList(list, nodes);
}

struct node* createList(int nodes) {
int i=0;
struct node* list = (struct node*) malloc(sizeof(struct node)* nodes);
//assert(list);
for(i=nodes-1;i>=0;--i) {
list[i].val= (nodes -i)-1;
list[i].next=list+(i-1);
}
list[0].next = NULL;
return &list[nodes-1];
}
struct node* freeList(struct node* list, int nodes) {
free(&list[1-nodes]);
}
