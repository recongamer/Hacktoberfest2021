#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int d = arr[1]-arr[0];
    int ans = 2;
    int cur = 2;
    int j = 2;

    while(j<n){
        if(arr[j] - arr[j-1] == d){
            cur++;
        }
        else{
        d = arr[j] - arr[j-1];
        cur = 2;
        }
        ans = max(ans,cur);
        j++;
    }
    cout<<"Longest Arithematic Sub Array :"<<ans<<endl;
    return 0;
}
