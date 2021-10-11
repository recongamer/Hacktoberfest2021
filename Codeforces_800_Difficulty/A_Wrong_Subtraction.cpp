#include<bits/stdc++.h>
using namespace std;

int main(){
    int num,k;
    cin>>num>>k;
    for(int i=0; i<k; i++){
        if(num%10==0){
            num/=10;
        }
        else{
            num-=1;
        }
    }
    cout<<num<<"\n";

    return 0;
}