#include<iostream>
using namespace std;

class A {
  int i;
public:
  A(int ii) : i(ii) { cout << "A's ctor is filled\n";}
  ~A() { cout << "A's dtor is called\n";}

  void f() const {}
};

class B {
  int i;
public:
  B(int ii) : i(ii) {cout << "B's ctor is filled\n";}
  ~B() {cout << "B's dtor is called\n";}
  void f() const {}
};

class C : public B {
  A a;
public:
  C(int ii) : B(ii), a(ii) {cout << "C's ctor is filled\n";}
  ~C() {cout << "C's dtor is called\n";} 
  void f() const {  
    a.f();
    B::f();
  }
};

int main() {
  C c(47);
  return 0;
}