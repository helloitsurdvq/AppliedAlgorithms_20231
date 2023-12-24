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

#define N 50
int n, K, c[N][N];
int c_min = INT_MAX;
int X[N];           // Route of bus is 0 -> X[1] -> ... -> X[2 * n] -> 0.
int appeared[N]{};  // True means v has appeared in partial solution.
int load = 0;       // Currently empty
int f = 0;
int f_min = INT_MAX;

void input() {
    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && c_min > c[i][j]) c_min = c[i][j];
        }
    }
}

void solution() {
    if (f + c[X[2 * n]][0] < f_min) {
        f_min = f + c[X[2 * n]][0];
    }
}

bool check(int v, int k) {
    if (appeared[v] == true) return false;
    if (v <= n) {  // Pickup point
        if (appeared[v + n] == true)
            return false;  // Drop-off point v + n is before pickup point v.
        if (load + 1 > K) return false;
    } else {  // Drop-off point
        if (appeared[v - n] == false)
            return false;  // Corresponding pickup point wasn't appeared.
    }
    return true;
}

// Try values for X[k], aware of X[1] -> X[k - 1]
void Try(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            X[k] = v;       // Route goes to point v.
            if (v <= n)     // Pickup point
                load += 1;  // One person gets in.
            else
                load -= 1;           // One person goes down.
            f += c[X[k - 1]][X[k]];  // Update distance (As in TSP)
            appeared[v] = true;
            if (k == 2 * n)
                solution();
            else {
                // Lower bound of length of complete route
                int g = f + c_min * (2 * n + 1 - k);
                if (g < f_min)  // As in TSP
                    Try(k + 1);
            }
            appeared[v] = false;
            f -= c[X[k - 1]][X[k]];
            if (v <= n)
                load -= 1;
            else
                load += 1;
        }
    }
}

int main() {
    faster
    input();
    Try(1);
    cout << f_min << "\n";
    return 0;
}