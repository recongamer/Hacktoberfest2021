#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	long long int t,x,y,sum,max,min;
	cin>>t;
	while(t--)
	{
	cin>>x>>y;
	max=lcm((x*y)-1,x*y);
	min=lcm(x,x*2);
	cout<<min<<" "<<max<<endl;
	}
	return 0;
}
