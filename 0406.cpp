#include <iostream>
#include <vector>

using namespace std;

// добавила pop,reverse,remove и remove all 

template<typename T>
class MyVector {
private:
    T* arr{};
    size_t length{};
    size_t capacity{};
public:
    MyVector(size_t capacity) {
        this->capacity = capacity;
        this->arr = new T[this->capacity]{};
    }

    MyVector(initializer_list<T> list) {
        this->capacity = list.size() * 2;
        this->length = list.size();
        this->arr = new T[this->capacity]{};

        for (auto i = list.begin(); i < list.end(); ++i) {
            this->arr[i - list.begin()] = *i;
        }
    }

    void append(T element) {
        if (this->length == this->capacity) {
            this->capacity *= 2;
            T* new_arr = new T[this->capacity]{};
            for (size_t i = 0; i < this->length; ++i) {
                new_arr[i] = this->arr[i];
            }
            delete[] this->arr;
            this->arr = new_arr;
        }
        this->arr[this->length] = element;
        this->length++;
    }

    size_t getLength() const {
        return this->length;
    }

    void pop_back() {
        if (length > 0) {
            length--;
        }
    }

    void reverse() {
        for (size_t i = 0; i < length / 2; ++i) {
            T temp = arr[i];
            arr[i] = arr[length - i - 1];
            arr[length - i - 1] = temp;
        }
    }

    void remove(size_t index) {
        if (index < length) {
            for (size_t i = index; i < length - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    void removeall(const T& element) {
        size_t index = 0;
        while (index < length) {
            if (arr[index] == element) {
                remove(index);
            }
            else {
                index++;
            }
        }
    }

    friend ostream& operator<<(ostream& os, MyVector<T>& v) {
        for (size_t i = 0; i < v.length; ++i) {
            os << v.arr[i] << ' ';
        }
        return os;
    }

    T& operator[](size_t index) {
        if (index < this->length) {
            return this->arr[index];
        }
    }
};

int main() {

    MyVector<int> v1{ 1, 2, 3, 4, 5, 3, 6, 2, 8, 1 };
    cout << "array: " << v1 << endl;

    v1.append(10);
    cout << "append: " << v1 << endl; //добавили в конец

    cout << "length: " << v1.getLength() << endl; // длина
    v1.pop_back();
    cout << "pop back: " << v1 << endl; //удалили с конца

    v1.reverse();
    cout << "reverse: " << v1 << endl; // превернулои

    size_t index = 5;
    v1.remove(index);
    cout << "removing element at index " << index << ": " << v1 << endl; //удвлили по индк

    int element = 2;
    v1.removeall(element);
    cout << "removed all " << element << ": " << v1 << endl;  //удалили все 2

    return 0;
}
