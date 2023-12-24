#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a[18], checked[18], ans = 9999;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Try(int i, int hh, int day){
    if(i == n){
        ans = min(day, ans);
        return;
    }
    int ok = 0; // unable to pick a new class => move on to next day and day++
    for(int j = 0; j < n; j++){
        if(!checked[j] && hh + a[j] <= 6){
            checked[j] = 1;
            ok = 1; // can pick more class
            Try(i+1, hh + a[j], day);
            checked[j] = 0;
        }
    }
    if(!ok) Try(i, 0, day + 1); // move on to new day
}

int main() {
    faster
    input();
    Try(0, 0, 1); // starting from day 1
    cout << ans;
    return 0;
}