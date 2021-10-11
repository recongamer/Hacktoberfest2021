#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    if(x<=5){
        cout<<"1\n";
    }
    else if(x%5==0){
        cout<<x/5<<"\n";
    }
    else{
        cout<<(x/5)+1<<"\n";
    }
    return 0;
}