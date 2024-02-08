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

int n, m, k, ans = 1e9, weight_mt[50][50];
vector<int> adj[50];
int need_connect_id[50], picked_list[50], picked_ck[50];

void backtrack(int id_now, int connect_cnt, int picked_cnt, int sum_edges){
    if (sum_edges >= ans) return;
    if (connect_cnt == k){
        ans = min(ans, sum_edges);
        return;
    }
    for (int i = 0; i < picked_cnt; ++i){
        for (int j = 0; j < adj[picked_list[i]].size(); ++j){
            int next_id = adj[picked_list[i]][j];
            if (picked_ck[next_id] == 0){
                picked_ck[next_id] = 1;
                picked_list[picked_cnt] = next_id;
                int next_connect_cnt = connect_cnt;
                if (need_connect_id[next_id] != -1) next_connect_cnt++;
                backtrack(next_id, next_connect_cnt, picked_cnt + 1, sum_edges + weight_mt[picked_list[i]][next_id]);
                picked_ck[next_id] = 0;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) need_connect_id[i] = -1;
    for (int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        weight_mt[u][v] = weight_mt[v][u] = w;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    int first_id;
    for (int i = 0; i < k; ++i){
        int wtf; cin >> wtf;
        first_id = wtf;
        need_connect_id[wtf] = i;
    }
    picked_ck[first_id] = 1;
    picked_list[0] = first_id;
    backtrack(first_id, 1, 1, 0);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    setIO("A");
    auto start = std::chrono::high_resolution_clock::now();
    solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    // cout << "Time taken by function: " << duration.count() << " seconds" << endl;
    return 0;
}