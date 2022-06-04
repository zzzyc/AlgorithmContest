#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 40;
ll c[N][N];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		for (int j = 0; j <= i; ++j) printf("%lld%c", c[i][j], " \n"[j == i]);
	}	
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


