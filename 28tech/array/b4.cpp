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

//tim hieu lon nhat voi dieu kien so sau > so truoc
int main(){
    faster
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n];
        fo(i, 0, n){
            cin >> a[i];
        }
        ll min_val = a[0], res = -1e9;
        fo(i, 1, n){
            if(a[i] > min_val) res = max(res, a[i] - min_val);
            min_val = min(a[i], min_val);
        }
        if(res == -1e9) cout << "-1\n";
        else cout << res << endl;
    }
    return 0;
}