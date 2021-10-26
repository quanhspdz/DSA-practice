#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string *arr = new string[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int *score = new int[n + 1];
    for (int i = 0; i < n; i++) {
        score[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == "D") {
            if (i > 0) {
                int k = i - 1;
                while (score[k] == 0 && k > 0) {
                    k--;
                }
                score[i] = score[k] * 2;
            }
        } else if (arr[i] == "C") {
            if (i > 0) {
                score[i - 1] = 0;
            }
        } else if (arr[i] == "+") {
            if (i > 1) {
                int k1 = i - 1;
                while (score[k1] == 0 && k1 > 1) {
                    k1--;
                } 
                int k2 = k1 - 1;
                while (score[k2] == 0 && k2 > 0) {
                    k2--;
                }
                score[i] = score[k1] + score[k2];
            }
        } else {
            stringstream stream(arr[i]);
            int x = 0;
            stream >> x;
            score[i] = x;
        }
    }

    int sumScore = 0;
    for (int i = 0; i < n; i++) {
        sumScore += score[i];
    }

    cout << sumScore << endl;
    return 0;
}