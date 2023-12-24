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

ll calc(ll num, char a, ll b){
    if(a == '+') return num += b;
    else if(a == '-') return num < b ? 0 : num -= b;
    else if(a == '*') return num *= b;
    else if(a == '/') return num /= b;
    return -1;
}

int main(){
    ll x, n;
    cin >> x >> n;
    while(n--){
        char a, c; 
        ll b, d;
        cin >> a >> b >> c >> d;
        x = max(calc(x, a, b), calc(x, c, d));
    }
    cout << x << endl;
    return 0;
}