// Theofanis has a riddle for you and if you manage to solve it, he will give you a Cypriot snack halloumi for free 
// (Cypriot cheese).

// You are given an integer n. You need to find two integers l and r such that −1018≤l<r≤1018 and 
// l+(l+1)+…+(r−1)+r=n.

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
        freopen("Error.txt", "w", stderr);
    #endif
}

int main(){
    init_code();
    // Your code goes here

    int t; cin>>t;
    while(t--){
    	ll n; cin>>n;
    	cout<<-n+1<<" "<<n<<endl;
    }   
    return 0;
}