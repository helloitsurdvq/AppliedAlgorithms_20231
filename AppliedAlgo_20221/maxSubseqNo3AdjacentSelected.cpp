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

/*
Cho một dãy gồm các số nguyên dương a1, a2, ..., an. Tìm tập con đã cho của dãy
sao cho tổng các phần tử trong tập con là lớn nhất và trong tập con không chứa
3 phần tử liên tiếp nào của dãy đã cho
1 ≤ n ≤ 10^5   1 ≤ ai ≤ 10^3
Input
7
4 10 6 6 6 2 5
Output: 31
*/

int n, a[100001], sum[100001], ans = -1;
int main(){
    faster
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    // Initialize sum for 1st 3 elements
    if (n >= 1) sum[0] = a[0];
    if (n >= 2) sum[1] = a[0] + a[1];
    if (n >= 3) sum[2] = max(sum[1], max(a[1] + a[2], a[0] + a[2]));
    for(int i = 3; i < n; i++){
        sum[i] = max(sum[i-1], max(sum[i-2] + a[i], sum[i-3] + a[i] + a[i-1]));
    }
    cout << sum[n-1];
    return 0;
}