//  this is one of the best way to search element in any array we also have linear search method but binary search have less time complexity as compare to linear search so we use this method to search elements in element

#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int num)
{
    int start = 0; //assigning starting point
    int end = n;   //assigning ending point
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (arr[middle] == num)
        {
            return middle;
        }
        else if (arr[middle] < num)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int n; // size of array
    cin >> n;
    int arr[n]; //decleration of array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; //input elements in array
    }
    int num = 0;
    cout << "Enter number you want to search: ";
    cin >> num; // taking input of searching element
    int pos = binarysearch(arr, n, num);
    if (pos == -1)
    {
        cout << "Element not found in array" << endl;
    }
    else
    {
        cout << pos << endl;
    }
    return 0;
}
