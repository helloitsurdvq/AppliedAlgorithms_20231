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
    ll n, m;
    cin >> n >> m;
    while(n--){
        string s; cin >> s;
        ll hs = 0;
        for(ll i = 0; i < s.size(); i++){
            ll as = s[i];
            hs += as * pow(256, s.size() - i - 1);
        }
        cout << hs%m << endl;
    }
    return 0;
}