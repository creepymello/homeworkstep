#include <iostream>
using namespace std;

//// 1
//class Student {
//private:
//    string name;
//    int age;
//    string university;
//
//public:
//    Student(string name, int age, string university) {
//        this->name = name;
//        this->age = age;
//        this->university = university;
//    }
//
//    void displayInfo() {
//        cout << "Name: " << name << endl;
//        cout << "Age: " << age << endl;
//        cout << "University: " << university << endl;
//    }
//};
//
//class Aspirant : public Student {
//private:
//    string researchTopic;
//
//public:
//    Aspirant(string name, int age, string university, string researchTopic)
//            : Student(name, age, university) {
//        this->researchTopic = researchTopic;
//    }
//
//    void displayInfo() {
//        Student::displayInfo();
//        cout << "Research Topic: " << researchTopic << endl;
//    }
//};
//
//int main() {
//    Student student("student", 20, "UNEC");
//    student.displayInfo();
//
//    cout << endl;
//
//    Aspirant aspirant("aspirant", 25, "ANAS", "Analysis of machine learning algorithms");
//    aspirant.displayInfo();
//
//    return 0;
//}

//// 2

//class Passport {
//protected:
//    string firstName;
//    string surname;
//    string nationality;
//    string passportNumber;
//
//public:
//    Passport(string firstName, string surname, string nationality, string passportNumber) {
//        this->firstName = firstName;
//        this->surname = surname;
//        this->nationality = nationality;
//        this->passportNumber = passportNumber;
//    }
//
//    void displayInfo() {
//        cout << "First Name: " << firstName << endl;
//        cout << "Last Name: " << surname << endl;
//        cout << "Nationality: " << nationality << endl;
//        cout << "Passport Number: " << passportNumber << endl;
//    }
//};
//
//class ForeignPassport : public Passport {
//private:
//    string visaInformation;
//    string foreignPassportNumber;
//
//public:
//    ForeignPassport(string firstName, string surname, string nationality, string passportNumber,
//                    string visaInformation, string foreignPassportNumber)
//            : Passport(firstName, surname, nationality, passportNumber) {
//        this->visaInformation = visaInformation;
//        this->foreignPassportNumber = foreignPassportNumber;
//    }
//
//    void displayInfo() {
//        Passport::displayInfo();
//        cout << "Visa Information. " << visaInformation << endl;
//        cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
//    }
//};
//
//int main() {
//    ForeignPassport foreignPassport("a", "b", "Azerbaijanian", "12345678",
//                                    "Valid visas: Schengen", "98765432");
//
//    foreignPassport.displayInfo();
//
//    return 0;
//}

//// 3

//
//class Transport {
//protected:
//    string type;
//    int passengerCapacity;
//    int cargoCapacity;
//
//public:
//    Transport(string type, int passengerCapacity, int cargoCapacity) {
//        this->type = type;
//        this->passengerCapacity = passengerCapacity;
//        this->cargoCapacity = cargoCapacity;
//    }
//
//
//
//    void displayInfo() {
//        cout << "Type: " << type << endl;
//        cout << "Passenger Capacity: " << passengerCapacity << endl;
//        cout << "Cargo Capacity: " << cargoCapacity << endl;
//    }
//};
//
//class Car : public Transport {
//public:
//    Car(int passengerCapacity, int cargoCapacity)
//            : Transport("Car", passengerCapacity, cargoCapacity) {}
//
//    void calculateTime(int distance) {
//        cout << "Time taken by Car: " << distance / 60 << " hours" << endl;
//    }
//
//    void calculateCost(int distance) {
//        cout << "Cost of Car transportation: " << distance * 0.1 << "AZN" << endl;
//    }
//};
//
//class Bicycle : public Transport {
//public:
//    Bicycle(int passengerCapacity, int cargoCapacity)
//            : Transport("Bicycle", passengerCapacity, cargoCapacity) {}
//
//    void calculateTime(int distance)  {
//        cout << "Time taken by Bicycle: " << distance / 10 << " hours" << endl;
//    }
//
//    void calculateCost(int distance) {
//        cout << "Cost of Bicycle transportation: " << distance * 0.05 << "AZN" << endl;
//    }
//};
//
//class Truck : public Transport {
//public:
//    Truck(int passengerCapacity, int cargoCapacity)
//            : Transport("Truck", passengerCapacity, cargoCapacity) {}
//
//    void calculateTime(int distance) {
//        cout << "Time taken by Truck: " << distance / 50 << " hours" << endl;
//    }
//
//    void calculateCost(int distance) {
//        cout << "Cost of Truck transportation: " << distance * 0.15 << "AZN" << endl;
//    }
//};
//
//int main() {
//    Car car(4, 100);
//    Bicycle bicycle(1, 20);
//    Truck truck(3, 500);
//// машина
//    car.displayInfo();
//    car.calculateTime(120);
//    car.calculateCost(120);
//
//    cout << endl;
//
//// велик
//    bicycle.displayInfo();
//    bicycle.calculateTime(120);
//    bicycle.calculateCost(120);
//
//    cout << endl;
//
//// грузовик
//    truck.displayInfo();
//    truck.calculateTime(120);
//    truck.calculateCost(120);
//
//    return 0;
//}
//
