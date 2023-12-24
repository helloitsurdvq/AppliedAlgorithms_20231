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

const ll maxn = 21;
ll n, a[maxn][maxn], x[maxn], c[maxn][maxn], bestCost;
int visited[maxn]; 

void solve(){

}

void Try(int i){
    foE(j, 2, n){
        if(!visited[j]){
            x[i] = j;
            visited[j] = 1;
            if(i == n) solve();
            else Try(i + 1);
            visited[j] = 0;
        }
    }
}

int main(){
    faster
    cin >> n;
    foE(i, 1, n){
        foE(j, 1, n){
            cin >> a[i][j];
        }
    }
    
    cout << bestCost;
    return 0;
}