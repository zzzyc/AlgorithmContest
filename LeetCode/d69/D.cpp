class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                int l = j > 0 ? grid[i][j - 1] : 0;
                int u = i > 0 ? grid[i - 1][j] : 0;
                int ul = (i > 0 && j > 0) ? grid[i - 1][j - 1] : 0;
                grid[i][j] = grid[i][j] + u + l - ul;
            }
        
        vector<vector<long long>> b(n, vector<long long>(m, 0));
        for(int i = 0; i + stampHeight - 1 < n; ++i)
            for(int j = 0; j + stampWidth - 1 < m; ++j) {
                long long sum = grid[i + stampHeight - 1][j + stampWidth - 1];
                if(i > 0) sum -= grid[i - 1][j + stampWidth - 1];
                if(j > 0) sum -= grid[i + stampHeight - 1][j - 1];
                if(i > 0 && j > 0) sum += grid[i - 1][j - 1];
                if(sum == 0) {
                    int rx = i + stampHeight - 1;
                    int ry = j + stampWidth - 1;
                    
                    b[i][j] += 1;
                    if(rx + 1 < n) b[rx + 1][j] -= 1;
                    if(ry + 1 < m) b[i][ry + 1] -= 1;
                    if(rx + 1 < n && ry + 1 < m) b[rx + 1][ry + 1] += 1;
                }
            }
        

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(i > 0) b[i][j] += b[i - 1][j];
                if(j > 0) b[i][j] += b[i][j - 1];
                if(i > 0 && j > 0) b[i][j] -= b[i - 1][j - 1];
            }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                int v = grid[i][j];
                if(i > 0) v -= grid[i - 1][j];
                if(j > 0) v -= grid[i][j - 1];
                if(i > 0 && j > 0) v += grid[i - 1][j - 1];    
                if(v == 1 || b[i][j] > 0);
                else return false;
            }
        return true;
    }
};
