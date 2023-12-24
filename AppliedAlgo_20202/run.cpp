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

ll n, a[100005], res = 0;

void input(){
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> a[i];
}

void solve(){
    for(int i = 0; i < n; i++){
        if(a[i+1] < a[i]) res++;
    }
}

int main(){
    faster
    input();
    solve();
    cout << res;
    return 0;
}