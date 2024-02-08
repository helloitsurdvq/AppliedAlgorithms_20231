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

int n, a[20], ans = 99999, checked[20];

void input(){
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Try(int i, int h, int day){
    if(i == n){
        ans = min(day, ans);
        return;
    }
    int ok = 0; // unable to pick a new class, move on to next day
    for(int j = 0; j < n; j++){
        if(!checked[j] && h + a[j] <= 6){
            checked[j] = 1;
            ok = 1; // can pick more class
            Try(i + 1, h + a[j], day);
            checked[j] = 0;
        }
    }
    if(!ok) Try(i, 0, day + 1); // move on to new day
}

int main(){
    faster;
    input();
    Try(0, 0, 1); // starting from day 1 
    cout << ans;
    return 0;
}