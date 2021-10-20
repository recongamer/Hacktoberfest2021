#include<iostream>
using namespace std;
void Swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void dnfsort(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            Swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            Swap(arr,mid,high);
            high--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of array - ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array - ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dnfsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
