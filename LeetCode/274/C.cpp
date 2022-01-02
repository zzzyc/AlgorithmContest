class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        long long m = mass;
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); ++i) {
            if(m >= a[i]) m += a[i];
            else return false;
        }
        return true;
    }
};

/*
Learning from Heltion.

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        vector<int> minv(17, -1);
        vector<long long> sum(17, 0);
        
        for(auto u : a) {
            int h = 31 - __builtin_clz(u);
            if(minv[h] == -1 || minv[h] > u) minv[h] = u;
            sum[h] += u;
        }
        
        long long s = mass;
        for(int i = 0; i < 17; ++i)
            if(s >= minv[i]) s += sum[i];
            else return false;
        return true;
    }
};

*/
