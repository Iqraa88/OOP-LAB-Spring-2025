#include <iostream>
#include <exception>


using namespace std;


class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>

class Queue {
    T* arr;
    int size;
    int index;

public:
    Queue(int size,int index=0) :size(size), index(index) {
        arr = new T[size];
    }

    void enqueue(T item) {
        if (index >= size){
            throw QueueOverflowException();
        }
        arr[index] = item;
        index++;
    }

    T dequeue() {
        if (index == 0)
            throw QueueUnderflowException();

        T first = arr[0];
        for (int i = 1; i < index; i++) {
            arr[i - 1] = arr[i];
        }



    index--;
        return first;
    }




    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue<int> q(2);

    cout << "Attempting to enqueue to a full queue..." << endl;
    try {

        q.enqueue(10);

        q.enqueue(20);
        q.enqueue(30); 
    } 
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }



    cout << "Attempting to dequeue from an empty queue..." << endl;
    try {
        q.dequeue();
        q.dequeue();
        q.dequeue(); 
    } 
    
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
