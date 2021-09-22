#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    string *s1 = new string[n];
    string *s2 = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> s1[i] >> s2[i];
    }

    
    for (int i = 0; i < n; i++) {
        sort(s1[i].begin(), s1[i].end());
        sort(s2[i].begin(), s2[i].end());
    }

    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}