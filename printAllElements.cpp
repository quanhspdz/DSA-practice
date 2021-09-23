#include <iostream>
using namespace std;

void printElements(int n) {
    if (n > 0) printElements(n - 1);
    cout << n << " ";
}


int main() {
    int n;
    cin >> n;
    if (n < 0) n *= -1;

    printElements(n);

    return 0;
}