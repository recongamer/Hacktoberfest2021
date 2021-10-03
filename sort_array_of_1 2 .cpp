// 1 2 2 1 2
//1 1 2 2 2
#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n){
	int c1 = 0;
	int c2 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			c1++;
		}
		else{
			c2++;
		}
	}
	int j = 0;
	for(int k = 0; k < c1; k++){
		a[j++] = 1;
	}
	for(int l = 0; l < c2; l++){
		a[j++] = 2;
	}
	for(int i = 0 ; i < n; i++){
		cout << a[i] << " ";
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] ;
	}
	solve(a,n);
}
