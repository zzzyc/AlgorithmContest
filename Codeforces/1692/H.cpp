#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int a[N], n;
int b[N], m;

struct Node {
	int l, r;
};

vector<Node> cnt[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
	
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	for (int i = 1; i <= m; ++i) cnt[i].clear();
	for (int i = 1; i <= n; ++i) {
		int j = i + 1;
		while (j <= n && a[j] == a[i]) j += 1;
		cnt[a[i]].push_back({i, j - 1});
		i = j - 1;
	}
	
	int v = b[a[1]], l = 1, r = 1, c = 1;
	for (int i = 1; i <= m; ++i) {
		int pre = -1, sum = 0;
		int L = -1, R = -1;
		for (int j = 0; j < cnt[i].size(); ++j) {
			if (pre != -1 && pre > cnt[i][j].l - cnt[i][j - 1].r - 1) {
				sum = pre - (cnt[i][j].l - cnt[i][j - 1].r - 1) + cnt[i][j].r - cnt[i][j].l + 1;
				pre = sum;
				R = cnt[i][j].r;
			} else {
				sum = cnt[i][j].r - cnt[i][j].l + 1;
				pre = cnt[i][j].r - cnt[i][j].l + 1;
				L = cnt[i][j].l;
				R = cnt[i][j].r;
			}
			if (sum > c) {
				c = sum;
				l = L;
				r = R;
				v = b[i];
			}
		}
	}
	
	printf("%d %d %d\n", v, l, r);
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


