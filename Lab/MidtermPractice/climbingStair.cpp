#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/*
Explanation: The tabulation solution eliminates recursion and uses a bottom-up approach to solve 
the problem iteratively. It creates a DP table (dp) of size n+1 to store the number of ways to 
reach each step. The base cases (0 and 1 steps) are initialized to 1 since there is only one way
to reach them. Then, it iterates from 2 to n, filling in the DP table by summing up the values 
for the previous two steps. Finally, it returns the value in the last cell of the DP table, 
which represents the total number of ways to reach the top.
*/

int climbStairs(int n){
    if (n == 0 || n == 1)
        return 1;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = dp[n];
    return ans;
}

int main(){
    int n; cin >> n;
    cout << climbStairs(n);
    return 0;
}