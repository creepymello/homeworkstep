#include <iostream>

using namespace std;

double fooMax(double* arr, int len);
double fooMin(double* arr, int len);
double fooAvg(double* arr, int len);
void fooAdd(double* A, double* B, int sizeA, int sizeB);
int Action(double* A, double* B, int sizeA, int sizeB, double (*func)(double*, int));

int main() {
    // Задаем массивы
    int sizeA{}, sizeB{};

    cout << "enter the length for array A: ";
    cin >> sizeA;
    cout << "enter the length for array B: ";
    cin >> sizeB;
    double* arrA = new double[sizeA];
    double* arrB = new double[sizeB];
    fooAdd(arrA, arrB, sizeA, sizeB);

    int choise; 
    cout << endl;
    cout << "1. Max" << endl <<
        "2. Min" << endl <<
        "3. Avg" << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
        Action(arrA, arrB, sizeA, sizeB, fooMax);
        break;
    case 2:
        Action(arrA, arrB, sizeA, sizeB, fooMin);
        break;
    case 3:
        Action(arrA, arrB, sizeA, sizeB, fooAvg);
        break;
    default:
        break;
    }
    
    return 0;
}

double fooMax(double* arr, int len) {
    double maxx = arr[0];
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] > maxx) maxx = arr[i];
    }
    return maxx;
}

double fooMin(double* arr, int len) {
    double minn = arr[0];
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] < minn) minn = arr[i];
    }
    return minn;
}

double fooAvg(double* arr, int len) {
    double summ = 0;
    for (size_t i = 0; i < len; i++)
    {
        summ += arr[i];
    }
    return summ / len;
}

int Action(double* A, double* B, int sizeA, int sizeB, double (*func)(double*, int)) {
    
    double resultA = func(A, sizeA);
    double resultB = func(B, sizeB);

    cout << "result for array A: " << resultA << endl;
    cout << "result for array B: " << resultB << endl;
    return 0;
}

void fooAdd(double* A, double* B, int sizeA, int sizeB) {
    cout << "enter the values of array A: ";
    for (size_t i = 0; i < sizeA; i++)
    {
        cin >> A[i];
    }
    cout << "enter the values of array B: ";
    for (size_t i = 0; i < sizeB; i++)
    {
        cin >> B[i];
    }
    cout << endl;
    cout << "array A: ";
    for (size_t i = 0; i < sizeA; i++)
    {
        cout << A[i] << ' ';
    }
    cout << "array B: ";
    for (size_t i = 0; i < sizeB; i++)
    {
        cout << B[i] << ' ';
    }
}