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
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int i, int j, int weight, bool undir = true)
    {
        l[i].push_back({j, weight});
        if (undir)
        {
            l[j].push_back({i, weight});
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node.first << " ";
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
                if (!visited[i.first])
                {
                    q.push(i.first);
                    visited[i.first] = true;
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
            if (!visited[node.first])
            {
                dfsHelper(node.first, visited);
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
                indegree[nbr.first]++;
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
                indegree[i.first]--;
                if (indegree[i.first] == 0)
                {
                    q.push(i.first);
                }
            }
        }
    }

    int dijkshtra(int source, int dest)
    {
        // To have the distances
        vector<int> distance(V, INT_MAX);
        // To have the set of distance, node
        set<pair<int, int>> s;
        // Pushing {0, source}
        distance[source] = 0;
        s.insert({0, source});

        while (!s.empty())
        {
            // Popping the first element from the set and storing the values
            auto itr = s.begin();
            int node = itr->second;
            int distTillNow = itr->first;
            s.erase(itr);
            // Parsing the nbrs of the first pair and updating the distances
            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.first;
                int edgeWeight = nbrPair.second;
                if (distTillNow + edgeWeight < distance[nbr])
                {
                    // Remove if nbr already exists
                    auto f = s.find({distance[nbr], nbr});
                    if (f != s.end())
                        s.erase(f);

                    // Insert updated one
                    distance[nbr] = distTillNow + edgeWeight;
                    s.insert({distance[nbr], nbr});
                }
            }
        }
        return distance[dest];
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1, false);
    g.addEdge(0, 2, 4, false);
    g.addEdge(0, 3, 7, false);
    g.addEdge(1, 2, 1, false);
    g.addEdge(2, 3, 2, false);
    g.addEdge(3, 4, 3, false);
    g.printAdjList();
    cout << g.dijkshtra(0, 2);
}