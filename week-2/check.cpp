#include <iostream>
#include <string>
using namespace std;

const int N = 10000;
char stackBrackets[N];
int stackSize = -1;

int posSaver[N];
int posSize = -1;
string eachBracket[N];
int bracketSize = -1;

string copyFromString(string source, int start, int end) {
    string result = "";
    if (end < source.length()) {
        int i;
        int resultLength = end - start + 1;
        for (i = 0; i < resultLength; i++) {
            result += source[start + i];
        }
    }
    return result;
}

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
            posSaver[++posSize] = i;
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isEmpty()) return false;
            eachBracket[++bracketSize] = copyFromString(s, posSaver[posSize--] + 1, i - 1);
            switch(s[i]) {
                case ')': {
                    if (top() == '(') {
                        pop();
                    }
                }
                case ']': {
                    if (top() == '[') {
                        pop();
                    }
                }
                case '}': {
                    if (top() == '{') {
                        pop();
                    }
                }
            }
        }
    }
    if (isEmpty()) return true;
    else return false;
}

int getResult(string source) {
    string result;
    int resultInt = 0;
    
    int numberOfMulti = 0, numberOfAdd = 0;
    for (int i = 0; i < source.length(); i++) {
        if (source[i] == '*' || source[i] == '/') {
            numberOfMulti++;
        }
        else if (source[i] == '+' || source[i] == '-') {
            numberOfAdd++;
        }
    }   
        int i = 0;
        while (numberOfAdd != 0 || numberOfMulti != 0) {
            if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/') {
                char prevNum;
                char nextNum;
                int k = i - 1;
                prevNum = source[k];
                while (prevNum < '0' || prevNum > '9') {
                    prevNum = source[--k];
                }
                k = i + 1;
                nextNum = source[k];
                while (nextNum < '0' || nextNum > '9') {
                    nextNum = source[++k];
                }

                int prevInt = (int) prevNum - 48;
                int nextInt = (int) nextNum - 48;
                switch(source[i]) {
                    case '*' : {
                        if (numberOfMulti > 0) {
                            resultInt += prevInt*nextInt;
                            cout << prevInt << " * " << nextInt << " = " << prevInt*nextInt <<  endl;
                            numberOfMulti--;
                        }
                        break;
                    }
                    case '/' : {
                        if (numberOfMulti > 0) {
                            resultInt += prevInt/nextInt;
                            cout << prevInt << " / " << nextInt << " = " << prevInt/nextInt << endl;
                            numberOfMulti--;
                        }
                        break;
                    }
                    case '+' : {
                        if (numberOfMulti == 0) {
                            cout << prevInt << " + " << nextInt << " = " << prevInt+nextInt << endl;
                            resultInt += prevInt + nextInt;
                            numberOfAdd--;
                        } 
                        break;
                    }
                    case '-' : {
                        if (numberOfMulti == 0) {
                            cout << prevInt << " - " << nextInt << " = " << prevInt-nextInt << endl;
                            resultInt += prevInt - nextInt;
                            numberOfAdd--;
                        } 
                        break;
                    }
                }
            }
            if (i < source.length() - 1) i++;
            else i = 0;
        }

    return resultInt;
}

int main() {

    string s;
    getline(cin, s);

    checkString(s);
    for (int i = 0; i <= bracketSize; i++) {
        cout << eachBracket[i] << endl;
    }

    cout << getResult(s) << endl;


    return 0;
}