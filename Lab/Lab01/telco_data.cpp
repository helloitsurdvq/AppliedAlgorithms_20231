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

map<string, int> numberCalls, timeCall;

int checkPhone(string s){
    if(s.size() != 10) return 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

int main(){
    faster
    string cmd, fromPhone, toPhone, date;
    int h1, m1, s1, h2, m2, s2;
    int cnt = 0, falseNum = 0;
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        cin >> fromPhone >> toPhone >> date;
        cin.ignore(1, ':'); cin >> h1; 
        cin.ignore(1, ':'); cin >> m1; 
        cin.ignore(1, ':'); cin >> s1;
        cin.ignore(1, ':'); cin >> h2;
        cin.ignore(1, ':'); cin >> m2;
        cin.ignore(1, ':'); cin >> s2;   
        int t1 = 3600 * h1 + 60 * m1 + s1;
        int t2 = 3600 * h2 + 60 * m2 + s2; 
        cnt++;
        if(checkPhone(fromPhone) == 0 || checkPhone(toPhone) == 0) falseNum++;
        numberCalls[fromPhone]++;
        timeCall[fromPhone] += (t2 - t1);
    }
    
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        else if(cmd == "?check_phone_number"){
            if(!falseNum) cout << "1\n";
            else cout << "0\n";
        } else if(cmd == "?number_calls_from"){
            string s; cin >> s;
            cout << numberCalls[s] << endl;
        } else if(cmd == "?number_total_calls") cout << cnt << endl;
        else if(cmd == "?count_time_calls_from"){
            string s; cin >> s;
            cout << timeCall[s] << endl;
        }
    } 
    return 0;
}