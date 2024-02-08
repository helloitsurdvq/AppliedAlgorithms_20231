#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s, final;
priority_queue <string> pq;
int n, checked[100001], prevCheck = 0;

void Try(int i, string cur){
    if(i == n){
        pq.push(cur);
        return;
    }
    for(int j = prevCheck; j < s.size(); j++){
        if(!checked[j]){
            checked[j] = 1;
            prevCheck = j;
            Try(i+1, cur+s[j]);
            checked[j] = 0;
        }
    }
}

int main(){
    faster;
    cin >> s >> n;
    Try(0, "");
    cout << pq.top();
    return 0;
}