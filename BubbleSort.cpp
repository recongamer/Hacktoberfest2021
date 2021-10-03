#include <bits/stdc++.h>
using namespace std;

void swapping(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                swapping(&arr[j], &arr[j + 1]);
            }
}

void show(int arr[], int arr_size)        //to display array elements
{
    int i;
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;            //size of array
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];           
   cout << "Enter elements of an array :" << "\n";
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
    bubbleSort(arr, n);
    cout << "Sorted array elements: \n";
    show(arr, n);
    return 0;
}