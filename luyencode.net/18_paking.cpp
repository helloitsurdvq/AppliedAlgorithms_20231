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

int n, v, a[35], checked[35] = {0}, sum = 0;

void input(){
    cin >> n >> v;
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Try(int i, int maxSum){
    if(i > n) return;
    if(maxSum <= v){
        if(maxSum > sum) sum = maxSum;
    } else return;
    for(int j = 0; j < n; j++){
        if(!checked[j]){
            checked[j] = 1;
            Try(i + 1, maxSum + a[j]);
            checked[j] = 0 ;
        }
    }
}

int main(){
    faster
    input();
    Try(0, 0);
    cout << sum;
    return 0;
}