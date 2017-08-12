#include<iostream>
using namespace std;
void swapRef(int &a, int&b)
{
int temp = a;
a= b;
b= temp;
}
int main()
{
int x =10;
int y= 20;
swapRef(x,y);
cout << x << y;
return 0;
}
