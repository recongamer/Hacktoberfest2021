//  C++ program to reverse a string.

#include <bits/stdc++.h>
using namespace std;

int main()
{   
  string str ; 
  cin>>str; 
  cout << "Before Reverse : "<< str << endl;  
  reverse(str.begin(), str.end());  
  cout <<"After Reverse  : " << str << endl;  
      return 0;
}
