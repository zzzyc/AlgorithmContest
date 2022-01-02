class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int pre = 0;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int c = 0;
            for(int j = 0; j < m; ++j) {
                if(bank[i][j] == '1') ++c;
            }
            res += c * pre;
            if(c > 0) pre = c;
        }
        
        return res;
    }
};
