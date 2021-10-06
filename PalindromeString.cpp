
#include<bits/stdc++.h>
using namespace std;

string Palindrome(string s){
  
  for (int i = 0; i < s.length() / 2; i++) {

        if (s[i] != s[s.length() - i - 1]) {
           
            return "String is not a Palindrome";
        }
    }
    
    return "String is a Palindrome";
}

int main()
{
    string s = "acdefedca";
    cout << Palindrome(s);
 
    return 0;
}
