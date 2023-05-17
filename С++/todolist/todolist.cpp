
#include <iostream>
#include <Windows.h>

using namespace std;

struct Task {
    char title[100];
    int priority;
    char description[100];
    char date[8];
};
void addTask(Task tasks[], int size, const int maxLen);
void deleteTask(Task tasks[], int size);
void editTask(Task tasks[], int size);
void searchTasksByTitle(const Task tasks[], int size, const char* title);
void searchTasksByPriority(const Task tasks[], int size, int priority);
void searchTasksByDescription(const Task tasks[], int size, const char* description);
void searchTasksByDate(const Task tasks[], int size, const char* date);
void displayTasks(const Task tasks[], int size);
void sortTasksByPriority(Task tasks[], int size);
void sortTasksByDateTime(Task tasks[], int size);
void saveTasksToFile(const Task tasks[], int size, const char* filename);
void loadTasksFromFile(Task tasks[], int& size, const char* filename, const int maxLen);


int main() {
    const int maxLen = 100;
    Task* tasks = new Task[maxLen];
    int size = 0;

    int choice;
    do {
        cout << "\n--- ToDo List ---\n";
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Edit Task" << endl;
        cout << "4. Search" << endl;
        cout << "5. Display Tasks" << endl;
        cout << "6. Sort" << endl;
        cout << "7. Save Tasks to File" << endl;
        cout << "8. Load Tasks from File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";


        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");

            addTask(tasks, size,maxLen);
            break;
        case 2:
            system("cls");

            deleteTask(tasks, size);
            break;
        case 3:
            system("cls");

            editTask(tasks, size);
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


void addTask(Task tasks[], int size, const int maxLen) {

    if (size >= maxLen) {
        cout << "The task list is full. Cannot add more tasks.\n";
        return;
    }

    cout << "Title: ";
    cin.ignore();
    cin.getline(tasks[size].title, 100);
    while (true) {
        cout << "Priority(1-10): ";
        cin >> tasks[size].priority;

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


    size++;
    cout << "Task added successfully.\n";

}

void deleteTask(Task tasks[], int size) {
    int index;

    if (size == 0) {
        cout << "Task list is empty. No tasks to delete.\n";
        return;
    }

    while (true) {
        cout << "Enter the index of the task to delete (0-" << size - 1 << "): ";
        cin >> index;

        if (index < 0 || index >= size) {
            cout << "Invalid index. Please enter a valid index.\n";
            continue;
        }

        break;
    }

    for (int i = index; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    size--;
    cout << "Task deleted successfully!\n";
}


void editTask(Task tasks[], int size) {
    int index;

    if (size == 0) {
        cout << "Task list is empty. No tasks to edit.\n";
        return;
    }

    while (true) {
        cout << "Enter the index of the task to edit (0-" << size - 1 << "): ";
        cin >> index;

        if (index < 0 || index >= size) {
            cout << "Invalid index. Please enter a valid index.\n";
            continue;
        }
        break;
    }

    cout << "Enter the updated task details" << endl;
    cout << "Title: ";
    cin.ignore();
    cin.getline(tasks[index].title, sizeof(tasks[index].title));

    while (true) {
        cout << "Priority(1-10): ";
        cin >> tasks[size].priority;

        if (tasks[size].priority > 10 || tasks[size].priority < 0) {
            cout << "The value is incorrect. Please try again!" << endl;
            continue;
        }
        break;
    }

    cout << "Description: ";
    cin.ignore();
    cin.getline(tasks[index].description, sizeof(tasks[index].description));

    while (true) {
        cout << "Date (YYYY-MM-DD): ";
        cin >> tasks[size].date;

        if (strlen(tasks[size].date) != 8) {
            cout << "Invalid date format. Please enter the date in YYYY-MM-DD format.\n";
            continue;
        }

        break;
    }

    cout << "Task edited successfully.\n";
}
