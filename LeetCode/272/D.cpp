class Solution {
public:
    
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> temp;
        
        auto b_s = [&](int x) {
            int l = 0, r = (int)temp.size() - 1;
            while(l < r) {
                int mid = l + r >> 1;
                if(temp[mid] > x) r = mid;
                else l = mid + 1;
            }
            return l;
        };
        
        int res = 0;
        for(int st = 0; st < k; ++st) {
            int c = 1;
            temp.clear();
            temp.push_back(arr[st]);
            for(int j = st + k; j < n; j += k) {
                c += 1;
                if(arr[j] >= temp.back()) temp.push_back(arr[j]);
                else temp[b_s(arr[j])] = arr[j];
            }
            
            res += c - (int)temp.size();
        }
        
        return res;
    }
};
