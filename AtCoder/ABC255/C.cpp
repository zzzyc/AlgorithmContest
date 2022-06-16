#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, A, D, N;

void solve() {
	scanf("%lld%lld%lld%lld", &X, &A, &D, &N);
	
	ll res = abs(X - A);
	
	if (D > 0) {
		
		ll L = 1, R = N;
		while (L < R) {
			ll mid = L + R + 1 >> 1;
			if (A + (mid - 1) * D <= X) L = mid;
			else R = mid - 1;
		} 
		
		res = min(res, abs(A + (L - 1) * D - X));
		if (L > 1) res = min(res, abs(A + (L - 2) * D - X));
		if (L < N) res = min(res, abs(A + L * D - X));
		
	} else if (D < 0) {
		
		ll L = 1, R = N;
		while (L < R) {
			ll mid = L + R + 1 >> 1;
			if (A + (mid - 1) * D >= X) L = mid;
			else R = mid - 1;
		} 
		
		res = min(res, abs(A + (L - 1) * D - X));
		if (L > 1) res = min(res, abs(A + (L - 2) * D - X));
		if (L < N) res = min(res, abs(A + L * D - X));
		
	} 
	
	printf("%lld\n", res);
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


