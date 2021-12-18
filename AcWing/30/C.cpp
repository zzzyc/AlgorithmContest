/*
author: solego
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
int Q, l, r;
int gcd(int a, int b) {	
	return b == 0 ? a : gcd(b, a % b);
}

int ans[100000 + 10];
int c;

void solve() {
	scanf("%d%d", &a, &b);
	int g = gcd(a, b);
	c = 0;
	for(int i = 1; 1ll * i * i <= g; ++i)
		if(g % i == 0) {
			ans[++c] = i;
			if(1ll * i * i != g) ans[++c] = g / i;
		}
		
	sort(ans + 1, ans + c + 1);
	
	
	
	scanf("%d", &Q);
	
	while(Q--) {
		scanf("%d%d", &l, &r);
		
		int left = 1, right = c;
		while(left < right) {
			int mid = left + right + 1 >> 1;
			if(ans[mid] <= r) left = mid;
			else right = mid - 1;
		} 
		
		if(ans[left] < l) puts("-1");
		else printf("%d\n", ans[left]);
	}		
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}

