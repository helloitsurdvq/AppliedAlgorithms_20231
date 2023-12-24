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

// 5 6
// 1 2
// 2 3
// 3 1
// 2 4
// 4 5
// 2 5

int n, m;
set<int> adj[1001];
int degree[1001]; // check the degree of node

void input(){
    cin >> n >> m;
    fo(i, 0, m){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}

void euler(int v){
    stack<int> st;
    vt<int> ec;
    st.push(v);
    while(!st.empty()){
        int x = st.top();
        if(adj[x].size() != 0){
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y); // xoa(x,y)
            adj[y].erase(x);
        } else{
            st.pop();
            ec.pb(x);
        }
    }
    reverse(all(ec));
    for(int x : ec) cout << x << " ";
}

int main(){
    faster
    input();
    euler(3); // start from node 3
    return 0;
}