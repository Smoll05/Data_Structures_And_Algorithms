class Queue {
public:
    virtual void enqueue(int) = 0;
    virtual int dequeue() = 0;
    virtual int peek() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
};