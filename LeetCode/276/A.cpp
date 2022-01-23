class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        for(int i = 0; i < s.size(); i += k) {
            if(i + k < n) res.push_back(s.substr(i, k));
            else {
                string temp = s.substr(i);
                while(temp.size() < k) temp += fill;
                res.push_back(temp);
            }
        }
        return res;
    }
};
