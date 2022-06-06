#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int a[N], n;
ll sum;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	ll x = sum, y = n;
	ll g = gcd(x, y);
	x /= g, y /= g;
	if (y != 1 && y != 2) {
		puts("0");
	} else {
		ll ans = 0;
		// 两数之和为 x
		if (y == 1) x *= 2;
		for (int i = 1; i < n; ++i) {
			int l = i + 1, r = n;
			while (l < r) {
				int mid = l + r >> 1;
				if (a[mid] >= x - a[i]) r = mid;
				else l = mid + 1;
			}
			if (a[l] == x - a[i]) {
				int left = l, right = n;
				while (left < right) {
					int mid = left + right + 1 >> 1;
					if (a[mid] <= x - a[i]) left = mid;
					else right = mid - 1;
				}
				ans += left - l + 1; 
			}
		}
		
		printf("%lld\n", ans);
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


