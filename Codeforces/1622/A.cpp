#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[3]; 

void solve() {
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	if (a[2] == a[0] + a[1]) puts("YES");
	else if((a[0] == a[1] && a[2] % 2 == 0) || (a[1] == a[2] && a[0] % 2 == 0)) {
		puts("YES");
	}
	else puts("NO");
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


