
#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S)
{
   unordered_map<char, int>mp;
   for(int i =0; i < S.size(); i++)
   {
       mp[S[i]]++;
   }
   

   unordered_map<char, int>::iterator itr;
   
   for(int i=0; i < S.size(); i++)
   {
        if(mp[S[i]] == 1)
            return S[i];
   }
   return '$';
}
int main()
{
    string str ="hello";
    cout << nonrepeatingCharacter(str);

    return 0;
}

