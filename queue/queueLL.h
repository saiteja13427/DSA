class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
    }
};

class Queue
{
    Node *f = NULL, *r = NULL;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (f == NULL)
        {
            f = r = temp;
        }
        else
        {
            Node *itr = f;
            r->next = temp;
            r = temp;
        }
    }

    void pop()
    {
        if (!empty())
        {
            Node *temp = f;
            f = f->next;
            delete temp;
        }
    }

    int front()
    {
        return f->data;
    }

    bool empty()
    {
        return f == NULL;
    }
};