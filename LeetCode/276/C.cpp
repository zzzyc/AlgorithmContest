typedef long long ll;
ll tr[100010];
int n;
ll get(int p) {
    ll res = 0;
    for(int i = p; i >= 1; i -= (i & -i)) {
        res = max(res, tr[i]);
    }
    return res;
}

void add(ll v, int p) {
    for(int i = p; i <= n; i += (i & -i)) {
        tr[i] = max(tr[i], v);
    }
}

class Solution {
public:
    
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        for(int i = 1; i <= n; ++i) tr[i] = 0;
        
        ll ans = 0;
        vector<ll> score(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            ll pre = get(i);
            
            score[i] = pre + questions[i - 1][0];
            if(i + questions[i - 1][1] + 1 <= n) add(score[i], i + questions[i - 1][1] + 1);
            ans = max(ans, score[i]);
        }
        
        return ans;
    }
};
