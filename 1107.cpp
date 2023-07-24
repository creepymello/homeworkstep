#include <iostream>

using namespace std;

// маина
class MyCar {
public:

    virtual void drive(){};
    virtual void park(){};
    virtual void doWork(){};
};

// седан
class Sedan : public MyCar {
public:
    void drive() override {
        cout << "The sedan is driving through city streets." << endl;
    } // я просто не понимаю какую другую логику сделать можно

    void park() override {
        cout << "The sedan is parked outside the house." << endl;
    }

    void doWork() override {
        cout << "A sedan transports a family" << endl;
    }
};

// автобус
class Bus : public MyCar {
public:
    void drive() override {
        cout << "The bus is moving along the route." << endl;
    }

    void park() override {
        cout << "The bus is parked in the parking lot." << endl;
    }

    void doWork() override {
        cout << "The bus carries passengers on schedule." << endl;
    }
};

// грузовик
class Truck : public MyCar {
public:
    void drive() override {
        cout << "A truck transports goods on the highway." << endl;
    }

    void park() override {
        cout << "The truck is parked in the warehouse." << endl;
    }

    void doWork() override {
        cout << "The truck delivers goods and materials." << endl;
    }
};

// спорткар
class SportsCar : public MyCar {
public:
    void drive() override {
        cout << "A sports car accelerates on the track." << endl;
    }

    void park() override {
        cout << "The sports car is parked in the garage." << endl;
    }

    void doWork() override {
        cout << "The sports car is racing." << endl;
    }
};

int main() {

    MyCar* sedan = new Sedan();
    MyCar* bus = new Bus();
    MyCar* truck = new Truck();
    MyCar* sportsCar = new SportsCar();


    sedan->drive();
    sedan->park();
    sedan->doWork();
    cout << endl;

    bus->drive();
    bus->park();
    bus->doWork();
    cout << endl;

    truck->drive();
    truck->park();
    truck->doWork();
    cout<< endl;


    sportsCar->drive();
    sportsCar->park();
    sportsCar->doWork();



    return 0;
}
