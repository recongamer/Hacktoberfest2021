#include <bits/stdc++.h>
using namespace std;
void perm(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<" ";
        return ;
    }
    else{
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            string left = s.substr(0,i);
            string right = s.substr(i + 1);
            string rest = left + right;
            perm(rest, ans + ch);
        }
    }
}
int main()
{
     string s;
    string answer="";
 
    cout<<"Enter the string : ";
    cin>>s;
 
    cout<<"\nAll possible strings are : ";
    perm(s , answer);
    return 0;
}

