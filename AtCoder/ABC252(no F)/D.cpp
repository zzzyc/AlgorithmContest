#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int a[N], n;
int cnt[N], g;
ll pre[N], ppre[N];

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		int j = i + 1;
		while(j <= n && a[j] == a[i]) j += 1;
		cnt[++g] = j - i;
		i = j - 1;
	}
	
	if(g < 3) {
		puts("0");
		return ;
	}
	
	ll res = 0;
	pre[2] = cnt[1] + cnt[2];
	pre[1] = cnt[1];
	ppre[2] = 1ll * cnt[1] * cnt[2];
	for(int i = 3; i <= n; ++i) {
		res += ppre[i - 1] * cnt[i];
		ppre[i] = ppre[i - 1] + cnt[i] * pre[i - 1];
		pre[i] = pre[i - 1] + cnt[i];
	}
	printf("%lld\n", res);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


