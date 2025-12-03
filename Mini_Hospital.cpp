#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string phone;
};

const int MAX_PATIENTS = 100;
Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        cout << "Hospital is full!" << endl;
        return;
    }

    cout << "--- Add Patient ---" << endl;
    cout << "Enter ID: ";
    cin >> patients[patientCount].id;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, patients[patientCount].name);

    cout << "Enter Age: ";
    cin >> patients[patientCount].age;

    cin.ignore();
    cout << "Enter Phone: ";
    getline(cin, patients[patientCount].phone);

    patientCount++;
    cout << "Patient added successfully!" << endl;
}

void viewPatients() {
    cout << "--- All Patients ---" << endl;

    if (patientCount == 0) {
        cout << "No patients." << endl;
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Phone: " << patients[i].phone << endl;
        cout << endl;
    }
}

void searchByID() {
    cout << "--- Search Patient by ID ---" << endl;

    int targetID;
    cout << "Enter ID: ";
    cin >> targetID;

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == targetID) {
            cout << "Patient found!" << endl;
            cout << "ID: " << patients[i].id << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Phone: " << patients[i].phone << endl;
            return;
        }
    }

    cout << "Patient not found." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "========== Mini Hospital ==========" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchByID(); break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
