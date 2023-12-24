#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
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

bool check(ll n){
    if (n < 0) n *= -1;
    string s = to_string(n);
    fo(i, 0, s.size()){
        if((i+1) % 2 != (s[i] - '0') % 2){
            return false;
        }
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(check(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}