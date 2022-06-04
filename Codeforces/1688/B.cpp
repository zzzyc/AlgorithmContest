#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200010;
const int INF = 0x3f3f3f3f;
int a[N], n;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	
	int even = 0;
	int c = INF;
	bool f = false;
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 2 == 0) {
			even += 1;
			int temp = 0;
			while (a[i] % 2 == 0) temp += 1, a[i] /= 2;
			c = min(c, temp);
		}
		else f = true;
	}
	
	if (f) printf("%d\n", even);
	else printf("%d\n", c + n - 1);
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


