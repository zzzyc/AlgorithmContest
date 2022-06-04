#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int x; 

void solve() {
	scanf("%d", &x);
	int c = 0;
	for (int i = 0; i < 31; ++i)
		if (x >> i & 1) c += 1;
	if (c == 1) {
		if (x == 1) puts("3");
		else printf("%d\n", x + 1);
	} else  {
		for (int i = 0; i < 31; ++i)
			if (x >> i & 1) {
				printf("%d\n", 1 << i);
				return ;
			}
	}
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


