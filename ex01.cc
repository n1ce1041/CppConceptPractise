/* **Goal**: Create a class with a pointer to a dynamically allocated memory block and implement the destructor, copy constructor, and copy assignment operator. */
#include <memory>
#include <iostream>

class SimpleClass {
public:
    SimpleClass(int value) : data(new int(value)) {
        std::cout << "Calling constructor" << std::endl;
    }
    // Implement copy constructor (Do a deep copy)
    SimpleClass(const SimpleClass& other){
        std::cout << "copy constructor is called" << std::endl;
        this->data = new int(*other.data);
    };

    // Implement copy assignment operator
    SimpleClass& operator=(const SimpleClass& other){
        std::cout << "copy assignment is called" << std::endl;
        
        // Avoid self-assignment
        if (this == &other) {
            return *this;
        }

        // Release any existing resource
        delete data;

        // Deep copy
        this->data = new int(*other.data);

        return *this;
    };

    ~SimpleClass(){
        std::cout << "destructor called" << std::endl;
        if(data != nullptr) delete data;
    };  // Implement destructor to free memory

    int getData(void){
        return *data;
    }
    
private:
    int* data;
};

void randomFunc(SimpleClass hello){
    // This should just do a deep copy
}

void randomFunc2(SimpleClass &hello){
    // This should just pass by value and not free it 
    SimpleClass random = hello; // This should copy assignment

    // Random is freed here.
}


int main() {

SimpleClass hello(3);

randomFunc(hello);
randomFunc2(hello);

// This is safe
std::cout << "Data of hello: " << hello.getData() << std::endl; 


return 0;
}
