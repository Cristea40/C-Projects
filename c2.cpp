#include <iostream>

void increment(int* p) {
    
    (*p)++;

    std::cout << "Inside increment function - Address: " << p << ", Value: " << *p << std::endl;
}

void increment_reference(int& ref) {
    ref++;
    
}

int main()
 {
     int number = 10;

    std::cout << "In main - Initial Address: " << &number << ", Initial Value: " << number << std::endl;

    increment(&number);

    std::cout << "In main - Updated Address: " << &number << ", Updated Value: " << number << std::endl;

    increment_reference(number);

    
    std::cout << "In main - Adress: " << &number << ", Update Value (reference): " << number << std::endl;


    return 0;
}

    

