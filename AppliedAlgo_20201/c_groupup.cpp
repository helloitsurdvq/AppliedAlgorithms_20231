#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fillchar(a,x) memset(a, x, sizeof (a))
#define vt vector
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    faster;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int final = 0;
        deque<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        while(v.size() != 1){
            int k = v.size(), res = 0;
            for(int i = 0; i < k-1; i += 2){
                int sum = v[i] + v[i+1];
                res = max(sum, res);
                v.push_back(sum);
                cout << res << " ";
            }
            cout << endl;
            if(k % 2 == 1){
                int y = v[k-1];
                v.push_back(y);
            }
            for(int i = 0; i < k; i++) v.pop_front();
            final += res;
        }
        cout << final << endl;
    }
    return 0;
}