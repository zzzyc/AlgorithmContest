#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int vis[N], a[N];
int n, k;

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		vis[i] = 0;
	}
	
	for (int i = 1; i < n; ++i) {
		if (a[i] < 2 * a[i + 1]) vis[i] = 1;
	}
	
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j < n && vis[j]) j += 1;
		if (j - i >= k) {
			ans += j - i - k + 1;
		}
		i = j;
	}
	printf("%d\n", ans);
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


