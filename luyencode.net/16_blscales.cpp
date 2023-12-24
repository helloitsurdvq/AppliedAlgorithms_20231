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

int n, m, w, res = 0, prevCheck = 0, sum = 0;
int an[21], am[100001];
int checkedN[10001] = {0}, checkedM[100001];

vt<int> v;
set<int> st;

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> an[i];
    for(int i = 0; i < m; ++i) cin >> am[i];
}

// void Try(int i, int currW, int target){
//     if(i > n) return;
//     if(target == currW) res = 1;
//     for(int j = 0; j < n; ++j){
//         if(!checkedN[j]){
//             checkedN[j] = 1;
//             Try(i + 1, currW + an[j], target);
//             checkedN[j] = 0;
//         }
//     }
// }

void Try(int i, int sum){
    if(i > n) return;
    if(i == n){
        st.insert(sum);
        return;
    }
    Try(i + 1, sum + an[i]);
    Try(i + 1, sum);
}

int main(){
    faster
    input();
    Try(0, 0);
    // for(int i = 0; i < m; ++i){
    //     Try(0, 0, am[i]);
    //     cout << res;
    //     res = 0; // reset
    // }
    // for(int i = 0; i < m; i++){
    //     if(v.) cout << "1";
    //     else cout << "0";
    // }
    for(int i = 0; i < m; i++){
        if(st.find(am[i]) != st.end()) cout << 1;
        else cout << 0;
    }
    return 0;
}