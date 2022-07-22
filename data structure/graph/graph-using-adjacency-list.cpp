#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int d) : data(d) { next = NULL; }
};

class AdjList
{
public:
    Node *head;

    AdjList() {}
    AdjList(Node *h) : head(h) {}
};

class Graph
{
private:
    const int V;
    AdjList *graph;

public:
    Graph(int v) : V(v)
    {
        graph = new AdjList[V];

        for (int i = 0; i < V; i++)
            graph[i].head = NULL;
    }

    void addEdge(int u, int v)
    {
        Node *node = new Node(v);

        if (graph[u].head == NULL)
            graph[u].head = node;
        else
        {
            Node *head = graph[u].head;
            while (head->next != NULL)
            {
                if (head->data == v)
                    return;

                head = head->next;
            }
            head->next = node;
        }

        node = new Node(u);
        if (graph[v].head == NULL)
            graph[v].head = node;
        else
        {
            Node *head = graph[v].head;
            while (head->next != NULL)
            {
                if (head->data == u)
                    return;

                head = head->next;
            }
            head->next = node;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "The Adjacency list of vertex " << i << " is: \n head ";
            Node *head = graph[i].head;
            while (head != NULL)
            {
                cout << head->data << " -> ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    return 0;
}