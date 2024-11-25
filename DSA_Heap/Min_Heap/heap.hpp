class Heap {
public:
    virtual int insert(int n) = 0;
    virtual int deleteMin() = 0;
    virtual void heapify(int arr[], int index) = 0;
    virtual int getLeft(int index) = 0;
    virtual int getRight(int index) = 0;
    virtual int getParent(int index) = 0;
};