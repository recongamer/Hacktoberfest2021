#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void PGE(int a[],int n){
	vector<int>v;
	stack<int>s;
	for(int i = 0; i < n; i++){
		if(s.size() == 0){
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top()> a[i]){
			v.push_back(s.top());
		}
		else if(s.size()>0 && s.top()<=a[i]){
			while(s.size() && s.top() <= a[i]){
				s.pop();
			}
			if(s.size() == 0){
				v.push_back(-1);
			}
			else{
				v.push_back(s.top());
			}
		}
		s.push(a[i]);

	}
	for(auto ans : v){
		cout << ans << " ";
	}
	cout << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i< n; i++){
			cin >> a[i];
		}
		PGE(a,n);
	}
}

