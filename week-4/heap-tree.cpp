#include <iostream>
using namespace std;

void swap(char a[], int parentsPos, int pos) {
    char tmp = a[parentsPos];
    a[parentsPos] = a[pos];
    a[pos] = tmp;
}

void swim(char a[], int k) {
    while (k > 0 && a[k/2] < a[k]) {
        swap(a, k/2, k);
        k = k/2;
    }
}

void insert(char a[], int size, char n) {
    a[size] = n;
    swim(a, size++);
}

int main() {
    int n = 7;
    char x;
    char *a = new char[n];

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(a, n, x);
    }

    return 0;
}