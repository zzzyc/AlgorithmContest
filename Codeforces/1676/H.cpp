#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int a[N], n;
pair<int, int> p[N];
int cnt[N];

int tr[N];
void add(int p, int x) {
	while(p <= n) {
		tr[p] += x;
		p += (p & -p);
	}
}

int sum(int p) {
	int res = 0;
	while(p >= 1) {
		res += tr[p];
		p -= (p & -p);
	}
	return res;
}

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) tr[i] = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		p[i] = {i, x};
	}
	
	sort(p + 1, p + n + 1);
	
	long long res = 0;
	for(int i = 1; i <= n; ++i) {
		res += sum(n) - sum(p[i].second - 1);
		add(p[i].second, 1);
	}
	
	printf("%lld\n", res);
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


