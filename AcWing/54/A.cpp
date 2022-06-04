#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt[26];

void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (auto u : s) {
		if (u >= 'A' && u <= 'Z') cnt[u - 'A'] += 1;
		else cnt[u - 'a'] += 1;
	}
	for (int i = 0; i < 26; ++i)
		if (cnt[i] <= 0) {
			puts("NO");
			return ;
		}
		
	puts("YES");
}

int main()
{
	int T = 1;
	//scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


