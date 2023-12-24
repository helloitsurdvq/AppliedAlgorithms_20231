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

int n, k, m, a[101], prevCheck = 0; // prevcheck for avoiding giao hoan cases
int currSum = 0, cnt = 0;
int checked[101] = {0};
//find the number of ways to select k elements from an array such that the sum equal to m
void input(){
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Try(int i, int currSum){
    if(i == k){
        if(currSum == m) cnt++;
        return;
    }
    for(int j = prevCheck; j < n; j++){
        if(currSum < m){
            if(!checked[j]){
                prevCheck = j; // prevcheck for avoiding giao hoan cases
                checked[j] = 1; 
                Try(i + 1, currSum + a[j]);
                checked[j] = 0;
                prevCheck = 0;
            }
        }
    }
}

int main(){
    faster
    input();
    Try(0, 0);
    cout << cnt;
    return 0;
}