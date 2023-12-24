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

stack<int> c; 
queue<int> h;
int n, a[100005];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) c.push(a[i]);
    string cmd; cin >> cmd;
    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] == 'C'){
            int dc = c.top();
            c.pop(); 
            h.push(dc);
        } else if(cmd[i] == 'H'){
            int dh = h.front();
            h.pop();
            c.push(dh); 
        }
    }
    while(!c.empty()){
        cout << c.top() << " ";
        c.pop();
    }
    return 0;
}