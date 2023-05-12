#include <iostream>
#include <Windows.h>

using namespace std;



struct Student {
    char name[50];
    char surname[50];
    int age;
    char faculty[50];
    int year;
};

struct Academy {
    char name[50];
    char faculty[50];
    Student students[100];
    int numStudents;
};

void addStudent(Academy academy) {
    if (academy.numStudents == 100) {
        cout << "Cannot add more students, maximum capacity reached." << endl;
        return;
    }

    Student student;
    cout << "enter name: ";
    cin >> student.name;

    cout << "enter surname: ";
    cin >> student.surname;

    cout << "enter age: ";
    cin >> student.age;

    cout << "enter faculty: ";
    cin >> student.faculty;

    cout << "enter year: ";
    cin >> student.year;

    academy.students[academy.numStudents] = student;
    academy.numStudents++;

    cout << "etudent added." << endl;
}

void removeStudent(Academy academy) {
    if (academy.numStudents == 0) {
        cout << "no students to remove." << endl;
        return;
    }

    char name2[50];
    cout << "enter name name of student to remove: ";
    cin >> name2;

    for (int i = 0; i < academy.numStudents; i++) {
        if (strcmp(academy.students[i].name, name2) == 0) {
            academy.students[i] = academy.students[academy.numStudents - 1];
            academy.numStudents--;
            cout << "student removed" << endl;
            return;
        }
    }

    cout << "srtudent not found" << endl;
}

void printFaculty(const Academy academy) {
    char faculty[50];
    cout << "enter faculty name: ";
    cin >> faculty;

    cout << "students in faculty " << faculty << ":" << endl;
    for (int i = 0; i < academy.numStudents; i++) {
        if (strcmp(academy.students[i].faculty, faculty) == 0) {
            cout << academy.students[i].surname << " " << academy.students[i].surname << endl;
        }
    }
}

int main() {
    Academy academy{};
    academy.numStudents = 0;

    cout << "enter academy name: ";
    cin >> academy.name;

    cout << "enter faculty name: ";
    cin >> academy.faculty;

    int choice = -1;

    while (choice != 0) {
        cout << "choose an option:" << endl;
        cout << "1.add student" << endl;
        cout << "2.remove student" << endl;
        cout << "3.print students by faculty" << endl;
        cout << "0.exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            addStudent(academy);
            break;
        case 2:
            system("cls");
            removeStudent(academy);
            break;
        case 3:
            system("cls");
            printFaculty(academy); 
            break;
        case 0:
            break;
        }
 
    }
    return 0;
}