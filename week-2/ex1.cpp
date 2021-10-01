#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void swap(string *a, string *b) {
    string tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(string arr[], int low, int high) {
    int position = low;
    string partitionVale = arr[high];

    for (int j = low; j < high; j++) {
        if (arr[j].length() < partitionVale.length()) {
            swap(&arr[j], &arr[position++]);
        }
        else if (arr[j].length() == partitionVale.length() && arr[j] < partitionVale) {
            swap(&arr[j], &arr[position++]);
        }
    }
    swap(&arr[position], &arr[high]);
    return (position);
}

void quickSortIncrease(string arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortIncrease(arr, low, p - 1);
        quickSortIncrease(arr, p + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    quickSortIncrease(s, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}