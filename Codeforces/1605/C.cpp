#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000010;
int n;
char s[N]; 

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 2; i <= n; ++i)
		if (s[i] == 'a' && s[i - 1] == 'a') {
			puts("2");
			return ;
		}
	
	for (int i = 3; i <= n; ++i)
		if (s[i - 2] == 'a' && s[i] == 'a') {
			puts("3");
			return ;
		}
		
	for (int i = 4; i <= n; ++i)
		if (s[i - 3] == 'a' && s[i] == 'a' && s[i - 1] != s[i - 2]) {
			puts("4");
			return ;
		}
		
	for (int i = 7; i <= n; ++i)
		if (s[i - 6] == 'a' && s[i] == 'a' && s[i - 3] == 'a' && (s[i - 5] == s[i - 4] && s[i - 2] == s[i - 1] && s[i - 1] != s[i - 4])) {
			puts("7");
			return ;
		}
	
	puts("-1");
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


