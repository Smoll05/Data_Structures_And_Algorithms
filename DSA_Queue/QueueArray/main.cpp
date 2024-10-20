#include <iostream>
#include "QueueArray.cpp"

int main() {
    Queue* queue = new QueueArray();

    cout << queue->dequeue() << endl;
    cout << queue->peek() << endl;
    queue->enqueue(1);
    cout << queue->peek() << endl;
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    cout << "Size: " << queue->size() << endl;
    cout << "Is Empty: " << queue->isEmpty() << endl;
    cout << queue->peek() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << "Size: " << queue->size() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << "Is Empty: " << queue->isEmpty() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << "Is Empty: " << queue->isEmpty() << endl;
}