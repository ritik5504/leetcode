class Solution {
public:
    int solve(int index,int buy,vector<int>& prices, int fee,vector<vector<int>>&dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit=0;

        if(buy){
            int buyy=-prices[index]+solve(index+1,0,prices,fee,dp);
            int skp=solve(index+1,1,prices,fee,dp);
            profit=max(buyy,skp);
        }else{
            int sell=prices[index]-fee+solve(index+1,1,prices,fee,dp);
            int skp=solve(index+1,0,prices,fee,dp);
            profit=max(sell,skp);
        }
        return dp[index][buy]= profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,1,prices,fee,dp);
        
    }
};