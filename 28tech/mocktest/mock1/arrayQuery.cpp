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

//co the dung multiset de AC
int main(){
    faster
    ll n, numStep; cin >> n;
    vt<ll> v(n);
    fo(i, 0, n) cin >> v[i];
    cin >> numStep;
    fo(i, 0, numStep){
        int step; cin >> step;
        if (step == 1){
            ll ele; cin >> ele;
            v.push_back(ele);
        } else if(step == 2){
            ll ele; cin >> ele;
            v.erase(remove(all(v), ele), v.end());
        } else if(step == 3){
            ll x; cin >> x;
            sort(all(v));
            if(binary_search(all(v), x)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}