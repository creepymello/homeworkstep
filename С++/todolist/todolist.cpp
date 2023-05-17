#include <iostream>
#include <Windows.h>

using namespace std;

struct Task {
    char title[100];
    int priority;
    char description[100];
    char date[8];
    char time[4];
};
void addTask(Task tasks[], int& size, const int maxLen); // добавляет
void deleteTask(Task tasks[], int& size); // удаляет 
void editTask(Task tasks[], int size); // меняет 
void searchTasksByTitle(const Task tasks[], int size, const char* title); // поиск по назв
void searchTasksByPriority(const Task tasks[], int size, int priority); // поиск по приоритету
void searchTasksByDescription(const Task tasks[], int size, const char* description); //поиск по описанию
void searchTasksByDate(const Task tasks[], int size, const char* date); // поиск по дате
void displayTasks(const Task tasks[], int& size); // вывод всех елементов 
void sortTasksByPriority(Task tasks[], int size); // сортировка по приоритету
void sortTasksByDateTime(Task tasks[], int size); // сортировка по дате 
// тут еще должна была быть работа с файлом,то есть сохранение инфы в файл, но я не успела
int cinNum(); // проверка не строка ли введена

int main() {
    const int maxLen = 100;
    Task* tasks = new Task[maxLen];
    int size = 0;

    int choice;
    do {
        cout << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Edit Task" << endl;
        cout << "4. Search" << endl;
        cout << "5. Display Tasks" << endl;
        cout << "6. Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";


        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");

            addTask(tasks, size, maxLen);
            break;
        case 2:
            system("cls");
            displayTasks(tasks, size);
            cout << endl;
            deleteTask(tasks, size);
            break;
        case 3:
            system("cls");

            editTask(tasks, size);
            break;
        case 4:
            system("cls");
            int searchChoise;
            cout << "Select the value you want! " << endl;
            cout << "1. Search Task by Title" << endl;
            cout << "2. Search Task by Priority" << endl;
            cout << "3. Search Task by Description" << endl;
            cout << "4. Search Task by Date" << endl;
            cout << "0. Exit" << endl;
            cin >> searchChoise;
            switch (searchChoise)
            {
            case 1:
                char searchTitle[100];
                cout << "Enter the title to search: ";
                cin.ignore();
                cin.getline(searchTitle, 100);
                searchTasksByTitle(tasks, size, searchTitle);

                break;
            case 2:
                int searchPriority;
                cout << "Enter the priority to search: ";
                searchPriority = cinNum();
                searchTasksByPriority(tasks, size, searchPriority);

                break;
            case 3:
                char searchDescription[100];
                cout << "Enter the description to search: ";
                cin.ignore();
                cin.getline(searchDescription, sizeof(searchDescription));
                searchTasksByDescription(tasks, size, searchDescription);

                break;
            case 4:
                char searchDate[20];
                cout << "Enter the date to search (YYYY-MM-DD): ";
                cin >> searchDate;
                searchTasksByDate(tasks, size, searchDate);

                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
                break;
            }
            break;
        case 5:
            system("cls");
            displayTasks(tasks, size);
            break;
        case 6:
            system("cls");
            int sortChoise;

            cout << "Select the value you want! " << endl;
            cout << "1. Sort Tasks by Priority" << endl;
            cout << "2. Sort Tasks by Date and Time" << endl;
            cout << "0. Exit" << endl;
            cin >> sortChoise;
            switch (sortChoise)
            {
            case 1:
                sortTasksByPriority(tasks, size);
                displayTasks(tasks, size);
                break;
            case 2:
                sortTasksByDateTime(tasks, size);
                displayTasks(tasks, size);
                break;
            case 0:
                break;

            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
                break;
            }
            break;
        case 0:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}


void addTask(Task tasks[], int& size, const int maxLen) {

    if (size >= maxLen) {
        cout << "The task list is full. Cannot add more tasks.\n";
        return;
    }

    cout << "Title: ";
    cin.ignore();
    cin.getline(tasks[size].title, 100);
    while (true) {
        cout << "Priority(1-10): ";
        tasks[size].priority = cinNum();

        if (tasks[size].priority > 10 || tasks[size].priority < 0) {
            cout << "The value is incorrect. Please try again!" << endl;
            continue;
        }
        break;
    }

    cout << "Description: ";
    cin.ignore();
    cin.getline(tasks[size].description, 100);

    while (true) {
        cout << "Date (YYYY-MM-DD): ";
        cin >> tasks[size].date;

        if (strlen(tasks[size].date) != 8) {
            cout << "Invalid date format. Please enter the date in YYYY-MM-DD format.\n";
            continue;
        }

        break;
    }
    while (true) {

        cout << "Time (HH:MM): ";
        cin >> tasks[size].time;

        if (strlen(tasks[size].time) != 4) {
            cout << "Invalid time format. Please enter the time in HH:MM format.\n";
            continue;
        }

        break;

    }


    size++;
    cout << "Task added successfully.\n";

}
void deleteTask(Task tasks[], int& size) {
    if (size == 0) {
        cout << "Task list is empty!" << endl;
        return;
    }

    cout << "Enter the index of the task to delete: ";
    int index = cinNum();

    if (index <= 0 || index > size) {
        cout << "Invalid index!" << endl;
        return;
    }

    index--;  // Adjusting the index to match the array indexing (subtract 1)

    for (int i = index; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    size--;

    cout << "Task deleted successfully!" << endl;
}


void editTask(Task tasks[], int size) {
    int index = 1;

    if (size == 0) {
        cout << "Task list is empty. No tasks to edit.\n";
        return;
    }

    while (true) {
        cout << "Enter the index of the task to edit (1 - " << size << "): ";
        cin >> index;

        if (index < 1 || index > size) {
            cout << "Invalid index. Please enter a valid index.\n";
            continue;
        }
        break;
    }

    cout << "Enter the updated task details" << endl;
    cout << "Title: ";
    cin.ignore();
    cin.getline(tasks[index - 1].title, 100);

    while (true) {
        cout << "Priority(1-10): ";
        cin >> tasks[index - 1].priority;

        if (tasks[index - 1].priority > 10 || tasks[index - 1].priority < 1) {
            cout << "The value is incorrect. Please try again!" << endl;
            continue;
        }
        break;
    }

    cout << "Description: ";
    cin.ignore();
    cin.getline(tasks[index - 1].description, 100);

    while (true) {
        cout << "Date (YYYY-MM-DD): ";
        cin >> tasks[index - 1].date;

        if (strlen(tasks[index - 1].date) != 10) {
            cout << "Invalid date format. Please enter the date in YYYY-MM-DD format.\n";
            continue;
        }

        break;
    }
    while (true) {

        cout << "Time (HH:MM): ";
        cin >> tasks[index - 1].time;

        if (strlen(tasks[index - 1].time) != 5) {
            cout << "Invalid time format. Please enter the time in HH:MM format.\n";
            continue;
        }

        break;
    }

    cout << "Task edited successfully.\n";
}



void searchTasksByTitle(const Task tasks[], int size, const char* title) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (strcmp(tasks[i].title, title) == 0) {
            cout << "Title: " << tasks[i].title << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Date: " << tasks[i].date << endl;
            cout << "Time: " << tasks[i].time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks found with the given title.\n";
    }
}

void searchTasksByPriority(const Task tasks[], int size, int priority) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (tasks[i].priority == priority) {
            cout << "Title: " << tasks[i].title << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Date: " << tasks[i].date << endl;
            cout << "Time: " << tasks[i].time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks found with the given priority.\n";
    }
}

void searchTasksByDescription(const Task tasks[], int size, const char* description) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (strcmp(tasks[i].description, description) == 0) {
            cout << "Title: " << tasks[i].title << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Date: " << tasks[i].date << endl;
            cout << "Time: " << tasks[i].time << endl;

            found = true;
        }
    }
    cout << endl;

    if (!found) {
        cout << "No tasks found with the given description.\n";
    }
}

void searchTasksByDate(const Task tasks[], int size, const char* date) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (strcmp(tasks[i].date, date) == 0) {
            cout << "Title: " << tasks[i].title << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Date: " << tasks[i].date << endl;
            cout << "Time: " << tasks[i].time << endl;

            found = true;
        }
    }
    cout << endl;

    if (!found) {
        cout << "No tasks found with the given date.\n";
    }
}

void displayTasks(const Task tasks[], int& size) {
 
    cout << "List of tasks:" << endl;

    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "Task " << i + 1 << ":" << endl;
        cout << "Title: " << tasks[i].title << endl;
        cout << "Priority: " << tasks[i].priority << endl;
        cout << "Description: " << tasks[i].description << endl;
        cout << "Date: " << tasks[i].date << endl;
        cout << "Time: " << tasks[i].time << endl;
    }
    cout << endl;
}

void sortTasksByPriority(Task tasks[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    cout << "Tasks sorted by priority.";
    cout << endl;
}

void sortTasksByDateTime(Task tasks[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(tasks[j].date, tasks[j + 1].date) > 0 ||
                (strcmp(tasks[j].date, tasks[j + 1].date) == 0 &&
                    strcmp(tasks[j].time, tasks[j + 1].time) > 0)) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    cout << "Tasks sorted by date and time.";
    cout << endl;
}

int cinNum()
{
    int num;
    while (true)
    {
        if (cin >> num)
        {
            break;
            // если ввод правильный 
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n'); // надеюсь вы не захотите ввести больше этого диапазона :/
            cout << "You can't enter a string, please enter a number: " << endl;
            // неправильный 
        }
    }
    return num;
}
