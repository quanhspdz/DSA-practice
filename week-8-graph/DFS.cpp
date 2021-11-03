#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T>> l;

public: 
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited) {
        cout << src << " ";
        visited[src] = true;

        l[src].sort();
        for (T neighbor:l[src]) {
            if (!visited[neighbor]) {
                dfs_helper(neighbor, visited);
            }
        }
    }

    void dfs(T src) {
        map<T, bool> visited;

        dfs_helper(src, visited);
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

    graph.dfs(1);

    cout << endl;
    return 0;
}