#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2010;
int q[N][6];
int cnt[N];
int v[5];
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < 5; ++i) v[i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 5; ++j) { 
			scanf("%d", &q[i][j]);
			cnt[j] += q[i][j];
		}
	
	for (int a = 0; a < 5; ++a)
		for (int b = a + 1; b < 5; ++b) {
			if (cnt[a] * 2 < n || cnt[b] * 2 < n) continue ;
			int L = 0, R = 0, mid = 0;
			for (int i = 1; i <= n; ++i) { 
				if (q[i][a] && q[i][b]) mid += 1;
				else if (q[i][a]) L += 1;
				else if (q[i][b]) R += 1;
			}
			
			int c = n / 2;
			if (L < c) mid -= c - L;
			if (R < c) mid -= c - R;
			
			if (mid >= 0) {
				puts("YES");
				return ;
			} 
		}
		
	puts("NO");
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


