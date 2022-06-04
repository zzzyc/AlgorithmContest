#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010;
string s;
int n;
int cnt[26];

void solve() {
	memset(cnt, 0, sizeof cnt);
	cin >> n;
	for (int i = n * 2 + 1; i >= 1; --i) {
		cin >> s;
		for (auto c : s) cnt[c - 'a'] += 1;
	}
	
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) {
			cout << char(i + 'a') << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


