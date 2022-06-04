#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int a[N];
int n, x, k;

struct Node {
	int v, id;
};

vector<Node> g[N];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		g[i % k].push_back({x, i});
	}
	
	for (int i = 0; i < k; ++i) {
		sort(g[i].begin(), g[i].end(), [](const Node& A, const Node& B) {
			return A.v < B.v;
		});
		for (int j = 0; j < g[i].size(); ++j)
			a[j * k + i] = g[i][j].v;
			
	} 
	
//	for (int i = 0; i < n; ++i) printf("%d%c", a[i], " \n"[i == n - 1]);
	
	for (int i = 1; i < n; ++i)
		if (a[i] < a[i - 1]) {
			puts("No");
			return ;
		}
	
	puts("Yes");
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


