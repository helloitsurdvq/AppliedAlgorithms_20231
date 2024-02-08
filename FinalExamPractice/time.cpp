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

int time(string s){
    int timeS = stoi(s.substr(6, 2)) + 60 * stoi(s.substr(3, 2)) + 3600 * stoi(s.substr(0, 2));
    return timeS;
}

int main(){
    faster
    string s; cin >> s;
    cout << time(s);
    return 0;
}