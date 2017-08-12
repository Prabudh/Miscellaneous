class B {
public:
   B():_b(100) {
       cout << "B constructor"<<endl;
   }
   ~B() {
       cout << "B destructor"<<endl;
   }
   B(const B& e) : _b(e._b) {
      cout << "B copy constructor"<<endl;
   }

   B& operator=(const B& e) 
   {
      if(this != &e)
      {
          _b=e._b;
      }
      return *this;
   }
private :
   int _b;
};

class D: public B {
public:
  D():_d(200) {
    cout<< "D constructor" <<endl;
  }
  ~D() {
    cout<<"D destructor" <<endl;
  }
 
  D(const D&e):B(e),_d(e._d) {
    cout<<"In d copy constructor";
  }
  D& operator=(const D& x)
  {
      if(this!=&x)
      {
         B::operator=(x);
         _d = x._d;
      }  
  return *this;
  }
  

private:
  int _d 
};
