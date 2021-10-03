#include <bits/stdc++.h>
using namespace std;

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    int a1 = 0, a2 = 0;

    for (int i = 0; i < size1 + size2; i++)
    {
        if(size1==0)
        {
            ans[i]=arr2[i];
        }
        else if(size2==0)
        {
            ans[i]=arr1[i];
        }
        else if ((arr1[a1] <= arr2[a2])&&(a1<size1)&&(a2<size2))
        {
            ans[i] = arr1[a1];
            a1++;
        }
        else if((arr1[a1] > arr2[a2])&&(a1<size1)&&(a2<size2))
        {
            ans[i] = arr2[a2];
            a2++;
        }
        else if(a1=size1)
        {
            ans[i]=arr2[a2];
            a2++;
        }
        else if(a2=size2)
        {
            ans[i]=arr1[a1];
            a1++;
        }
        else if(a1==size1&&a2==size2)
        {
            break;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size1;
        cin >> size1;

        int *arr1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> arr1[i];
        }

        int size2;
        cin >> size2;

        int *arr2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> arr2[i];
        }

        int *ans = new int[size1 + size2];

        merge(arr1, size1, arr2, size2, ans);

        for (int i = 0; i < size1 + size2; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] ans;
    }
}
