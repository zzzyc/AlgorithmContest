typedef long long ll;

class Solution {
public:
    long long maxRunTime(int m, vector<int>& b) {
        int n = b.size();
        
        auto check = [&](ll t) {
            ll sum = 0;
            for(auto u : b) sum += min((ll)u, t);
            return sum >= t * m;
        };
        
        ll l = 1, r = 1e14;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
