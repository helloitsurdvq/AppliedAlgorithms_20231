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

ll x[10000001], n, k;

void solve(){
    foE(i, 1, k) 
        cout << x[i];
    cout << endl;
}

// gia tri max co the dat duoc: n-k+i
// gia tri min co the nhan duoc la phan tu dung truoc + 1
void Try(int i){
    foE(j, x[i-1] + 1, n-k+i){
        x[i] = j;
        if(i == k) 
            solve();
        else 
            Try(i + 1);
    }
}

int main(){
    faster
    cin >> n >> k;
    x[0] = 0; // can than de khi xay dung i = 1, thi gia tri nho nhat co the nhan duoc la x[0] + 1 = 0 + 1 = 1
    Try(1);
    return 0;
}