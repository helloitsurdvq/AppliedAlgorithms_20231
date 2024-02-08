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
    faster;
    ll n, m; cin >> n >> m;
    ll x = max(m, n), y = min(m, n);
    ll ans = 1;
    for(ll i = 1; i < 1e5; i++){
        if(i % 2 == 1){
            if(x < i*i/2 + 1 || y < i*i/2) break;
        } else{
            if(x < i*i/2 || y < i*i/2) break;
        }
        ans = i;
    }
    cout << ans;
    return 0;
}