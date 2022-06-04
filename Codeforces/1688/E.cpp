#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 210, M = 510;
int n, m;
struct Node {
	int id, w;
}e[M];
char s[M];

int ask(int id) {
	s[id] = '1';
	printf("? %s\n", s + 1);
	fflush(stdout);
	s[id] = '0';
	int t;
	scanf("%d", &t);
	return t;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) s[i] = '0';
	
	for (int i = 1; i <= m; ++i) e[i].w = ask(i), e[i].id = i;
	sort(e + 1, e + m + 1, [](const Node& A, const Node& B) {
		return A.w < B.w;
	});
	
	int res = e[1].w;
	s[e[1].id] = '1';
	for (int i = 2; i <= m; ++i) {
		int t = ask(e[i].id);
		if (t == res + e[i].w) {
			res = t;
			s[e[i].id] = '1';
		}
	}
	
	printf("! %d\n", res);
	fflush(stdout);
}

int main()
{
	int T = 1;
//	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		solve();
	}

	return 0;
}


