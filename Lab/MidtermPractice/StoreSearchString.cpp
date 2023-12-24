#include <bits/stdc++.h> 
using namespace std;
int main() {
    unordered_set<string> database;
    while (1) {
        string key; cin >> key;
        database.insert(key);
        if(key == "*") break;
    }
    while (1) {
        string cmd, actionKey;
        cin >> cmd;
        if (cmd == "find") {
            cin >> actionKey;
            cout << (database.count(actionKey) > 0) << endl;
        } else if (cmd == "insert") {
            cin >> actionKey;
            auto result = database.insert(actionKey);
            cout << (result.second ? 1 : 0) << endl;
        } else if (cmd == "***") break;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define pb push_back
// #define pf push_front
// #define fi first
// #define se second
// #define sz(a) int((a).size())
// #define fillchar(a,x) memset(a, x, sizeof (a))
// #define vt vector
// #define all(a) a.begin(), a.end()
// #define rall(a) a.rbegin(), a.rend()
// #define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// vt<string> st;
// int main(){
//     while(1){
//         string s; cin >> s;
//         if(s == "*") break;
//         st.push_back(s);
//     }
//     while(1){
//         string cmd; cin >> cmd;
//         if(cmd == "find"){
//             string find; cin >> find;
//             int check = 0;
//             for(string s : st){
//                 // cout << s << " ";
//                 if(s == find){
//                     check = 1; 
//                     break;
//                 }
//                 else check = 0;
//             }
//             cout << check << endl;
//         } else if(cmd == "insert"){
//             string x; cin >> x;
//             int check = 0;
//             for(string s : st){
//                 // cout << s << " ";
//                 if(s == x){
//                     check = 0; 
//                     break;
//                 }
//                 else {
//                     check = 1;
//                     st.push_back(x);
//                 }
//             }
//             cout << check << endl;
//         } else if(cmd == "***") break;
//     }
//     return 0;
// }
