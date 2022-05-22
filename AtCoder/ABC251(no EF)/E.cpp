#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300010;
int a[N], n;
ll f[N][2];

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	
	// Ñ¡a[1]
	f[1][0] = 1e18, f[1][1] = a[1];
	for(int i = 2; i <= n; ++i) {
		f[i][0] = f[i - 1][1];
		f[i][1] = min(f[i - 1][0], f[i - 1][1]) + a[i];
	}
	ll ans = min(f[n][0], f[n][1]);
	
	// ²»Ñ¡a[1]
	f[1][0] = 0, f[1][1] = 1e18;
	for(int i = 2; i <= n; ++i) {
		f[i][0] = f[i - 1][1];
		f[i][1] = min(f[i - 1][0], f[i - 1][1]) + a[i];
	}
	ans = min(ans, f[n][1]);
	printf("%lld\n", ans);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


