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
    int sum1 = 0;
    while (i < n1 && sum1+ arr1[i] <= x) {
        sum1 += arr1[i++];
        k1++;
    }
    
    i = 0;
    int sum2 = 0;
    while (i < n2 && sum2 + arr2[i] <= x) {
        sum2 += arr2[i++];
        k2++;
    }

    score = k1 + k2;
    int sum = sum1 + sum2;
    while (sum > x) {
        if (k2 <= 0 || arr1[k1 - 1] > arr2[k2 - 1]) {
            sum -= arr1[k1 - 1];
            k1--;
            score--;
        }
        else if (k1 <= 0 || arr1[k1 - 1] < arr2[k2 - 1]) {
            sum -= arr2[k2 - 1];
            k2--;
            score--;
        }
    }


    cout << score << endl;

    return 0;
}