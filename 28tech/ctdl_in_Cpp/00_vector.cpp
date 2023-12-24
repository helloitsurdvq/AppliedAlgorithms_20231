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

//vector<kieu_du_lieu> ten_vector ==> array dong
//push_back(): day element vao trong vector


int main(){
    faster
    vt<int> v; int sum = 0;
    int n; cin >> n;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // cout << v.size() << endl; // kich thuoc cua vector
    // v.push_back(40);
    // cout << v.size() << endl;
    // cout << v[0] << endl; // truy cap phan tu dau tien trong vector
    // cout << v[v.size() - 1] << v.back() << endl; // truy cap phan tu cuoi cung trong vector (co hai cach)

    // //duyet cac phan tu trong vector
    // fo(i, 0, v.size()) cout << v[i] << " ";
    // cout << endl;

    // //v.end(): ko phai tro toi sau gia tri cuoi cung
    // for(vt<int>::iterator it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    fo(i, 0, n) { // khoi tao cac phan tu trong vector
        int x; cin >> x;
        v.push_back(x);
        sum += v[i];
    }
    cout << sum;
    return 0;
}