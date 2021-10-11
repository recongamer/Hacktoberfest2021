#include <iostream>
using namespace std;

int jos(int n,int k){
    if(n==1){
        return 1;
    }
    return (jos(n-1,k)+k-1)% n+1; 
}

int main() {
	int n,k;
	cin>>n>>k;
	cout<<jos(n,k);
	return 0;
}
