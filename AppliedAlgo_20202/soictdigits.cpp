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

int nTest, n, a[8], checked[8], cnt = 0;
// H, U, S, T, O, I, C
bool checkAns(){
    ll hust = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    ll soict = a[2] * 10000 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[3];
    ll f = hust + soict;
    ll nonZero = (a[0] != 0) && (a[2] != 0);
    return (f == n) && nonZero;
    // return (f == n);
}

void Try(int i){
    if(i == 7){
        if(checkAns()) cnt++;
        return;
    }
    for(int j = 0; j <= 9; j++){
        if(!checked[j]){
            a[i] = j;
            checked[j] = 1;
            Try(i + 1);
            checked[j] = 0;
        }
    }
}

int main(){
    faster
    // cin >> nTest;
    // while(nTest--){
        
    // }
    cin >> n;
        Try(0);
        cout << cnt << endl;
    return 0;
} 