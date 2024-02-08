# include <bits/stdc++.h>
using namespace std;

string S, final;
int n, k;

void build(int x, string cur) {
	if (cur.length() == k) {
		if (final < cur) {
			final = cur;
		}
		return;
	}
	if (x == n) return;
	if (cur < final) return;
	
	//cout << cur << endl;
	string temp;
	
	temp.append(cur);
	temp += S.substr(x, 1);
	for (int i = x+1; i < n - k + cur.length() + 2; ++i) {
		build(i, cur);
		build(i, temp);
	}
	
}

int main() {
	cin >> S >> k;
	n = S.length();
	if (n == k) {
		cout << S;
		return 0;
	}
	build(0, "");
	cout << final;
	
	return 0;
}
