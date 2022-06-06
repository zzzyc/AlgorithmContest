#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;

struct Node {
	ll a, b;
} q[N];

ll n;
ll cnt[N];

void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) cnt[i] = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld%lld", &q[i].a, &q[i].b), cnt[q[i].b] += 1;
	
	
	sort(q + 1, q + n + 1, [](const Node& A, const Node& B) {
		return A.a < B.a;
	});
	
	ll res = n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++i) {
		int j = i + 1;
		while (j <= n && q[j].a == q[i].a) j += 1;
		
		int c = j - i;
		if (c > 1) {
			for (int k = i; k < j; ++k) {
				res -= 1ll * (c - 1) * (cnt[q[k].b] - 1);
			}
		}
		
		i = j - 1;
	}
	
	printf("%lld\n", res);
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


