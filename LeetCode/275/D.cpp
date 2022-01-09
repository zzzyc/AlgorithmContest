class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < plantTime.size(); ++i)
            vec.push_back({plantTime[i], growTime[i]});

        sort(vec.begin(), vec.end(), [](const pair<int, int>& A, const pair<int, int>& B) {
            return A.second > B.second;
        });
        
        int temp = 0;
        int res = 0;
        for(auto u : vec) {
            temp += u.first;
            res = max(res, temp + u.second);
        }
        
        return res;
    }
};
