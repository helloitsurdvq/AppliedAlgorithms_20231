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
    string s; cin >> s;
    if(s[4] != '-' || s[7] != '-') cout << "INCORRECT\n";
    else if(s[8] >= '4' || s[5] < '0' || s[5] > '1') cout << "INCORRECT\n";
    else if(s[5] == '1' && s[6] >= '3') cout << "INCORRECT\n";
    else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-') s[i] = ' ';
            if((i == 5 || i == 8) && s[i] == '0') continue;
            cout << s[i];
        }
    }
    return 0;
}