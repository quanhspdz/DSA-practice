#include <iostream>
#include <vector>
using namespace std;

void Graph_DFS(vector< vector<bool> >friends, int n, vector<bool> &visited, int v) {
    for (int i = 0; i < n; i++) {
        if (friends[v][i] == 1 && !visited[i] && i != v) {
            visited[i] = 1;
            Graph_DFS(friends, n, visited, i);
        }
    }
}

int friendGroups(vector< vector<bool> >friends, int n) {
    if (!n) {
        return 0;
    }
 
    int numGroups = 0;    
    vector<bool> visited (n, 0);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            Graph_DFS(friends, n, visited, i);
            numGroups++;
        }
    }
    
    return numGroups;
}

int main() {
  int n ;
  cin >> n;

  bool friends_temp[n][n];

  for ( int i =0; i< n; i++) {
      for ( int j=0 ; j<n; j++) {
          cin >> friends_temp[i][j];
      }
  }

  vector< vector<bool> > friends; 

  for (int i=0; i < n; i++) {
    vector<bool> temp;
    for (int j=0;j < n;j++)
      temp.push_back(friends_temp[i][j]);
    friends.push_back(temp);
  }
  
  cout << friendGroups(friends, n) << endl;
  return 0;
}