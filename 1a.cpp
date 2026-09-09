#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int arr1[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    cout << "Array elements:\n";
    for(int i = 0; i < n; i++) {
        cout << "Index " << i << ": " << arr1[i] << "\n";
    }
    
    int index, newValue;
    cout << "Enter index to modify and new value: ";
    cin >> index >> newValue;
    arr1[index] = newValue;
    
    cout << "Updated Array:\n";
    for(int i = 0; i < n; i++) {
        cout << "Index " << i << ": " << arr1[i] << "\n";
    }
    return 0;
}
