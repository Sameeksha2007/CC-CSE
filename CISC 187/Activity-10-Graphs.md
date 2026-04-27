# Activity 10: Graphs
## Question 1: Create a theoretical graph using a pen and paper OR electronically.
        A
       / \
      B---C
       \ /
        D
       / \
      E   F
- Vertices: A, B, C, D, E, F
- Edges: A–B, A–C, B–C, B–D, C–D, D–E, D–F

## Question 2: Implement the graph created in step 1 and apply breadth and depth-first search algorithms using C++.
```C++
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS — uses a queue, visits level by level
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS: ";
        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << (char)('A' + v) << " ";
            for (int nb : adj[v])
                if (!visited[nb]) { visited[nb] = true; q.push(nb); }
        }
        cout << endl;
    }

    // DFS — uses a stack, explores deep before backtracking
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        cout << "DFS: ";
        while (!s.empty()) {
            int v = s.top(); s.pop();
            if (!visited[v]) {
                cout << (char)('A' + v) << " ";
                visited[v] = true;
                for (int i = adj[v].size()-1; i >= 0; i--)
                    if (!visited[adj[v][i]]) s.push(adj[v][i]);
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,1); // A-B
    g.addEdge(0,2); // A-C
    g.addEdge(1,2); // B-C
    g.addEdge(1,3); // B-D
    g.addEdge(2,3); // C-D
    g.addEdge(3,4); // D-E
    g.addEdge(3,5); // D-F
    g.BFS(0);
    g.DFS(0);
    return 0;
}
```

## Question 3: Compare both search algorithms in the context of Big O notations.
- Both algorithms visit every vertex and edge once, giving the same time complexity [O(V + E)] and space [O(V)]. 
- The differences:
1. BFS = goes level by level, finds shortest path, best for shortest node
2. DFS = goes deep path, can go longer path, best for cycle detection 
