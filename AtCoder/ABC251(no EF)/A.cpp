#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;
	for(int i = 0; i < 6 / (int)s.size(); ++i) {
		cout << s;
	}
	cout << "\n";
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


