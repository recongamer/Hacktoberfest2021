#include<iostream>
using namespace std;
int equilibrium(int a[],int n){
	int leftSum = 0;
	int rightSum = 0;
	int pos = -1;
	for(int i = 0; i < n; i++){
		rightSum += a[i];
	}
	for(int j = 0; j < n; j++){
		rightSum -= a[j];
		if(leftSum == rightSum){
			pos = j+1;
			break;
		}
		leftSum += a[j];

	}
	return pos;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0 ; i < n; i++){
			cin >>a[i];
		}
		cout << equilibrium(a,n) << endl;
	}
}
