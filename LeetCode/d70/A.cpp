class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += cost[i];
            if(i - 1 >= 0) sum += cost[i - 1];
            i -= 2;
        }
        
        return sum;
    }
};
