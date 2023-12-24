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

int a[8][8] = {0};
int X[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = {-1, 1,-2, 2,-2, 2,-1, 1};
int cnt = 0, n;

void solve(){
    fo(i, 0, n){
        fo(j, 0, n) cout << a[i][j] << " ";
        cout << endl; 
    }
}

// void Try(int x, int y){
//     fo(i, 0, 8){
//         int u = x + X[i], v = y + Y[i];
//         if(u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0){
//             cnt++;
//             a[x][y] = cnt;
//             if(cnt == n * n){
//                 solve();
//                 exit(0);
//             } else Try(u, v);
//             cnt--;
//             a[x][y] = 0;
//         } 
//     }
// }

void Try(int x, int y){
    cnt++;
    a[x][y] = cnt;
    if(cnt == n * n){
        solve();
        exit(0);
    }
    fo(i, 0, 8){
        int u = x + X[i], v = y + Y[i];
        if(u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0){
            Try(u, v); 
        } 
    }
    cnt--;
    a[x][y] = 0;
}

int main(){
    cin >> n;
    int x, y;
    cout << "Initial location: ";
    cin >> x >> y;
    Try(x, y);
    cout << "Unable to find the path\n";
    return 0;
}