#include <iostream>

class CharacterPrinter {
public:
    
    static void a(int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << 'a';
        }
        std::cout <<"\n";
    }

    
    static void b(int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << 'b';
        }
        std::cout <<"\n";
    }

    
    static void run(void (*func)(int), int n) {
        int count = 0;
        while (count < 5) {
            func(n);
            count++;
        }
    }
};

int main()
 {
     CharacterPrinter::run(CharacterPrinter::a, 10);
     CharacterPrinter::run(CharacterPrinter::b, 15);
     

    return 0;
}


