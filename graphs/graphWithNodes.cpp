#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
    string name;

public:
    list<string> nbrs;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto &city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }

    void printGraph()
    {
        for (auto &cityPair : m)
        {
            string city = cityPair.first;
            Node *node = cityPair.second;
            cout << city << "-->";
            for (auto &nbrs : node->nbrs)
            {
                cout << nbrs << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<string> city;
    city.push_back("Delhi");
    city.push_back("Hyderabad");
    city.push_back("Chennai");
    city.push_back("Bangalore");
    Graph g(city);

    g.addEdge("Hyderabad", "Delhi");
    g.addEdge("Hyderabad", "Chennai");
    g.addEdge("Hyderabad", "Bangalore");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Chennai", "Bangalore");

    g.printGraph();
}