#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve() {
	int n;
	scanf("%d", &n);
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int t = i;
		int v = 1;
		for (int j = 2; j * j <= t; ++j) {
			int c = 0;
			while (t % j == 0) c += 1, t /= j;
			if (c & 1) v *= j;
		}
		
		if (t > 1) v *= t;
		
		for (int j = 1; 1ll * v * j * j <= n; ++j) {
			ans += 1;
		}
	}
	
	printf("%lld\n", ans);	
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


