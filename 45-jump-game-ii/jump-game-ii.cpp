class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        if(nums[i]==0) return 1e9;

        int ans=1e9;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                ans=min(ans,1+solve(nums,i+j,dp));
            }
        }
         return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
        
        
    }
};