#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
 
using namespace std;
 
vector<bool> v;
vector<vector<int> > g;
 
void edge(int a, int b)
{
    g[a].pb(b);
    g[b].pb(a);
}
 
void bfs(int u)
{
    queue<int> q;
 
    q.push(u);
    v[u] = true;
 
    while (!q.empty()) {
 
        int f = q.front();
        q.pop();
 
        cout << f << " ";
 
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}
 
int main()
{
    int n, e;
    cin >> n >> e;
 
    v.assign(n * 2, false);
    g.assign(n * 2, vector<int>());
 
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }
 
    for (int i = 1; i < n; i++) {
        if (!v[i])
            bfs(i);
    }
    
    cout << endl;
    return 0;
}