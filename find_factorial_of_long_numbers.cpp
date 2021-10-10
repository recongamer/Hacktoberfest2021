// Find factorail of large numbers
// 100 factorail has 153 more
// so, it cant be fit into long long data type also 
// so, we use application of arrays
#include<iostream>
#include<vector>
using namespace std;

// this function will multiply the x with the previously stored arr values and update the arr

int multiplyWith(vector<int> &arr,int arr_size,int x)
{
	int carry = 0;

	for(int i=0 ; i<arr_size ; ++i)
	{
		int product = arr[i]*x + carry ;
		arr[i] = product%10;
		carry = product/10;
	}
	while(carry)
	{
		arr[arr_size] = carry%10;
		arr_size++;
		carry = carry/10;
	}
	return arr_size;
}

void findFact(int n)
{
	// factorial will be stored in this array
	vector<int> arr(200);
	arr[0] = 1; // intializing
	int arr_size = 1; // array size will be in this variable

	for(int i=2 ; i<=n ; ++i)
	{
		// this function will multiply 'i' values and store in the array
		arr_size = multiplyWith(arr,arr_size,i);
	}

	// now we will print the array content from reverse side
	for(int i=arr_size-1 ; i>=0 ; --i)
	{
		cout<<arr[i];
	}
	cout<<endl;
}

int main()
{
	int x;
	cout<<"Enter a number: "<<endl;
	cin>>x;
	findFact(x);
	return 0;
}
