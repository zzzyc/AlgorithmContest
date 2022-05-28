#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve(int ca) {
	string s;
	cin >> s;
	
	int i = 0;
	if(s[0] == '9') i += 1;
	for(; i < s.size(); ++i) {
		int c = s[i] - '0';
		if(9 - c < c) s[i] = (9 - c) + '0';
	}
	cout << s << "\n";
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);

	return 0;
}


