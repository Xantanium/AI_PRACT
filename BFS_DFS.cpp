#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;

public:
    Graph(int v);

    void addEdge(int u, int v);

    void bfs(int n);
    void dfs(int n);

private:
    void dfsUtil(int n, vector<bool>& visited);
};

int main(int argc, char* argv[])
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS from node 0: ";
    g.bfs(0);

    cout << "\nDFS from node 0: ";
    g.dfs(0);

    return 0;
}

Graph::Graph(int v)
    : v(v)
{
    this->adj.resize(v);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(int start)
{
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void Graph::dfs(int start)
{
    vector<bool> visited(v, 0);
    dfsUtil(start, visited);
}

void Graph::dfsUtil(int n, vector<bool>& visited)
{
    visited[n] = true;
    cout << n << " ";
    for (int neighbour : adj[n]) {
        if (!visited[neighbour])
            dfsUtil(neighbour, visited);
    }
}
