#include<iostream>
using namespace std;
class patient;
class data {
int _age;
int _sugar;
int _bp;
friend class patient;
};

class patient {
   public :
   patient(int a, int s, int bp)
   {
     cout<< "In patient constructor";
     _d._age = a;
     _d._sugar = s;
     _d._bp = bp;
   }
   void print();
   private:
   data _d;
};

void patient::print()
{
cout << "age : " << _d._age<< "sugar level: "<<_d._sugar << "bp : "<< _d._bp<<endl;
}

int main()
{
patient x(1,2,3);
x.print();
return 0;
}
