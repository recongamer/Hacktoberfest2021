#include<iostream>
using namespace std;
void dnf_sort(int *arr ,int n)
{
    int low =0;
    int mid =0;
    int high =n-1;
    while(mid <= high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else{
            if(arr[mid]==1)
            {
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }

    }
}
void swap(int *arr ,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int arr[] ={1,0,2,2,1,0,0};
    dnf_sort(arr,7);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";

    }
     return 0;
}