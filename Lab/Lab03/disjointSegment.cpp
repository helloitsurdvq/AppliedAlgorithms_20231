#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
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

int n;
pair<int, int> a[100001];
// a[i] -> segment
// a[i].first -> left coordinate
// a[i].second -> right coordinate

void input(){
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> a[i].fi >> a[i].se;
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.se < b.se;
}

void solve(){
    int res = 0, end = -1;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n ; i++){
        if(a[i].fi > end){
            res++;
            end = a[i].se;
        }
    }
    cout << res << endl;
}

int main(){
    faster
    input();
    solve();
    return 0;
}