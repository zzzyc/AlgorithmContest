#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010, M = N << 1;
int h[N], e[M], ne[M], idx;
int a[N], n, k;
int sum, cnt;
bool ok;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int fa) {
	int s = a[u];
	for (int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		if (v != fa) {
			s ^= dfs(v, u);
		}
	}
	
	if (s == sum) cnt += 1, s = 0;
	
	return s;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), h[i] = -1;
	idx = 0; cnt = 0;
	for (int i = 1, a, b; i < n; ++i) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	sum = 0;
	for (int i = 1; i <= n; ++i) sum ^= a[i];
	if (sum == 0) {
		puts("YES"); 
	} else {
		if (k == 2) {
			puts("NO");
			return ;
		}

		dfs(1, -1);
		if (cnt >= 3) puts("YES");
		else puts("NO");
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


