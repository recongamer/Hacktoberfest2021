#include<bits/c++.h>
int main()
{
  int x,rem=0,rev=0;
  cout<<"Enter the number to be reversed"<<endl;
  cin>>x;
  while(x>0)
  {
    rem=x%10;
    rev=rev*10+rem;
    x=x/10;
    
  }
  cout<<"Reverse of number is"<<rev<<endl;
  return 0;
}
    
