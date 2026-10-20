#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; 
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n]; 
    
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
