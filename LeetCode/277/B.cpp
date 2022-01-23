class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a, b;
        for(auto u : nums) 
            if(u < 0) a.push_back(u);
            else b.push_back(u);
        
        vector<int> res;
        for(int i = 0; i < a.size(); ++i) {
            res.push_back(b[i]);
            res.push_back(a[i]);
        }
        return res;
    }
};
