#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int a;
	cin >> a;
	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		int x; cin >> x;
		if (x > a) ans += 1;
	}
	cout << ans << "\n";
	
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


