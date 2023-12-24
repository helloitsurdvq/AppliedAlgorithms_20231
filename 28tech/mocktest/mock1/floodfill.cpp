#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
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

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // duyet 8 o xung quanh
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, a[100][100], cnt = 0;

void input(){
    cin >> n >> m;
    foE(i, 1, n){
        foE(j, 1, m) cin >> a[i][j];
    }
}

void Try(int i, int j, int x){ // loang tu 1 o hien tai sang cac o chung dinh 
    cnt++;
    a[i][j] = 1000; // danh dau la da duoc duyet
    fo(k, 0, 8){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >=1 && j1 <= m && a[i1][j1] == x){
            Try(i1, j1, x);
        }
    }
}

int main(){
    faster
    input();
    map<int, vector<int>> mp;// luu tru ket qua
    foE(i, 1, n){
        foE(j, 1, m){
            if(a[i][j] != 1000){
                int tmp = a[i][j];
                cnt = 0; // reset dien tich 
                Try(i, j, tmp);
                mp[tmp].push_back(cnt);
            }
        }
    } 
    for(auto it : mp){
        sort(all(it.second)); // sort cac vung dien tich
        cout << it.first << " : ";
        for(auto x : it.second) cout << x << " ";
        cout << endl;
    }
    return 0;
}