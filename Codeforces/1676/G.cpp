#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4010;
vector<int> g[N];
int a[N], n;
char s[N];
int res;

int dfs(int u) {
	int sum = (s[u] == 'W') ? 1 : -1;
	for(auto v : g[u]) {
		sum += dfs(v);
	}
	if(sum == 0) res += 1;
	return sum;
}

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int i = 2; i <= n; ++i) scanf("%d", &a[i]), g[a[i]].push_back(i);
	scanf("%s", s + 1);
	res = 0;
	dfs(1);
	printf("%d\n", res);
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


