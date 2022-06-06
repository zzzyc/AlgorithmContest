#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	priority_queue<ll, vector<ll>, greater<ll>> q;
	int n;
	ll len;
	scanf("%d%lld", &n, &len);
	
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		q.push(x);
		len -= x;
	}
	
	if (len > 0) q.push(len);
	
	ll res = 0;
	while (q.size() > 1) {
		ll a = q.top(); q.pop();
		ll b = q.top(); q.pop();
		res += a + b;
		q.push(a + b);
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


