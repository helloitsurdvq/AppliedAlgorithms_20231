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

typedef struct Citizen{
    string dob, fcode, mcode, alive, rcode;
} Citizen;

unordered_map<string, Citizen> db;
map<string, int> bornAt;
map<string, int> bornAtCumulative;
int flag;
int mostAlive(string code){
    Citizen cur;
    try{
        cur = db.at(code);
    } catch(const std::exception& e) {
        return 0;
    }
    if(flag == 1 && cur.fcode != "0000000" && cur.mcode != "0000000"){
        flag = 0; //has been visited
        return 1 + max(mostAlive(cur.fcode), mostAlive(cur.mcode));
    }
    if(cur.alive == "Y" && cur.fcode != "0000000" && cur.mcode != "0000000")
        return 1 + max(mostAlive(cur.fcode), mostAlive(cur.mcode));
    else return 0;
}

int main(){
    faster;
    string s;
    while(cin >> s && s != "*"){
        Citizen citizen;
        cin >> citizen.dob >> citizen.fcode >> citizen.mcode >> citizen.alive >> citizen.rcode;
        db[s] = citizen;
        bornAt[citizen.dob]++;
    }
    int cumulativeCount = 0;
    for (auto entry : bornAt) {
        cumulativeCount += entry.second; 
        bornAtCumulative[entry.first] = cumulativeCount; 
    }
    while(cin >> s && s != "***"){
        if(s == "NUMBER_PEOPLE") cout << db.size() << endl;
        else if(s == "NUMBER_PEOPLE_BORN_AT"){
            string date; cin >> date;
            try{
                cout << bornAt.at(date) << endl;
            } catch(const std::exception& e) {
                cout << 0 << endl;
            }
        } else if(s == "MOST_ALIVE_ANCESTOR"){
            string code; cin >> code;
            flag = 1;
            cout << mostAlive(code) << endl;
        } else if(s == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string d1, d2; cin >> d1 >> d2;
            int countStart = (bornAtCumulative.lower_bound(d1) != bornAtCumulative.begin()) ? prev(bornAtCumulative.lower_bound(d1))->second : 0;
            int countEnd = prev(bornAtCumulative.upper_bound(d2))->second;
            cout << countEnd - countStart << endl;
        } else if(s == "MAX_UNRELATED_PEOPLE"){
            int cnt = 0;
            for(auto i : db){
                if(i.second.fcode == "0000000" && i.second.mcode == "0000000") cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}