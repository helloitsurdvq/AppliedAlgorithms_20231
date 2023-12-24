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

ll x[10000001], n, used[10000001]; // danh dau 1 phan tu da su dung

void solve(){
    foE(i, 1, n) cout << x[i] << " ";
    cout << endl;
}

void Try(int i){
    foE(j, 1, n){
        if(!used[j]){ // xet xem lieu rang co the gan x[i] = j hay ko 
            x[i] = j;
            used[j] = 1; // danh dau phan tu j da duoc su dung
            if(i == n)
                solve();
            else Try(i + 1);
            used[j] = 0; // backtrack
        }
    }
}

int main(){
    faster
    cin >> n;
    Try(1);
    return 0;
}