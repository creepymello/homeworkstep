#include <iostream>
using namespace std;


void caesarCipher(char* str, int kolc);
void firstsortfoo(char* str);
void secondsortfoo(char* str);
int main() {
    char* str = new char[100];
    int kolc;

    cout << "enter the line to encrypt: ";

   cin.getline(str, 100); cout << endl;

   cout << "enter the number of positions to shift: ";
   cin >> kolc; cout << endl;

   caesarCipher(str, kolc);

   cout << "encrypted string: " << str << endl;
    
   cout << "bubble sort: ";
   firstsortfoo(str); 
   cout << "insertion sort: ";
   secondsortfoo(str); 
   return 0;
}


void caesarCipher(char* str, int kolc)
{
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {

        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'A' + (str[i] - 'A' + kolc) % 26;

        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'a' + (str[i] - 'a' + kolc) % 26;
       }

}


void firstsortfoo(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    for (size_t i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;
}


void secondsortfoo(char* str){
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        char stri = str[i];
        int j = i - 1;
        if (j >= 0 && str[j] > stri) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = stri;
    }

    for (size_t i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;
}




