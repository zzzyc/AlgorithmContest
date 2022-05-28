#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;
string s[N];
int p[10][N];
int vec[10];
int n;

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) { 
		cin >> s[i]; 
		for(int j = 0; j < s[i].size(); ++j)
			p[s[i][j] - '0'][i] = j;
	} 
	int res = 0x3f3f3f3f;
	for(int j = 0; j < 10; ++j) {
		int temp = -1;
		memset(vec, -1, sizeof vec);
		for(int k = 0; k < n; ++k) vec[p[j][k]] += 1;
		for(int k = 0; k < 10; ++k) 
			if(vec[k] != -1) temp = max(temp, vec[k] * 10 + k);
		if(temp != -1) res = min(res, temp);
	}
	cout << res << "\n";
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve();

	return 0;
}


