#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

const int MAX_POS = INT_MAX;
const int MAX = INT_MAX;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    sort(adj[u].begin(), adj[u].end());
    for (int i=0; i<adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
            DFSUtil(adj[u][i], adj, visited);
        }
    }
}
 
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    DFSUtil(1, adj, visited);
}
 
int main()
{   
    int n, m;
    cin >> n >> m;
    int V = n;
 
    vector<int> adj[V + V];

    while (m > 0) {
        m--;
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    DFS(adj, V);

    cout << endl;
    return 0;
}