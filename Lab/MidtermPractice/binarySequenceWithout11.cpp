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

int n, a[21];

void solve(){
    for(int i = 0; i < n; i++) cout << a[i];
    cout << endl;
}

void Try(int i){
    if(i == n) {
        solve();
        return;
    }
    for(int j = 0; j <= 1; j++){
        if(j == 0){
            a[i] = j;
            Try(i+1);
        }
        else if(j == 1){
            if(a[i-1] == 1) continue;
            else{
                a[i] = j;
                Try(i+1);
            }
        }
    }
}

int main(){
    cin >> n;
    Try(0);
    return 0;
}