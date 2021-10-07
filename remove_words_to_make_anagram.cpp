#include <bits/stdc++.h>
using namespace std;
const int CHARS = 26;
 
int countDeletions(string str1, string str2)
{
    int arr[CHARS] = {0};
    for(int i=0;i<str1.length();i++)
        arr[str1[i] - 'a']++;    
    
    for(int i=0;i<str2.length();i++)
        arr[str2[i] - 'a']--;    
    
    long long int ans = 0;
    for(int i =0;i<CHARS;i++)
        ans += abs(arr[i]);
    return ans;
    
}
 
int main() {
    string str1 = "bcadeh", str2 = "hea";
    cout << countDeletions(str1, str2);
    return 0;
}

