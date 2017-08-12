#include<iostream>
using namespace std;
class patient;
class data
{
public:
//print();
private: 
int _a;
int _b;
int _c;
friend class patient;
};
/*patient::print()
{
cout<<_a<<" "<<_b<<" "<<_c;
}
*/
class patient{
public:
void print();
patient(int a, int b, int c);
~patient();
friend ostream & operator<<(ostream& o, patient& d);
private:
data _d;
};
void patient::print()
{
cout<<_d._a<<" "<<_d._b<<" "<<_d._c;
}

ostream& operator<<(ostream& o, patient& d)
{
    //o<<"a="<<d._d._a<<" b="<<d._d._b<<" c="<<d._d._c;
   d.print();
}
patient::patient(int a, int b, int c)
{
cout<<"In patient constructor";
_d._a=a;
_d._b=b;
_d._c=c;
}
patient::~patient()
{
cout<<"Destructor";
}
int main()
{
patient x(1,2,3);
cout << x;
return 0;
}
