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

// input
// 9 9
// 1 2 
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9

ll n, m;
vt<ll> adj[1001]; 
bool visited[1001];

void input(){
    cin >> n >> m;
    fo(i, 0, m){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x); // neu input la do thi co huong thi bo dong nay
    }
    fillchar(visited, false);
}

void dfs(ll u){
    cout << u << " "; // tham dinh u
    visited[u] = true; // danh dau u da duoc tham
    for(auto v : adj[u]){
        if(!visited[v]) // neu dinh v chua duoc tham
            dfs(v);
    }
}

int main(){
    faster
    input();
    dfs(1);
    return 0;
}