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

// 5
// SV00001 Pham Duc Tuan
// SV00002 Pham Hong Trong Tam
// SV00003 Nguyen Duc Trong Tam
// SV00004 Luong Hong Trong Tam
// SV00005 Pham Manh Hung
// 10
// 26/11/2022 19:27:24 SV00005 code.ptit.edu.vn
// 26/11/2022 19:15:12 SV00005 code.ptit.edu.vn
// 26/11/2022 19:19:56 SV00001 code.ptit.edu.vn
// 26/11/2022 19:56:41 SV00005 code.ptit.edu.vn
// 26/11/2022 19:59:27 SV00005 code.ptit.edu.vn
// 26/11/2022 19:52:10 SV00003 facebook.com
// 26/11/2022 19:23:16 SV00004 code.ptit.edu.vn
// 26/11/2022 19:28:16 SV00004 code.ptit.edu.vn
// 26/11/2022 19:23:16 SV00005 youtube.com
// 26/11/2022 19:22:34 SV00004 youtube.com

// SV00001 Pham Duc Tuan OK
// SV00002 Pham Hong Trong Tam FAIL
// SV00003 Nguyen Duc Trong Tam FAIL
// SV00004 Luong Hong Trong Tam FAIL
// SV00005 Pham Manh Hung FAIL

int main(){
    faster
    int n; cin >> n;
    map<string, pair<string, bool>> student;
    cin.ignore();
    fo(i, 0, n){
        string s; getline(cin, s);
        vt<string> v;
        string tmp;
        stringstream ss(s);
        while(ss >> tmp) v.push_back(tmp);
        string msv = v[0], name = "";
        fo(i, 1, v.size()) name += v[i] + " ";
        name.pop_back(); // loai bo dau cach
        student[msv].first = name;
        student[msv].second = true;
    }

    int m; cin >> m;
    set<string> duthi;
    fo(i, 0, m){
        string x, y, z, t; cin >> x >> y >> z >> t;
        if(t != "code.ptit.edu.vn") student[z].second = false;
        if(t == "code.ptit.edu.vn") duthi.insert(z);
    }
    for(auto i : student){
        cout << i.first << " " << i.second.first << " ";
        if(i.second.second == false || duthi.count(i.first) == 0) cout << "FAIL\n";
        else cout << "OK\n";
    }
    return 0;
}