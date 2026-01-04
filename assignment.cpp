#include <iostream>
#include <fstream>
using namespace std;

void addAssignment();
void viewAssignment();

int main() {
    int choice;
    do {
        cout << "\n===== Assignment Management =====\n";
        cout << "1. Add new assignments\n2. Show all assignments\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) addAssignment();
        else if(choice == 2) viewAssignment();
        else if(choice != 0) cout << "Invalid choice, please try again.\n";

    } while(choice != 0);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}

void addAssignment() {
    ofstream file("assignment.txt");
    string tasks[3];
    for(int i = 0; i < 3; i++) {
        cout << "Enter assignment #" << i+1 << ": ";
        cin >> tasks[i];
        file << tasks[i] << endl;
    }
    file.close();
    cout << "All assignments have been saved.\n";
}

void viewAssignment() {
    ifstream file("assignment.txt");
    string task;
    cout << "\n--- List of Assignments ---\n";
    while(file >> task) {
        cout << task << endl;
    }
    file.close();
}
