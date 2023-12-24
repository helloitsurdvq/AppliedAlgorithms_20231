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

// size, insert, find, count, erase: cac ham cua set
// s.insert(x), which adds the element x to s if not already present.
// s.erase(x), which removes the element x from s if present.
// s.count(x), which returns 1 if s contains x and 0 if it doesn't.
int main(){
    set<ll> s; // khoi tao
    s.insert(100); s.insert(200); // nhet cac phan tu
    cout << s.size() << endl;

    //multiset: cac phan tu trong multiset co the giong nhau
    return 0;
}