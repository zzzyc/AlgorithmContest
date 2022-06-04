#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
const int M = N << 2;
int h[N], e[M], ne[M], idx;
int n, m, Q, x, k;
int q[N], hh, tt;
int vis[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	idx = 0;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	scanf("%d", &Q);
	while (Q--) {
		ll res = 0;
		scanf("%d%d", &x, &k);
		k += 1;
		hh = 1, tt = 0;
		q[++tt] = x;
		vis[x] = 1;
		while (hh <= tt) {
			int u = q[hh++];
			res += u;
			if (vis[u] == k) continue ;
			for (int i = h[u]; i != -1; i = ne[i]) {
				int v = e[i];
				if (!vis[v]) {
					q[++tt] = v;
					vis[v] = vis[u] + 1;
				}
			}
		}
		
		for (int i = 1; i <= tt; ++i) vis[q[i]] = 0;
		
		printf("%lld\n", res);
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


