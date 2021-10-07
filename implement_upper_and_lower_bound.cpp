// implementation of upper_bound() and lower_bound() with help of binary search
// Time Complexitcy will be : O(log n)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// function to calculate lower_bound()
int lower_bound(vector<int> &v , int element)
{
	int lo = 0 , hi = v.size() - 1;
	int mid;

	while(hi - lo > 1)
	{
		mid = (lo+hi)/2;
		if(v[mid] < element)
		{
			lo = mid+1;
		}
		else
		{
			hi = mid;
		}
	}
	if(v[lo]>=element) return lo;
	if(v[hi]>=element) return hi;
	return -1;
}

// funciton to calculate upper_bound()
int upper_bound(vector<int> &v , int element)
{
	int lo = 0 , hi = v.size()-1 ;
	int mid;

	while(hi-lo>1)
	{
		mid = (lo+hi)/2;
		if(v[mid] <= element)
		{
			lo = mid+1;
		}
		else
		{
			hi = mid;
		}
	}
	if(v[lo]>element) return lo;
	else if(v[hi]>element) return hi;
	return -1;
}

int main()
{
	int n,to_find,lower_index,upper_index;
	cin>>n;

	vector<int> arr(n);
	//reading values of vector
	for(int i=0 ; i<n ; ++i)
	{
		cin>>arr[i];
	}
  //you need to sort the vector/ array if you want to apply lower_bound() , upper_bound()
  sort(arr.begin(),arr.end());
	cout<<"Enter element to find : ";
	cin>>to_find;

	lower_index = lower_bound(arr,to_find); // function calling

	if(lower_index == -1)
	{
		cout<<"Lower bound does not exists "<<endl;
	}
	else
	{
		cout<<"Found at : "<<lower_index << " " <<"and value at that index is : "<<arr[lower_index]<<endl;

	}

	upper_index = upper_bound(arr,to_find); // function calling

	if(upper_index == -1)
		cout<<"Upper bound does not exists"<<endl;
	else
		cout<<"Found at: "<<upper_index<<" and value at that index is : "<<arr[upper_index]<<endl;
	return 0;
}

// we can also use inbuit function upper_bound() and lower_bound() to check our functions
