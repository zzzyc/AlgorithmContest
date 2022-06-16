#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;
char s[N];
int n;

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	int c = 0;
	for (int i = 1; i <= n; ++i) if (s[i] == '0') c += 1;
	vector<int> g;
	
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0') {
			if (i > c) g.push_back(i);
		} else {
			if (i <= c) g.push_back(i);
		}
	
	
	if (!g.empty()) { 
		puts("1");
		printf("%d", (int)g.size());
		for (int i = 0; i < g.size(); ++i) printf(" %d", g[i]);
		puts("");
	} else {
		puts("0");
	} 
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


