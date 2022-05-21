#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, int> mp;
int n;
string s;
int t;

void solve() {
	cin >> n;
	
	int idx = -1, val = -1;
	for(int i = 1; i <= n; ++i) {
		cin >> s >> t;
		if(mp.count(s)) continue;
		if(t > val) idx = i, val = t;
		mp[s] = 1;
	}
	cout << idx << "\n";
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


