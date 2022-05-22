class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int c = 0;
        for(auto u : s)
            if(u == letter) c += 1;
        int res = c * 100 / n;
        return res;
    }
};
