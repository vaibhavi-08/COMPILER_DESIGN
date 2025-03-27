#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int x;
    A(){
        x=1;
    }
    virtual ~A() = default;  
};
class B : public A{
    public:
    int y;
    B(){
        y=2;
    }
};
class C: public A{
    public:
    int z;
    C(){
        z=2;
    }
};
int main(){
    C* objc=new C();
    A* obja=new A();
    B* objb=new B();
    A* ptra;
    B* ptrb;
    ptra=objc;
    C* ptrc=dynamic_cast<C*>(ptra);
    cout << ptrc->z << endl;
}