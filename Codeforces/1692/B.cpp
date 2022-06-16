#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;
int a[N], n;
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	
	int ans = 0;
	int sig = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i + 1;
		while (j <= n && a[j] == a[i]) j += 1;
		
		int c = j - i;
		c -= 1;
		
		ans += c;
		if (c & 1) sig += 1, ans -= 1; 
		
		i = j - 1;
	}
	
	ans += sig;
	if (sig & 1) ans += 1;
	
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


