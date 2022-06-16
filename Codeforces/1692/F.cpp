#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int cnt[10];
	memset(cnt, 0, sizeof cnt);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		cnt[x % 10] += 1;
	}
	
	for (int i = 0; i < 10; ++i) 
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k) {
				if ((i + j + k) % 10 == 3) {				
					cnt[i] -= 1;
					cnt[j] -= 1;
					cnt[k] -= 1;
					if (cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) {
						puts("YES");
						return ;
					}
					cnt[i] += 1;
					cnt[j] += 1;
					cnt[k] += 1;
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


