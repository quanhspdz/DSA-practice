#include <iostream>
#include <stack>
#include <string>
#include <deque>
#include <list>

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

deque<Student> studentStack;

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
bool deleteStudent(string mssv) {
    list<Student> students;
    while (!studentStack.empty()) {
        Student student = studentStack.back();
        studentStack.pop_back();

        if (mssv.compare(student.MSSV) == 0) {
            break;
        } else {
            students.push_back(student);
        }
    }
    while (!students.empty()) {
        studentStack.push_back(students.back());
        students.pop_back();
    }

    return false;
}

void showInfo(Student student) {
    cout << endl;
    cout << "Name: " << student.name << endl;
    cout << "Mssv: " << student.MSSV << endl;
    cout << "Avarage grade: " << student.avgGrade << endl;
}

void listStudentsAvgGreater5() {
    deque<Student> stack = studentStack;
    while (!stack.empty()) {
        Student student = stack.back();
        stack.pop_back();
        if (student.avgGrade >= 5) {
            showInfo(student);
        }
    }
}

void listStudents() {
    deque<Student> stack = studentStack;
    while (!stack.empty()) {
        Student student = stack.back();
        stack.pop_back();
        showInfo(student);
    }
}

void listRankedStudent() {
    deque<Student> stack = studentStack;
    while (!stack.empty()) {
        Student student = stack.back();
        stack.pop_back();
        
        if (student.avgGrade < 5) {
            showInfo(student);
            cout << "=> Loai yeu" << endl;
        } else if (student.avgGrade < 6.5) {
            showInfo(student);
            cout << "=> Loai trung binh" << endl;
        } else if (student.avgGrade < 7) {
            showInfo(student);
            cout << "=> Loai trung binh kha" << endl;
        } else if (student.avgGrade < 8) {
            showInfo(student);
            cout << "=> Loai kha" << endl;
        } else if (student.avgGrade < 9) {
            showInfo(student);
            cout << "=> Loai gioi" << endl;
        } else {
            showInfo(student);
            cout << "=> Loai xuat sac" << endl;
        }
    }
}

int main() {
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

    int out = 0;
    while (out != 1) {
        cout << "Nhan 1 de tim kiem sinh vien!" << endl;
        cout << "Nhan 2 de xoa sinh vien" << endl;
        cout << "Nhan 3 de liet ke sinh vien diem trung binh >= 5" << endl;
        cout << "Nhan 4 de xep hang sinh vien" << endl;
        cout << "Nhan 5 de xem danh sach sinh vien" << endl;
        cout << "Nhan 0 de thoat" << endl;

        int selection;
        cin >> selection;
        switch(selection) {
            case 1: {
                cout << "Nhap MSSV de tim kiem: ";
                string mssv;
                cin >> mssv;
                if (findStudent(mssv, studentStack)) {
                    cout << "Tim thay sinh vien!" << endl;
                } else {
                    cout << "Khong tim thay sinh vien" << endl;
                }
                break;
            }
            case 2: {
                cout << "Nhap MSSV cua sinh vien can xoa: ";
                string mssv;
                cin >> mssv;
                deleteStudent(mssv);
                break;
            }
            case 3: {
                listStudentsAvgGreater5();
                break;
            }
            case 4: {
                listRankedStudent();
                break;
            }
            case 5: {
                listStudents();
                break;
            }
            case 0: {
                out = 1;
                break;
            }
        }
    }
    
    return 0;
}