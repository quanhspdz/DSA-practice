#include <iostream>
using namespace std;

int  main() {
    int n;
    cin >> n;
    int *arr = new int[n];
        for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    int *count = new int[max + 1];
    for (int i = 0; i <= max + 1; i++) {
        count[i] = 0;
    }

    //count element frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int couples = 0;
    for (int i = 0; i <= max + 1; i++) {
        couples += count[i] / 2;
    }

    cout << couples << endl;

    return 0;
}