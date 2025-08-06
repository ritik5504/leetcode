class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<int>&dp){
        if(i>=j)return 0;
        if(dp[i] != -1) return dp[i];

        int rob=nums[i]+solve(nums,i+2,j,dp);
        int skip=solve(nums,i+1,j,dp);

        return dp[i]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        int case1=solve(nums,0,n-1,dp1);
        int case2=solve(nums,1,n,dp2);

        return max(case1,case2);
        
    }
};