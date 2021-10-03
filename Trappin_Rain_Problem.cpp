//Trapping Water Problem/ Trapping Rain Problem

// This problem is a very popular interview problem that is often asked in interviews and it is based on array.
// Here's an efficient implementation of the problem.

#include<bits/stdc++.h>  // This is to include all the required libraries
using namespace std;     //


int getWater(int container[],int size)
{
  int lmax[size], rmax[size];  // This arrays contains some preprocessed values of maximum capacity considered from both ends of an array.
  lmax[0]=container[0];
  int capacity = 0;
  
  // We dont consider the first and the last value as they are acting as the boundary for trapping water.
  for(int i = 1;i<size;i++)
    lmax[i] = max(lmax[i-1],container[i]);
 
  rmax[size-1]=container[size-1];
  for(int i = size-2;i>0;i--)
  {
  	rmax[i] = max(container[i],rmax[i+1]);
  }
  
  for(int i =1;i<size-1;i++)                   //this will interate through every position in container and will get the capacity.
    capacity += min(lmax[i],rmax[i]) - container[i];
    
    return capacity;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);   // to speed up the compilation time. Not necessary.
	
	int test_cases = 0;
	cin>> test_cases;
	
	while(test_cases--)
	{
		int size = 0;
		cin>> size;
	
		int * container = new int[size];
		for(int i =0; i<size; i++)
			cin>>container[i];
		
		cout<<"Trapping Water/Rain Capacity is : "<<getWater(container,size)<<" ltrs \n";
	}
	
	return 0;
}
