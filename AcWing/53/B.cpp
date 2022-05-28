#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve(int ca) {
	string s;
	cin >> s;
	
	ll res = 0;
	if(s[0] == '0' || s[0] == '4' || s[0] == '8') res += 1;
	for(int r = 1; r < s.size(); ++r) {
		if((s[r] - '0') & 1) {
			continue ;
		}
		
		if(s[r] == '0' || s[r] == '4' || s[r] == '8') {
			res += 1;
			int pre = s[r - 1] - '0';
			if(pre % 2 == 0) res += r;
		} else if(s[r] == '2' || s[r] == '6') {
			int pre = s[r - 1] - '0';
			if(pre % 2 == 1) res += r;
		}
	}
	
	printf("%lld\n", res);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);

	return 0;
}


