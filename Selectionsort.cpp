//SELECTION SORT

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,z;cin>>n;
    int arr[n];
    
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
            for(int i=0;i<n;i++){
                int min_ind=i;
                for(int j=i+1;j<n;j++){
                    if(arr[j]<arr[min_ind])min_ind=j;
                }
                swap(arr[min_ind],arr[i]);
            }
            for(int i=0;i<n;i++){
                cout<<arr[i]<<endl;
            }
}



