/*
author: solego
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
char s[N];
int dp[N];
int n;

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	
	int res = 0;
    	for(int i = 1; i <= n; ++i) {
		if(s[i] == ')') {
		    if(s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
		    else {
			int pre = i - 1 - dp[i - 1];
			if(s[pre] == '(') dp[i] = dp[i - 1] + dp[pre - 1] + 2;
		    }
		}
		res = max(res, dp[i]);
    	}
	
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(dp[i] == res) cnt += 1;
	
	if(res == 0) cnt = 1;
	printf("%d %d\n", res, cnt);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}

