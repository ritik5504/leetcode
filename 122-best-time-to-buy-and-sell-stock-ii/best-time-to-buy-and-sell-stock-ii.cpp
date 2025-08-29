class Solution {
public:
    int solve(int index,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(index==prices.size()) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];
        int profit=0;
        if(buy){
            int buyy=-prices[index]+solve(index+1,0,prices,dp);
            int skip=solve(index+1,1,prices,dp);
            profit=max(buyy,skip);

        }else{
            int sell=prices[index]+solve(index+1,1,prices,dp);
            int skip=solve(index+1,0,prices,dp);
            profit=max(sell,skip);

        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};