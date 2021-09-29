#include <iostream>
using namespace std;

const int N = 1000;
unsigned long long tmp[N];
void init() {
    for (int i = 0; i < N; i++) {
        tmp[i] = -1;
    }
}

unsigned long long fibo(int n) {
    if (tmp[n] == -1) {
        if (n <= 1) tmp[n] = n;
        else {
            tmp[n] = fibo(n - 1) + fibo(n - 2);
        }
    }
    return tmp[n];
}

int main() {
    int n;
    cin >> n;
    
    init();

    cout << fibo(n) << endl;

    return 0;
}