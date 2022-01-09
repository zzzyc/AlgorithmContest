class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) nums.push_back(nums[i]), cnt += nums[i];
        
        if(cnt == 0) return 0;
        
        int m = nums.size();
        int sum = 0;
        for(int i = 0; i < cnt - 1; ++i) sum += nums[i];
        
        int res = 0x3f3f3f3f;
        for(int i = cnt - 1; i < m; ++i) {
            sum += nums[i];
            res = min(res, cnt - sum);
            sum -= nums[i - cnt + 1];
        }
        return res;
    }
};
