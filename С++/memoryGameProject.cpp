#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

// размер поля 
void sizeFoo(int rows, int cols);

// для перемешивания карт
void shuffleCards(int cards[], int numCards);

// для вывода игрового поля
void showBoard(int cards[], bool flipped[], int rows, int cols,int ttime);

// выбор 
void chooseFoo(int index1, int index2, bool* flipped);

// для проверки являются ли две карты совпадающими
bool isMatch(int cards[], int index1, int index2);

// для ожидания нажатия
void keyPress();



int main()
{
    int rows{}, cols{};
    while (rows < 2 || rows > 10) {
        cout << "enter number of rows (2-10): ";
        cin >> rows;
        /*    if (!isdigit(rows)) {
                cout << "Invalid input. Please enter a number." << endl; с этим пока не разобралась,
                бесконечный цикл получается*/
    }
    while (cols < 2 || cols > 10) {
        cout << "enter number of cols (2-10): ";
        cin >> cols;
    }
    // размер поля 


    int numCards = rows * cols;
    int ttime{};
    if (numCards > 10) ttime = 20;
    else ttime = 10;
    int* cards = new int[numCards];
    bool* flipped = new bool[numCards];

    // перемпешивание
    shuffleCards(cards, numCards);

    // вывод поля
    showBoard(cards, flipped, rows, cols,ttime);




    return 0;
}


void shuffleCards(int cards[], int numCards)
{

    srand(time(0));
    for (size_t i = 0; i < numCards; i++)
    {
        cards[i] = i / 2;
    }
    for (size_t i = 0; i < numCards; i++)
    {
        int j = rand() % numCards;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}



void showBoard(int cards[], bool flipped[], int rows, int cols, int ttime) {
    int timeLeft = ttime;
    while (timeLeft > 0) {
        system("cls");
        cout << "memory game\n\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = i * cols + j;
                if (flipped[index]) {
                    cout << cards[index] << '\t';
                }

            }
            cout << endl;
        }
        cout << endl << "Look carefully at the numbers and try to remember their meanings.\nThe values will disappear after " 
            << timeLeft << " seconds" << endl;

        Sleep(1000);
        timeLeft--;
    }
    system("cls");
    cout << "memory game\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "X\t";
        }
        cout << endl;
    }
    cout << endl << "time is up :)" << endl;
}



void chooseFoo(int index1, int index2, bool* flipped) {

    while (flipped[index1]) {
        cout << "choose first card: ";
        cin >> index1;
        index1--;
    }

    while (index2 == index1 || flipped[index2]) {
        cout << "choose second card: ";
        cin >> index2;
        index2--;
    }
}




bool isMatch(int cards[], int index1, int index2)
{
    return cards[index1] == cards[index2];
}



