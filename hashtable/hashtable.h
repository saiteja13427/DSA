#include <cstring>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;
    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    // Recursively destroys all linked nodes
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class hashtable
{
    Node<T> **table;
    // Current Size(cs)    Total number of entries
    // Total Size(ts)      Total size of table
    int cs;
    int ts;

    int hashFunction(string key)
    {
        int index = 0;
        int power = 1;
        for (auto ch : key)
        {
            index += (ch * power) % 29;
            power = (power * 29) % 29;
        }
        return index % ts;
    }

    // Increasing table size and rehashing
    void rehash()
    {
        // Storing pointer to old table and inserting in new table

        Node<T> **oldTable = table;

        cs = 0;
        int oldTs = ts;
        ts = 2 * ts + 1;
        table = new Node<T> *[ts];

        // Initialise the new table with NULLs
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        // Transfer elements from old table to new table
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
                insert(key, value);
                temp = temp->next;
            }

            // Deleting the complete linkedilist
            // This will delete only head node but the destructor of the node class will
            // delete all the linkedlist recursively
            if (oldTable[i])
                delete oldTable[i];
        }

        // Deleting the array we have []
        delete[] oldTable;
    }

public:
    hashtable(int size = 7)
    {
        cs = 0;
        ts = size;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }
    // Inserting into hash table
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    void insert(string key, T value)
    {
        // Getting index from hash func
        int index = hashFunction(key);
        Node<T> *n = new Node<T>(key, value);

        // Insertion at head of the linked list
        n->next = table[index];
        table[index] = n;

        cs++;
        float loadFactor = (float)cs / (float)ts;

        // Rehashing if loadfactor is > 0.7
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    // Check if a key exists in hash table
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    bool isPresent(string key)
    {
        int index = hashFunction(key);
        Node<T> *itr = table[index];

        while (itr != NULL)
        {
            if (itr->key == key)
                return true;
            itr = itr->next;
        }
        return false;
    }

    // Searching in hash table
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    // Return type          T* (address of value if present || NULL if not present)
    T *search(string key)
    {
        int index = hashFunction(key);
        Node<T> *itr = table[index];

        while (itr != NULL)
        {
            if (itr->key == key)
                return &itr->value;
            itr = itr->next;
        }
        return NULL;
    }

    // Erasing a node in hash table
    // Time Complexity      O(1) mostly
    // Space Complexity     O(1)
    void erase(string key)
    {
        int index = hashFunction(key);
        Node<T> *itr = table[index];

        // Head is the key
        if (itr->key == key)
        {
            Node<T> *temp = itr;
            table[index] = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        while (itr->next != NULL)
        {
            if (itr->next->key == key)
            {
                Node<T> *temp = itr->next;
                itr->next = itr->next->next;
                temp->next = NULL;
                delete temp;
                return;
            }
        }
    }

    // Operator Overoading to allow hashtable["apple"] = 1 syntax
    T &operator[](string key)
    {
        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }

        return *valueFound;
    }

    // Printing the state of hashtable
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << i << endl;
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << ": " << temp->value << endl;
                temp = temp->next;
            }
        }
    }
};