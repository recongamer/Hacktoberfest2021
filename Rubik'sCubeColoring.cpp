// Theofanis is starving, and he wants to eat his favorite food, sheftalia. However, he should
// first finish his homework. Can you help him with this problem?

// You have a perfect binary tree of 2k−1 nodes — a binary tree where all vertices i from 1 to
// 2k−1−1 have exactly two children: vertices 2i and 2i+1. Vertices from 2k−1 to 2k−1 don't 
// have any children. You want to color its vertices with the 6 Rubik's cube colors 
// (White, Green, Red, Blue, Orange and Yellow).

// Let's call a coloring good when all edges connect nodes with colors that are neighboring 
// sides in the Rubik's cube.


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> list;
typedef unordered_map<int,int> dict;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Macros
#define MOD 1000000007
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define COUNT(str,ch) count(str.begin(),str.end(),ch)
#define ERASE(str,index) str.erase(str.begin()+index) 
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end()) 
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end()) 
#define fill(a,v) memset(a, v, sizeof a)

void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
        // freopen("Error.txt", "w", stderr);
    #endif
}
ll power(int a, int b){
	if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2);
    ans *= ans;
    ans %= MOD;
    if(b % 2){
        ans *= a;
    }
    return ans % MOD;
}
int main(){
    init_code();
    // Your code goes here

    int n; cin>>n;
    // ll nodes = power(2, n) - 2;
    ll nodes = (1LL<<n) - 2;
    ll ans = power(4, nodes);
    ans *= 6;
    cout<<ans%MOD<<endl;
    
    return 0;
}