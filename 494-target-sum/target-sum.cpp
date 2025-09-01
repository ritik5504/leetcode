class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int curr,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(curr==target) return 1;

            else{
                return 0;
            }
        }

        if(dp[i][curr+1000] != -1) return dp[i][curr+1000];

        int add=solve(nums,target,i+1,curr+nums[i],dp);
        int sub=solve(nums,target,i+1,curr-nums[i],dp);

        return  dp[i][curr+1000]= add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+2000,-1));
        return solve(nums,target,0,0,dp);
        
    }
};