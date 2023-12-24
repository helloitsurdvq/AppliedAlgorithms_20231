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

int main (){
    faster
    // string x, y; cin >> x >> y;
    int x[10001], y[10001], m, n;
    // int n = x.size(), m = y.size();
    cin >> n >> m;
    fo(i, 0, n) cin >> x[i];
    fo(i, 0, m) cin >> y[i];
    int f[n+1][m+1]; // bai toan lon
    foE(i, 0, n){
        foE(j, 0, m){
            if(i == 0 || j == 0) f[i][j] = 0; // neu 1 trong 2 xau la rong thi kqua luon = 0
            else{
                if(x[i-1] == y[j-1]){ // xet ky tu cuoi cung trong xuat
                    f[i][j] = f[i-1][j-1] + 1;
                } else{
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}