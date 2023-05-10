#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

// размер поля 
void sizeFoo(int rows,int cols);

// для перемешивания карт
void shuffleCards(int cards[], int numCards);

// для вывода игрового поля
void showBoard(int cards[], bool flipped[], int rows, int cols);

// выбор 
void chooseFoo(int index1, int index2, bool* flipped);
 
// для проверки являются ли две карты совпадающими
bool isMatch(int cards[], int index1, int index2);


int main()
{
    




    return 0;
}



void sizeFoo(int rows, int cols) {

    while (rows < 2 || rows > 10) {
        cout << "enter number of rows (2-10): ";
        cin >> rows;
    }
    while (cols < 2 || cols > 10) {
        cout << "enter number of cols (2-10): ";
        cin >> cols;
    }
}


void shuffleCards(int cards[], int numCards)
{
 
}

void showBoard(int cards[], bool flipped[], int rows, int cols){
    system("cls");
    cout << "MEMORY GAME\n\n";
    
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

