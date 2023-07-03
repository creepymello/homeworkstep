#include <iostream>
using namespace std;

// я ваш код с гита за основу взяла

template <typename T>
class MyQueue {
public:
    MyQueue() = default;
    MyQueue(const MyQueue& other) = delete;
    MyQueue& operator=(const MyQueue& other) = delete;

    MyQueue(uint16_t capacity, bool isExpandable = false)
    {
        this->capacity = capacity;
        this->arr = new T[capacity]{};
        this->isExpandable = isExpandable;
        this->front = 0;
        this->rear = -1;
        this->size = 0;
    }

    ~MyQueue()
    {
        delete[] this->arr;
    }

    void enqueue(T value)
    {
        if (this->size == this->capacity && !this->isExpandable)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        else
        {
            if (this->size == this->capacity && this->isExpandable)
            {
                this->capacity *= 2;

                T* newArr = new T[this->capacity]{};

                for (uint16_t i = 0; i < this->size; i++)
                {
                    newArr[i] = this->arr[(this->front + i) % this->capacity];
                }

                delete[] this->arr;
                this->arr = newArr;

                this->front = 0;
                this->rear = this->size - 1;
            }
        }

        if (this->size == 0)
        {
            this->front = 0;
            this->rear = 0;
        }
        else
        {
            this->rear = (this->rear + 1) % this->capacity;
        }

        this->arr[this->rear] = value;
        this->size++;
    }



    T dequeue()
    {
        if (this->size == 0)
        {
            cout << "Queue is empty" << endl;
            return T{};
        }

        T objForReturn = this->arr[this->front];
        this->arr[this->front] = T{};
        this->front = (this->front + 1) % this->capacity;
        this->size--;

        if (this->size == 0)
        {
            this->front = 0;
            this->rear = -1;
        }

        return objForReturn;
    }



    T getFront()
    {
        if (this->size == 0)
        {
            cout << "Queue is empty" << endl;

        }
        return this->arr[this->front];
    }


private:
    T* arr{};
    uint16_t size{};
    uint16_t capacity{};
    bool isExpandable{ false };
    uint16_t front{};
    uint16_t rear{};
};

int main()
{
    MyQueue<int> queue(5, true);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "The first item in the queue is: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    cout << "The first item in the queue is: " << queue.getFront() << endl;

    return 0;
}
