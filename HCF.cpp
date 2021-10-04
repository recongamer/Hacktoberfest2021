#include<iostream>
using namespace std;

int GCD(int , int);
int GCD(int a, int b)
{
        if(b==0)
        return a;
        else if(a==0)
        return b;
        else 
        return GCD(b,a%b);

}
int main()
{
int a,b;
cout<<"ENTER 2 NUMBERS FOR HCF FINDING";
cin>>a>>b;
cout<<"HCF="<< GCD(a,b);
return 0;
}
