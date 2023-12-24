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

// delete max-value element in array
priority_queue <int> pq;
int n; 

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }
}

void solve(){
    while(1){
        string cmd; cin >> cmd;
        if (cmd == "*") break;
        else if (cmd == "insert"){
            int x; cin >> x;
            pq.push(x);
        }
        else if (cmd == "delete-max"){
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}

int main(){
    faster
    // freopen("input.txt", "r", stdin);
    input();
    solve();
    return 0;
}