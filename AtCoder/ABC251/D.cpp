#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int w;
	scanf("%d", &w);
	
	printf("%d\n", 300);
	for(int k = 0, temp = 1; k < 3; ++k) {
		for(int i = 1; i <= 100; ++i)
			printf("%d%c", temp * i, " \n"[i == 99 && k == 2]);
		temp *= 100;
	} 
	
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


