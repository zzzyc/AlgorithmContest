class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        unordered_map<string, int> cs;
        for(auto& u : s) {
            sort(u.begin(), u.end());
            cs[u] += 1;
        }
        
        int cnt = 0;
        for(auto& u : t) {
            sort(u.begin(), u.end());
            for(int i = 0; i < u.size(); ++i) {
                if(!i || u[i] != u[i - 1]) {
                    string str = "";
                    if(i > 0) str += u.substr(0, i);
                    str += u.substr(i + 1);
                    if(cs.count(str)) {
                        cnt += 1;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
