#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
int pre[N];
int suf[N];
int n;

void solve() {
	memset(pre, -1, sizeof pre);
	memset(suf, -1, sizeof suf);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1];
		if(a[i] == 0) pre[i] = i;
	}
	for(int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1];
		if(a[i] == 0) suf[i] = i;
	}
	
	for(int i = 1; i <= n; ++i) {
		int L = pre[i] == -1 ? -1 : (i - pre[i]);
		int R = suf[i] == -1 ? -1 : (suf[i] - i);
		if(L == -1 && R == -1) printf("-1");
		else if(L == -1) printf("%d", R);
		else if(R == -1) printf("%d", L);
		else printf("%d", min(L, R));
		printf("%c", " \n"[i == n]);
	}
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


