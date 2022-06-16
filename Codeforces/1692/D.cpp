#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int t) {
	int m = t % 60;
	int h = t / 60 % 24;
	if (m % 10 == h / 10 && m / 10 == h % 10) return true;
	return false;
}

void solve() {
	string st;
	int x;
	cin >> st >> x;
	int t = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + (st[3] - '0') * 10 + (st[4] - '0');
	int g = __gcd(1440, x);
	int fz = x / g;
	int fm = 1440 / g;
	
	int k = fm;
	
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		if (check(t)) {
//			printf("%02d:%02d\n", t / 60 % 24, t % 60);
			ans += 1;
		} 
		t += x;
	}
	
	printf("%d\n", ans);
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


