#include <iostream>
#include <string>

class Animal {
private:
    std::string name;

public:
    
    Animal(const std::string& animalName){
        name = animalName;
    }

    
    void eat() const {
        std::cout << name << " is eating..." << std::endl;
    }

    
    ~Animal() {
        std::cout << name << " is being destroyed." << std::endl;
    }
};

int main() {
    
    Animal* animalArray = static_cast<Animal*>(malloc(3 * sizeof(Animal)));

 
    new (&animalArray[0]) Animal("Lion");
    new (&animalArray[1]) Animal("Elephant");
    new (&animalArray[2]) Animal("Monkey");

    
    for (int i = 0; i < 3; ++i) {
        animalArray[i].eat();
    }

    
    for (int i = 0; i < 3; ++i) {
        animalArray[i].~Animal();
    }

    
    free(animalArray);

    return 0;
}


