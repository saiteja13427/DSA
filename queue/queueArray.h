template <typename T>
class Queue
{

    T *arr;
    int front, rear, cs, ms;

public:
    Queue(int length)
    {
        ms = length;
        cs = 0;
        front = 0;
        rear = length - 1;
        arr = new T[length];
    }

    bool empty()
    {
        return cs == 0;
    }

    bool full()
    {
        return ms == cs;
    }

    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % ms;
            cs--;
        }
    }

    T f()
    {
        return arr[front];
    }
};