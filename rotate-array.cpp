#include<iostream>
using namespace std;

void reverse(vector<int> &A, int s, int e)
{
    for(int i = s; i <= (e+s)/2; i++){
        int temp = A[i];
        A[i] = A[e-i+s];
        A[e-i+s] = temp;
    }
}

void rotate(vector<int>& A, int k) 
{
    int i,n=A.size();
    k = k % n;
    if(k == 0) return;
    reverse(A, 0, n-1);
    reverse(A, 0, k-1);
    reverse(A, k, n-1);
}
int main()
{
    vector<int>A{4,5,6,7,0,1,2};
    rotate(A,3);

    for(int i = 0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
}
