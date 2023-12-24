#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define rsz resize
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fo(i, l, r) for (auto i = l; i < r; i++)
#define foE(i, l, r) for (auto i = l; i <= r; i++)
#define rfoE(i, l, r) for (auto i = l; i >= r; i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define ceil_div(a, b) (a % b == 0 ? a / b : a / b + 1)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define point pair<ll, ll>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ld EPS = 1e-9, gold = ((1+sqrt(5))/2);
using vi = vt <int>;
// unfinished
int main(){
    faster
    ll n, sum; cin >> n >> sum;
    map<ll, ll> mp;
    vt<ll> v;
    fo(i, 0, n){
        ll x; cin >> x;
        v.pb(x);
    }
    fo(i, 0, n-1){
        fo(j, i+1, n){
            if(v[i] + v[j] == sum) mp.insert({i+1, j+1});
        }
    }
    if(mp.empty()){
        cout << "IMPOSSIBLE\n";
    } else{
        for(auto x : mp){
            cout << x.fi << " " << x.se << endl;
        }
    }
    return 0;
}