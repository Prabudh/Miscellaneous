#ifndef dstack_H
#define dstack_H

#include "../util/util.h"
#include "../darray/darray.h"

template <typename T>
bool darray<T>::_display = false;

template <typename T>
class dstack {
public:
    dstack(int size = 50);
    ~dstack();
    int num_elements() const;
    bool isempty() const;
    bool isfull() const;
    void push(const T& b);
    T& top();
    void pop();
    void for_each_element_of_stack_from_top_to_bottom(void(*pf) (T&c));
    bool display()const{return _display;}
    static void set_display(bool x) {
       darray<T>::set_display(x);
       _display =x;
    }
    dstack(const dstack<T>& s) = delete;
    dstack<T>& operator=(const dstack<T>& rhs) = delete;
private:
    int _sp;
    darray<T> _stack;
    static bool _display;
};

templat<class T>
void dstack<T>:: for_each_element_ofstack_from_top_to_bottom(void(*pf)(T &c))
{
for(int i = _sp-1;i>=0;i--) {
   pf(_stack[i]);
}
}
