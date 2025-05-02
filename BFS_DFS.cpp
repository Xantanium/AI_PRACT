#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    int m_v;
    vector<vector<int>> adj;

public:
    Graph(int v);

    void addEdge(int u, int v);

    void bfs(int n);
    void dfs(int n);

private:
    void dfsUtil(int n, vector<bool> visited);
};

int main(int argc, char* argv[])
{
    Graph g(5);

    g.addEdge(1, 5);
    g.addEdge(1, 5);
    g.addEdge(1, 5);
    g.addEdge(1, 5);
    g.addEdge(1, 5);

    g.bfs(1);
    g.dfs(1);

    return 0;
}

Graph::Graph(int v)
    : m_v(v)
{
    this->adj.resize(v);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(int n)
{
    vector<bool> visited(m_v, false);
    queue<int> q;

    visited[n] = true;
    q.push(n);

    cout << "Starting bfs from node: " << n << endl;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
