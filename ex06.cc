/*
 * **Goal**: Create a simple inheritance hierarchy with a base class and derived
 * classes.
 */
#include <iostream>
#include <memory>

class Shape{
    public:
        Shape(std::string name): owner(name){
        }

        virtual std::string getOwner() const =0;
        virtual void draw() const = 0;
        virtual ~Shape() = default;
    protected:
    std::string owner;
};

class Circle: public Shape{
    public:
        Circle(std::string name): Shape(name){
        }

        std::string getOwner() const override {
            std::cout << "Owner is " << owner << std::endl;
            return owner;
        }

        void draw() const override{
            std::cout << "Drawing a Circle!" << std::endl;
        }

};

class Square: public Shape{
    public:
        Square(std::string name): Shape(name){
        }

        std::string getOwner() const override {
            std::cout << "Owner is " << owner << std::endl;
            return owner;
        }

        void draw() const override{
            std::cout << "Drawing a Square!" << std::endl;
        }

};

int main() {

    Square sq("square");
    Circle circ("circle");

    sq.draw();
    circ.draw();

    sq.getOwner();
    circ.getOwner();

    return 0;
}

