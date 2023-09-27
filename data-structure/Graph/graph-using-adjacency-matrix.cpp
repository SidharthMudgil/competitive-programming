#include <iostream>

using namespace std;

class Graph
{
private:
    const int V;
    int **adj;

public:
    Graph(int v) : V(v)
    {
        adj = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adj[i] = new int[V];
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v)
    {
        if (u < V && v < V)
        {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
            cout << "    " << i << " ";
        cout << endl;

        for (int i = 0; i < V; i++)
        {
            cout << i << " ";

            for (int j = 0; j < V; j++)
                cout << "| " << adj[i][j] << " | ";

            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}