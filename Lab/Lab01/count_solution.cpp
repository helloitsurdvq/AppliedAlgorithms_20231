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

int n, m, cnt = 0;
vt<int> a(1000001);

void solution(){
    cnt++;
}

void Try(int i, int sum){
    if(i == n){
        if(sum == m) solution();
        return;
    }
    for(int j = 1; j <= (m-sum)/a[i]; ++j){
        Try(i+1, sum + j * a[i]);
    }
}

int main(){
    faster
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    Try(0, 0);
    cout << cnt;
    return 0;
}