class Solution {
public:
    int solve(int i,vector<int>& nums, int target, vector<vector<int>>&dp){
        if(target == 0) return 0;
        if(i==nums.size() || target <0) return -1e9;

        if(dp[i][target] != -1) return dp[i][target];

        int skp=solve(i+1,nums,target,dp);
        int take= 1+ solve(i+1,nums,target-nums[i],dp);

        return  dp[i][target] =max(skp,take);
        
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans= solve(0,nums,target,dp);

        return ans < 0 ? -1 : ans;

    }
};