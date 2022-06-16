#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
ll h[N], n;
ll ah[N];

bool check(ll x) {
	for (int i = 1; i <= n; ++i) ah[i] = h[i];
	for (int i = n; i >= 3; --i) {
		if (ah[i] < x) return false;
		ll d = min(h[i], (ah[i] - x)) / 3;
		ah[i] -= 3ll * d;
		ah[i - 1] += d;
		ah[i - 2] += 2ll * d;
	}
	if (ah[1] < x || ah[2] < x) return false;
	return true;
}

void solve() {
	scanf("%d", &n);
	ll l = 1, r = 1;
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &h[i]), ah[i] = h[i], r = max(r, h[i]);
	

	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	
	printf("%lld\n", l);
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


