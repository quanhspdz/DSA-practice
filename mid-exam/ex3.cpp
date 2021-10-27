#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int mid = n / 2;
    double result;
    if (n % 2 == 0) {
        result = (double) (arr[mid] + arr[mid - 1]) / 2;
    } else {
        result = (double) arr[mid];
    }

    printf("%0.1lf\n", result);


    return 0;
}