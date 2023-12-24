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

bool binarySearch(int *a, int n, int x){
    int l = 0, r = n-1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] < x) l = m + 1;
        else r = m-1;
    }
    return false;
}

int main(){
    int n, x; cin >> n >> x;
    // int a[n];
    // fo(i, 0, n) cin >> a[i];
    // sort(a, a+n);
    // if (binarySearch(a, n, x)) cout << "Found!" << endl;
    // else cout << "Not found!" << endl;
    vi v(n); //since we have using vi = vt <int>;
    fo(i, 0, n) cin >> v[i];
    sort(all(v)); // all(v) = v.begin(), v.end()
    if(binary_search(all(v), x)) cout << "Found\n"; // available function
    else cout << "Not found!\n";
    return 0;
}