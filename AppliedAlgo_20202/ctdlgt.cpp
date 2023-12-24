#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n, a[8], checked[8], cnt = 0;
// C, T, D, L, G, U
// CTDLGT + TTUD = N

bool checkAns(){
    ll t1 = a[0] * 100000 + a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[1];
    ll t2 = a[1] * 1000 + a[1] * 100 + a[5] * 10 + a[2];
    ll f = t1 + t2;
    ll nonZero = (a[0] != 0) && (a[1] != 0);
    return (f == n) && nonZero;
}

void Try(int i){
    if(i == 6){
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
    cin >> n;
    Try(0); 
    cout << cnt;
    return 0;
}