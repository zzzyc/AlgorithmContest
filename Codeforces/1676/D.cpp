#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int BASE = 200;
const int N = BASE * 2 + 10;
int a[N][N];
int LD[N], LU[N];
int n, m;

void solve() {
	memset(LD, 0, sizeof LD);
	memset(LU, 0, sizeof LU);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) { 
			scanf("%d", &a[i][j]);
			LD[i - j + 200] += a[i][j];
			LU[i + j] += a[i][j];
		}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) 
			res = max(res, LD[i - j + 200] + LU[i + j] - a[i][j]);
	
	printf("%d\n", res);	
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


