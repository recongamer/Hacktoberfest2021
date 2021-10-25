#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n;
	cin>>t;
	while(t--)
	{
	cin>>n;
	vector<pair<int,int>> b(n);
	for(int i=0;i<n;i++)
	{
	cin >> b[i].first;
	b[i].second = i;
	}
	sort(b.begin(), b.end());
	vector<int> a(n,0);
	int req=0;
	for(int i=0;i<n;i++)
	{
		if(req<=b[i].first-1)
		{
			a[b[i].second]=req;
			req++;
		}
	}
	for(auto &i : a) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
