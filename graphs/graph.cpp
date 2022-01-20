// Network Like DS
#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <set>
using namespace std;

// Using class to make data sharing between functions easy
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << endl;
            for (auto i : l[curr])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void dfsHelper(int source, bool *visited)
    {
        cout << source << endl;
        visited[source] = true;
        for (auto node : l[source])
        {
            if (!visited[node])
            {
                dfsHelper(node, visited);
            }
        }
    }
    void dfs(int source)
    {
        bool visited[V] = {0};
        dfsHelper(source, visited);
    }

    // For this to work, we need to make the graph unidirectional and acyclic
    void topological_sort()
    {
        int indegree[V] = {0};
        // Calculating indegree i.e dependency
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        // Pushing all 0 dependency nodes to queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // Popping from q -> decreasing dependency of all neighnours by 1-> Pushing 0 dependency neighnours to queue
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << endl;
            for (auto i : l[curr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 5, false);
    g.addEdge(4, 5, false);
    g.addEdge(1, 4, false);
    g.addEdge(1, 2, false);
    g.printAdjList();
    g.topological_sort();
}