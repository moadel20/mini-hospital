#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int g1, g2, g3;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int countStudents = 0;

void addStudent() {
    if (countStudents == MAX_STUDENTS) {
        cout << "Class full!\n";
        return;
    }

    cout << "Enter ID: ";
    cin >> students[countStudents].id;

    cin.ignore();
    cout << "Name: ";
    getline(cin, students[countStudents].name);

    cout << "Grade 1: ";
    cin >> students[countStudents].g1;
    cout << "Grade 2: ";
    cin >> students[countStudents].g2;
    cout << "Grade 3: ";
    cin >> students[countStudents].g3;

    countStudents++;
    cout << "Done.\n";
}

void viewStudents() {
    if (countStudents == 0) {
        cout << "No data.\n";
        return;
    }

    for (int i = 0; i < countStudents; i++) {
        double avg = (students[i].g1 + students[i].g2 + students[i].g3) / 3.0;

        cout << "\nID: " << students[i].id
             << "\nName: " << students[i].name
             << "\nGrades: " << students[i].g1 << " " << students[i].g2 << " " << students[i].g3
             << "\nAverage: " << avg << "\n";
    }
}

void findByID() {
    int idd;
    cout << "ID: ";
    cin >> idd;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == idd) {
            double avg = (students[i].g1 + students[i].g2 + students[i].g3) / 3.0;

            cout << "\nFound:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Grades: " << students[i].g1 << " " << students[i].g2 << " " << students[i].g3 << "\n";
            cout << "Average: " << avg << "\n";
            return;
        }
    }

    cout << "Not found.\n";
}

int main() {
    int ch;

    while (true) {
        cout << "\n1- Add Student\n2- View All\n3- Search\n4- Exit\nChoose: ";
        cin >> ch;

        if (ch == 1) addStudent();
        else if (ch == 2) viewStudents();
        else if (ch == 3) findByID();
        else if (ch == 4) break;
        else cout << "Wrong choice.\n";
    }

    return 0;
}
