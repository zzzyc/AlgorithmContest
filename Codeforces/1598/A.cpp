#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[2][110]; 
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < 2; ++i) scanf("%s", s[i]);
	
	bool ok = true;
	for (int j = 0; j < n; ++j)
		if (s[0][j] == s[1][j] && (s[0][j] == '1')) {
			ok = false;
			break;
		}
	
	puts(ok ? "YES" : "NO");
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


