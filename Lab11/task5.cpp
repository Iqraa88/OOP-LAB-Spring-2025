#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeStockException : public exception {
};

class OverCapacityException : public exception {
};

template <class T>

class InventoryItem {
    T stock;
    T capacity;

public:
    InventoryItem(T capacity) : stock(0), capacity(capacity) {}

    void setStock(T newValue) {

        cout << "Attempting to set stock to " << newValue << "...";
        if (newValue > capacity) {
            cout << " Capacity Limit Exceeds..." << endl;
            throw OverCapacityException();

        }
         else if (newValue < 0) {
            cout << "-----------" << endl;
            throw NegativeStockException();
        } 
        else {
            cout << "---------- "<< endl;
            stock = newValue;
        }
    }
};

int main() {


    InventoryItem<int> item(100);

    try {
        item.setStock(-5);
    } 
    catch (const NegativeStockException& e) {

        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }
    
    
    catch (const exception& e) {
        cout << "Caught std::exception - what(): " << e.what() << endl;
    }

    try {
        item.setStock(120);

    } 
    
    catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }
    
    catch (const exception& e) {
        cout << "Caught std::exception - what(): " << e.what() << stdendl;
    }

    return 0;
}
