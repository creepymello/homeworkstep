#include <iostream>

using namespace std;


//int main() {
//    int num;
//    cout << "Enter a number: ";
//    cin >> num;
//
//    int arr[3][3];
//
//    arr[0][0] = num;
//
//    for (int i = 0; i < 3; i++) {
//        for (int j = 1; j < 3; j++) {
//            arr[i][j] = arr[i][j - 1] * 2;
//        }
//        if (i < 2) {
//            arr[i + 1][0] = arr[i][2] * 2;
//        }
//    }
//
//    cout << "array: " << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << arr[i][j] << " ";
//        }
//    }
//
//    return 0;
//}


//int main() {
//    int n;
//    cout << "Enter a number: ";
//    cin >> n;
//
//    int arr[3][3];
//
//    arr[0][0] = n;
//    for (int i = 1; i < 3; i++) {
//        arr[0][i] = arr[0][i - 1] + 1;
//    }
//
//    for (int i = 1; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            arr[i][j] = arr[i - 1][j] + 1;
//        }
//    }
//
//    cout << "Array: " << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << arr[i][j] << " ";
//        }
//    }
//
//    return 0;
//}
