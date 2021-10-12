#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    int d1=n%10;
    int d2=(n/10)%10;
    int d3=(n/100)%10;
    int d4=(n/1000)%10;
    if(d1!=d2 && d1!=d3 && d1!=d4 && d2!=d3 && d2!=d4 && d3!=d4){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    n++;
    while(!check(n)){
        n++;
    }
    cout<<n<<"\n";
    return 0;
}