#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
int a[N], n, s;
int pos[N];

void solve() {
	int sum = 0;
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[i] = 0x3f3f3f3f;
		sum += a[i];
	}
	
	
	
	if (sum < s) {
		puts("-1");
		return ;
	}
	
	int ans = 0;
	
	pos[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
		if (a[i] >= s && pos[a[i] - s] != 0x3f3f3f3f)
			ans = max(ans, i - pos[a[i] - s]);
		pos[a[i]] = min(pos[a[i]], i);
	}

	printf("%d\n", n - ans);
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


