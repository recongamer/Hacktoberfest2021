//NOT COMPLETED
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans[n];
    for(int i=0; i<n; i++){
        if(arr[i]==i+1){
            ans[i]=arr[i];
        }
        else{
            ans[i]=arr[arr[i]%n];
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}