template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *top = NULL;

public:
    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = top;
        top = n;
    }

    bool pop()
    {
        if (isEmpty())
            return false;
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    T getTop()
    {
        return top->data;
    }
};