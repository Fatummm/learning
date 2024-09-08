#include <iostream>
#include <memory>

class A {
public:
    A(int x) {
        std::cout << "Constructor(int): " << x << "\n";
    }
    A(const A&) {
        std::cout << "Copy constructor\n";
    }
    virtual ~A() {
        std::cout << "Destructor\n";
    }
    virtual void foo() const {
        std::cout << "A::foo()\n";
    }
};


class B : public A {
private:

public:
    B(int x = 17) : A(42) {
        std::cout << "Constructor(int): " << x << "\n";
    }
};

int main() {
    std::unique_ptr<A> ptr(new B);
    ptr->foo();
}
/*
Constructor(int): 42
Constructor(int): 17
A::foo()
Destructor
Destructor
*/