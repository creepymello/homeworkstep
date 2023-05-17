#include <iostream>

using namespace std;



struct Animal {
    char name[100];
    int age;
    char gender;
};

struct Zoo {
    char name[100];
    int maxAnimals;
    int numAnimals;
    Animal animals[100];
};

void addAnimal(Zoo& zoo) {
    if (zoo.numAnimals >= zoo.maxAnimals) {
        cout << "Зоопарк полон. Невозможно добавить больше животных." << endl;
        return;
    }

    Animal newAnimal;
    cout << "Введите название животного: ";
    cin >> newAnimal.name;
    cout << "Введите возраст животного: ";
    cin >> newAnimal.age;
    cout << "Введите пол животного: ";
    cin >> newAnimal.gender;

    zoo.animals[zoo.numAnimals] = newAnimal;
    zoo.numAnimals++;

    cout << "Животное добавлено в зоопарк." << endl;
}

void removeAnimal(Zoo& zoo, int index) {
    if (index < 0 || index >= zoo.numAnimals) {
        cout << "Неверный индекс животного." << endl;
        return;
    }

    for (int i = index; i < zoo.numAnimals - 1; i++) {
        zoo.animals[i] = zoo.animals[i + 1];
    }

    zoo.numAnimals--;

    cout << "Животное удалено из зоопарка." << endl;
}

void editAnimal(Zoo& zoo, int index) {
    if (index < 0 || index >= zoo.numAnimals) {
        cout << "Неверный индекс животного." << endl;
        return;
    }

    Animal& animal = zoo.animals[index];

    cout << "Текущие данные животного:" << endl;
    cout << "Название: " << animal.name << endl;
    cout << "Возраст: " << animal.age << endl;
    cout << "Пол: " << animal.gender << endl;

    cout << "Введите новые данные животного:" << endl;
    cout << "Название: ";
    cin >> animal.name;
    cout << "Возраст: ";
    cin >> animal.age;
    cout << "Пол: ";
    cin >> animal.gender;

    cout << "Животное отредактировано." << endl;
}

void showAllAnimals(const Zoo& zoo) {
    cout << "Животные в зоопарке:" << endl;

    for (int i = 0; i < zoo.numAnimals; i++) {
        const Animal& animal = zoo.animals[i];

        cout << "Животное " << i + 1 << ":" << endl;
        cout << "Название: " << animal.name << endl;
        cout << "Возраст: " << animal.age << endl;
        cout << "Пол: " << animal.gender << endl;
        cout << endl;
    }
}

int main() {
    Zoo zoo;
    int maxAnimal = 100;
    cout << "Введите название зоопарка: ";
    cin >> zoo.name;
    zoo.maxAnimals = maxAnimal;
    zoo.numAnimals = 0;

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить животное" << endl;
        cout << "2. Удалить животное" << endl;
        cout << "3. Редактировать животное" << endl;
        cout << "4. Показать всех животных" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addAnimal(zoo);
            break;
        case 2:
            int removeIndex;
            cout << "Введите индекс животного для удаления: ";
            cin >> removeIndex;
            removeAnimal(zoo, removeIndex - 1);
            break;
        case 3:
            int editIndex;
            cout << "Введите индекс животного для редактирования: ";
            cin >> editIndex;
            editAnimal(zoo, editIndex - 1);
            break;
        case 4:
            showAllAnimals(zoo);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
