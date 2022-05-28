#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010, M = N << 1;
const int INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], idx;
int n;
ll s[N], a[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, ll used) {
	if(s[u] != INF) a[u] = s[u] - used;
	for(int i = h[u]; i != -1; i = ne[i])
		dfs(e[i], s[u]);
}

void solve(int ca) {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) h[i] = -1;
	idx = 0;
	
	for(int i = 2; i <= n; ++i) {
		int fa;
		scanf("%d", &fa);
		add(fa, i);
	}
	
	for(int i = 1; i <= n; ++i) scanf("%lld", &s[i]);
	
	
	for(int i = 1; i <= n; ++i)	{
		if(s[i] == -1) { 
			s[i] = INF; 
			for(int j = h[i]; j != -1; j = ne[j])
				s[i] = min(s[i], s[e[j]]);
		} 
	} 
	
	for(int i = 1; i <= n; ++i)
		for(int j = h[i]; j != -1; j = ne[j])
			if(s[i] > s[e[j]]) {
				puts("-1");
				return ;
			}
			
	dfs(1, 0ll);
	ll res = 0;
	for(int i = 1; i <= n; ++i) res += a[i];
	printf("%lld\n", res);
	
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);

	return 0;
}


