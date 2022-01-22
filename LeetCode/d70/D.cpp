typedef long long ll;
class Solution {
public:
    int numberOfWays(string str) {
        const int mod = 1e9 + 7;
        int n = str.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) if(str[i] == 'S') ++cnt;
        if(cnt == 0 || (cnt & 1)) return 0;
        
        int res = 1;
        for(int i = 0; i < n; ++i) {
            int c = 0;
            while(i < n && c < 2) {
                if(str[i] == 'S') ++c;
                i += 1;
            }
            
            cnt -= c;
            i -= 1;
            // c == 2
            int j = i + 1;
            while(j < n && str[j] != 'S') j += 1;
            
            if(cnt > 0) res = 1ll * res * (j - i) % mod;
            
            i = j - 1;
        }
        
        return res;
    }

