#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[2][2];
void solve() {
	int r, c;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			scanf("%d", &a[i][j]);
	printf("%d\n", a[r - 1][c - 1]);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


