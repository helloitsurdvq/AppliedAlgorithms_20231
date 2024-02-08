#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define el '\n'
#define ull unsigned long long
#define fo(i, k, n, m) for (ll i = k; i < n; i += m)
#define rfo(i, k, n, m) for (ll i = k; i > n; i -= m)
#define ceil_div(a, b) (a % b == 0 ? a / b : a / b + 1)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define INF ULONG_MAX
#define NINF INT_MIN
#define pi 3.14159265359
const ll mod = 1e9 + 7;
map<string, set<string>> trans;
unordered_map<string, ll> money_trans;
map<string, ll> visited;
ll total_trans = 0, total_money = 0, inspect_cycle = 0;
void dfs(string s, string tmp, ll cnt, ll k){
    if (inspect_cycle) return;
    visited[tmp] = 1;
    for (auto x : trans[tmp]){
        if (x == s){
            if (cnt == k){
                inspect_cycle = 1;
                return;
            }
        }
        if (visited[x] == 0){
            dfs(s, x, cnt + 1, k);
            visited[x] = 0;
        }
    }
    visited[tmp] = 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string from_account, to_account, time_point, atm;
    ll money;
    while (1){
        cin >> from_account;
        if (from_account == "#") break;
        cin >> to_account >> money >> time_point >> atm;
        trans[from_account].insert(to_account);
        visited[from_account] = 0;
        visited[to_account] = 0;
        money_trans[from_account] += money;
        total_money += money;
        total_trans++;
    }
    string command;
    while (1){
        cin >> command;
        if (command == "#") break;
        if (command == "?number_transactions") cout << total_trans << el;
        else if (command == "?total_money_transaction") cout << total_money << el;
        else if (command == "?list_sorted_accounts"){
            for (auto x : visited) cout << x.first << " ";
            cout << el;
        } else if (command == "?total_money_transaction_from"){
            string cmd; cin >> cmd;
            cout << money_trans[cmd] << el;
        } else if (command == "?inspect_cycle"){
            string cmd; ll k;
            cin >> cmd >> k;
            dfs(cmd, cmd, 1, k);
            cout << inspect_cycle << el;
            inspect_cycle = 0;
        }
    }
}