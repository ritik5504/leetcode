class Solution {
public:
    bool solve(int idx,vector<int>& nums,int n,int target,vector<vector<int>>&dp){
        if(target < 0) return 0;
        if(idx>= n) return 0;
        if(target == 0) return 1;

        if(dp[idx][target] != -1) return dp[idx][target];

        int inc=solve(idx+1,nums,n,target-nums[idx],dp);
        int exc=solve(idx+1,nums,n,target,dp);

        return dp[idx][target]=inc or exc;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total =0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total % 2 != 0) return 0;
        int target=total/2;

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return solve(0,nums,n,target,dp);
        
    }
};