
#include <iostream>

using namespace std;

int main()
{
int i,n;
cin>>n;
int mx=0;
int arr[n];
for(i=0;i<n;i++){
    cin>>arr[i];
}
for(i=0;i<n;i++){
//    mx=max(mx,arr[i]);
  //  cout<<mx<<endl;
    for(int j=i;j<n;j++){
        mx+=arr[j];
        cout<<arr[j] ;
        //
    }
 //   cout<<endl;
}
    return 0;
}
