#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a,x) memset(a, x, sizeof (a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    faster
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n], res = 0;
        vector<ll> dp(100001, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++)
            dp[a[i]] = dp[a[i] - 1] + 1;
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}