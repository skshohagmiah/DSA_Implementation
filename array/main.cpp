#include <iostream>

using namespace std;

int main () {

    int arr[8] = {3,24,5,3,5,3,34, 1000};

    arr[0] = 100;

    for(int i = 0 ; i < size(arr); i++){
        cout << "Iteration " << arr[i] << endl;
    }

    int matrix[3][3] = {{1,2,3}, {3,2,1}, {8,3,5}};

    for(int i = 0; i < size(matrix); i++){
        for (int j = 0; j < size(matrix[0]); j++){
            cout << "Row and Column " << matrix[i][j] << endl;
        }
    }

    cout << "Size formula " << sizeof(arr) / sizeof(arr[1]) << '\n';
    return 0;
}