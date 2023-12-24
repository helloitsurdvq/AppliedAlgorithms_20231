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

//pair<datatype1, datatype2> p;
int main(){
    pair<int, int> v = make_pair(100, 200); // tao 1 diem co toa do 100 200
    cout << v.first << endl;
    cout << v.second << endl;
    // co the dung pair long nhau de pair<pair<int, int>> v

    // co the dung tuple thay cho pair long nhau 
    tuple<int, int, int> t(1,2,3); // khoi tao tuple va trong tuple co the co nhieu kieu du lieu khac nhau 
    cout << get<2>(t) << endl;
    return 0;
}