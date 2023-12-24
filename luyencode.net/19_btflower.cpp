#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int m, n, a[21][21], res = 0, cnt = 0; // m rows, n columns
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void input(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}

void Try(int x, int y){
    cnt++;
    a[x][y] = cnt;
    if(cnt = n * n){
        
    }
}

int main(){
    faster
    input();

    return 0;
}