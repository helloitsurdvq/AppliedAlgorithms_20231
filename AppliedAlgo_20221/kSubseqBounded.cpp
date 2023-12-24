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

/*
    Cho một dãy gồm các số nguyên a1, a2, ..., am. Một dãy con k-phần tử của dãy 
    đã cho là một dãy gồm k phần tử liên tiếp của dãy đã cho. Trọng số của dãy 
    con k-phần tử là tổng của các phần tử trong dãy con này. Cho các số nguyên 
    dương k, A và B. Tính Q là số lượng dãy con k-phần tử sao cho trọng số mỗi dãy
    con này đều lớn hơn hoặc bằng A và nhỏ hơn hoặc bằng B (A ≤ q ≤ B).
    1 ≤ n ≤ 10^5    1 ≤ k ≤ n/2    1 ≤ A ≤ B ≤ 10^6
    input: 
    6 3 4 10
    7 5 3 1 2 10
    output: 2
*/

int n, k, a, b, arr[100001], res = 0;
void solve(){
    for(int i = 0; i < n-k+1; i++){
        int sum = 0;
        for(int j = i; j < i+k; j++){
            sum += arr[j];
        }
        if(sum >= a && sum <= b) res++;
    }
    cout << res;
}

void solve2(){ // more optimal
    int currSum = 0;
    for(int i = 0; i < n; i++){
        currSum += arr[i];
        // cout << currSum << " ";
        if(i >= k) currSum -= arr[i-k]; // Use old sum to get new sum by subtract the fourth-left element
        // cout << currSum << " " << endl;
        if(i >= k - 1 && currSum >= a && currSum <= b) res++;
    }
}

int main(){
    faster
    cin >> n >> k >> a >> b;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve2();
    cout << res;
    return 0;
}