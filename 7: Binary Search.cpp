#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements in ascending order: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    
    bool sorted=true;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            sorted = false;
            break;
        }
    }
    
    if(sorted==false) {
        cout<<"Array is not sorted in ascending order"<<endl;
        return 0;
    }
    
    bool found = false;
    int low=0;
    int high = n-1;
    
    while(low<=high&&found==false) {
        int mid = low+(high-low)/2;
        if(arr[mid]==key) {
            cout<<"Element found at position: "<<mid+1<<endl;
            found=true;
        }
        else if(key<arr[mid]){
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    if(found==false)
        cout<<"Element not found"<<endl;
        
    return 0;
}
