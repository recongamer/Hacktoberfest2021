#include <bits/stdc++.h>
using namespace std;

void heap(int a[], int n, int val)
{
    int max = val;
    int l = 2 * val + 1;
    int r = l + 1;
    if (l < n && a[l] > a[max])
        max = l;
    if (r < n && a[r] > a[max])
        max = r;
    if (max != val)
    {
        swap(a[val], a[max]);
        heap(a, n, max);
    }
}

void heapSort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {

        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

void display(int a[], int n)         //to display array elements
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{    int n;       //size of array
    cout<<"Enter no. of Elements : ";
         cin>>n;
          int ha[n];
        cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>ha[i];
    }
    cout << "Elements before Sorting is " << endl;
    display(ha, n);
    heapSort(ha, n);
    cout << " Sorted array using Heap Sort is " << endl;
    display(ha, n);
}