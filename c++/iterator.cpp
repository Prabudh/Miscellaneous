#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<string>
#include <iostream>
#include<vector>
using namespace std;

std::string::iterator contains(char c, string s1) {
std::string::iterator i = std::find(s1.begin(), s1.end(),c);
if(i!=s1.end())
return i;
else
return s1.end();
}
static void print1(const char* title, const string& s) {
cout<<title;
cout<< s << endl;
cout<< "size = " << s.size() << endl;
}

int anagram(const string s1, string s2) 
{
for(int i=0;i<s1.size();i++)
{
std::string::iterator j = std::find(s2.begin(),s2.end(),s1[i]);
if(j!=s2.end())
{
s2.erase(j);
print1("str: ",s2);
}
else
return false;
}
return s2.size()==0;
}
int main(int argc, char *argv[]) {
printf("\n%s , %s\n", argv[1], argv[2]);
printf("%d", anagram(argv[1],argv[2]));
}
