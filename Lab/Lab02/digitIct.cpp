#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
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
int n, c[8], checked[10], cnt = 0;

bool check(){
    int ict = c[0] * 100 + c[1] * 10 + c[2];
    int k62 = c[6] * 100 + 62;
    int hust = c[3] * 1000 + c[4] * 100 + c[5] * 10 + c[2];
    int f = ict - k62 + hust;
    return f == n;
}

void Try(int i){
    if(i == 7){
        if(check()) cnt++;
        return;
    }
    for(int j = 1; j <= 9; j++){
        if(!checked[j]){
            c[i] = j;
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
    cout << cnt << endl;
    return 0;
}