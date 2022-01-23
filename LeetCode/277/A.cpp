class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for(int i = 1; i + 1 < nums.size(); ++i)
            if(nums[i] > nums[0] && nums[i] < nums.back()) ++res;
        return res;
    }
};
