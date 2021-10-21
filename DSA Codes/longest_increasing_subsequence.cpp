// contributed by Ankit Kumar Srivastava for Hacktoberfest 2021

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll check(vector<ll>& v)
{
    if (v.size() == 0)
        return 0;

    vector<ll> tail(v.size(), 0);
    ll length = 1;

    tail[0] = v[0];

    for (ll i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i];
    }
    cout<< "Length of Longest Increasing Subsequence is : "<< check(v);
    return 0;
}
