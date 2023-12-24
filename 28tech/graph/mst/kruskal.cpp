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

// 6 9
// 1 2 12
// 1 3 4
// 2 3 1
// 2 4 5
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

struct edge{
	int u, v;
	int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];
vt<edge> canh;

void make_set(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false; // khong the gop a, b vao voi nhau
	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] + sz[b];
	return true;
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		edge e;
		e.u = x; e.v = y; e.w = w;
		canh.pb(e);
	}
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void kruskal(){
	vt<edge> mst; //Tao cay khung cuc tieu rong
	int d = 0;
	sort(canh.begin(), canh.end(), cmp); //Sort danh sach canh theo chieu dai tang dan
	for(int i = 0; i < m; i++){
		if(mst.size() == n - 1) break;
		edge e = canh[i]; // chon canh e la canh nho nhat
		if(Union(e.u, e.v)){
			mst.pb(e);
			d += e.w;
		}
	}
	if(mst.size() != n - 1){
		cout << "Unconnected graph\n";
	} else{
		cout << d << endl;
		// for(auto it : mst){
		// 	cout << it.u << " " << it.v << " " << it.w << endl;
		// }
	}
}

int main(){
	input();
	make_set();
	kruskal();
    return 0;
}