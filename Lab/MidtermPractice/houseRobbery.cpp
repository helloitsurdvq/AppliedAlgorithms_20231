#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main(){
    faster
    int n; cin >> n;
    vector<int> num(n+1);
    for(int i = 0; i < n; i++) cin >> num[i];
    vector<int> dp(n+1);
    if(n >= 1) dp[0] = num[0];
    if(n >= 2) dp[1] = max(num[0], num[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + num[i]);
    }
    int ans = dp[n-1];
    cout << ans;
    return 0;
}