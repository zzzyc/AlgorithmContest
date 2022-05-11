#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;
int a[N], n;
void solve() {
	scanf("%d", &n);
	
	int mn = 1e9;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), mn = min(mn, a[i]); 
	int sum = 0;
	for(int i = 1; i <= n; ++i) sum += a[i] - mn;
	printf("%d\n", sum);
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


