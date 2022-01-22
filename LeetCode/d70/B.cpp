class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        long long cur = 0;
        long long mx = 0;
        long long mn = 0;
        
        for(auto u : d) {
            cur += u;
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        
        long long len = mx - mn;
        long long alen = upper - lower;
        return max(0ll, alen - len + 1);
    }
};
