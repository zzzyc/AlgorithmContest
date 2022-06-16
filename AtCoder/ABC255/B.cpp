#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const double eps = 1e-10;
const int N = 1010;
int n, k;

int q[N];
int x[N], y[N];
int vis[N];

bool check(double r) {
	r = r * r; 
	for (int i = 1; i <= n; ++i) vis[i] = 0;
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j) {
			int a = x[q[i]] - x[j];
			int b = y[q[i]] - y[j];
			double d = 1.0 * a * a + 1.0 * b * b;
			if (r > d || fabs(r - d) < eps) vis[j] = 1; 
		}
		
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) return false;
	return true;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i) scanf("%d", &q[i]);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	
	double L = 0, R = 1e9;
	while (R - L > eps) {
		double mid = (L + R) / 2;
		if (check(mid)) R = mid;
		else L = mid;
	}
	
	printf("%.10lf\n", L);
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


