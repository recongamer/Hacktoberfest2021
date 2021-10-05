//Find Nth Root of any given number using binary search
// example cuberoot of 11 = 2.22398

#include<iostream>
#include<math.h>
using namespace std;

//this funcion multiples the given mid value 'n' times and returns the result
double multiply(double mid , double n)
{
	double ans=mid;

	for(int i=1 ; i<n ; ++i)
	{
		ans = ans * mid;
	}
	return ans;
}

// this function calcualtes the Nth root and returns the result to the main funcion
double getNthRoot(double n , double m)
{
	double lo=1 , hi=m , mid;
	double eps = 1e-6;
// eps for the decimal places in the result of ans

	while((hi - lo) > eps)
	{
		mid = (lo+hi)/2.0;
		if(multiply(mid,n) < m)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	return lo;
}

int main()
{
	double n,m,ans;

	// n is the root , and m is the number 
	cout<<"Enter the n and m values : "<<endl;
	cin>>n>>m;

	ans = getNthRoot(n,m); //function call
	cout << ans<<endl;

	cout << pow(m,1.0/n); // calculate the Nth Root using inbuilt function
	// by result we can say that our function and inbuilt function result is same.

	return 0;
}
