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

int n, m;
const int maxn = 1001;
vt<int> ke[maxn];
int color[maxn];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    fillchar(color, -1);
}

// 0 : RED , 1 : BLUE
bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0; // 0 : RED
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(color[x] == -1){
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if(color[x] == color[v]) return false;
        }
    }
    return true;
}

bool dfs(int u, int par){
    color[u] = 1 - color[par];
    for(int v : ke[u]){
        if(color[v] == -1){
            if(!dfs(v, u)) return false; // return dfs(v, u)
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

int main(){
    input();
    bool check = true;
    color[0] = 1;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(i, 0)){
                check = false; 
                break;
            }
        }
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}