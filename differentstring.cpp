#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int i,n;
 cin>>n;
 vector<string> str(n,".");
 for(i=0; i<n;i++)
 {
  cin>> str[i];
 }
 string ans = "";
 for(i=0; i<n;i++)
 {
  if(str[i][i] == '0'){
   ans += '1';
  }
  else{
   ans += '0';
  }
 }
 cout<<ans<<endl;
    }
    return 0;
}