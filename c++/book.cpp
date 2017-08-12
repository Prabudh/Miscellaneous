#include<iostream>
using namespace std;
class book {
public:
   book(char* n, int c = 0):_name(NULL),_code(c){
       cout<<"In constructor of book :"<< n<< "code:"<< _code<<endl;
       _name = new char[strlen(n)];
       strcpy(_name,n);
   }
   ~book() {
    cout << "In destructor of book:"<< _name << " code:" <<_code<<endl; 
    delete[] _name;
    }
   book(const book& a);
   book& operator=(const book & a);
   friend void operator<<(ostream&,const book &a);
   friend void print(const book &a);
private:
char * _name;
int _code;
};
void print(const book &x)
{
cout<<"book name: "<<x._name <<" code : "<<x._code;
}
book ::book(const book & a)
{
    this->_code= a._code;
int l = strlen(a._name)+1;
this->_name = new char[l];
strcpy(this->_name,a._name);
}

book& book::operator=(const book &a)
{
if(this!=&a)
{ 
delete[] this->_name;
this->_code= a._code;
int l = strlen(a._name)+1;
this->_name = new char[l];
strcpy(this->_name,a._name);
}
return *this;
}

void operator<<(ostream& o,const book &x)
{
o<<"book name: "<<x._name <<" code : "<<x._code; 
}
int main()
{
book b1("algo");
book b2("402",10);
book *b3 = new book("maths",20);
book b4(b1);
book b5 = b2;
cout<<b5;
delete b3;
return 0;
}
