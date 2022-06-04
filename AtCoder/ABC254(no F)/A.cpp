#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve() {
	int n;
	scanf("%d", &n);
	printf("%d%d\n", n % 100 / 10, n % 10);
}

int main()
{
	int T = 1;
	//scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


