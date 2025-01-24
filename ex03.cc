/*
 * **Goal**: Create a class that uses `std::unique_ptr` to manage its resource.
 * Demonstrate ownership transfer and automatic cleanup.
 */

#include <memory>
#include <iostream>



class Resource {
public:
    Resource(int value) : data(std::make_unique<int>(value)) {}

    void display() const { std::cout << *data << std::endl; }

    int getData(void) const {
        return *data;
    }

    int setData(int n){
        *this->data = n;
        return n;
    }



private:
    std::unique_ptr<int> data;
};


void randomOne(Resource &first){
    std::cout << "Random One " 
    << "value is still :" << first.getData() << std::endl;

    first.setData(3);

    return;
}

void randomTwo(Resource first){
    // Compiler will warn and say that this is implicitly deleted.
    // Not called, but thanks clang.
    first.setData(69);

    return;
}

void randomThree(Resource* first){
    // Compiler will warn and say that this is implicitly deleted.
    // Not called, but thanks clang.
    first->setData(59);

    return;
}



int main() {

    Resource first(5);
    std::cout << "Value is " << first.getData() << std::endl; // 5
    randomOne(first);
    std::cout << "Value is " << first.getData() << std::endl; // 3 
    randomThree(&first);
    std::cout << "Value is " << first.getData() << std::endl;

    return 0;
}
