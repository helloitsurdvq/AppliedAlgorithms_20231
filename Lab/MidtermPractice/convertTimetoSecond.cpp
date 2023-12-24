#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    string t;
    cin >> t;
    if(t[2] != ':' || t[5] != ':') cout << "INCORRECT";
    else if((t[0] > '2')
        || (t[0] == '2' && t[1] >= '5') 
        || (t[3] < '0' || t[3] >= '6') 
        || (t[6] < '0' || t[6] >= '6') ) 
        cout << "INCORRECT";
    else{
        int time = 3600*((t[0] - '0')*10 + (t[1] - '0'))
                 + 60*((t[3] - '0')*10 + (t[4] - '0'))
                 + ((t[6] - '0')*10 + (t[7] - '0'));
        cout << time;
    }
    return 0;
}