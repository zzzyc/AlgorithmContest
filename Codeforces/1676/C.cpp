#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s[55];
int n, m;

void solve() {
	int sum = 1e9;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	for(int i = 1; i <= n; ++i) 
		for(int j = i + 1; j <= n; ++j) {
			int temp = 0;
			for(int k = 0; k < m; ++k) {
				int a = s[i][k] - 'a', b = s[j][k] - 'a';
				if(a > b) swap(a, b);
				temp += b - a;
			}
			sum = min(sum, temp);
		}
	printf("%d\n", sum);
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


