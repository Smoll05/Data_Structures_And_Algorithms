#include <iostream>
#include <cstdlib>
#include <math.h>
#include "List.hpp"
using namespace std;

class DynamicArray : public List {
    int* array;
    int size;
    int capacity = 5;

    public:
    DynamicArray() {
    	array = (int*) calloc( capacity, sizeof(int) );
        size = 0;
    }


    void add(int num) {
        if(size == capacity) {
            capacity = ceil(capacity * 1.5);
            array = (int*) realloc (array, capacity * sizeof(int));
        }
        array[size++] = num;
    }


    void addAt(int num, int pos) {
        int i;
        for(i = size; i >= pos; i--) {
            array[i] = array[i - 1];
        }
        
        if(size == capacity) {
            capacity = ceil(capacity * 1.5);
            array = (int*) realloc (array, capacity * sizeof(int));
        }
        
        array[i] = num;
        size++;
    }


    int remove(int num) {
        int pos = 1;
        for(int i = 0; i < size; i++) {
            if(array[i] == num) {
                for(int j = i; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                
                size--;
                if(size <= floor((2.0/3) * capacity)) {
                    capacity = max(ceil(capacity * 0.75), 5.0);
                    array = (int*) realloc (array, capacity * sizeof(int));
                }
                return pos;
            }
            pos++;
        }
        return -1;
    }
       

    int get(int pos) {
        return array[pos-1];
    }


    int removeAt(int pos) {
        int ret = array[pos-1];
        
        for(int i = pos-1; i < size - 1; i++) {
            array[i] = array[i+1];
        }
        
        size--;
        if(size <= floor(2.0/3.0 * capacity)) {
            capacity = max(ceil(capacity * 0.75), 5.0);
            array = (int*) realloc (array, capacity * sizeof(int));
        }
        
        return ret;
    }


    void print() {
        int i;
        cout << "Size: " << size << "/" << capacity << endl;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }
};