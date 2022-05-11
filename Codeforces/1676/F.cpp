#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int a[N], n, k;

void solve() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	
	int pre = -1;
	int L = -1, R = -1;
	int curL = -1, curR = -1;
	for(int i = 1; i <= n; ) {
		int j = i + 1;
		while(j <= n && a[j] == a[i]) j += 1;
		if(j - i >= k) {
			if(curL == -1 || a[i] - pre > 1) {
				curL = a[i], curR = a[i];
			} else {
				curR = a[i];
			}
			pre = a[i];	
		}
		if(L == -1 || curR - curL > R - L) L = curL, R = curR;
		i = j;
	}
	if(L != -1) {
		printf("%d %d\n", L, R);
	} else {
		printf("-1\n");
	}
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


