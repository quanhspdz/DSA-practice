#include<iostream>
using namespace std;

void move(int disk, string firstColumn, string finalColumn) {
    cout << "Move " << disk << " from " << firstColumn << " to " << finalColumn << endl;
}
void hanoiTowerMove(int n, string firstColumn, string tempColumn, string finalColumn){
    if (n == 1) move(n, firstColumn, finalColumn);
    else {
        hanoiTowerMove(n-1, firstColumn, finalColumn, tempColumn);
        move(n, firstColumn, finalColumn);
        hanoiTowerMove(n-1, tempColumn, firstColumn, finalColumn);
    }
}


int main() {
    string a = "column A", b = "column B", c = "colunn C";
    int n;
    cin >> n;

    hanoiTowerMove(n, a, b, c);

    return 0;
}
