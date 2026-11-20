#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// DIY 11.2: Generic Queue
// Implement a class template Queue<T> with enqueue/dequeue/front; test with string.

template <typename T>
class Queue {
private:
    T *arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int cap = 10) : capacity(cap), frontIndex(0), rearIndex(-1), count(0) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(const T &item) {
        if (count == capacity) {
            throw overflow_error("Queue is full!");
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        count++;
    }

    T dequeue() {
        if (empty()) {
            throw underflow_error("Queue is empty!");
        }
        T item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return item;
    }

    T front() const {
        if (empty()) {
            throw underflow_error("Queue is empty!");
        }
        return arr[frontIndex];
    }

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue<string> q(5);

    cout << "Enqueuing string packets..." << endl;
    q.enqueue("PACKET_HEADER");
    q.enqueue("PAYLOAD_DATA_01");
    q.enqueue("PAYLOAD_DATA_02");
    q.enqueue("PACKET_CRC_CHECKSUM");

    cout << "Front element: " << q.front() << endl;

    cout << "\nDequeuing all elements:" << endl;
    while (!q.empty()) {
        cout << "  Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}
