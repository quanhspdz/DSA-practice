#include <iostream>
using namespace std;

const int N = 100000;
char stackBrackets[N];
int stackSize = -1;

bool isFull() {
    return (stackSize == N);
}

bool isEmpty() {
    return (stackSize == -1);
}

void push(char data) {
    if (!isFull()) {
        stackBrackets[++stackSize] = data;
    }
}

char pop() {
    return stackBrackets[stackSize--];
}

char top() {
    return stackBrackets[stackSize];
}


bool checkString(string s) {
    int i;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isEmpty()) return false;
            switch(s[i]) {
                case ')': {
                    if (top() == '(') {
                        pop();
                    }
                    break;
                }
                case ']': {
                    if (top() == '[') {
                        pop();
                    }
                    break;
                }
                case '}': {
                    if (top() == '{') {
                        pop();
                    }
                    break;
                }
            }
        }
    }
    if (isEmpty()) return true;
    else return false;
}

void clearStack() {
    while (!isEmpty()) {
        pop();
    }
}

int main() {
    int n;
    cin >> n;
    string s[n+1];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        string tmp = s[i];
        cout << tmp << endl;
        if (checkString(tmp)) cout << "yes" << endl;
        else cout << "no" << endl;
        clearStack();
    }


    return 0;
}