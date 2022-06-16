#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	int id;
	int v;
};

vector<Node> vec[2];

const int N = 200010;
int n, p[N], q[N];
char s[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	scanf("%s", s + 1);
	for (int i = 0; i < 2; ++i) vec[i].clear();
	for (int i = 1; i <= n; ++i)
		vec[s[i] - '0'].push_back({i, p[i]});
		
	// 对于0的部分，肯定分配 1~vec[0].size()
	for (int i = 0; i < 2; ++i) 
		sort(vec[i].begin(), vec[i].end(), [](const Node& A, const Node& B) {
			return A.v < B.v;
		});
		
	for (int i = 0, j = 1; i < 2; ++i) {
		for (int k = 0; k < vec[i].size(); ++k)
			q[vec[i][k].id] = j++;
	}
	
	for (int i = 1; i <= n; ++i) printf("%d%c", q[i], " \n"[i == n]);
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


