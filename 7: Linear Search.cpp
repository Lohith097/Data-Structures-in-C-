#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    
    bool found = false;
    for(int i=0;i<n&&found==false;i++){
        if(arr[i]==key){
            cout<<"Element found at position: "<<i+1<<endl;
            found=true;
        }
    }
    
    if(found==false)
        cout<<"Element not found"<<endl;
        
    return 0;
}
