#include<iostream>

using namespace std;
void countSort(int * a , int n){
    int max = 0;
    for(int i=0 ; i<n ; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int b[max+1] = {0};
    for(int i=0 ; i<n ; i++){
       b[a[i]] = b[a[i]]+1;
    }
    int i=0;
    int j=0;
    while(i< max+1){
        if(b[i]>0){
            a[j] = i;
            b[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    countSort(arr , n);
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
