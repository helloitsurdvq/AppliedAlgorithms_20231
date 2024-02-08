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

typedef struct Trans{
    string fromAcc;
    string toAcc;
    int money;
    string timePoint;
    string atm;
} Trans;
int numTrans = 0, totalMoney = 0, inspectCycle = 0;
map<string, ll> visited;
map<string, set<string>> transs;
map<string, ll> totalMoneyTrans;

int timePeriod(string s, string t1, string t2){
    int timeS = stoi(s.substr(6, 2)) + 60 * stoi(s.substr(3, 2)) + 3600 * stoi(s.substr(0, 2));
    int timeT1 = stoi(t1.substr(6, 2)) + 60 * stoi(t1.substr(3, 2)) + 3600 * stoi(t1.substr(0, 2));
    int timeT2 = stoi(t2.substr(6, 2)) + 60 * stoi(t2.substr(3, 2)) + 3600 * stoi(t2.substr(0, 2));
    return timeS >= timeT1 && timeS <= timeT2;
}

void dfs(string s, string tmp, int cnt, int k){
    if (inspectCycle) return;
    visited[tmp] = 1;
    for(auto x : transs[tmp]){
        if(x == s){
            if(cnt == k){
                inspectCycle = 1;
                return;
            }
        }
        if(!visited[x]){
            dfs(s, x, cnt + 1, k);
            visited[x] = 0;
        }
    }
    visited[tmp] = 0;
}

int main(){
    faster
    vt<Trans> trans;
    string s;
    while(cin >> s && s != "#"){
        Trans tran;
        tran.fromAcc = s;
        cin >> tran.toAcc >> tran.money >> tran.timePoint >> tran.atm;
        trans.push_back(tran);
        numTrans++;
        totalMoney += tran.money;
        transs[tran.fromAcc].insert(tran.toAcc);
        totalMoneyTrans[tran.fromAcc] += tran.money;
        visited[tran.fromAcc] = 0;
        visited[tran.toAcc] = 0;
    }
    while(cin >> s && s != "#"){
        if(s == "?number_transactions") cout << numTrans << endl;
        else if(s == "?total_money_transaction") cout << totalMoney << endl;
        else if(s == "?list_sorted_accounts"){
            vt<string> acc;
            for(Trans tran : trans){
                acc.push_back(tran.fromAcc);
                acc.push_back(tran.toAcc);
            }
            sort(acc.begin(), acc.end());
            for(int i = 0; i < acc.size(); i++){
                if(acc[i] == acc[i-1]) continue;
                cout << acc[i] << " ";
            }
            cout << endl;
        } else if (s == "?total_money_transaction_from"){
            string from; cin >> from;
            cout << totalMoneyTrans[from] << endl;
        } else if(s == "?inspect_cycle"){
            string acc; int k;
            cin >> acc >> k;
            dfs(acc, acc, 1, k);
            cout << inspectCycle << endl;
            inspectCycle = 0;
        } else if(s == "?max_money_period"){
            string t1, t2; cin >> t1 >> t2;
            int maxMoney = 0;
            for(Trans tran : trans){
                if(timePeriod(tran.timePoint, t1, t2)) maxMoney = max(maxMoney, tran.money);
            }
            cout << maxMoney << endl;
        }
    }
    return 0;
}