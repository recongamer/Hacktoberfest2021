#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

//O(logN)

void multiply(ll a[2][2], ll b[2][2])
{

    ll f_value = (((a[0][0] % M) * (b[0][0] % M)) % M + ((a[0][1] % M) * (b[1][0] % M)) % M) % M;
    ll s_value = (((a[0][0] % M) * (b[0][1] % M)) % M + ((a[0][1] % M) * (b[1][1] % M)) % M) % M;
    ll t_value = (((a[0][1] % M) * (b[0][0] % M)) % M + ((a[1][1] % M) * (b[1][0] % M)) % M) % M;
    ll l_value = (((a[0][1] % M) * (b[0][1] % M)) % M + ((a[1][1] % M) * (b[1][1] % M)) % M) % M;

    a[0][0] = f_value;
    a[0][1] = s_value;
    a[1][0] = t_value;
    a[1][1] = l_value;
}

void power(ll a[2][2], ll n)
{

    if (n == 0 || n == 1)
    {
        return;
    }

    power(a, n / 2);

    multiply(a, a);

    if (n % 2 == 1)
    {
        ll m[2][2] = {{1, 1}, {1, 0}};
        multiply(a, m);
    }
}

ll fib(ll n)
{

    if (n == 0)
    {
        return 0;
    }

    ll a[2][2] = {{1, 1}, {1, 0}};
    power(a, n - 1);

    return a[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}