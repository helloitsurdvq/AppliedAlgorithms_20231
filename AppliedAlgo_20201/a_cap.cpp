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

void solve(){
        ll cnt = 0;
        ll n1; cin >> n1;
        vt<ll> a1(n1);
        fo(i, 0, n1) 
            cin >> a1[i];
        sort(all(a1));
        ll n2; cin >> n2;
        vt<ll> a2(n2);
        fo(i, 0, n2) {
            cin >> a2[i];
            if(binary_search(all(a1), a2[i]))
                cnt++;
        }
        cout << cnt << endl;
}

int main(){
    faster
    int t; cin >> t;
    while(t--){
        solve();
        return 0;
    }
}