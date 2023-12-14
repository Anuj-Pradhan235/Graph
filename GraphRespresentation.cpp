#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<vector<int>> adjMat;
    unordered_map<int, vector<int>> adjLis;
    int n, e;
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;
        adjMat.resize(n, vector(n, 0));
    }
    void addEdge(int u, int v, bool direction)
    {
        adjMat[u][v] = 1;
        adjLis[u].push_back(v);
        if (direction == false)
        {
            adjMat[v][u] = 1;
            adjLis[v].push_back(u);
        }
    }
    void printAdjLis()
    {
        cout << "AdjLis:" << endl;
        for (auto i : adjLis)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j << " ";
            cout << endl;
        }
    }
    void printAjdMat()
    {
        cout << "AdjMat:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << adjMat[i][j] << " ";
            cout << endl;
        }
    }
};
int main()
{
    int n, e;
    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;
    Graph g(n, e);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }
    g.printAdjLis();
    g.printAjdMat();
}