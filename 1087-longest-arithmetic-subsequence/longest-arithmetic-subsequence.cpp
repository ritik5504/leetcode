class Solution {
public:
    int n;
    vector<unordered_map<int,int>> dp;

    int solve(int i, int diff, vector<int>& nums) {
        if (dp[i].count(diff)) return dp[i][diff];

        int ans = 1; 

        
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] - nums[j] == diff) {
                ans = max(ans, 1 + solve(j, diff, nums));
                break; 
            }
        }
        return dp[i][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, {});
        int ans = 2; 

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int diff = nums[i] - nums[j];
                ans = max(ans, solve(j, diff, nums) + 1);
            }
        }
        return ans;
    }
};
