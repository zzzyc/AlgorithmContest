#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;
int n, a[N];
ll h;

void solve() {
	scanf("%d%lld", &n, &h);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	ll c = h / (a[0] + a[1]);
	h -= c * (a[0] + a[1]);
	c *= 2;
	if (h > 0) h -= a[0], c += 1;
	if (h > 0) h -= a[1], c += 1;
	printf("%lld\n", c);
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


