#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
// ordered_set : insert , erase , find , upper_bound() , lower_bound()
// ordered_set : order_of_key , find_by_order
#define ll long long
#define vt vector
#define el '\n'
#define ull unsigned long long
#define fo(i, k, n, m) for (ll i = k; i < n; i += m)
#define rfo(i, k, n, m) for (ll i = k; i > n; i -= m)
#define ceil_div(a, b) (a % b == 0 ? a / b : a / b + 1)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define INF ULONG_MAX
#define NINF INT_MIN
#define pi 3.14159265359
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    ll k; cin >> k;
    vt<char> a[26];
    fo(i, 0, s.size(), 1) a[s[i] - 'a'].push_back(i);
    ll cnt = 0, n = s.size(), prev = -1;
    string ans = "";
    while (cnt < k){
        rfo(i, 25, -1, 1){
            if (a[i].empty()) continue;
            ll down = lower_bound(a[i].begin(), a[i].end(), prev) - a[i].begin();
            ll up = upper_bound(a[i].begin(), a[i].end(), n - k + cnt) - a[i].begin() - 1;
            if (down > up || down == a[i].size()) continue;
            prev = a[i][down] + 1;
            cnt++;
            ans += s[a[i][down]];
            break;
        }
    }
    cout << ans << el;
}