#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int o=(n+1)/2;
    long long int e=n/2;
    cout<<(e*(e+1))-(o*o)<<endl;
    return 0;
}