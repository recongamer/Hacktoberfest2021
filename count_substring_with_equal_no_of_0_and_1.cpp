#include <bits/stdc++.h>
 
using namespace std;
int cntsubarray(int a[],int n){
    map<int,int>mp;
    int count=0;
    int sum=0;
    mp.insert(0,1);
    for(int i=0;i<n;i++){
        if(a[i]==0){
            sum+=-1;
        }
        else{
            sum+=1;
        }
        if (mp[sum]){
            count += mp[sum];
             mp[sum]++;
        }
        else{
            mp[sum] = 1;
        }
    }
    return count;
}
int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count = "
         << cntsubarray(arr, n);
    return 0;
}