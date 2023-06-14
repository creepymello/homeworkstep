#include <iostream>

using namespace std;

//// 1 
// 
// 
//int cinNum();
// 
//class Circle {
//private:
//    double radius;
//
//public:
//
//    Circle(double radius) {
//        this->radius = radius;
//    }
//
//    bool operator==(const Circle& other) const {
//        return radius == other.radius;
//    }
//
//    bool operator>(const Circle& other) const {
//        return radius > other.radius;
//    }
//
//    Circle& operator+=(double value) {
//        radius += value;
//        return *this;
//    }
//
//    Circle& operator-=(double value) {
//        radius -= value;
//        return *this;   // я не знала как перегружать -= +=,посмотрела в инете
//    }
//
//  
//    void printInfo() const {
//        cout << "Circle with radius: " << radius << std::endl;
//    }
//};
//
//int main() {
//    double radius1, radius2, value;
//
//    cout << "Enter radius for Circle 1: ";
//    radius1 = cinNum();
//
//    cout << "Enter radius for Circle 2: ";
//    radius2 = cinNum();
//
//    Circle circle1(radius1);
//    Circle circle2(radius2);
//
//    cout << "Enter value to increase the radius of Circle 1: ";
//    value = cinNum();
//    circle1.operator+=(value);
//    
//
//    cout << "Enter value to decrease the radius of Circle 2: ";
//    value = cinNum();
//    circle2.operator-=(value);
//
//    if (circle1.operator==(circle2)) {
//        cout << "Circle 1 is equal to Circle 2" << endl;
//    }
//    else if (circle1.operator>(circle2)) {
//        cout << "Circle 1 is greater than Circle 2" << endl;
//    }
//    else {
//        cout << "Circle 1 is smaller than Circle 2" << endl;
//    }
//
//
//    circle1.printInfo(); 
//    circle2.printInfo();
//    
//    
//    return 0;
//}
//
//
//int cinNum() {
//    int num;
//    while (true)
//    {
//        if (cin >> num)
//        {
//            break;
//
//        }
//        else
//        {
//            cin.clear();
//            cin.ignore(10000000, '\n'); 
//            cout << "You can't enter a string, please enter a number: " << endl;
//        }
//    }
//    return num;
//}


//// 2


//class Airplane {
//private:
//    string type;
//    uint16_t numOfPass;
//    uint16_t maxNumOfPass; // если делаю конст, то не могу конструктор написать
//
//public:
//    Airplane() = default;
//
//    Airplane(string type, uint16_t numOfPass, uint16_t maxNumOfPass) {
//        this->type = type;
//        this->numOfPass = numOfPass;
//        this->maxNumOfPass = maxNumOfPass;
//    }
//
//
//    bool operator==(const Airplane& other) const {
//        return type == other.type;
//    }
//
//    Airplane& operator++() {
//        if (numOfPass < maxNumOfPass) numOfPass++;
//
//        return *this;
//    }
//
//    Airplane& operator--() {
//        if (numOfPass > 0) numOfPass--;
//        return *this;
//    }
//
//    bool operator>(const Airplane& other) const {
//        return maxNumOfPass > other.maxNumOfPass;
//    }
//
//    void print() const {
//        cout << "Airplane type: " << type << endl;
//        cout << "Number of passengers: " << numOfPass << endl;
//        cout << "Max number of passengers: " << maxNumOfPass << endl;
//    }
//};
//
//int main() {
//    Airplane airplane1("Boeing 737", 100, 150);
//    Airplane airplane2("B737 MAX", 120, 180);
//    
//
//    if (airplane1.operator==(airplane2)) {
//        cout << "The airplanes have the same type." << endl;
//    }
//    else {
//        cout << "The airplanes have different types." << endl;
//    }
//
//    cout << endl << "Increased passengers in airplane1." << endl;
//    airplane1.operator++();
//    airplane1.print(); cout << endl;
//    
//
//    cout << "Decreased passengers in airplane2." << endl;
//    airplane2.operator--();
//    airplane2.print(); cout << endl;
//
//
//    if (airplane1.operator>(airplane2)) {
//        cout << "airplane1 can accommodate more passengers than airplane2." << endl;
//    }
//    else {
//        cout << "airplane2 can accommodate more passengers than airplane1." << endl;
//    }
//
//    return 0;
//}

