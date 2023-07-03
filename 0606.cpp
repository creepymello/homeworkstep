#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T data, Node* prev = nullptr, Node* next = nullptr) {  
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList(Node<T>* head = nullptr,Node<T>* tail = nullptr){
        this->head = head;
        this->tail = tail;

    }

    void append(T data) {           // добавление элемента в конец списка
        Node<T>* newNode = new Node<T>(data);  // Создание нового узла
        if (head == nullptr) {       // ксли список пустой
            head = newNode;
            tail = newNode;
        } else {                     // если список не пустой
            tail->next = newNode;    // указатель next последнего узла устанавливается на новый узел
            newNode->prev = tail;    // указатель prev нового узла на последний узел
            tail = newNode;          // нвый узел становится хвостом списка
        }
    }

    // для добавления элемента в начало списка
    void prepend(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {       // если список пустой
            head = newNode;
            tail = newNode;
        } else {                     // если список не пустой
            newNode->next = head;    // указатель next нового узла на первый узел
            head->prev = newNode;    // указатель prev первого узла на новый узел
            head = newNode;          // еовый узел становится головой списка
        }
    }

    // для вставки элемента по индексу
    void insert(int index, T data) {
        if (index < 0) {             // проверка на индекс
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0) {            // ксли индекс равен 0 вставляем элемент в начало списка
            prepend(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;     //  текущий узел на голову
        int currentIndex = 0;        // текущий индекс на 0

        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        newNode->prev = current;     // prev нового узла на текущий узел
        newNode->next = current->next;  // next нового узла на следующий узел

        if (current->next != nullptr) current->next->prev = newNode;  // prev следующего узла на новый узел

        current->next = newNode;     // next текущего узла на новый узел

        if (current == tail) tail = newNode; // новый узел становится хвостом списка

    }

    // для удаления последнего элемента списка
    void pop() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head == tail) {          // если в списке только один элемент
            delete head;             // удаление узла
            head = nullptr;
            tail = nullptr;
        } else {                     // если в списке > 1 элемента
            Node<T>* nodeToRemove = tail;  // указатель на узел который нужно удалить
            tail = tail->prev;        // хвост на предыдущий узел
            tail->next = nullptr;     // обнуление нового хвоста
        }
    }

    // для удаления элемента по указанному индексу
    void removeAt(int index) {
        if (index < 0) {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0) {
            if (head == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }

            Node<T>* nodeToRemove = head;  // указатель на узел который нужно удалить
            head = head->next;        // голова на следующий узел

            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr;

            return;
        }

        Node<T>* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        current->prev->next = current->next;

        if (current->next != nullptr) current->next->prev = current->prev;

        if (current == tail) tail = current->prev;

    }

    // для удаления элемента из списка
    void remove(T data) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) head = current->next;
                else current->prev->next = current->next;

                if (current == tail) tail = current->prev;
                else current->next->prev = current->prev;

                return;
            }

            current = current->next;
        }

        cout << "Element not found in the list!" << endl;
    }

    void print() {
        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);
    list.insert(2, 5);
    list.print();

    list.pop();
    list.removeAt(1);
    list.remove(2);
    list.print();

    return 0;
}
