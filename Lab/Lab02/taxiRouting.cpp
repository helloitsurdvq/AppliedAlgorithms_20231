#include <bits/stdc++.h>
using namespace std;
#define MAX 30
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, c[MAX][MAX], cmin;
bool visited[MAX];
int sol[MAX];
int f, fbest;
int load; 

bool check(int station){
    if (visited[station]) return false;
    if (station <= n && load==1) return false;
    if (station > n && !visited[station-n]) return false;
    return true;
}

void backtrack(int k){
    if (k==2*n+1){
        if (fbest > f + c[sol[2*n]][0]) fbest = f + c[sol[2*n]][0];
        return;
    }

    for (int i=1; i<=2*n; i++){
        if (check(i)){
            sol[k] = i;
            visited[i] = true;
            f += c[sol[k-1]][sol[k]];
            load = (i <= n) ? 1 : 0;
            if (f + (2*n+1-k)*cmin < fbest) backtrack(k+1);
            visited[i] = false;
            f -= c[sol[k-1]][sol[k]];
            load = (i <= n) ? 0 : 1;
        }
    }
}

int main(){
    faster
    cin >> n;
    for (int i=0; i<=2*n; i++){
        visited[i] = false;
        for (int j=0; j<=2*n; j++){
            cin >> c[i][j];
            if (cmin > c[i][j]) cmin = c[i][j];
        }
    }

    fbest = INT_MAX;
    backtrack(1);
    cout << fbest;

    return 0;
}