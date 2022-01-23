class Solution {
public:
    int minMoves(int target, int cnt) {
        
        int t = 0;
        while(target > 1 && cnt > 0) {
            if(target & 1) target -= 1;
            else cnt -= 1, target /= 2;
            t += 1;
        }
        if(cnt == 0) t += target - 1;
        return t;
    }
};
