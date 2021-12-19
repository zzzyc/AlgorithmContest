class Solution {
public:
    
    bool isP(string& s) {
        int l = 0, r = (int)s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto& s : words)
            if(isP(s)) return s;
        
        return "";
    }
};
