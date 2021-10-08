// Find factorial of numbers 1<=n<=150
// 100! factorial has total 150+ digits which cant be stored in long long also
// so, here we use array's applications

#include<iostream>
using namespace std;

int multiply(int res[],int res_size,int x)
{
	int carry = 0;
	for(int i=0 ; i<res_size ; ++i)
	{
		int prod = res[i]*x + carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry)
	{
		res[res_size] = carry%10;
		res_size++;
		carry = carry/10;
	}
	return res_size;
}

void findfact(int n)
{
	int res[200];
	res[0] = 1;
	int res_size = 1;

	for(int i=2 ; i<=n ; ++i)
	{
		res_size = multiply(res,res_size,i);
	}

	// cout<<"Factorial is: ";
	for(int i=res_size-1 ; i>=0 ; --i)
	{
		cout<<res[i];
	}
	cout<<endl;
}

int main()
{
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	findfact(n);
	return 0;
}

/* 100 fact value is : 93326215443944152681699238856
2667004907159682643816214685929638952
175999932299156089414639761565182862536
97920827223758251185210916864000000000000000000000000
*/
