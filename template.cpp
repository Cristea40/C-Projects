#include <iostream>

template <typename T>
class MyListItem {
public:
    T value;
    MyListItem* next;

    MyListItem(const T& val){
        value = val;
        next=nullptr;
    }
};

int main() {
    
    MyListItem<int>* item1 = new MyListItem<int>(10);
    MyListItem<int>* item2 = new MyListItem<int>(20);
    MyListItem<int>* item3 = new MyListItem<int>(30);

    
    item1->next = item2;
    item2->next = item3;

    
    MyListItem<int>* current = item1;
    while (current != nullptr) {
        std::cout << "Value: " << current->value << std::endl;
        current = current->next;
    }

 
    delete item1;
    delete item2;
    delete item3;

    return 0;
}


