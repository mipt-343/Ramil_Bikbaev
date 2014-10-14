#include <iostream>

using namespace std;

template<class T>
class smartP
{
    T *_p;
public:
    smartP(T *p)
    {
	cout << "Constructor called!\n";
	_p = p;
    }
    ~smartP()
    {
	cout << "Destructor called!\n";
	delete _p;
    }
    void myprint()
    {
    cout<<*_p;
    }
};

void f()
{
    smartP<int> pi(new int(10));
    pi.myprint();
}

void g()
{
    smartP<int> d(new int(20));
    d.myprint();
}
int main()
{
    f();
    g();
    return 0;
}