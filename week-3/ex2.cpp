#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n1, n2, x;
    cin >> n1 >> n2 >> x;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) 
        cin >> arr1[i];
    for (int i = 0; i < n2; i++) 
        cin >> arr2[i];

    int score = 0;
    int k1 = 0, k2 = 0, i = 0;
    int sum = 0;
    while (k1 < n1 && sum + arr1[k1] <= x) {
        sum += arr1[k1++];
    }

    k2 = 0;
    score = k1;
    while (k2 < n2) {
        sum += arr2[k2++];
        while (sum > x && k1 > 0) {
            sum -= arr1[--k1];
        }
        if (sum <= x && k2 + k1 > score) {
            score = k2 + k1;
        }
    }


    cout << score << endl;

    return 0;
}