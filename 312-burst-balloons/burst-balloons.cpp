class Solution {
public:
    int solve(vector<int>& nums,int l,int r,vector<vector<int>>&dp){
        if(l>r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int maxcoin=0;
        for(int i=l;i<=r;i++){
            int coin=nums[i];

            if(l-1 >=0){
                coin *= nums[l-1];
            }else{
                coin *= 1;
            }

            if(r+1<nums.size() ){
                coin *= nums[r+1];
            }else{
                coin *= 1;
            }
            int total=solve(nums,l,i-1,dp)+solve(nums,i+1,r,dp)+coin;

            maxcoin=max(maxcoin,total);
        }
        return dp[l][r]= maxcoin;
        
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,n-1,dp);

        
    }
};