#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
            swap(arr[j], arr[j+1]);
            swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main(){
    int arr[]={112,34,1,31,32,4243,413};
    int n= sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

}
