#include<iostream>
class exam {
public:
   exam(int a=10,string& s );
private:
  int _id;
  string _exam;
};
exam::exam(int a, string & s):_id(a),_exam(s)
{
cout<<"In exam constructor"<<endl;
}
class cs32exam : public  exam {
public:
  cs32exam(int a, string &s, string &csexam):exam(a,s),_cs32Exam(csexam)
{
    cout << "In cs32 constructor";
}
private:
   string _cs32Exam;
   
};
