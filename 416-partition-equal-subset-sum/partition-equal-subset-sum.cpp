class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, vector<vector<int>>& dp){
        if(sum == 0) return 1;
        if(i == nums.size()) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool ans = false;

        if(nums[i] <= sum){
            ans = ans || solve(nums, i+1, sum-nums[i], dp);
        }
        ans = ans || solve(nums, i+1, sum, dp);

        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;


        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int> ((sum/2)+1, -1));

        return solve(nums, 0, sum/2, dp);
    }
};