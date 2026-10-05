#include <iostream>
#include <stdexcept>
#include <cstddef>
using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;

    void resize() {
        size_t newCapacity = capacity * 2;
        int* temp = new int[newCapacity];

        for (size_t i = 0; i < size; ++i) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

public:
    explicit DynamicArray(size_t initialCapacity = 5)
        : data(nullptr), size(0), capacity(initialCapacity) {
        if (capacity == 0) {
            capacity = 1;
        }

        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
        data = nullptr;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void addItem(int value) {
        if (size >= capacity) {
            resize();
        }

        data[size] = value;
        ++size;

        cout << "Added item: " << value << endl;
    }

    bool removeItemAt(int index) {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            cout << "Invalid index!" << endl;
            return false;
        }

        for (size_t i = static_cast<size_t>(index); i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size;

        cout << "Item removed from index " << index << endl;
        return true;
    }

    int findItem(int target) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == target) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }

    void printAll() const {
        if (size == 0) {
            cout << "Current List Contents: [empty]" << endl;
            return;
        }

        cout << "Current List Contents: ";

        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

void processMatrix() {
    const int ROWS = 3;
    const int COLS = 3;

    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transpose[COLS][ROWS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;

    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "--- STARTING REFACTORED SUBSYSTEM ---" << endl;

    DynamicArray records;

    records.addItem(10);
    records.addItem(20);
    records.addItem(30);
    records.addItem(40);
    records.addItem(50);
    records.addItem(60);

    cout << "\nSize: " << records.getSize() << endl;
    cout << "Capacity: " << records.getCapacity() << endl;

    records.printAll();

    int foundIndex = records.findItem(30);

    if (foundIndex != -1) {
        cout << "Found 30 at index: " << foundIndex << endl;
    } else {
        cout << "30 was not found." << endl;
    }

    records.removeItemAt(2);
    records.printAll();

    records.removeItemAt(99);
    records.printAll();

    records.removeItemAt(-5);
    records.printAll();

    cout << "Search for 999: " << records.findItem(999) << endl;

    processMatrix();

    cout << "\n--- SUBSYSTEM FINISHED ---" << endl;

    return 0;
}
