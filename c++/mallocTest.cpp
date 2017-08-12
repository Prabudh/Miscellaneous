#include<iostream>
using namespace std;
static void test_obj(int size) {
class student {
public :
int age;
char *id;
};
student* a = new student;
a->age = 25;
a->id = new char[size];
strcpy(a->id,"Z567");
cout << "student id =" << a->id << "student age =" <<a->age <<endl;
delete[]a->id;
delete a;
}
int main() {
test_obj(5);
return 0;
}
