#include <bits/stdc++.h>
using namespace std;
#define UNIQUE(S) S.erase(unique(S.begin(), S.end()), S.end())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 10000

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll mod = 1e9 + 7; // 1e9 + 7;
const ll oo = (ll)(1e18) + 7;
const double eps = 1e-3;
const double eps_cmp = 1e-7;

ll dr[] = {1, 1, 0, -1, -1, -1, 0, 1}; // S,SE,E,NE,N,NW,W,SW neighbors
ll dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; // trick to explore an implicit 2D grid graph
ll dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool valid(ll i, ll j, ll n, ll m) { return i >= 1 && i <= n && j >= 1 && j <= m; }
bool isEqual(double a, double b){
    return (abs(a - b) < eps_cmp);
}

void setIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x) { return out << x.f << ' ' << x.s; }
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x) { return in >> x.f >> x.s; }

template <typename T>
istream &operator>>(istream &in, vector<T> &a){
    for (auto &x : a) in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a){
    for (auto &x : a) out << x << ' ';
    return out;
};

vector<int> adj[100001];
int modd = 10000;

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += pow(2, adj[i].size() - 1) - 1;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setIO("A");
    solve();
    return 0;
}