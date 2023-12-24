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

stack<int> s;
int main(){    
    while(1){
        string cmd; cin >> cmd;
        if(cmd == "#") break;
        else if(cmd == "PUSH"){
            int x; cin >> x;
            s.push(x);
        } else if(cmd == "POP"){
            if(s.empty()) cout << "NULL" << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        } 
    }   
    return 0;
}