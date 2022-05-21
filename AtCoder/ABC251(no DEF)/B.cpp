#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 310;
int a[N];
int vis[1000010];
int n, w;
void solve() {
	vis[0] = 1;
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		int sum = a[i];
		if(sum <= w) vis[sum] = 1;
		for(int j = i + 1; j <= n; ++j) { 
			sum = a[i] + a[j];
			if(sum <= w) vis[sum] = 1; 
			for(int k = j + 1; k <= n; ++k) { 
				sum = a[i] + a[j] + a[k];
				if(sum <= w) vis[sum] = 1;
			}
		} 
	}
	
	int cnt = 0;
	for(int i = 1; i <= w; ++i)
		cnt += vis[i];
		
	printf("%d\n", cnt);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


