#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v){
        cin>>it;
    }
    int max_index = max_element(v.begin(),v.end()) - v.begin();
    int min_term = *min_element(v.begin(), v.end());
    int min_index = min_element(v.begin(),v.end()) - v.begin();
    for(int i=min_index; i<n; i++){
        if(v[i]==min_term){
            min_index=i;
        }
    }
    if(max_index>min_index){
        min_index++;
    }
    cout<<max_index+(n-min_index-1)<<endl;
    return 0;
}