#include<iostream>
using namespace std;
#pragma warning(disable: 4996)
class student {
public:
  student(const char * s, int age = 1, bool male=false);
  ~student();
  void print() const;
  student(const student& x);
  student& operator=(const student&y);
  friend void print(ostream& o, const student &a) {
     o<<a._name<<" "<<a._age<<endl;
  }
  friend void operator<<(ostream &o, student &a) {
       o<<a._name << " "<<a._age<<" " <<a._m<<endl;
  }
private:
   char * _name;
   int _age;
   bool _m;
   void _release();
   void _copy(const student &z);
};

student::student(const student &x)
{
    cout<<"In Copy Constructor"<<endl;
    _name = new char[strlen(x._name)+1];
    _age = x._age;
    _m = x._m;
    strcpy(_name,x._name);
}
void student::_copy(const student &x)
{
    _name = new char[strlen(x._name)+1];
    _age = x._age;
    _m = x._m;
    strcpy(_name,x._name);
}

student& student::operator=(const student &y)
{
 cout<<"In = operator"<<endl;
  if(this!=&y)
  {
   _release();
   _copy(y);
   }
return *this;
}

void student ::_release()
{
delete[]_name;
}
student::student(const char*s, int age, bool male):_name(NULL),_age(age),_m(male)
{
   cout<<"In student constructor " << s << endl;
   _name = new char[strlen(s)+1];
   strcpy(_name,s);
}
void student::print() const {

    cout<<"Name"<<_name<<" age "<<_age<<"sex";
    (_m)?cout<<"male":cout<<"female";
    cout<<endl;
}
student ::~student()
{
     cout<<"In student desturctor"<< _name;
     delete[] _name;
}

static void test_shallow_copy_crash() {
   student tom("Tom Jr", 21);
   tom.print();
   student mary(tom);
   mary.print();
}

static void test_shallow_equal_crash() {
    student mary("mary",32);
    mary.print();
    student nary("vlsi");
    nary =mary;
    nary.print();
    cout<<nary;
}

int main()
{
test_shallow_equal_crash();
test_shallow_copy_crash();

return 0;
}
