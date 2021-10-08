#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {   
        sort(arr, arr+n);
       
        for(int i = 0;i<n;i++)
        {    
            int p = arr[i];
            if(p>0 && p<n)
            {
                if(arr[p-1] != arr[i])
                {
                    swap(arr[i], arr[p-1]) ;
                    i--;
                 }
                
                
            }
           
        }
        int i = 0;
        for(int i = 0;i<n;i++)
        {
              if(arr[i] != i+1) 
              return i+1;

       }
       return i+1;
    } 
};




int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   
