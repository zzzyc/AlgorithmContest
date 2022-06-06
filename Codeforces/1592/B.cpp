#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010;
int a[N], n, x;
int v[N], g;
void solve() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	g = 0;
	for (int i = 1; i <= n; ++i) {
		if (i + x <= n || i - x >= 1) v[++g] = a[i];
	}
	
	sort(v + 1, v + g + 1);
	for (int i = 1, j = 1; i <= n; ++i) {
		if (i + x <= n || i - x >= 1) a[i] = v[j], j += 1;
	}
	
	for (int i = 2; i <= n; ++i)
		if (a[i] < a[i - 1]) {
			puts("NO");
			return ;
		}
	puts("YES");
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


