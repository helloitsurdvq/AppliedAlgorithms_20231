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

const int maxn = 100001, INF = 1e9;
int n, m, s, t, pre[maxn];
vt<pair<int, int>> adj[maxn];
 
void input(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		//adj[y].push_back({x, w});
	}
}
 
void dijkstra(int s){
	vt<ll> d(n + 1, INF); //Mang luu khoang cach duong di
	d[s] = 0;
	priority_queue<pair<int, int>, vt<pair<int, int>> , greater<pair<int, int>>> Q; //{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.se, kc = top.fi;
		if(kc > d[u]) continue;
		//Relaxation : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.fi;
			int w = it.se;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << d[i] << ' ';
}
 
void bellmanFord(int n, int start){
	vt<int> d(n + 1, INF);
	d[start] = 0;
	fo(k, 1, n-1){
		foE(u, 1, n){
			fo(j, 0, adj[u].size){
				int v = adj[u][j].v;
				int w = adj[u][j].w;
				d[v] = min(d[v], w + d[u]);
			}
		}
	}
}

int main(){
	faster
	input();
	dijkstra(s);
    return 0;
}