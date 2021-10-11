#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    transform(s.begin(), s.begin()+1, s.begin(), ::toupper);
    cout<<s<<"\n";
    return 0;
}