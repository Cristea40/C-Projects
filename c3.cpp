#include <iostream>

class CharacterPrinter {
public:
    
    static void a() {
        for (int i = 0; i < 10; ++i) {
            std::cout << 'a';
        }
        std::cout <<"\n";
    }

    
    static void b() {
        for (int i = 0; i < 10; ++i) {
            std::cout << 'b';
        }
        std::cout <<"\n";
    }

    
    static void run(void (*func)()) {
        int count = 0;
        while (count < 5) {
            func();
            count++;
        }
    }
};

int main()
 {
     CharacterPrinter::run(CharacterPrinter::a);
     CharacterPrinter::run(CharacterPrinter::b);

    return 0;
}

    

