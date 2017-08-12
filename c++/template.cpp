#include<iostream>
using namespace std;
template<typename T>
static void print_array(const char*s, const T& a,int size) {
cout <<s <<"{";
for(int i=0;i<size;i++) {
  cout<<a[i];
  if(i<size-1) {
    cout<<"'"; 
  }
}
cout<<"}"<<endl;
}

int main() {
    int a[] = { 1, 2, 3, 4, 5 };
    print_array("a is ",a,sizeof(a)/sizeof(int)) ;
    double b[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    print_array("b is ",b,sizeof(b)/sizeof(double)) ;
    char c[] = "HELLO";
    print_array("c is ",c,sizeof(c)/sizeof(char)) ;
    return 0 ;
}
