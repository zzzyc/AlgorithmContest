#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000010;
char s[N];
int pre[N];
int temp[N]; 
int n;

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	if (n & 1) {
		puts("0");
		return ;
	}
	
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1];
		if (s[i] == '(') pre[i] += 1;
		else pre[i] -= 1;
	}
	
	if (pre[n] != 2 && pre[n] != -2) {
		puts("0");
		return ;
	} 
	
	int res = 0;
	if (pre[n] == 2) {
		
		for (int i = 1; i <= n; ++i)
			if (pre[i] < 0) {
				puts("0");
				return ;
			}
		
		temp[n] = pre[n];
		for (int i = n - 1; i >= 1; --i) temp[i] = min(temp[i + 1], pre[i]);
		
		for (int i = 1; i <= n; ++i)
			if (temp[i] >= 2 && s[i] == '(') res += 1;
			
	} else {
		
		for (int i = 1; i <= n; ++i)
			if (pre[i] < -2) {
				puts("0");
				return ;
			}
		
		temp[1] = pre[1];
		for (int i = 2; i <= n; ++i) {
			temp[i] = min(temp[i - 1], pre[i]);
		}
		
		for (int i = 1; i <= n; ++i) {
			if (temp[i - 1] < 0) break;
			else if (s[i] == ')') res += 1; 
		}
	}
	printf("%d\n", res);
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


