#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-12;

int a, b;
int dd;

void solve() {
	scanf("%d", &dd);
	double d = dd; 
	double half = d / 2.0 + eps;
	double L = 0, R = half;
	if(dd == 1 || dd == 2 || dd == 3) puts("N");
	else {
		printf("Y ");
		if(dd == 0) puts("0.0000000000 0.0000000000");
		else {
			while(R - L > eps) {
				double mid = (L + R) / 2.0;
				if((d - mid) * mid <= d) {
					L = mid;
				} else {
					R = mid;
				}
			}
			printf("%.10lf %.10lf\n", dd - L, L);
		}
	}
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


