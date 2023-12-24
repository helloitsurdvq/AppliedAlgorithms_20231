#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

ll ans = 0;
int b[9][9];
bool filled[9][9]; // 1 if the cell value is not 0, else 0

bool markrow[9][10];
bool markcol[9][10];
bool marksquare[3][3][10];

void input(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> b[i][j];
        }
    }
}

void check(){

}

int main(){
    input();
    return 0;
}