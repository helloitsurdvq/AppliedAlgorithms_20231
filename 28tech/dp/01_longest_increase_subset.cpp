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

//tim do dai day con tang dai nhat trong mang

int main(){
    faster
    ll n; cin >> n;
    vt<ll> a(n);
    fo(i, 0, n) cin >> a[i];
    vt<ll> l(n, 1); // truong hop co so - deu co do dai = 1 
    // l[i]: do dai day con tang dai nhat ket thuc o index i
    // l[i] = max(l[i], l[j] + 1) : a[i] > a[j] (j la nhung phan tu dung truoc j)
    fo(i, 0, n){
        fo(j, 0, i){
            if(a[i] > a[j]) 
                l[i] = max(l[i], l[j] + 1);
        }
    }
    cout  << *max_element(all(l)) << endl;
    return 0;
}