#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

// для перемешивания карт
void shuffleCards(int cards[], int numCards);

// для вывода игрового поля
void showBoard(const int cards[], const bool flipped[], int rows, int cols, int ttime);

// выбор 
void chooseFoo(int index1, int index2, bool* flipped);

// для проверки являются ли две карты совпадающими
bool isMatch(int cards[], int index1, int index2);

// для ожидания нажатия
void keypress();


// нужно еще добавить функцию которая открывает угаданные карты,
// проверку находится ли введенная пользователем карта в диапазоне numCards
int main()
{
    int numFlips = 0;
    int numMatches = 0;
    int startTime = time(NULL);
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
    const int nepTime = 5;
    // перемпешивание
    shuffleCards(cards, numCards);

    showBoard(cards, flipped, rows, cols, ttime);
    while (numMatches < numCards / 2)
    {
        int index1;
        do
        {
            cout << "Choose first card (1 - " << numCards << "): ";
            cin >> index1;
            index1--;
            break;


        } while (flipped[index1]);

        // аользователь выбирает вторую карту
        int index2;
        do
        {
            cout << "Choose second card(1 - " << numCards << ") : ";
            cin >> index2;
            index2--;
            break;

        } while (flipped[index2] || index1 == index2);

        // переворачиваем выбранные карты
        flipped[index1] = true;
        flipped[index2] = true;
        numFlips++;

        if (isMatch(cards, index1, index2)) {
            cout << endl << "Match!" << endl;
            flipped[index1] = true;
            flipped[index2] = true;

            if (numMatches == numCards / 2) {
                cout << "Congratulations, you won!" << endl;
            }
        }
        else {
            cout << endl << "No match." << endl;
            Sleep(1000);
            showBoard(cards, flipped, rows, cols, nepTime);
            flipped[index1] = false;
            flipped[index2] = false;
        
        }
        keypress();
    }
    int endTime = time(NULL);
    int timeee = endTime - startTime;
    cout << "Congratulations! You won!" << endl;
    cout << "Number of flips: " << numFlips << endl;
    cout << "Time taken: " << timeee << " seconds" << endl;

    keypress();



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



void showBoard(const int cards[], const bool flipped[], int rows, int cols, int ttime){
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
                else {
                    cout << "X\t";
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



//void chooseFoo(int index1, int index2, bool* flipped) {
//
//    while (flipped[index1]) {
//        cout << "choose first card: ";
//        cin >> index1;
//        index1--;
//    }
//
//    while (index2 == index1 || flipped[index2]) {
//        cout << "choose second card: ";
//        cin >> index2;
//        index2--;
//    }
//}




bool isMatch(int cards[], int index1, int index2)
{
    return cards[index1] == cards[index2];
}



void keypress() {
    cout << "please click ENTER to continue: ";
    cin.ignore();
    cin.get();
}
