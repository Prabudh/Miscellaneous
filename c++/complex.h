#include ../util/util.h
class complex {
public:
complex();
complex(int x,int y);
void setxy();

complex& operator=(const complex& a);
release();
~complex();
private:
int _x;
int _y;
char* _s;
};
complex& complex::operator=(const complex&a)
{
   if(this!=&a)
   {
     release();
     setxy(a.x,a.y);
   }
return *this;
}
complex::setxy(int x, int y)
{
  _x=x;
  _y=y;
  _s = new char[strlen(itoa(x))+strlen(itoa(y))+2];

  strcpy(_s,"0+0i");
}

complex::complex()
{
  _x=0;
  _y=0;
  _s = new char[strlen("0+0i")+1]
  strcpy(_s,"0+0i");
}
complex::release()
{
delete[]_s;
}


