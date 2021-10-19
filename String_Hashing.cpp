#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

ll compute_hash(string s)
{
    ll hash = 0;
    ll pr = 1;
    for (ll i = 0; i < s.size(); i++)
    {
        hash = (hash + ((s[i] - 'a' + 1) * pr) % M) % M;
        pr = (pr * 31) % M;
    }
    return hash;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << compute_hash(s) << endl;

    return 0;
}