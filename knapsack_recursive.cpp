#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int W){
	if(W== 0 or n == 0){
		return 0;
	}
	if(wt[n-1]<=W){
		return (val[n-1] + knapsack(wt,val,n-1,W-wt[n-1])) or knapsack(wt,val,n-1,W);
	}
	else if(wt[n-1]>W){
		return knapsack(wt,val,n-1,W);
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int b[n];
	for(int i = 0; i < n; i++){
		cin >>b[i];
	}
	int W;
	cin >> W;
	cout << knapsack(a,b,n,W);
}
