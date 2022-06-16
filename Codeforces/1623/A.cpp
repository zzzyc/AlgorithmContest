#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, rb, cb, rd, cd;

void solve() {
	scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);
	int res = 0x3f3f3f3f;
	if (rb <= rd) res = min(res, rd - rb);
	else res = min(res, n - rb + n - rd);
	
	if (cb <= cd) res = min(res, cd - cb);
	else res = min(res, m - cb + m - cd);
	
	printf("%d\n", res);
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


