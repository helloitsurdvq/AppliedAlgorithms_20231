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

ll x[100], n, row = 8, col[100], cheoXuoi[100], cheoNguoc[100], cnt = 0;
ll a[100][100];

void solve(){
    fillchar(a, 0);
    foE(i, 1, n) a[i][x[i]] = 1;
    foE(i, 1, n){
        foE(j, 1, n)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    foE(j, 1, n){
        if(col[j] && cheoXuoi[i-j+n] && cheoNguoc[i+j-1]){ // 3 vi tri phai empty
            x[i] = j;
            col[j] = cheoXuoi[i-j+n] = cheoNguoc[i+j-1] = 0; // 3 vi tri da duoc quan li
            if(i == n) {
                solve();
                cnt++;
            }
            else Try(i + 1);
            col[j] = cheoXuoi[i-j+n] = cheoNguoc[i+j-1] = 1;
        }
    }
}

int main(){
    faster
    cin >> n;
    foE(i, 1, 99)
        col[i] = cheoXuoi[i] = cheoNguoc[i] = 1;
    Try(1);
    cout << "Number of solutions: " << cnt << endl;
    return 0;
}