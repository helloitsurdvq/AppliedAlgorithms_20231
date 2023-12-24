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

ll n, s, c[30001], p[30001], checked[30001], maxProfit = 0, currFund = 0;
vt <vt<ll>> ans(30001, vt<ll> (26, 0));

// void Try(ll i, ll max){
//     if(i > n) return;
//     if(max > maxProfit) maxProfit = max;
//     for(int j = 0; j < n; ++j){
//         if(currFund <= s){
//             if(!checked[j]){
//                 checked[j] = 1;
//                 currFund += c[j];
//                 if(currFund < s) 
//                     Try(i+1, max + p[j]);
//                 checked[j] = 0;
//                 currFund -= c[j];
//             }
//         }
//     }
// }

void bfs(){
    queue<pair<int, int>> q;
    q.push({s, -1});
    while(!q.empty()){
        ll u = q.front().fi;
        ll v = q.front().se;
        q.pop();
        for(ll i = v + 1; i < n; ++i){
            if(u >= c[i]){
                for(ll j = 0; j < i; ++j){
                    if(ans[u - c[i]][i] <= ans[u][j] + p[i]){
                        ans[u - c[i]][i] = ans[u][j] + p[i];
                        maxProfit = max(maxProfit, ans[u - c[i]][i]);
                    }
                }
                q.push({u - c[i], i});
            }
        }
    }
}

int main(){
    faster
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> c[i];
    for(int i = 0; i < n; ++i) cin >> p[i];
    bfs();
    cout << maxProfit << endl;
    return 0;
}