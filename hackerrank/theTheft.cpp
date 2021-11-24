#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

class Things{
    public:
        int value;
        int weight;
        double priority;
};

bool thingsCmp(Things const & a, Things const & b) {
    return a.priority < b.priority;
}

int main() {
    int n, m;
    cin >> n >> m;
    Things things[n + 2];
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> weight >> value;
        things[i].value = value;
        things[i].weight = weight;
    }
    for (int i = 0; i < n; i++) {
        things[i].priority = (double) things[i].value / things[i].weight;
    }

    sort(things, things + n, thingsCmp);
    int s = m;
    int k = n - 1;
    int maxValue = 0;
    while (s > 0 && k >= 0) {
        if (s - things[k].weight < 0) {
            k--;
        } else {
            s = s - things[k].weight;
            maxValue += things[k].value;
        }
    }

    cout << maxValue << endl;
    return 0;
}