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

//phu hop voi cac bai toan tan suat xuat hien cua phan tu trong mang
int main(){
    map<ll, ll> mp; // (key, value)
    // mp[100] = 200; //(100, 200)
    // mp[200] = 300; //(200, 300)
    // mp.insert({300, 400});
    // cout << mp.size() << endl;
    // mp[100] = 500; //(ko phai them moi ma la thay the cap (100,200) => (100, 500))
    // cout << mp.size() << endl;

    // //duyet map
    // for(auto x : mp) cout << x.first << " " << x.second << endl;
    // // tim kiem = ham count
    // if(mp.count(500) != 0) cout << "Found\n";
    // else cout << "Not found\n";
    
    // //tim kiem = ham find
    // if(mp.find(100) != mp.end()) cout << "Found\n";
    // else cout << "Not found\n";
    // mp.erase(100); // xoa 
    
    // van dung: dem so lan xuat hien cua cac phan tu trong mang, roi in ra so luong cua cac phan tu ra 
    int n; cin >> n;
    fo(i, 0, n){
        int x; cin >> x;
        mp[x]++;
    }
    for(auto i : mp) cout << i.fi << " " << i.se << endl;
    return 0;
}