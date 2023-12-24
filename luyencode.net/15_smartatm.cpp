#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a,x) memset(a, x, sizeof (a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, a[100001], cnt = 999999, sum = 0, currCnt = 0;
vt <int> ans(100001, 1e6);

void bfs(){
    queue<pair<int, int>> q;
    q.push({m, 0});
    while(!q.empty()){
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for(int i = 0; i < n; ++i){
            if(u >= a[i]){
                if(ans[u - a[i]] == 1e6){
                    ans[u - a[i]] = v + 1;
                    q.push({u - a[i], v + 1});
                }
            }
        }
    }
}

int main(){
    faster
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    bfs();
    cout << (ans[0] == 1e6 ? -1 : ans[0]) << endl;
    return 0;
}