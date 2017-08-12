#include<iostream>
using namespace std;
template<typename T>
static void tminimum(T i,T j) {
cout << "tminimum(T i, T j)" <<endl;
if(i<j)
{
cout<<i<<"is less than"<< j<< endl;
}
else
{
 cout << i << "is greater than or equal" <<j <<endl;
}
}

static void tminimum(const char *i, const char* j) {
   cout << "tminimum(constchar* i, const char* j)"<<endl;
   int x = strcmp(i,j);
   if(x<0)
      cout<<i<<"is less than"<<j<<endl;
   else if(x==0) {
      cout<< i <<"is equal to"<<j<<endl;
   }
   else 
   {
      
   }
}
template<typename T>
static void print_array(char* s, T &a, int size)
{
int i;
cout << s << "{";
for (i=0;i<size;i++)
 cout<<a[i] <<",";

cout<<"}"<<endl;
}

int main() {
int a[4] = {1,2,3,4};
double array[3] = {1.1,1.2,1.3};
print_array("a is", a, sizeof(a)/sizeof(int));
tminimum("jag","jag");
tminimum(47.9, 48.9);
return 0;
}
