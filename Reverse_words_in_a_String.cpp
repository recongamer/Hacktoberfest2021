#include <bits/stdc++.h>                                                               
using namespace std;

void reverse(string& s, int low, int high){
    while(low < high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
}
string reverseString(string str){
    str.insert(str.end(), ' ');
    int start =0;
    int n =str.length();
    for(int end=0; end<n; end++)
    {
        if(str[end]==' '){
            reverse(str,start,end-1);
            start=end+1;
        }
        
    } 
    str.pop_back();
    reverse(str,0, str.length() -1);
    return str;
}

int main(){
    
    string str = "Ikl like this code";
 
    string rev = reverseString(str);
 
    
    cout << rev;
    return 0;
    
}

