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

const int MOD = 1e9 + 7, MaxN = 1e6 + 1;
int n, a[MaxN], tmp[MaxN], cnt = 0;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
}

int mergeParts(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, cnt = 0;
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            cnt = (cnt + (mid - i + 1)) % MOD;
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];
    for (i = left; i <= right; i++) a[i] = tmp[i];
    return cnt;
}

int mergeSort(int left, int right) {
    int mid, cnt = 0;
    if (right > left) {
        mid = (right + left) / 2;
        // Inversion count is sum of inversions of left-part, right-part and inversions in merging.
        cnt = (cnt + mergeSort(left, mid)) % MOD;
        cnt = (cnt + mergeSort(mid + 1, right)) % MOD;
        cnt = (cnt + mergeParts(left, mid, right)) % MOD;
    }
    return cnt;
}


int main(){
    faster
    input();
    cout << mergeSort(1, n);
    return 0;
}