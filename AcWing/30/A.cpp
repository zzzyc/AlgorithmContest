/*
author: solego
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, h;
	cin >> n >> h;
	int res = 0;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		if(x > h) res += 2;
		else res += 1;
	}
	cout << res << "\n";
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}

