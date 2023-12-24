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
const int maxn = 1001;
 
struct canh{
	int x, y, w;
};
 
int n, m; //n : so luong dinh, m so luong canh
vt<pair<int,int>> adj[maxn];
bool used[maxn]; // used[i] = true : i thuoc tap V(MST), used[i] = false : i thuoc tap v
 
void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	memset(used, false, sizeof(used));
}
 
void prim(int u){
	vt<canh> MST; // cay khung
	int d = 0; // chieu dai cay khung
	used[u] = true; // dua dinh u vao tap V(MST)
	while(MST.size() < n - 1){
		//e = (x, y) : Cạnh ngắn nhất có x thuộc V và y thuộc V(MST)
		int min_w = INT_MAX;
		int X, Y; // luu 2 dinh cua canh e
		for(int i = 1; i <= n; i++){
			//neu dinh i thuoc tap V(MST)
			if(used[i]){ //duyet danh sach ke cua dinh i
				for(pair<int,int> it : adj[i]){
					int j = it.first, w = it.second;
					if(!used[j] && w < min_w){
						min_w = w;
						X = j; 
						Y = i;
					}
				}
			}
		}
		MST.pb({X, Y, min_w});
		d += min_w;
		used[X] = true; // cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << d << endl;
	for(canh e : MST) cout << e.x <<  " " << e.y << " " << e.w << endl;
}
 
int main(){
	input();
	prim(4);
    return 0;
}