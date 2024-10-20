#include <iostream>
#include "List.hpp"
using namespace std;

class ArrayList : public List {
    int array[5];
    int size;

    public:
    ArrayList() {
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;
        array[3] = 0;
        array[4] = 0;
        size = 0;
    }


    void add(int num) {
        if (size < 5) {
            array[size++] = num;
        } else {
            cout << "PUNO NA MY FRIEND" << endl;
        }
    }


    void addAt(int num, int pos) {
        size++;
        for(int i = size - 1; i >= pos; i--) {
            array[i] = array[i-1];
        }
        array[pos - 1] = num;
    }


    int remove(int num) {
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                array[size-1] = 0;
                size = size-1;
                return i+1;
            } 
        }
        return -1;
    }


    int get(int pos) {
        return array[pos-1];
    }


    int removeAt(int pos) {
        int elem = array[pos - 1];
        for(int i = pos-1; i < size - 1; i++) {
            array[i] = array[i+1];
        }
        array[--size] = 0;
        
        return elem;
    }


    int removeAll(int num) {
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(array[i] == num) {
                for(int j = i; j < size - 1; j++) {
                    array[j] = array[j+1];
                }
                i--;
                array[--size] = 0;
                count++;
            }
        }
        return count;
    }


    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};