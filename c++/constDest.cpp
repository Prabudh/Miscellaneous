#include<iostream>
using namespace std;
class book {
public:
  book(const char* s, int c =0, bool x= false);
  ~book();
  void print()const;
private:
  char * _name;
  int _cost;
  bool _in;
};
book :: book(const char *s, int c, bool x):_name(NULL),_cost(c),_in(x)
{
  cout << "In book constructor" << s <<endl;
  int l = strlen(s)+1;
  this->_name = new char[l];
  strcpy(_name,s);
}

book::~book() {
  cout<<"In book destructor"<<_name<<endl;
  delete[]this->_name;
}

void book::print() const {
cout <<"Name"<<_name << "cost" <<_cost;
(_in) ? cout << "In":cout<<"Out";
cout<<endl;
}

int main() {
book b1("algorithm");
book b2("c++", 79);
b1.print();
b2.print();
return 0;
}
