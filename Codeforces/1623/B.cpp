#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;

int vis[N];
struct Node {
	int l, r;
} q[N];
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &q[i].l, &q[i].r), vis[i] = 0;
	
	sort(q + 1, q + n + 1, [](const Node& A, const Node& B) {
		return A.r - A.l < B.r - B.l; 
	});
	
	for (int i = 1; i <= n; ++i) 
		for (int j = q[i].l; j <= q[i].r; ++j)
			if (!vis[j]) {
				vis[j] = 1;
				printf("%d %d %d\n", q[i].l, q[i].r, j);
			}
	puts("");
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


