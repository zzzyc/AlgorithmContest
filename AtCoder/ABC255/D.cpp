#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int a[N], n, Q, x;
ll pre[N];
ll suf[N];

void solve() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	
	for (int i = 2; i <= n; ++i) {
		pre[i] = pre[i - 1] + 1ll * (i - 1) * (a[i] - a[i - 1]);
	}
	
	for (int i = n - 1; i >= 1; --i) {
		suf[i] = suf[i + 1] + 1ll * (n - i) * (a[i + 1] - a[i]);
	}
	
	while (Q--) {
		scanf("%d", &x);
		if (x < a[1]) printf("%lld\n", suf[1] + 1ll * n * (a[1] - x));
		else if(x > a[n]) printf("%lld\n", pre[n] + 1ll * n * (x - a[n]));
		else {
			// a[i] >= x 的第一个 a[i]
			int l = 1, r = n;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (a[mid] <= x) l = mid;
				else r = mid - 1; 
			}
			
			ll res = pre[l] + 1ll * (x - a[l]) * l;
			if (l < n) res += suf[l + 1] + 1ll * (a[l + 1] - x) * (n - l); 
			printf("%lld\n", res);
		}
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


