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

int arr[100001], n, k, cnt = 0;

int main(){
    faster
    cin >> n >> k;
    int currSum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        currSum += arr[i];
        if(i >= k) currSum -= arr[i-k]; // Use old sum to get new sum
        if(i >= k - 1 && currSum % 2 == 0) cnt++;
    }
    cout << cnt;
    return 0;
}