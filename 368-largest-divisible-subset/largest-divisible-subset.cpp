class Solution {
public:
    vector<int> solve(int pre, int i, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if (i == nums.size()) return {};

        if (!dp[pre + 1][i].empty()) return dp[pre + 1][i];

        
        vector<int> skip = solve(pre, i + 1, nums, dp);

      
        vector<int> take;
        if (pre == -1 || nums[i] % nums[pre] == 0) {
            take = solve(i, i + 1, nums, dp);
            take.insert(take.begin(), nums[i]);
        }

      
        return dp[pre + 1][i] = (take.size() > skip.size() ? take : skip);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

       
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n));

        return solve(-1, 0, nums, dp);
    }
};
