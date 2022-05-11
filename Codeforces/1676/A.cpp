#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;
	int sum = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
	sum -= (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
	puts(sum == 0 ? "YES" : "NO");
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


