#include <iostream>
#include <memory>

using namespace std;

// DIY 13.1: Raw to smart
// Take any Week-4 program that used new/delete and rewrite it with unique_ptr
// so no explicit delete remains.

class Buffer {
private:
    int id;
    unique_ptr<int[]> data; // automatically manages dynamic array lifetime
    int size;

public:
    Buffer(int id, int s) : id(id), data(make_unique<int[]>(s)), size(s) {
        cout << "[Buffer #" << id << "] Created with " << size << " elements." << endl;
        for (int i = 0; i < size; ++i) {
            data[i] = (i + 1) * 10;
        }
    }

    ~Buffer() {
        // Automatic cleanup via unique_ptr -- no delete or delete[] needed!
        cout << "[Buffer #" << id << "] Destructed and memory freed automatically." << endl;
    }

    void print() const {
        cout << "Buffer #" << id << " contents: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Entering scope ===" << endl;
    {
        // Replaces raw pointer 'Buffer *b = new Buffer(1, 5);'
        auto buf = make_unique<Buffer>(1, 5);
        buf->print();

        // Transfer ownership using std::move (unique_ptr cannot be copied)
        unique_ptr<Buffer> movedBuf = std::move(buf);
        cout << "Ownership transferred. Calling via new owner:" << endl;
        movedBuf->print();

        // Exiting scope will automatically destroy movedBuf and free the memory!
    }
    cout << "=== Exited scope (no memory leaks, zero manual deletes) ===" << endl;

    return 0;
}
