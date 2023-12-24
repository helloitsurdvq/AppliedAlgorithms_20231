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
#define Point pair<int, int>
int main(){
    faster
    int n, m, r, c; cin >> n >> m >> r >> c;
    r--; c--;
    int walls[n][m], steps[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> walls[i][j];
        }
    }
    queue<Point> fringe;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    fringe.push({r, c}); // the starting Point
    walls[r][c] = 1;
    steps[r][c] = 0;
    while (!fringe.empty()) {
        Point currPoint = fringe.front();
        fringe.pop();
        for (int i = 0; i < 4; i++) {
            int x = currPoint.fi + dx[i];
            int y = currPoint.se + dy[i];
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
                cout << steps[currPoint.fi][currPoint.se] + 1;
                return 0;
            }
            if (!walls[x][y]) {
                fringe.push({x, y});
                steps[x][y] = steps[currPoint.fi][currPoint.se] + 1;
                walls[x][y] = 1;
            }
        }
    }
    cout << -1;
    return 0;
}