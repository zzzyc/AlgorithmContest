#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[3]; 

void solve() {
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	
	int sum = a[0] + a[1] + a[2];
	int b[3] = {sum / 3 - 1, sum / 3, sum / 3 + 1};

	int resv = 0x3f3f3f3f; 
	for (int i = 0; i < 3; ++i) {
		// a[1] -> b[i]
		int ch = a[1] - b[i];
		int v1 = b[i], v2 = a[0] + a[2] + ch;
		resv = min(resv, abs(v2 - v1 * 2));
	}
	
	printf("%d\n", resv);
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


