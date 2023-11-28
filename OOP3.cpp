#include <iostream>
#include <vector>

class Animal{
    public:

    int Legs;

    Animal(int legs){
        Legs = legs;

    }

     virtual void eat() {

        std::cout<<"This animal is eating"<<"\n";
    }

    int numlegs(){
        return Legs;

    }
};

class Dog: public Animal{
    public:

    Dog(int legs):Animal(legs){

    }

    void bark(){
        std::cout<<"Ham Ham"<<"\n";
    }
    void eat() override{

        std::cout<<"This dog is eating"<<"\n";
    }

    
};

class Cat: public Animal{
    public:

    Cat(int legs):Animal(legs){
        
    }

    void eat() override{

        std::cout<<"This cat is eating"<<"\n";
        
    }
};

int main()
 {

    std::vector<Animal*>animals;

    Dog Rex(4);
    Cat Bella(4);

    animals.push_back(&Rex);
    animals.push_back(&Bella);

    for (const auto& animal : animals) {
        animal->eat();
        std::cout << "Animal have : " << animal->numlegs() <<"\n";
    }
    

    return 0;
}

    

