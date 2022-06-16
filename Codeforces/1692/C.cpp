#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10;
char s[N][N];
int n = 8;

void solve() {
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < n; ++j)
			if (s[i][j] == '#' && s[i - 1][j - 1] == '#' && s[i - 1][j + 1] == '#' && s[i + 1][j - 1] == '#' && s[i + 1][j + 1] == '#') {
				printf("%d %d\n", i, j);
				return ;
			}
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


