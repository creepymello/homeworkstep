#include <iostream>
#include <cstdint>
#include <stdexcept>
// за основу взят ваш код с гита:(((
using namespace std;

template <typename T>
class MyStack
{
public:
    MyStack() = default;
    MyStack(const MyStack &other) = delete;
    MyStack &operator=(const MyStack &other) = delete;

    MyStack(uint16_t capacity, bool isExpandable = false)
    {
        this->capacity = capacity;
        this->arr = new T[capacity]{};
        this->isExpandable = isExpandable;
    }

    ~MyStack()
    {
        delete[] this->arr;
    }

    void push(T value)
    {
        if (this->size == this->capacity && !this->isExpandable)
        {
            throw overflow_error("Stack overflow");
        }
        else
        {
            if (this->size == this->capacity && this->isExpandable)
            {
                try {
                    this->capacity *= 2;
                    T *newArr = new T[this->capacity]{};
                    for (uint16_t i = 0; i < this->size; i++)
                    {
                        newArr[i] = this->arr[i];
                    }
                    delete[] this->arr;
                    this->arr = newArr;
                } catch (const std::bad_alloc& e) {
                    throw e;
                }
            }
        }
        this->arr[this->size] = value;
        this->size++;
    }

    T pop()
    {
        if (this->size == 0)
        {
            throw underflow_error("Stack is empty");
        }
        this->size--;
        T objForReturn = this->arr[this->size];
        this->arr[this->size] = T{};
        return objForReturn;
    }

    T peek(bool reset = false)
    {
        static uint16_t peekIterator = this->size;
        if (reset)
        {
            peekIterator = this->size;
        }
        if (this->size == 0)
        {
            throw underflow_error("Stack is empty");
        }
        if (peekIterator == 0)
        {
            peekIterator = this->size;
        }
        peekIterator--;
        return this->arr[peekIterator];
    }

private:
    T *arr{};
    uint16_t size{};
    uint16_t capacity{};
    bool isExpandable{false};
};

int main()
{
    try {
        MyStack<int> stack(5, false);


        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);


        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

    }
    catch (const overflow_error &e) {
        cerr << "Overflow error: " << e.what() << endl;
    }
    catch (const underflow_error &e) {
        cerr << "Underflow error: " << e.what() << endl;
    }

    return 0;
}
