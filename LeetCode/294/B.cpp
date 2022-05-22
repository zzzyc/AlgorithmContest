class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rock, int rest) {
        int n = cap.size();
        for(int i = 0; i < n; ++i)
            cap[i] -= rock[i];
        sort(cap.begin(), cap.end());
        
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int mn = min(rest, cap[i]);
            if(mn == cap[i]) res += 1;
            rest -= mn;
        }
        return res;
    }
};
