#include <iostream>
#include <memory>

class A; // Forward declaration of class A

class B {
public:
    std::shared_ptr<A> a_ptr;  // Shared pointer to A

    ~B() {
        std::cout << "B destroyed\n";
    }
};

class A {
public:
    std::shared_ptr<B> b_ptr;  // Shared pointer to B

    ~A() {
        std::cout << "A destroyed\n";
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // Create circular reference
    a->b_ptr = b;
    b->a_ptr = a;

    std::cout << "Creating circular reference between A and B\n";

    // Both A and B are still alive due to the circular reference
    return 0;
}
