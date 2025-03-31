#include <bits/stdc++.h>
using namespace std;
class A{
    cout<<"*";
    public:
    int x;
    
    class D{
        public:
        void func(){
            A a;
            cout<<'#';
            int z=a.x;
            int w=a.y;
            cout<<z<<" ";
            cout<<w;
        }

    };
    void func2(){
        D d;
        d.func();
    }
    int y; 
};
// class B : public A{
//     public:
//     int y;
//     B(){
//         y=2;
//     }
// };
// class C: public A{
//     public:
//     int z;
//     C(){
//         z=2;
//     }
// };
int main(){
    // C* objc=new C();
    // A* obja=new A();
    // B* objb=new B();
    // A* ptra;
    // B* ptrb;
    // ptra=objc;
    // C* ptrc=dynamic_cast<C*>(ptra);
    // cout << ptrc->z << endl;

    A a;
    a.x=2;
    a.y=3;
    a.func2();
}