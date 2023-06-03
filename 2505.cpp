#include <iostream>
#include <string>
using namespace std;


int cinNum();
bool cinBool();

struct Processor {
    string model;
    int frequency;
};

struct Memory {
    int capacity;
};

struct Storage {
    int capacity;
    string type;
};

class Computer {
private:
    string make;
    string model;
    Processor processor;
    Memory memory;
    Storage storage;
    bool hasGraphicsCard;

public:
    Computer(const string& brand, const string& model, const Processor& processor, const Memory& memory,
        const Storage& storage, bool hasGraphicsCard) {
        this->make = brand;
        this->model = model;
        this->processor = processor;
        this->memory = memory;
        this->storage = storage;
        this->hasGraphicsCard = hasGraphicsCard;
    }

    void display() const {
        cout << "Brand: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Processor: " << processor.model << " (" << processor.frequency << " MHz)" << endl;
        cout << "Memory: " << memory.capacity << " GB" << endl;
        cout << "Storage: " << storage.capacity << " GB, " << storage.type << endl;
        cout << "Has Graphics Card: " << (hasGraphicsCard ? "Yes" : "No") << endl;
    }
};

int main() {
    string make, model, processorModel, storageType;
    int processorFrequency, memoryCapacity, storageCapacity;
    bool hasGraphicsCard;

    cout << "Enter computer brand: ";
    cin >> make;
    

    cout << "Enter computer model: ";
    cin >> model;

    cout << "Enter processor model: ";
    cin >> processorModel;
    cin.ignore();

    cout << "Enter processor frequency (MHz): ";
    processorFrequency = cinNum();

    cout << "Enter memory capacity (GB): ";
    memoryCapacity = cinNum();
    cin.ignore();

    cout << "Enter storage type: ";
    cin >> storageType;

    cout << "Enter storage capacity (GB): ";
    storageCapacity = cinNum();

    cout << "Does it have a graphics card (1 - Yes, 0 - No): ";
    hasGraphicsCard = cinBool(); 

    Processor processor{processorModel, processorFrequency};
    Memory memory{memoryCapacity};
    Storage storage{storageCapacity, storageType};

    Computer computer(make, model, processor, memory, storage, hasGraphicsCard);

    cout << endl << "Computer data:" << endl;
    computer.display();

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

bool cinBool() {

    bool value;
    string input;
    while (true)
    {
        cin >> input;
        if (input == "true" || input == "1")
        {
            value = true;
            break;
        }
        else if (input == "false" || input == "0")
        {
            value = false;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'true' or 'false': " << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }
    return value;
}
