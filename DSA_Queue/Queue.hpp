class Queue {
public:
    virtual void enqueue(int) = 0;
    virtual int dequeue() = 0;
    virtual int peek() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
};