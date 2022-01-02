class Solution {
public:

	const int INF = 0x3f3f3f3f;
    vector<vector<int>> from;
    vector<int> in;
    vector<int> f;
    vector<int> q;
    vector<int> dist;
    int n;
    int cirlen;
    int d;
    int ans;
    
    void dfs(int u, int dep) {
    	if(in[u] == 2) return ;
    	if(in[u] == 1) {
    		cirlen = dep - dist[u];
    		d = dist[u];
    		return ;
		}
		in[u] = 1;
		dist[u] = dep;
		dfs(f[u], dep + 1);
		in[u] = 2;
	}
    
    int maximumInvitations(vector<int>& _f) {
    	f = _f;
    	n = f.size();
    	from = vector<vector<int>>(n, vector<int>());
    	in = vector<int>(n, 0);
    	q = vector<int>();
    	dist = vector<int> (n, INF);
    	for(int i = 0; i < n; ++i) { 
    		from[f[i]].push_back(i);
    		if(f[f[i]] == i) in[i] = 2, q.push_back(i);
		}
		
		ans = 0;
		for(auto i : q) {
			queue<int> que;
			que.push(i);
			dist[i] = 0;
			int len = 0, p = -1;
			while(!que.empty()) {
				auto u = que.front(); que.pop();
				if(len < dist[u]) p = u, len = dist[u];
				for(auto& v : from[u]) {
					if(in[v] == 2) continue;
					if(dist[v] > dist[u] + 1)
						dist[v] = dist[u] + 1, que.push(v);
				}
			}
			ans += len + 1;
			while(p != -1 && in[p] == 0) in[p] = 2, p = f[p];
		}
		
		for(int i = 0; i < n; ++i)
			if(in[i] == 2) dist[i] = INF;
			else dist[i] = 0;
		
		for(int i = 0; i < n; ++i) {
			if(in[i]) continue;
			d = -1;
			cirlen = 0;
			dfs(i, 1);
			ans = max(ans, cirlen);
		}
		return ans;
    }
};
