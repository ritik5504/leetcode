class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = 0;
        int n = stones.size();

        
        for (int i = 2; i < n; i++) {
            res = max(res, stones[i] - stones[i - 2]);
        }

       
        res = max(res, stones[1] - stones[0]);

        return res;
    }
};
