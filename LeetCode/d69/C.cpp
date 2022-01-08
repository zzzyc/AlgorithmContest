class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int eq[26] = {0};
        int cnt[26][26] = {0};
        for(auto& u : words) {
            if(u[0] == u[1]) ++eq[u[0] - 'a'];
            else cnt[u[0] - 'a'][u[1] - 'a'] += 1;
        }
        
        int res = 0, c = 0;
        for(int i = 0; i < 26; ++i) {
            if(eq[i] & 1) ++c, --eq[i];
            res += eq[i] * 2;
        }
        if(c > 0) res += 2;
        for(int i = 0; i < 26; ++i)
            for(int j = i + 1; j < 26; ++j)
                res += min(cnt[i][j], cnt[j][i]) * 4;
        
        return res;
    }
};
