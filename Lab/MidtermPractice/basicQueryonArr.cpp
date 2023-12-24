// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int main(){ 
    faster
    // freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int a[10001];
    for(int i = 0; i < n; i++) cin >> a[i];
    string cmd; cin >> cmd;
    while(1){
        string c; cin >> c;
        if(c == "find-max"){
            int m = -9999;
            for(int i = 0; i < n; i++){
                if(a[i] > m) m = a[i];
            }
            cout << m << endl;
        }
        else if(c == "find-min"){
            int m = 9999;
            for(int i = 0; i < n; i++){
                if(a[i] < m) m = a[i];
            }
            cout << m << endl;
        }
        else if(c == "find-max-segment"){
            int x, y; cin >> x >> y;
            int m = -9999;
            for(int i = x-1; i <= y-1; i++){
                if(a[i] > m) m = a[i];
            }
            cout << m << endl;
        }
        else if(c == "sum"){
            int sum = 0;
            for(int i = 0; i < n; i++) sum += a[i];
            cout << sum << endl;
        }
        else if(c == "***") break;
    }
    return 0;
}