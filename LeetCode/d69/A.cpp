class Solution {
public:
    string capitalizeTitle(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') res += ' ';
            else {
                int j = i + 1;
                while(j < n && isalpha(s[j])) j += 1;
                
                if(j - i > 2) res += toupper(s[i]);
                else res += tolower(s[i]);
                
                for(int k = i + 1; k < j; ++k) res += tolower(s[k]);
                i = j - 1;
            }
        }
        return res;
    }
};
