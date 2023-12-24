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

ll n, m, a[1000001], cnt = 0;
int main(){
    faster
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int i = 0, j = n - 1;
    while(i < j){
        if(a[i] + a[j] == m){
            cnt++; i++;
        } else if(a[i] + a[j] < m) i++;
        else j--;
    }
    cout << cnt;
    return 0;
}