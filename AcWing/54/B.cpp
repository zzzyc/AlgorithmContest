#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2010;

struct Node {
	ll x, y, v;
}a[N];
Node n1, n2;

ll get(ll x, ll y) {
	return x * x + y * y;
}

struct Dist {
	ll v1, v2, id;
}d[N];
ll suf[N];

void solve() {
	int n;
	scanf("%d%lld%lld%lld%lld", &n, &n1.x, &n1.y, &n2.x, &n2.y);
	
	for (int i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
	
	ll r1 = 0, r2 = 0;
	for (int i = 1; i <= n; ++i) {
		d[i].v1 = get(a[i].x - n1.x, a[i].y - n1.y);
		d[i].v2 = get(a[i].x - n2.x, a[i].y - n2.y);
		d[i].id = i;
	}
	
	sort(d + 1, d + n + 1, [](const Dist& A, const Dist& B) {
		return A.v1 < B.v1;
	});
	
	ll res = 1e18;
	suf[n] = d[n].v2;
	suf[n + 1] = 0;
	for (int i = n - 1; i >= 1; --i) {
		suf[i] = max(suf[i + 1], d[i].v2);
	}
	
	for (int i = 0; i <= n; ++i) {
		res = min(res, d[i].v1 + suf[i + 1]);
	}
	
	printf("%lld\n", res);
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


