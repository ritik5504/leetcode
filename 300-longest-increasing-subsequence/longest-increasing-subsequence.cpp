class Solution {
public:
    int solve(int curr,int pre,vector<int>& nums,vector<vector<int>>&dp){
        if(curr==nums.size()) return 0;

        if(dp[curr][pre+1] != -1) return dp[curr][pre+1];

        int take=0;
        if(pre == -1 || nums[curr] > nums[pre]){
            take=1+solve(curr+1,curr,nums,dp);
        }
        int skip=solve(curr+1,pre,nums,dp);

        return dp[curr][pre+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(0,-1,nums,dp);
    }
};