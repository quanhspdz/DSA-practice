#include <iostream>
#include <stack>
#include <string>
#include <deque>

using namespace std;

typedef struct {
    string name;
    string MSSV;
    double avgGrade;
} Student;

typedef struct tagNode {
    Student info;
    struct tagNode *nextNode;
} Node;

bool findStudent(string mssv, deque<Student> studentStack) {
    while (!studentStack.empty()) {
        Student student = studentStack.back();
        studentStack.pop_back();
        if (mssv.compare(student.MSSV) == 0) {
            return true;
        }
    }
    return false;
}
bool deleteStudent(string mssv, deque<Student> studentStack) {

}

int main() {
    deque<Student> studentStack;


    string next = "next";
    string temp;

    while (!next.empty()) {
        string name;
        getline(cin, name);
        if (name.empty()) {
            break;
        }
        string mssv;
        getline(cin, mssv);
        double avg;
        cin >> avg;
        getline(cin, temp);

        Student student;
        student.name = name;
        student.MSSV = mssv;
        student.avgGrade = avg;

        studentStack.push_back(student);
    }

    if (findStudent("234344", studentStack)) {
        cout << "Found Thang ngu" << endl;
    }

    while (!studentStack.empty()) {
        Student student = studentStack.back();
        studentStack.pop_back();
        cout << "Name: " << student.name << endl;
        cout << "Mssv: " << student.MSSV << endl;
        cout << "Avarage grade: " << student.avgGrade << endl;
        cout << endl;
    }
    
    return 0;
}