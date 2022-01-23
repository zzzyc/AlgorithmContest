class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int j = i + 1;
            while(j < n && nums[j] == nums[i]) ++j;
            if(j - i == 1) {
                if((j == n || nums[j] - nums[i] > 1) && (i == 0 || nums[i] - nums[i - 1] > 1)) 
                    res.push_back(nums[i]);
            } 
            
            i = j - 1;
        }
        
        return res;
    }
};
