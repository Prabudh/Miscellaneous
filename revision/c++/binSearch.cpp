#include <iostream>
using namespace std;
#include<assert.h>
static void init(int *s, int ssize) {
  for (int i = 0 ; i< ssize ; i++) {
     s[i] = i;
  }
}
static void binary_search(int *s, int ssize, int tofind) {
  cout << "Number to find = " << tofind << endl;
  {
     int p = s[0];
     for(int i=1;i<ssize;i++) {
       assert(p<s[i]);
       p = s[i];
     }
  }

int l =0;
int h= ssize;
int ittr = 0;
while(1) {
   int m = (l+h)/2;
   cout << "l = " << l << " h = " << h << " m = " << m << endl;
   if(s[m] == tofind) {
     cout << "Found " << tofind << " after " << ittr << " iterations at location " << m << endl;
     break;
   }
  
  if (l >=h) {
    cout << "NOT Found " << tofind << " after " << ittr << " iterations\n";
    break;  
  }
  ittr++;
  if(s[m] < tofind) {
    l = m+1;
  } else {
    h = m-1;
   }
}
}

int main() {
  const int N = 10000;
  int s[N];
  init(s,N);
  binary_search(s,N,44);
  binary_search(s,N,N+78);
  return 0;

}
