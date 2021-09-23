#include <iostream>

using namespace std;

class Person {
    public:
        string name;
        int age;
        string gender; //true == "girl" because girl always true! :))
    
    Person (string inputName, int inputAge, string inputGender) {
        name = inputName;
        age = inputAge;
        gender = inputGender;
    }
    
    public: void setPersonInfor() {
        cout << "Welcome to Nowhere!" << endl;
        cout << "What's your name?\n>>> ";
        string userName;
        getline(cin, userName);

        cout <<"How old are you?\n>>> ";
        int userAge;
        cin >> userAge;

        cout << "You ara girl or boy?\n>>> ";
        string userGender;
        cin >> userGender;

        name = userName;
        age = userAge;
        gender = userGender;
    }
    public: void showPersonInfor() {
        cout << "Your name: " << name << endl;
        cout << "Your age: " << age << endl;
        cout << "Your gender: " << gender << endl;
    }
};

int main() {
    Person user("", -1, "");

    user.setPersonInfor();
    user.showPersonInfor();

    return 0;
}