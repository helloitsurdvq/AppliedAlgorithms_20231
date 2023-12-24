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

ll x[10000001], n;

// pseudo code for Backtracking:
// Try(int i){a[1,2,3,4,5,6,7..n]
//     for(j = <kha nang 1>; j <= <kha nang M>; j++){ //liet ke tat ca cac kha nang cua m 
//         if(<chap nhan kha nang j>){
//             X[i] = <kha nang j>;
//             <đánh dấu đã chọn x[i] nếu cần>;
//             if(i == n)
//                 <Thong bao cau hinh tim duoc>;
//             else 
//                 Try(i + 1);
//             <xóa đánh dấu đã chọn x[i] nếu cần>;
//         }
//     }
// }

void solve(){
    foE(i, 1, n) 
        cout << x[i];
    cout << endl;
}

void Try(int i){
    foE(j, 0, 1){ // kha nang la moi bit x[i] chi nhan duoc 2 gia tri 0,1
        x[i] = j;
        if(i == n)
            solve();
        else 
            Try(i+1);
    }
}

int main(){
    faster
    cin >> n;
    Try(1);
    return 0;
}