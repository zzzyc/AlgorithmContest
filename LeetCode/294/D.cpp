typedef long long ll;
class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int totalStrength(vector<int>& a) {
        ll res = 0;
        int n = a.size();
        vector<int> Lrank(n + 2, 0), Rrank(n + 2, 0);
        for(int i = 1; i <= n; ++i) Lrank[i] = i, Rrank[n - i + 1] = i;
        vector<ll> ppre(n + 2, 0), ssuf(n + 2, 0);
        vector<ll> pre(n + 2, 0), suf(n + 2, 0);
        for(int i = 1; i <= n; ++i) pre[i] = (pre[i - 1] + a[i - 1]) % mod;
        for(int i = n; i >= 1; --i) suf[i] = (suf[i + 1] + a[i - 1]) % mod;
        for(int i = 1; i <= n; ++i) ppre[i] = (ppre[i - 1] + 1ll * a[i - 1] * Lrank[i] % mod) % mod;
        for(int i = n; i >= 1; --i) ssuf[i] = (ssuf[i + 1] + 1ll * a[i - 1] * Rrank[i] % mod) % mod;
        
        vector<int> Rfirst(n + 2, 0);
        vector<int> Lfirst(n + 2, 0);
        stack<int> stk;
        for(int i = 1; i <= n; ++i) {
            while(!stk.empty() && a[stk.top() - 1] >= a[i - 1]) stk.pop();
            if(!stk.empty()) Lfirst[i] = stk.top();
            else Lfirst[i] = 0;
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        for(int i = n; i >= 1; --i) {
            while(!stk.empty() && a[stk.top() - 1] > a[i - 1]) stk.pop();
            if(!stk.empty()) Rfirst[i] = stk.top();
            else Rfirst[i] = n + 1;
            stk.push(i);
        }
        
        for(int i = 1; i <= n; ++i) {
        	// 计算左边 
            ll Lf = Lfirst[i];
            ll Lv = ((ppre[i - 1] - ppre[Lf]) % mod + mod) % mod;
            Lv = (Lv - 1ll * Lrank[Lf] * (pre[i - 1] - pre[Lf]) % mod + mod) % mod;
            
            // 计算右边 
            ll Rf = Rfirst[i];
            ll Rv = ((ssuf[i + 1] - ssuf[Rf]) % mod + mod) % mod;
            Rv = (Rv - 1ll * Rrank[Rf] * (suf[i + 1] - suf[Rf]) % mod + mod) % mod;
            
            // 计算最小值 
            ll Mv = 1ll * (i - Lf) * (Rf - i) % mod * a[i - 1] % mod;
            
            // 计算左边和 乘 右边方案数，    计算右边和 乘 左边方案数 
            ll temp = (Lv * (Rf - i) % mod + Rv * (i - Lf) % mod) % mod;
            
            // 计算所有区间i的和 
            ll sum = (temp + Mv) % mod;
            
            res = (res + 1ll * sum * a[i - 1] % mod) % mod;
        }
        
        return res;
    }
};
