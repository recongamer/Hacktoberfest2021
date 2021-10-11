#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0; i<s.length(); i+=2){
        v.push_back((int)s[i]-48);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size()-1; i++){
        cout<<v[i]<<"+";
    }
    cout<<v[v.size()-1]<<endl;

    return 0;
}