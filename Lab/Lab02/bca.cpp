#include <iostream>
#include <vector>
using namespace std;
#define N 50                // (variable length array declaration not allowed at file scope)
int m;                      // number of teachers
int n;                      // number of courses
int x[N];                   // i-th course is taught by teacher x[i]
int res;                    // minimum load
int load[N];                // current load
bool conflict[N][N];        // course conflict pairs
vector<int> T[N];           // (preference list) list of teachers can be assigned to course i
void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k; 
        cin >> k;
        for (int t = 1; t <= k; t++) {
            int c;
            cin >> c;
            T[c].push_back(t);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            conflict[i][j] = false;
    int k;
    cin >> k;
    for (int r = 1; r <= k; r++) {
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}
bool check (int t, int k) {
    for (int i = 1; i <= k-1; i++) {
        if (conflict[i][k] && x[i] == t)
            return false;
    }
    return true;
}

void solution() {
    int maxLoad = 0;
    for (int t = 1; t <= m; t++) {
        maxLoad = max(maxLoad, load[t]);
    }
    if (maxLoad < res) res = maxLoad;
}

void TRY(int k) {
    for (int i = 0; i < T[k].size(); i++) {
        int t = T[k][i];
        if (check(t, k)) {
            x[k] = t;   // assign course k to teacher t
            load[t] += 1;
            if (k == n) solution();
            else {
                if (load[t] < res)
                    TRY(k + 1);
            }
            load[t] -= 1;
        }
    }
}

int main () {
    input();
    for (int t = 1; t <= m; t++)
        load[t] = 0;
    res = 1e9;
    TRY(1);
    cout << res;
    return 0;
}