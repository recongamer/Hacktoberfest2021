#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int cost=((w*(w+1))/2)*k;
    (cost>n)?(cout<<cost-n<<"\n"):cout<<"0\n";
    return 0;
}