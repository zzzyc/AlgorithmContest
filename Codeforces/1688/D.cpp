#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;
int a[N];
ll n;
ll pre[N];
ll k;

void solve() {
	ll ans = 0;
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	
	if (n == 1) {
		ans = a[1] + k - 1;
	} else if (k <= n) {
		for (int i = k; i <= n; ++i)
			ans = max(ans, pre[i] - pre[i - k]);
		ans += (k - 1) * k / 2;
	} else {
		for (int i = 1; i <= n; ++i) ans += a[i];
		ans += (k - n + k - 1) * n / 2;
	}
	
	printf("%lld\n", ans);
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


