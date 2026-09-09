#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows (m) and columns (n): ";
    cin >> m >> n;
    
    int arr2[m][n];
    cout << "Enter elements:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr2[i][j];
        }
    }
    
    cout << "2D Array:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
    
    int row, col, newValue;
    cout << "Enter row, column to modify, and new value: ";
    cin >> row >> col >> newValue;
    arr2[row][col] = newValue;
    
    cout << "Updated 2D Array:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
