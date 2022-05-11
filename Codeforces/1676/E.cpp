#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int a[N], n, Q;
int q[N], id[N];
int ans[N];

void solve() {
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= Q; ++i) scanf("%d", &q[i]), id[i] = i;
	
	sort(a + 1, a + n + 1, greater<int>()); 
	sort(id + 1, id + Q + 1, [&](const int a, const int b) {
		return q[a] < q[b];	
	});
	
	int sum = 0;
	for(int i = 1, j = 1; i <= Q; ++i) {
		while(j <= n && sum < q[id[i]]) {
			sum += a[j];
			j += 1;
		}
		if(sum >= q[id[i]]) ans[id[i]] = j - 1;
		else ans[id[i]] = -1; 
	}
	
	for(int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


