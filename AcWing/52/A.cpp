#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	
	int res = 0;
	for(int i = 1; i <= n + 1; ++i) {
		sum += 1ll * i * (i + 1) / 2;
		if(sum > n) {
			printf("%d\n", i - 1);
			break;
		}
	}
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


