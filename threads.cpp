#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;
const int max_count = 100;

void printChar(char ch, int threadNum) {
    for (int i = 0; i < max_count; ++i) {
        
        counter++;

        
        std::lock_guard<std::mutex> lock(mtx);

        
        if (counter % 3 == threadNum) {
            std::cout << ch << std::flush;
        }
    }
}

int main() {
    
    std::thread threadA(printChar, 'A', 0);
    std::thread threadB(printChar, 'B', 1);
    std::thread threadC(printChar, 'C', 2);

    
    threadA.join();
    threadB.join();
    threadC.join();

    std::cout <<"\n";

    return 0;
}

