#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;
int n, k;
int a[N], b[N];
int c = 0;

void solve() {
	scanf("%d%d", &n, &k);
	int mx = 0;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), mx = max(mx, a[i]);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &b[i]);
		if(a[b[i]] == mx) {
			puts("Yes");
			return ;
		}
	}
	
	puts("No");
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


