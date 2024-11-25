#include <cstdlib>
#include <stdexcept>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "heap.hpp"

using namespace std;

class MinHeap : Heap {
private:
    int* arr;
    int size;
    int capacity;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    MinHeap() : size(0), capacity(5) {
        arr = (int*) malloc (capacity * sizeof(int));
    }

    int insert(int index) {
        if(size == capacity) {
            capacity *= 1.5;
            arr = (int*) realloc (arr, capacity * sizeof(int));
        }

        arr[size] = index;
        int curr = size;

        while(curr > 0 && arr[(curr-1) / 2] > arr[curr]) {
            swap(arr[(curr-1)/2], arr[curr]);
            curr = (curr-1)/2;
        }

        size++;
        return index;
    }

    int deleteMin() {
        int ret = arr[0];

        arr[0] = arr[size-1];
        heapify(arr, 0);

        size--;
        if(size <= capacity/2) {
            capacity = max(capacity * 0.5, 5.0);
            arr = (int*) realloc (arr, capacity * sizeof(int));
        }

        return ret;
    }

    void heapify(int arr[], int index) {
        int left = 2 * index + 1;
        int right = left + 1;
        int smallest = index;

        if(left < size && arr[left] < arr[index]) smallest = left;

        if(right < size && arr[right] < arr[smallest]) smallest = right;

        if(smallest != index) {
            swap(arr[smallest], arr[index]);
            heapify(arr, smallest);
        }
    }


    int getLeft(int index) {
        int left = 2*index+1;
        if(left >= size) throw logic_error(to_string(index) + " does not have a left child\n");

        return arr[left];
    }

    int getRight(int index) {
        int right = 2*index+2;
        if(right >= size) throw logic_error(to_string(index) + " does not have a right child\n");

        return arr[right];
    }

    int getParent(int index) {
        int parent = (index-1)/2;
        if(parent < 0) throw logic_error(to_string(index) + " does not have a parent");

        return arr[parent];
    }

    int getValue(int index) {
        if(index < 0 || index >= size) throw logic_error("Index out of bounds");

        return arr[index];
    }

    void print() {
        cout << "Heap Array: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};