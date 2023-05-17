#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

// для перемешивания карт
void shuffleCards(int cards[], int numCards);

// для вывода игрового поля
void showBoard(const int cards[], const bool flipped[], int rows, int cols, int ttime);

// открывает верные карты
void openCards(const int cards[], const bool flipped[], int rows, int cols);

// для проверки являются ли две карты совпадающими
bool isMatch(int cards[], int index1, int index2);

// для проверки ввода
int cinNum();

int main()
{
    int numFlips = 0;
    int numMatches = 0;
    int startTime = time(NULL); // запускаем таймер
    int rows{}, cols{};

    // размер поля
    while (rows < 2 || rows > 5) {
        cout << "enter number of rows (2-5): ";
        rows = cinNum();
    }
    while (cols < 2 || cols > 5) {
        cout << "enter number of cols (2-5): ";
        cols = cinNum();
    }

    int numCards = rows * cols;

    // установка времени видимости карт
    int ttime{};
    if (numCards > 10) ttime = 15;
    else if (numCards <= 6) ttime = 5;
    else if (numCards > 6 && numCards <= 10) ttime = 10;

    int* cards = new int[numCards];
    bool* flipped = new bool[numCards];
   /* int* flippedCards = new int[numCards];
    for (int i = 0; i < numCards; i++) {
        flippedCards[i] = -1;
    }*/

    const int nepTime = 3;

    // перемешивание
    shuffleCards(cards, numCards);

    // выводим поле
    showBoard(cards, flipped, rows, cols, ttime);

    // цикл игры
    while (numMatches < numCards / 2)
    {
        // выбор первой карты
        int index1;

        do
        {
            cout << "Choose first card (1 - " << numCards << "): ";
            index1 = cinNum();
            index1--;

            if (index1 > numCards) continue;
            

            else break;

        } while (flipped[index1]);

       
        // выбор второй карты
        int index2;

        do
        {
            cout << "Choose second card(1 - " << numCards << ") : ";
            index2 = cinNum();
            index2--;
            
                
            if (index2 > numCards) continue;
            else if (index1 == index2) continue;

            else break;

        } while (flipped[index2]);

        numFlips++;

        // проверка совпалили карты
        if (isMatch(cards, index1, index2)) {
            cout << "Match!" << endl;
            flipped[index1] = true;
            flipped[index2] = true;
           
            numMatches++;
            Sleep(500);
            openCards(cards, flipped, rows, cols);

            system("cls");

            flipped[index1] = false;
            flipped[index2] = false;

            openCards(cards, flipped, rows, cols);
           
        }

        else {
            cout << "No match." << endl;
            Sleep(1000);
            if (numMatches < 1)
                showBoard(cards, flipped, rows, cols, nepTime);

            flipped[index1] = false;
            flipped[index2] = false;
        }
    }
    int endTime = time(NULL); // конец таймера
    int timeee = endTime - startTime;


    cout << "Congratulations! You won!" << endl;
    cout << "Number of flips: " << numFlips << endl;
    cout << "Time taken: " << timeee << " seconds" << endl;

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


void showBoard(const int cards[], const bool flipped[], int rows, int cols, int ttime) {
    int timeLeft = ttime;
    while (timeLeft > 0) {
        system("cls");
        cout << "memory game\n\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = i * cols + j;
                if (flipped[index]) cout << cards[index] << '\t';
                else cout << "X\t";
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

void openCards(const int cards[], const bool flipped[], int rows, int cols) {
    system("cls");
    cout << "memory game\n\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (flipped[index]) cout << "X\t";
            else cout << cards[index] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}


bool isMatch(int cards[], int index1, int index2)
{
    return cards[index1] == cards[index2];
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
