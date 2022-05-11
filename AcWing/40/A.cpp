#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b;
int cnt[10];
vector<int> A, B;
vector<ll> suf;
ll res;

bool check(int u) {
    ll v = 0;
    for(int i = 0; i <= 9; ++i)
        for(int j = 0; j < cnt[i]; ++j)
            v = v * 10 + i;
    return (v <= suf[u]);
}

bool checkMax(int u) {
	ll v = 0;
    for(int i = 9; i >= 0; --i)
        for(int j = 0; j < cnt[i]; ++j)
            v = v * 10 + i;
    return (v <= suf[u]);
}

bool dfs(int u, int n, ll temp, bool limit) {
    if(u == n) {
        res = max(res, temp);
        return true;
    }

	if(!limit) {
		for(int i = 9; i >= 0; --i)
			for(int j = 0; j < cnt[i]; ++j)
				temp = temp * 10 + i;
		res = max(res, temp);
		return true; 
	}
    
    for(int i = B[u]; i >= 0; --i) {
        if(cnt[i] > 0 && check(u)) { 
        	cnt[i] -= 1; 
            bool ok = (dfs(u + 1, n, temp * 10 + i, limit && i == B[u]));
            cnt[i] += 1;
            if(ok) return true;
        } 
    }
    
    return false;
}

int main()
{
    scanf("%lld%lld", &a, &b);
    while(a) {
        A.push_back(a % 10);
        cnt[a % 10] += 1;
        a /= 10;
    }
    
    ll tb = b;
    while(tb) {
        B.push_back(tb % 10);
        tb /= 10;
    }
    
    reverse(B.begin(), B.end());
    
    if(A.size() > B.size()) {
        printf("-1\n");
        return 0;
    } else if(A.size() < B.size()) {
        ll ans = 0;
        for(int i = 9; i >= 0; --i)
            while(cnt[i] > 0) ans = ans * 10 + i, cnt[i] -= 1;
            
        printf("%lld\n", ans);
        return 0;
    }
    
    for(int i = 0; i < B.size(); ++i) {
        ll v = 0;
        for(int j = i; j < B.size(); ++j)
            v = v * 10 + B[j];
        suf.push_back(v);
    }

    if(cnt[B[0]] > 0) {
        cnt[B[0]] -= 1;
        dfs(1, (int)B.size(), B[0], true);
        cnt[B[0]] += 1;
    }
    
    ll ans = 0; bool ok = false;
    for(int i = B[0] - 1; i >= 1; --i)
        if(cnt[i] > 0) {
            ans = ans * 10 + i;
            cnt[i] -= 1;
            ok = true;
            break;
        }
    if(ok) {
	    for(int i = 9; i >= 0; --i)
	        while(cnt[i] > 0) ans = ans * 10 + i, cnt[i] -= 1; 
	}
	
    ans = max(res, ans);
    
    printf("%lld\n", ans);
    
    return 0;
}
