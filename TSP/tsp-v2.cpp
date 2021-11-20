//Instead we can use this version of the same code which will work for any starting vertex instead of just 0.
#include <bits/stdc++.h>
using namespace std;

int dp[16][4];
int start;
int V = 4;
int dist[10][10] = {
    {0, 20, 12, 25},
    {20, 0, 30, 34},
    {12, 30, 0, 10},
    {25, 34, 10, 0}};

int VISITED_ALL = (1 << V) - 1;
vector<int> path;

//Since mask can have 2 to the power n different values and currcity can have n different values therefore
//we create a dp table of dp[2^n][n]

int tsp(int mask, int currcity)
{
    if (mask == VISITED_ALL)
        return dist[currcity][start];

    int ans = INT_MAX;
    int val;

    if (dp[mask][currcity] != -1)
        return dp[mask][currcity];
    //Here we loop through all the cities possible
    for (int city = 0; city < V; city++)
    {

        //Only the cities yet not visited are visited here
        if ((mask & (1 << city)) == 0)
        {
            //We calculate the distance from the current city to all the other unvisited cities which in itself does this hence bringing the minimum distance itself in callback.
            //the 1<<city thing just marks itself in the mask this way and mask at any moment has ki how many cities have been visited already
            int newAns = dist[currcity][city] + tsp((mask | (1 << city)), city);
            if (newAns < ans)
            {
                ans = newAns;
                val = city;
            }
        }
    }
    if (find(path.begin(), path.end(), val) == path.end())
        path.push_back(val);

    return dp[mask][currcity] = ans;
}

int main()
{
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
            dp[i][j] = -1;
    }

    cout << "Enter the start city: ";
    cin>>start;
    //start = 1;
    int initialMask = (1 << start);
    cout << tsp(initialMask, start) << endl;

    cout << "Path is: ";

    path.push_back(start);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}


