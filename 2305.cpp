#include <iostream>
using namespace std;

int cinNum();

class Student {
private:
    string fullName;
    string BD;
    string city;
    string country;
    string universityName;
    string universityCity;
    string universityCountry;
    int groupNumber;
    int Phonenumber;

public:

    void inputStudentData() {
        cout << "Enter the student's full name: ";
        cin >> fullName;
        cin.ignore();
        cout << "Enter the student's date of birth: ";
        cin >> BD;

        cout << "Enter the student's contact phone number: ";
        Phonenumber = cinNum();

        cout << "Enter the student's city: ";
        cin >> city;

        cout << "Enter the student's country: ";
        cin >> country;

        cout << "Enter the name of the educational institution: ";
        cin >> universityName;
        cin.ignore();

        cout << "Enter the city where the school is located:  ";
        cin >> universityCity;

        cout << "Enter the country where the school is located: ";
        cin >> universityCountry;

        cout << "Enter the student's group number: ";
        groupNumber = cinNum();
    }

    void displayStudentData() const {
        cout << "Student's full name:: " << fullName << endl;
        cout << "Date of birth: " << BD << endl;
        cout << "Contact phone number " << Phonenumber << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "Name of educational institution: " << universityName << endl;
        cout << "City of the educational institution: " << universityCity << endl;
        cout << "Country of educational institution: " << universityCountry << endl;
        cout << "Group number: " << groupNumber << endl;
    }


    string getFullName() const {
        return fullName;
    }

    string getDateOfBirth() const {
        return BD;
    }

    int getContactPhone() const {
        return Phonenumber;
    }

    string getCity() const {
        return city;
    }

    string getCountry() const {
        return country;
    }

    string getUniversityName() const {
        return universityName;
    }

    string getUniversityCity() const {
        return universityCity;
    }

    string getUniversityCountry() const {
        return universityCountry;
    }

    int getGroupNumber() const {
        return groupNumber;
    }
};

int main() {
    Student student;

    student.inputStudentData();

    cout << "Student data:" << endl;
    student.displayStudentData();

    return 0;
}


int cinNum()
{
    int num;
    while (true)
    {
        if (cin >> num) break;
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n'); 
            cout << "You can't enter a string, please enter a number: " << endl;
           
        }
    }
    return num;
}
