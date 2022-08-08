#pragma once
#include <iostream>

// Pattern studies: abstract class

class Animal {
public:
    //every child class must implement makeNoise
    virtual void makeNoise() = 0;

    //children classes can use move if they want to
    void move(int speed) {

        if (speed > 0) {
            std::cout << "The animal moved \n";
        }
        else {
            std::cout << "The animal is standing still \n";
        }

    }
};

class Dog : public Animal {
public:
    //does not override move

    //implements makeNoise
    void makeNoise() {
        std::cout << "woof \n";
    }

    //has non-inherited function, specific of its kind
    bool beGoodBoy() {
        std::cout << "dog is being a good boy \n";
        return true;
    }
};


