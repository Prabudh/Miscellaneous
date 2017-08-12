#include<iostream>
using namespace std;
bool verifyIfBst(int* seq,int length)
{
int i, j;
int root = seq[length-1];
for(i=0;i<length-1;i++)
{
    if(seq[i]>root)
       break; 
}
j=i;
for(;j<length-1;j++)
{
    if(seq[j]<root)
    {
        
        return false;
    }
}

bool left = true;
if(i>0)
left = verifyIfBst(seq,i);

bool right = true;
if(i<length-1)
right = verifyIfBst(seq+i,length-i-1);

return (left && right);

}
int main()
{
int seq[7] = {5,7,6,9,11,10,8};
if(verifyIfBst(seq,7))
printf("Seq is a BST");

}
