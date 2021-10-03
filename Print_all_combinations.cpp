//Given a number n, generate all distinct ways to write n as the sum of positive integers. 
//For example, with n = 4, the options are 4, 3 + 1, 2 + 2, 2 + 1 + 1, and 1 + 1 + 1 + 1.

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &A)
{
    for(auto i:A)
    cout<<i<<" ";
    cout<<"\n";
}
void finding(int i,int n,vector<int>&A)
{
   if(n==0)
   print(A);
   for(int j=i;j<=n;j++)
   {
       A.push_back(j);
       finding(j,n-j,A);
       A.pop_back();
   }
}
int main()
{
    int n;
    cout<<"Enter the integer n : \n";
    cin>>n;
    cout<<"All combinations  :\n";
   vector<int>A;
   finding(1,n,A);
      
    return 0;
}
