#include <iostream>
class Animal{
    public:

    int Legs;

    Animal(int legs){
        Legs = legs;

    }

     virtual void eat()=0;

    int numlegs(){
        return Legs;

    }
};

class Dog: public Animal{
    public:

    Dog(int legs):Animal(legs){

    }
    void eat(){

        std::cout<<"This dog is eating"<<"\n";
    }

    void bark(){
        std::cout<<"Ham Ham"<<"\n";
    }
     
};

class Cat: public Animal{
    public:

    Cat(int legs):Animal(legs){
        
    }

    void eat(){

        std::cout<<"This cat is eating"<<"\n";
        
    }
};

int main()
 {

    Dog dog1(4);
    dog1.eat();
    dog1.bark();
    Cat cat1(4);
    cat1.eat();
    std::cout << "Number of legs: " << cat1.numlegs() <<"\n";
    

    return 0;
}


