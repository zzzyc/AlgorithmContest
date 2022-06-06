#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
ll a[N], n;

void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	
	ll ans = n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++i) {
		int j = i + 1;
		while (j <= n && a[j] == a[i]) j += 1;
		
		ll c = j - i;
		if (c >= 2) {
			ll temp = c * (c - 1) / 2;
			temp *= (n - c);
			ans -= temp;
			
			if (c > 2) {
				ans -= c * (c - 1) * (c - 2) / 6;
			}	
		}
		
		i = j - 1;
	}
	
	printf("%lld\n", ans);
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


