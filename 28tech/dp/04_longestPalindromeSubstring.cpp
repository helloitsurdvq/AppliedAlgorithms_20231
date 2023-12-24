#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define rsz resize
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fo(i, l, r) for (auto i = l; i < r; i++)
#define foE(i, l, r) for (auto i = l; i <= r; i++)
#define rfoE(i, l, r) for (auto i = l; i >= r; i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define ceil_div(a, b) (a % b == 0 ? a / b : a / b + 1)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define point pair<ll, ll>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ld EPS = 1e-9, gold = ((1+sqrt(5))/2);
using vi = vt <int>;

// cho xau S chi gom cac ki tu viet thuong va dai khong qua 1000 ky tu. 
// hay tim xau con doi xung dai nhat cua S

// f[i][j]: xau con co do dai bat dau tu chi so i va ket thuc o chi so j
// 1. neu s[i] != s[j] ==> f[i][j] = false
// 2. neu s[i] == s[j] va f[i+1][j-1] = true ==> f[i][j] = true
// ===> f[i][j] = (f[i+1][j-1] && (s[i] == s[j]))

int main(){
    faster
    string s; cin >> s;
    int n = s.size(), ans = 0;
    s = "x" + s;
    // f[i][j] = (f[i+1][j-1] && (s[i] == s[j]))
    bool f[n+1][n+1];
    fillchar(f, false);
    foE(i, 1, n) f[i][i] = true; // xau con co do dai = 1 va luon true
    // xet cac xau con co do dai tu 2 den n
    foE(len, 2, n){
        foE(i, 1, n - len + 1){
            int j = i + len - 1;
            if(len == 2 && (s[i] == s[j])) 
                f[i][j] = true;
            else 
                f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
            if(f[i][j]) ans = max(ans, len);
        }
    }
    cout << ans << endl;
    return 0;
}