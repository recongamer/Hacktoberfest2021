// C++ implementation of Shell Sort 
#include<iostream> 
using namespace std; 
void ShellSort(int arr[], int n)
{
	for(int gap=n/2;gap>0;gap /= 2)
	{
		for(int j = gap;j<n;j+=1)
		{
			int temp = arr[j];
			int i=0;
			
			for(i=j;(i>=gap)&&(arr[i-gap]>temp);i-=gap)
			{
				arr[i] = arr[i-gap];
			}
			arr[i] = temp;
		}
	}
}

int main() 
{ 
	int n;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	int arr1[n],arr2[n];
	
	cout<<"Enter "<<n<<" integers in any order"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
		arr2[i]=arr1[i];
	}
	
	cout<<endl<<"Before Sorting: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr1[i]<<" ";
	}
		
	cout<<endl<<endl<<"SHELL SORT "<<endl;
	
	ShellSort(arr1, n); // SHELL SORT CALLED HERE
   
	cout<<endl<<"After Sorting: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr1[i]<<" ";
	}
	
   return 0; 
}
