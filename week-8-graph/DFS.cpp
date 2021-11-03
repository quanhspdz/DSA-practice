#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T>> l;

public: 
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src) {
        map<T, bool> visited;
        queue<T> q;
        
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor:l[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {    

    Graph<int> graph;
    
    int vertex, edge;
    cin >> vertex >> edge;
    
    int n = edge;
    while (n > 0) {
        n--;
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    graph.bfs(1);

    cout << endl;
    return 0;
}