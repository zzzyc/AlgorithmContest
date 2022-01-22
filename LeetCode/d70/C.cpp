class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res;
        vector<vector<int>> d(n, vector<int>(m, 0x3f3f3f3f));
        queue<vector<int>> q;
        q.push(start);
        d[start[0]][start[1]] = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = u[0] + dx[i], ny = u[1] + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 0 && d[nx][ny] > d[u[0]][u[1]] + 1) {
                    d[nx][ny] = d[u[0]][u[1]] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(d[i][j] != 0x3f3f3f3f && grid[i][j] >= p[0] && grid[i][j] <= p[1])
                    res.push_back({i, j});
        
        sort(res.begin(), res.end(), [&](const vector<int>& A, const vector<int>& B) {
            if(d[A[0]][A[1]] == d[B[0]][B[1]]) {
                if(grid[A[0]][A[1]] == grid[B[0]][B[1]]) {
                    if(A[0] == B[0]) return A[1] < B[1];
                    return A[0] < B[0];
                }
                return grid[A[0]][A[1]] < grid[B[0]][B[1]];
            }
            return d[A[0]][A[1]] < d[B[0]][B[1]];
        });
        
        while(res.size() > k) res.pop_back();
        return res;
    }
};
