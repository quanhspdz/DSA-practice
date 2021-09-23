#include <iostream>
#include <string>
using namespace std;

double connectNum(int a, int b) {
    double result = 0;
    string bString = to_string(b);
    int numberOfElement = bString.length();

    int k = 1;
    for (int i = 0; i < numberOfElement; i++) {
        k *= 10;
    }

    result = a * k + b;

    return result;
}
void sortMax(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (connectNum(arr[j], arr[j + 1]) < connectNum(arr[j + 1], arr[j])) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortMax(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}