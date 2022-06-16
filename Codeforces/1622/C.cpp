#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int n;
ll a[N], k;
ll pre[N];

void solve() {
	scanf("%d%lld", &n, &k);
	
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
	
	if (pre[n] <= k) {
		puts("0");
		return ;
	}
	
	k = pre[n] - k;
	ll ans = k;
	for (int i = 1; i < n; ++i) {
		ll y = max(0ll, k - pre[i] + a[n] * i + i) / (i + 1);
		ans = min(ans, i + y);
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


