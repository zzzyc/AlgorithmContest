#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
const int M = N << 1;
int h[N], e[M], ne[M], w[M], idx;
int n, m; 

struct Node {
	int id;
	ll d;
	bool operator < (const Node& A) const {
		return d > A.d;
	}
};

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int pre[N];
ll dist[N];
bool st[N];
priority_queue<Node> q;
void dijkstra(int fir) {
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; ++i) {
		dist[i] = 1e18;
		st[i] = false;
	}
	
	dist[fir] = 0;
	q.push({fir, dist[fir]});
	
	while(!q.empty()) {
		Node t = q.top(); q.pop();
		int u = t.id;
		if(st[u]) continue ;
		st[u] = true;
		
		for(int i = h[u]; i != -1; i = ne[i]) {
			int v = e[i];
			if(dist[v] > dist[u] + w[i]) {
				dist[v] = dist[u] + w[i];
				pre[v] = i;
				q.push({v, dist[v]});
			}
		}
	}
}

void solve(int ca) {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) h[i] = -1;
	idx = 0;
	for(int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	
	dijkstra(1);
	for(int i = 2; i <= n; ++i) printf("%d%c", pre[i] / 2 + 1, " \n"[i == n]);
	
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);

	return 0;
}


