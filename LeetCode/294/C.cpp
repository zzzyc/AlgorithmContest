class Solution {
public:
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int minimumLines(vector<vector<int>>& s) {
        sort(s.begin(), s.end(), [](const vector<int>& A, const vector<int>& B) {
            return A[0] < B[0]; 
        });
        
        int res = 0;
        int n = s.size();
        int prex = 0, prey = 0, pref = 1;
        for(int i = 1; i < n; ++i) {
            int ych = s[i][1] - s[i - 1][1];
            int xch = s[i][0] - s[i - 1][0];
            int fch = 1;
            if(ych < 0) fch = -1, ych = -ych;
            int g = gcd(xch, ych);
            xch /= g, ych /= g;
            if(prex == 0) {
                res += 1;
                prex = xch;
                prey = ych;
                pref = fch;
            } else {
                if(pref == fch && prex == xch && prey == ych) {
                    
                } else {
                    res += 1;
                    prex = xch;
                    prey = ych;
                    pref = fch;
                }
            }
        }
        return res;
    }
};
