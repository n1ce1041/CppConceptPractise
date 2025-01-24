/*
 * **Goal**: Implement a class that uses `std::shared_ptr` to manage shared
 * ownership. Show reference counting.
 */

#include <memory>
#include <iostream>

class SharedResource {
public:
    SharedResource(int value) : data(std::make_shared<int>(value)) {}

    void display() const { std::cout << *data << std::endl; }

    void setData(int val) {
        *data = val;
    }

    int getData(void) const {
        return *data;
    }

    // Getter for shared_ptr
    std::shared_ptr<int> getDataPtr() const {
        return data;
    }

private:
    std::shared_ptr<int> data;
};

int main() {
    SharedResource one(4);

    std::cout << "Initial References: " << one.getDataPtr().use_count() << std::endl;  // Output: 1

    std::shared_ptr<int> ptr2 = one.getDataPtr();
    std::cout << "References after creating ptr2: " << one.getDataPtr().use_count() << std::endl;  // Output: 2

    {
        std::shared_ptr<int> ptr3 = one.getDataPtr();
        std::cout << "References after creating ptr3: " << one.getDataPtr().use_count() << std::endl;  // Output: 3
    }

    std::cout << "References after ptr3 goes out of scope: " << one.getDataPtr().use_count() << std::endl;  // Output: 2

    return 0;
}

