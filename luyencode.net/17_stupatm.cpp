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

int n, m, a[21], checked[21], cnt = 0, prevCheck = 0;
vector<int> res;

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Try(int i, int target){
    if(target == m){
        for(int j = 0; j < res.size(); j++) cout << res[j] << " ";
        cout << endl;
        cnt++;
        return;
    }
    for (int j = prevCheck; j < n; j++){
        if(!checked[j]){
            checked[j] = 1;
            res.push_back(a[j]);
            prevCheck = j;
            Try(i+1, target + a[j]);
            res.pop_back();
            checked[j] = 0;
        }
    }
}

int main(){
    faster
    input();
    Try(0,0);
    if(!cnt) cout << "-1";
    return 0;
}