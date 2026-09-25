// Concept 9: Base Pointer With Virtual Function
// Aim: To implement run-time polymorphism using a virtual function and base pointer.

// Include input-output stream library
#include <iostream>

// Base class Animal introducing a virtual function
class Animal {
public:
    // Virtual function sound() allowing dynamic binding in derived classes
    virtual void sound() const {
        // Default base implementation
        std::cout << "Animal makes a sound\n";
    }

    // Default virtual destructor to ensure safe deletion via base pointers
    virtual ~Animal() = default;
};

// Derived class Dog inheriting from Animal
class Dog : public Animal {
public:
    // Override virtual sound() function for Dog behavior
    void sound() const override {
        // Output Dog sound
        std::cout << "Dog barks\n";
    }
};

// Derived class Cat inheriting from Animal
class Cat : public Animal {
public:
    // Override virtual sound() function for Cat behavior
    void sound() const override {
        // Output Cat sound
        std::cout << "Cat meows\n";
    }
};

// Entry point of program
int main() {
    // Instantiate Dog object
    Dog dog;

    // Instantiate Cat object
    Cat cat;

    // Declare Animal base pointer pointing to Dog instance
    Animal* animal = &dog;

    // Polymorphic call: dynamically resolves and invokes Dog::sound()
    animal->sound();

    // Reassign base pointer to point to Cat instance
    animal = &cat;

    // Polymorphic call: dynamically resolves and invokes Cat::sound()
    animal->sound();

    // Return 0 indicating successful completion
    return 0;
}
