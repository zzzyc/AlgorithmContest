class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long res = 0;
        int n = p.size();
        for(int i = 0; i < n; ++i) {
            int j = i + 1;
            while(j < n && p[j] + 1 == p[j - 1]) j += 1;
            int c = j - i;
            
            res += 1ll * c * (c + 1) / 2;
            
            i = j - 1;
        }
        
        return res;
    }
};
