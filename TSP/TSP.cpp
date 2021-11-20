#include <iostream>
using namespace std;

#define INT_MAX 99999999;
int n = 4;
//mang sau de luu khoang cach giua cac dinh
int dist[1000][1000];
//mang sau de luu cac khoang cach da duoc tinh truoc (quy hoach dong):
int tempDist[1000][1000];
//string luu tien trinh di:
string road = "";

int VISITED_ALL = (1 << n) - 1;

int TSP(int mask, int pos) {
    //neu da tham het cac dinh thi return:
    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }

    //neu khoang cach da duoc tinh truoc thi tai su dung:
    if (tempDist[mask][pos] != -1) {
        return tempDist[mask][pos];
    }

    int minWeight = INT_MAX;
    //dung for de tim den nhung dinh chua duoc tham
    for (int i = 0; i < n; i++) {
        //neu chua dinh chua duoc tham thi:
        if ((mask & (1 << i)) == 0) {
            int newWeight = dist[pos][i] + TSP(mask | (1 << i), i);
            minWeight = min(minWeight, newWeight);
        }
    }

    return tempDist[mask][pos] = minWeight;
}

int main() {
    //du lieu vao:
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    //khoi tao 1 mang ban luu khoang cach da duoc tinh, gia tri ban dau la -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            tempDist[i][j] = -1;
        }
    }

    cout << TSP(1, 0) << endl;

    return 0;
}