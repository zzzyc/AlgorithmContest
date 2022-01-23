class Solution {
public:
    int maximumGood(vector<vector<int>>& st) {
        int res = 0;
        int n = st.size();
        vector<int> ok(n); 
        for(int i = 0; i < 1 << n; ++i) { 
            int c = 0;
            for(int j = 0; j < n; ++j) ok[j] = 0;
            for(int j = 0; j < n; ++j) 
                if(i >> j & 1) { 
                    ++c;
                    for(int k = 0; k < n; ++k) 
                        if(st[j][k] == 1) ok[k] |= 1;
                        else if(st[j][k] == 0) ok[k] |= 2;
                }
            
            bool yes = true;
            for(int j = 0; j < n; ++j)
                if(ok[j] == 3) yes = false;
                else if(ok[j] == 1 && (i >> j & 1) != 1) yes = false;
                else if(ok[j] == 2 && (i >> j & 1) != 0) yes = false;
            if(yes) res = max(res, c);
        }
        
        return res;
    }
};
