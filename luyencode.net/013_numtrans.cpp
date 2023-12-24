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

int a[100001], checked[1000], n, res = 0;

int concat(int a, int b){
    ostringstream oss;
    oss << a << b;
    istringstream iss(oss.str());
    int c;
    iss >> c;

    return c;
}

void Try(int i, int currMax){
    if(i > n) return;
    if(currMax > res) res = currMax;
    for(int j = 0; j < n; ++j){
        if(!checked[j]){
            checked[j] = 1;
            Try(i + 1, concat(currMax, a[j]));
            checked[j] = 0;
        }
    }
}

int main (){
    faster
    cin >> n;
    for(int i = 0; i < n ; ++i){
        cin >> a[i];
    }
    Try(0, 0);
    cout << res;
    return 0;
}