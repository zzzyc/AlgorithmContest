#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
const int M = N << 1;
int h[N], e[M], ne[M], idx;
int n, m; 

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int vis[N];
void dfs(int u) {
	if(vis[u]) return ;
	vis[u] = 1;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		if(!vis[v]) {
			printf("%d %d\n", u, v);
			dfs(v);
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = h[u]; i != -1; i = ne[i]) {
			int v = e[i];
			if(!vis[v]) {
				printf("%d %d\n", u, v);
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void solve(int ca) {
	scanf("%d%d", &n, &m);
	memset(h, -1, (n + 1) * sizeof(int));
	idx = 0;
	
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	dfs(1);
	memset(vis, 0, (n + 1) * sizeof(int));
	bfs(1);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);

	return 0;
}
