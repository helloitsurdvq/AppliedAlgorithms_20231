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

// dp[i][j]: gia tri lon nhat cua cai tui khi lua chon cac do vat 1,2,3...i va co trong luong j
// max(dp[i][j], dp[i-1][j-w[i]] + v[i]): co the dua 1 do vat vao hoac khong dua

// 7 22 
// 10 3 22 50 83 16 41        ==> output: 196 
// 99 97 54 19 60 70 48

int main(){
    faster
    ll w[1000], v[1000], n, s;
    cin >> n >> s;
    foE(i, 1, n) cin >> w[i];
    foE(i, 1, n) cin >> v[i];
    ll dp[n + 1][s + 1];
    fillchar(dp, 0);
    foE(i, 1, n){
        foE(j, 1, s){
            dp[i][j] = dp[i - 1][j]; // khong lua chon do vat thu i vao trong tui
            if(j >= w[i]) // co the dua do vat thu i vao tui
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][s]<< endl;
    return 0;
}