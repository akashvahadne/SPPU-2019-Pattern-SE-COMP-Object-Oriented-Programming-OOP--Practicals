// Q.5.Write a function template for selection sort that inputs, sorts and outputs 
// an integer array and a float array.

#include <iostream>
using namespace std;
#define SIZE 10

template<class T>
void sel(T A[], int n) {
    int i, j, min;
    T temp;
    for (i = 0; i < n- 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array:";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
}

int main() {
    int A[SIZE];
    float B[SIZE];
    int n, i;
    int ch;
    do {
        cout << "\n* * * * *SELECTION SORT SYSTEM * ** **";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter total number of int elements (max " << SIZE << "): ";
                cin >> n;
                if (n > SIZE) {
                    cout << "Number of elements exceeds the maximum size." << endl;
                    break;
                }
                cout << "\nEnter int elements: ";
                for (i = 0; i < n; i++) {
                    cin >> A[i];
                }
                sel(A, n);
                break;
            case 2:
                cout << "\nEnter total number of float elements (max " << SIZE << "): ";
                cin >> n;
                if (n > SIZE) {
                    cout << "Number of elements exceeds the maximum size." << endl;
                    break;
                }
                cout << "\nEnter float elements: ";
                for (i = 0; i < n; i++) {
                    cin >> B[i];
                }
                sel(B, n);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 3);
    return 0;
}
